#ifndef BOUNDEDQUEUE_H
#define BOUNDEDQUEUE_H

#include <cstddef>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

template <class T> class BoundedQueue {
public:
  explicit BoundedQueue(size_t size)
      : buf_(std::unique_ptr<T[]>(new T[size])), max_size_(size) {}

  void put(T item);
  T get();
  void push(T &value);
  T pop();
  bool tryPush(const T &value);
  bool tryPop(T &out);
  void reset();
  bool empty() const;
  bool full() const;
  size_t capacity() const;
  size_t size() const;

private:
  std::mutex mutex_;
  std::unique_ptr<T[]> buf_;
  size_t head_ = 0;
  size_t tail_ = 0;
  const size_t max_size_;
  bool full_ = 0;
};

template <class T> void BoundedQueue<T>::put(T item) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (full_) {
    throw std::runtime_error("Queue is full");
  }
  buf_[tail_] = std::move(item);
  tail_ = (tail_ + 1) % max_size_;
  full_ = (tail_ == head_);
}

template <class T> T BoundedQueue<T>::get() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (empty()) {
    throw std::runtime_error("Queue is empty");
  }
  T item = std::move(buf_[head_]);
  head_ = (head_ + 1) % max_size_;
  full_ = false;
  return item;
}

template <class T> void BoundedQueue<T>::push(T &value) {
  std::unique_lock<std::mutex> lock(mutex_);
  while (full_) {
    lock.unlock();
    std::this_thread::yield();
    lock.lock();
  }
  buf_[tail_] = std::move(value);
  tail_ = (tail_ + 1) % max_size_;
  full_ = (tail_ == head_);
}

template <class T> T BoundedQueue<T>::pop() {
  std::unique_lock<std::mutex> lock(mutex_);
  while (empty()) {
    lock.unlock();
    std::this_thread::yield();
    lock.lock();
  }

  T item = std::move(buf_[head_]);
  head_ = (head_ + 1) % max_size_;
  full_ = false;
  return item;
}

template <class T> bool BoundedQueue<T>::tryPush(const T &value) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (full_) {
    return false;
  }

  buf_[tail_] = value;
  tail_ = (tail_ + 1) % max_size_;
  full_ = (tail_ == head_);
  return true;
}

template <class T> bool BoundedQueue<T>::tryPop(T &out) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (empty()) {
    return false;
  }
  out = std::move(buf_[head_]);
  head_ = (head_ + 1) % max_size_;
  full_ = false;
  return true;
}

template <class T> void BoundedQueue<T>::reset() {
  std::lock_guard<std::mutex> lock(mutex_);
  head_ = tail_ = 0;
  full_ = false;
}

template <class T> bool BoundedQueue<T>::empty() const {
  return (!full_ && (head_ == tail_));
}

template <class T> bool BoundedQueue<T>::full() const { return full_; }

template <class T> size_t BoundedQueue<T>::capacity() const {
  return max_size_;
}

template <class T> size_t BoundedQueue<T>::size() const {
  if (full_) {
    return max_size_;
  }
  if (tail_ >= head_) {
    return tail_ - head_;
  }
  return max_size_ - head_ + tail_;
}

#endif

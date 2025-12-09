#include "/Users/fil/code/Dev Container (C++)/Prac/OOP/Thread safe Bounded queue/include/BoundedQueue.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void producer(BoundedQueue<int> &queue, int id, int count) {
  for (int i = 0; i < count; ++i) {
    int value = id * 1000 + i;
    queue.push(value);
    std::cout << "Producer " << id << " pushed: " << value << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}

void consumer(BoundedQueue<int> &queue, int id, int count) {
  for (int i = 0; i < count; ++i) {
    int value = queue.pop();
    std::cout << "Consumer " << id << " popped: " << value << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main() {
  std::cout << "=== Testing BoundedQueue ===" << std::endl << std::endl;

  // Test 1: Basic operations
  std::cout << "Test 1: Basic put/get operations" << std::endl;
  BoundedQueue<int> queue1(5);

  std::cout << "Queue capacity: " << queue1.capacity() << std::endl;
  std::cout << "Queue size: " << queue1.size() << std::endl;
  std::cout << "Queue empty: " << (queue1.empty() ? "yes" : "no") << std::endl;

  queue1.put(10);
  queue1.put(20);
  queue1.put(30);

  std::cout << "After adding 3 items, size: " << queue1.size() << std::endl;
  std::cout << "Got: " << queue1.get() << std::endl;
  std::cout << "Got: " << queue1.get() << std::endl;
  std::cout << "Size after getting 2 items: " << queue1.size() << std::endl;
  std::cout << std::endl;

  // Test 2: tryPush and tryPop
  std::cout << "Test 2: tryPush and tryPop" << std::endl;
  BoundedQueue<int> queue2(3);

  std::cout << "tryPush 1: " << (queue2.tryPush(100) ? "success" : "failed")
            << std::endl;
  std::cout << "tryPush 2: " << (queue2.tryPush(200) ? "success" : "failed")
            << std::endl;
  std::cout << "tryPush 3: " << (queue2.tryPush(300) ? "success" : "failed")
            << std::endl;
  std::cout << "Queue is full: " << (queue2.full() ? "yes" : "no") << std::endl;
  std::cout << "tryPush 4 (should fail): "
            << (queue2.tryPush(400) ? "success" : "failed") << std::endl;

  int value;
  queue2.tryPop(value);
  std::cout << "tryPop got: " << value << std::endl;
  std::cout << "Queue is full: " << (queue2.full() ? "yes" : "no") << std::endl;
  std::cout << std::endl;

  // Test 3: Multi-threaded test
  std::cout << "Test 3: Multi-threaded producer-consumer" << std::endl;
  BoundedQueue<int> queue3(10);

  std::vector<std::thread> threads;

  // Create 2 producers
  threads.emplace_back(producer, std::ref(queue3), 1, 5);
  threads.emplace_back(producer, std::ref(queue3), 2, 5);

  // Create 2 consumers
  threads.emplace_back(consumer, std::ref(queue3), 1, 5);
  threads.emplace_back(consumer, std::ref(queue3), 2, 5);

  // Wait for all threads to finish
  for (auto &t : threads) {
    t.join();
  }

  std::cout << "\nFinal queue size: " << queue3.size() << std::endl;
  std::cout << std::endl;

  // Test 4: Reset functionality
  std::cout << "Test 4: Reset functionality" << std::endl;
  BoundedQueue<int> queue4(5);
  queue4.put(1);
  queue4.put(2);
  queue4.put(3);
  std::cout << "Size before reset: " << queue4.size() << std::endl;
  queue4.reset();
  std::cout << "Size after reset: " << queue4.size() << std::endl;
  std::cout << "Empty after reset: " << (queue4.empty() ? "yes" : "no")
            << std::endl;
  std::cout << std::endl;

  std::cout << "=== All tests completed ===" << std::endl;

  return 0;
}

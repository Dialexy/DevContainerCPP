#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdexcept>
#include <string>
#include <typeindex>
#include <vector>

class Settings {
public:
  explicit Settings(size_t capacity = 10);

  template <typename T> void set(const std::string &key, const T &value);

  template <typename T> T get(const std::string &key) const;

  bool exists(const std::string &key) const;
  void remove(const std::string &key);
  size_t size() const;

private:
  struct Entry {
    std::string key;
    void *data;
    std::type_index type;
  };

  std::vector<Entry> entries_;
  size_t maxSize_;

  int findIndex(const std::string &key) const;
  void freeEntry(Entry &e);
};

#endif

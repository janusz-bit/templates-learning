// Zadanie - isIntKey()
// Napisz metodą isIntKey() w VectorMap. Powinna ona zwracać true gdy KeyType jest intem i lub false w przeciwnym przypadku.

// Przejrzyj listę <type_traits> w poszukiwaniu inspiracji 🙂

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>
template <typename T1, typename T2> class VectorMap {
    static_assert(std::is_default_constructible_v<T1> && std::is_default_constructible_v<T2>, "No default constructors");
  std::vector<T1> keys_;
  std::vector<T2> values_;

  T2 &at_(const T1 &key, const bool noThrow = false) {
    auto it = std::find(keys_.begin(), keys_.end(), key);
    if (!noThrow && it == keys_.end()) {
      throw std::out_of_range("No key");
    }
    size_t where = std::distance(it, keys_.end());
    return values_[where];
  }

public:
  void insert(const T1 &key, const T2 &value) {
    keys_.push_back(key);
    values_.push_back(value);
    return;
  }

  T2 &operator[](const T1 &key) { return at_(key, true); }

  T2 &at(const T1 &key) { return at_(key); }

  bool isIntKey()
  {
    return std::is_same_v<T1, int>;
  }
};

int main() {
  VectorMap<double, char> map;
  VectorMap<int, char> map1;
  map.insert(1, 'c');
  map[1] = 'e';        // replaces value under 1
  std::cout << map[1]<<'\n'<<map.isIntKey()<<'\n'; // prints 'e'
  std::cout<<map1.isIntKey()<<'\n';

  map.at(2);           // throw std::out_of_range
}
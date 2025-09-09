// Zadanie - is_int_key
// W klasie VectorMap dodaj stałą is_int_key typu bool. Powinna być ona ustawiona na true gdy klucz jest typu int, a na false w przeciwnym przypadku.

// Ogólnie ta stała powinna robić to samo co metoda isIntKey(), z tą różnicą, że nie musimy tworzyć obieku klasy, aby ją dostać (to właśnie jest metaprogramowanie).

// Poszukaj przydatnych rzeczy w bibliotece <type_traits> 🙂

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

  static constexpr bool is_int_key = std::is_same_v<T1, int>;
};

int main() {
  VectorMap<double, char> map;
  map.insert(1, 'c');
  map[1] = 'e';        // replaces value under 1
  std::cout << map[1]<<'\n'<<map.isIntKey()<<'\n'; // prints 'e'
  std::cout<<VectorMap<int, char>::is_int_key<<'\n';

  map.at(2);           // throw std::out_of_range
}
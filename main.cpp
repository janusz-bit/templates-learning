// Zadanie - VectorMap
// Napisz klasę szablonową VectorMap, która ma reprezentować przekombinowaną
// std::map.

// Wewnątrz ma ona mieć 2 std::vector tego samego rozmiaru. Pierwszy vector
// będzie przechowywał klucze, a drugi wartości.

// Elementy na tej samej pozycji w obu wektorach tworzą parę, tak jak 1 i c na
// poniższym przykładzie.

// VectorMap<int, char> map;
// map.insert(1, 'c');
// map[1] = 'e';           // replaces value under 1
// std::cout << map[1];    // prints 'e'
// map.at(2);              // throw std::out_of_range
// Zaimplementuj metody insert(), operator[], at().

// Nie przejmuj się możliwymi duplikatami kluczy. To nie jest ważne w tym
// zadaniu. Możesz za to zaimplementować dodatkowe metody z interfejsu std::map
// 🙂

// Używaj cppreference.

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
template <typename T1, typename T2> class VectorMap {
  std::vector<T1> keys_;
  std::vector<T2> values_;

public:
  void insert(const T1& key, const T2& value) {
    keys_.push_back(key);
    values_.push_back(value);
    return;
  }
  T2 &operator[](const T1 &key) {
    auto it = std::find(keys_.begin(), keys_.end(), key);
    if (it == keys_.end()) {
      throw std::out_of_range("");
    }
    size_t where = std::distance(it, keys_.end());
    return values_[where];
  };
  T2 &at(const T1 &key) { return operator[](key); }
};

int main() {
  VectorMap<int, char> map;
  map.insert(1, 'c');
  map[1] = 'e';        // replaces value under 1
  std::cout << map[1]; // prints 'e'
  map.at(2);           // throw std::out_of_range
}
// Zadanie
// Napisz częściową specjalizację klasy VectorMap dla kluczy typu bool. Taka
// wersja mapy może trzymać tylko 2 pary, bo możemy mieć tylko 2 klucze: true
// oraz false. Nie musimy zatem trzymać wewnątrz wektorów i możemy
// zoptymalizować implementację.

// Zaimplementuj odpowiednio wszystkie metody dostępne w głównym szablonie.

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>
template <typename T1, typename T2> class VectorMap {
  static_assert(std::is_default_constructible_v<T1> &&
                    std::is_default_constructible_v<T2>,
                "No default constructors");
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

  bool isIntKey() { return std::is_same_v<T1, int>; }

  static constexpr bool is_int_key = std::is_same_v<T1, int>;
};

template <typename T2> class VectorMap<bool, T2> {
  T2 false_, hasValueFalse{};
  T2 true_, hasValueTrue{};

  T2 &at_(const bool &key, const bool noThrow = false) {
    if (hasValueTrue) {
      return true_;
    } else if (hasValueFalse) {
      return false_;
    }
    throw std::out_of_range("No key");
  }

public:
  void insert(const bool &key, const T2 &value) {
    if (key) {
      true_ = value;
      hasValueTrue = true;
    } else {
      false_ = value;
      hasValueFalse = true;
    }
    return;
  }

  T2 &operator[](const bool &key) { return at_(key, true); }

  T2 &at(const bool &key) { return at_(key); }

  bool isIntKey() { return std::is_same_v<bool, int>; }

  static constexpr bool is_int_key = std::is_same_v<bool, int>;
};

int main() {
  VectorMap<double, char> map;
  map.insert(1, 'c');
  map[1] = 'e'; // replaces value under 1
  std::cout << map[1] << '\n' << map.isIntKey() << '\n'; // prints 'e'
  std::cout << VectorMap<int, char>::is_int_key << '\n';

  std::cout<<"---------\n";
  VectorMap<bool, char> map1;
  std::cout<<"---------\n";
  map1.insert(true, 'c');
  std::cout<<"---------\n";
  map1[true] = 'e'; // replaces value under `true`
  std::cout<<"---------\n";
  std::cout << map1[true] << '\n' << map1.isIntKey() << '\n'; // prints 'e'
  std::cout<<"---------\n";
  std::cout << VectorMap<bool, char>::is_int_key << '\n';
  std::cout<<"---------\n";


  map.at(2); // throw std::out_of_range
}
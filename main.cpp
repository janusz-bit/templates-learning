// Zadanie
// Napisz funkcję makeComplex(), która tworzy liczbę zespoloną std::complex z dwóch dostarczonych liczb. Jeśli typy tych liczb są różne, powinna utworzyć się liczba zespolona z typem pierwszego parametru.

// std::complex<int> a = makeComplex(4, 5);        // both ints
// std::complex<double> b = makeComplex(3.0, 2.0); // both doubles
// std::complex<int> c = makeComplex(1, 5.0); // int, double -> takes int


#include <complex>
#include <iostream>


template <typename T1, typename T2>
std::complex<T1> makeComplex(T1 real, T2 imag)
{
    return std::complex<T1>(real,imag);
};


int main()
{
    auto complex = makeComplex(4, 4.5);
    std::cout<<complex.real()<<" + i * "<<complex.imag()<<'\n';
}

#ifndef MATRIX_NUMERICAL_H
#define MATRIX_NUMERICAL_H

#include "MatrixBase.h"
#include <type_traits>

template <typename T>
class MatrixNumerical;

// Renvoie le mineur : on retire une ligne et une colonne.
template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& matrix,
                              std::size_t excludedRow, std::size_t excludedCol);

template <typename T>
class MatrixNumerical : public MatrixBase<T>
{
    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value,
                  "MatrixNumerical exige un type numerique (hors bool).");

    void checkSameSize(const MatrixNumerical& other) const;

public:
    MatrixNumerical();

    MatrixNumerical(std::size_t r, std::size_t c, T value = T{});

    explicit MatrixNumerical(const std::vector<std::vector<T>>& values);

    MatrixNumerical(std::initializer_list<std::vector<T>> values);

    MatrixNumerical(const MatrixNumerical&) = default;
    MatrixNumerical& operator=(const MatrixNumerical&) = default;

    // Developpement de Laplace sur la premiere ligne.
    // long double evite les divisions entieres et les calculs non signes.
    long double getDeterminant() const;

    MatrixNumerical operator+(const MatrixNumerical& other) const;

    MatrixNumerical operator-(const MatrixNumerical& other) const;

    MatrixNumerical operator*(const MatrixNumerical& other) const;

    // L'inverse peut contenir des fractions meme si T est int.
    MatrixNumerical<long double> getInverse() const;

    // Convention : A / B = A * inverse(B).
    MatrixNumerical<long double> operator/(const MatrixNumerical& other) const;

    static MatrixNumerical getIdentity(int size);
};

// Les definitions des templates doivent etre visibles a la compilation.
#include "MatrixNumerical.cpp"

#endif

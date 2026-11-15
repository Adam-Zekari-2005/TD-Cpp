#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <vector>

template <typename T>
class MatrixBase
{
protected:
    std::vector<std::vector<T>> data;
    std::size_t rows;
    std::size_t cols;

public:
    MatrixBase();

    MatrixBase(std::size_t r, std::size_t c, const T& value = T{});

    explicit MatrixBase(const std::vector<std::vector<T>>& values);

    MatrixBase(std::initializer_list<std::vector<T>> values);

    MatrixBase(const MatrixBase&) = default;
    MatrixBase& operator=(const MatrixBase&) = default;

    // Les indices commencent a 0. addElement place/remplace une valeur.
    void addElement(std::size_t row, std::size_t col, const T& value);

    const T& getElement(std::size_t row, std::size_t col) const;

    std::size_t getRows() const;
    std::size_t getCols() const;

    void Display() const;
};

// Les definitions des templates doivent etre visibles a la compilation.
#include "MatrixBase.cpp"

#endif

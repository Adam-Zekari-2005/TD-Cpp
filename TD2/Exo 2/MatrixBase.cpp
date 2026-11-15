#ifndef MATRIXBASE_IMPLEMENTATION
#define MATRIXBASE_IMPLEMENTATION

#include "MatrixBase.h"

template <typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) 
{}

template <typename T>
MatrixBase<T>::MatrixBase(std::size_t r, std::size_t c, const T& value)
    : data(r, std::vector<T>(c, value)), rows(r), cols(c) 
{}

template <typename T>
MatrixBase<T>::MatrixBase(const std::vector<std::vector<T>>& values)
    : data(values), rows(values.size()),
      cols(values.empty() ? 0 : values[0].size())
{
    for (const auto& row : data)
        if (row.size() != cols)
            throw std::invalid_argument("Les lignes doivent avoir la meme taille.");
}

template <typename T>
MatrixBase<T>::MatrixBase(std::initializer_list<std::vector<T>> values)
    : MatrixBase(std::vector<std::vector<T>>(values)) 
{}

template <typename T>
void MatrixBase<T>::addElement(std::size_t row, std::size_t col, const T& value)
{
    data.at(row).at(col) = value;
}

template <typename T>
const T& MatrixBase<T>::getElement(std::size_t row, std::size_t col) const
{
    return data.at(row).at(col);
}

template <typename T>
std::size_t MatrixBase<T>::getRows() const
{ return rows; }

template <typename T>
std::size_t MatrixBase<T>::getCols() const
{ return cols; }

template <typename T>
void MatrixBase<T>::Display() const
{
    for (const auto& row : data)
    {
        for (const auto& value : row)
            std::cout << value << '\t';
        std::cout << '\n';
    }
}

#endif

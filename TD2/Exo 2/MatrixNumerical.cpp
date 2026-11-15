#ifndef MATRIXNUMERICAL_IMPLEMENTATION
#define MATRIXNUMERICAL_IMPLEMENTATION

#include "MatrixNumerical.h"

template <typename T>
void MatrixNumerical<T>::checkSameSize(const MatrixNumerical& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)
        throw std::invalid_argument("Les dimensions doivent etre identiques.");
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() 
{}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::size_t r, std::size_t c, T value)
    : MatrixBase<T>(r, c, value) 
{}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(const std::vector<std::vector<T>>& values)
    : MatrixBase<T>(values) 
{}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::initializer_list<std::vector<T>> values)
    : MatrixBase<T>(values) 
{}

template <typename T>
long double MatrixNumerical<T>::getDeterminant() const
{
    if (this->rows != this->cols)
        throw std::invalid_argument("Le determinant exige une matrice carree.");
    if (this->rows == 0)
        return 1; // Convention utile pour le cofacteur d'une matrice 1 x 1.
    if (this->rows == 1)
        return static_cast<long double>(this->data[0][0]);

    long double determinant = 0;
    for (std::size_t j = 0; j < this->cols; ++j)
    {
        const int sign = (j % 2 == 0) ? 1 : -1;
        determinant += sign * static_cast<long double>(this->data[0][j])
                     * getCoFactor(*this, 0, j).getDeterminant();
    }
    return determinant;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical& other) const
{
    checkSameSize(other);
    MatrixNumerical result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; ++i)
        for (std::size_t j = 0; j < this->cols; ++j)
            result.data[i][j] = this->data[i][j] + other.data[i][j];
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical& other) const
{
    checkSameSize(other);
    MatrixNumerical result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; ++i)
        for (std::size_t j = 0; j < this->cols; ++j)
            result.data[i][j] = this->data[i][j] - other.data[i][j];
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical& other) const
{
    if (this->cols != other.rows)
        throw std::invalid_argument("Produit impossible : colonnes(A) != lignes(B).");
    MatrixNumerical result(this->rows, other.cols);
    for (std::size_t i = 0; i < this->rows; ++i)
        for (std::size_t j = 0; j < other.cols; ++j)
            for (std::size_t k = 0; k < this->cols; ++k)
                result.data[i][j] += this->data[i][k] * other.data[k][j];
    return result;
}

template <typename T>
MatrixNumerical<long double> MatrixNumerical<T>::getInverse() const
{
    const long double determinant = getDeterminant();
    if (determinant == 0)
        throw std::domain_error("Matrice singuliere : inverse impossible.");

    MatrixNumerical<long double> inverse(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; ++i)
        for (std::size_t j = 0; j < this->cols; ++j)
        {
            const int sign = ((i + j) % 2 == 0) ? 1 : -1;
            const long double cofactor = sign * getCoFactor(*this, i, j).getDeterminant();
            // Transposition des cofacteurs : inverse(j, i) = C(i, j) / det.
            inverse.addElement(j, i, cofactor / determinant);
        }
    return inverse;
}

// Convention : A / B = A * inverse(B).
template <typename T>
MatrixNumerical<long double> MatrixNumerical<T>::operator/(const MatrixNumerical& other) const
{
    if (this->cols != other.rows)
        throw std::invalid_argument("Dimensions incompatibles pour la division.");
    MatrixNumerical<long double> left(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; ++i)
        for (std::size_t j = 0; j < this->cols; ++j)
            left.addElement(i, j, static_cast<long double>(this->data[i][j]));
    return left * other.getInverse();
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size)
{
    if (size < 0)
        throw std::invalid_argument("La taille doit etre positive ou nulle.");
    const auto n = static_cast<std::size_t>(size);
    MatrixNumerical identity(n, n);
    for (std::size_t i = 0; i < n; ++i)
        identity.data[i][i] = T{1};
    return identity;
}

template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& matrix,
                              std::size_t excludedRow, std::size_t excludedCol)
{
    if (excludedRow >= matrix.getRows() || excludedCol >= matrix.getCols())
        throw std::out_of_range("Indice de cofacteur invalide.");

    MatrixNumerical<T> minor(matrix.getRows() - 1, matrix.getCols() - 1);
    std::size_t minorRow = 0;
    for (std::size_t i = 0; i < matrix.getRows(); ++i)
    {
        if (i == excludedRow)
            continue;
        std::size_t minorCol = 0;
        for (std::size_t j = 0; j < matrix.getCols(); ++j)
        {
            if (j == excludedCol)
                continue;
            minor.addElement(minorRow, minorCol++, matrix.getElement(i, j));
        }
        ++minorRow;
    }
    return minor;
}

#endif

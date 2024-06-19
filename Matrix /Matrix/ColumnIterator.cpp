//
// Created by mfbut on 11/17/2019.
//

#include "ColumnIterator.h"
#include "ConstColumnIterator.h"
#include "Matrix.h"

Matrix::ColumnIterator::ColumnIterator(Matrix* matrix, int col) {
    this->matrix = matrix;
    this->col = col;
}

Matrix::ColumnIterator::operator ConstColumnIterator() const {
    ConstColumnIterator temp(matrix, col);
    return temp;
}

Matrix::ConstVectorRef Matrix::ColumnIterator::operator*() const {
  return const_cast<const Matrix*>(matrix)->colAt(col);
}

Matrix::ColumnIterator::value_type Matrix::ColumnIterator::operator*() {
    return matrix->colAt(col);
}



Matrix::ConstVectorRef  Matrix::ColumnIterator::operator[](int offset) const {
  return const_cast<const Matrix*>(matrix)->colAt(col + offset);
}

Matrix::ColumnIterator::value_type Matrix::ColumnIterator::operator[](int offset) {
    return matrix->colAt(col + offset);
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator++() {

    ++col;
    return *this;
}

const Matrix::ColumnIterator Matrix::ColumnIterator::operator++(int) {
    ColumnIterator temp(*this);
    ++(*this);
    return temp;
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator--() {
    --col;
    return *this;
}

const Matrix::ColumnIterator Matrix::ColumnIterator::operator--(int) {
    ColumnIterator temp(*this);
    --(*this);
    return temp;
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator+=(int amount) {
    col += amount;
    return *this;
}

Matrix::ColumnIterator Matrix::ColumnIterator::operator+(int amount) const {
    ColumnIterator temp(*this);
    temp.col += amount;
    return temp;
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator-=(int amount) {
    col-= amount;
    return *this;
}

Matrix::ColumnIterator Matrix::ColumnIterator::operator-(int amount) const {
    ColumnIterator temp(*this);
    temp.col -= amount;
    return temp;
}

Matrix::ColumnIterator::difference_type Matrix::ColumnIterator::operator-(const ColumnIterator& rhs) {
    return abs(col - rhs.col);
}

bool Matrix::ColumnIterator::operator==(const ColumnIterator& rhs) const {

    return(col==rhs.col&& matrix==rhs.matrix);
}

bool Matrix::ColumnIterator::operator!=(const ColumnIterator& rhs) const {
    return(col<rhs.col) ;
}

bool Matrix::ColumnIterator::operator<(const ColumnIterator& rhs) const {
    return(col < rhs.col);
}

bool Matrix::ColumnIterator::operator<=(const ColumnIterator& rhs) const {
    return(col <= rhs.col);
}

bool Matrix::ColumnIterator::operator>(const ColumnIterator& rhs) const {
    return(col > rhs.col);
}

bool Matrix::ColumnIterator::operator>=(const ColumnIterator& rhs) const {
    return(col >= rhs.col);
}

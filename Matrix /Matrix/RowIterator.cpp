//
// Created by mfbut on 11/17/2019.
//

#include "RowIterator.h"
#include "Matrix.h"

Matrix::RowIterator::RowIterator(Matrix* matrix, int row)  {
    this->matrix = matrix;
    this->row = row;

}

Matrix::RowIterator::operator ConstRowIterator() const {
   ConstRowIterator temp(matrix, row);
   return temp;
   }

Matrix::ConstVectorRef Matrix::RowIterator::operator*() const {
  //make sure that we call the const at method on matrix
  return const_cast<const Matrix*>(matrix)->rowAt(row);
}

Matrix::ConstVectorRef Matrix::RowIterator::operator[](int offset) const {
  //make sure that we call the const at method on matrix
  return const_cast<const Matrix*>(matrix)->rowAt(row + offset);
}

Matrix::RowIterator::value_type Matrix::RowIterator::operator*() {
    return matrix->rowAt(row);

}

Matrix::RowIterator::value_type Matrix::RowIterator::operator[](int offset) {
    return matrix->rowAt(row + offset);
}

Matrix::RowIterator& Matrix::RowIterator::operator++() {
    ++row;
    return *this;
}

const Matrix::RowIterator Matrix::RowIterator::operator++(int) {
    RowIterator temp(*this);
    ++temp.row;
    return *this;

}

Matrix::RowIterator& Matrix::RowIterator::operator--() {
    --row;
    return *this;
}

const Matrix::RowIterator Matrix::RowIterator::operator--(int) {
    RowIterator temp(*this);
    --temp.row;
    return *this;
}

Matrix::RowIterator& Matrix::RowIterator::operator+=(int amount) {
    row += amount;
    return *this;
}

Matrix::RowIterator Matrix::RowIterator::operator+(int amount) const {
    RowIterator temp(*this);
    temp.row += amount;
    return temp;
}

Matrix::RowIterator& Matrix::RowIterator::operator-=(int amount) {
    row-= amount;
    return *this;
}

Matrix::RowIterator Matrix::RowIterator::operator-(int amount) const {
    RowIterator temp(*this);
    temp.row -= amount;
    return temp;
}

Matrix::RowIterator::difference_type Matrix::RowIterator::operator-(const RowIterator& rhs) {
    return abs(row - rhs.row);
}

bool Matrix::RowIterator::operator==(const RowIterator& rhs) const {
    return(row==rhs.row&&matrix==rhs.matrix);
}

bool Matrix::RowIterator::operator!=(const RowIterator& rhs) const {
    return(row<rhs.row);
}

bool Matrix::RowIterator::operator<(const RowIterator& rhs) const {
    return(row<rhs.row);
}

bool Matrix::RowIterator::operator<=(const RowIterator& rhs) const {
    return(row<=rhs.row);
}

bool Matrix::RowIterator::operator>(const RowIterator& rhs) const {
    return(row>rhs.row);
}

bool Matrix::RowIterator::operator>=(const RowIterator& rhs) const {
    return(row>=rhs.row);
}

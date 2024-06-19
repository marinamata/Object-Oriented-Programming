//
// Created by mfbut on 11/17/2019.
//


#include "ConstRowIterator.h"
#include "Matrix.h"

Matrix::ConstRowIterator::ConstRowIterator(const Matrix* matrix, int row) {
    this->matrix = matrix;
    this->row = row;
}

Matrix::ConstRowIterator::value_type Matrix::ConstRowIterator::operator*() const {
    return const_cast<const Matrix*>(matrix)->rowAt(row);
}

Matrix::ConstRowIterator::value_type Matrix::ConstRowIterator::operator[](int offset) const {
    return const_cast<const Matrix*>(matrix)->rowAt(row + offset);
}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator++() {
    ++row;
    return *this;
}

const Matrix::ConstRowIterator Matrix::ConstRowIterator::operator++(int) {
    ConstRowIterator temp(*this);
    ++(*this);
    return temp;

}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator--() {
    --row;
    return *this;

}

const Matrix::ConstRowIterator Matrix::ConstRowIterator::operator--(int) {
    ConstRowIterator temp(*this);
    ++(*this);
    return temp;

}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator+=(int amount) {
    row += amount;
    return *this;

}

Matrix::ConstRowIterator Matrix::ConstRowIterator::operator+(int amount) const {
    ConstRowIterator temp(*this);
    temp.row+= amount;
    return temp;

}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator-=(int amount) {
    row-= amount;
    return *this;

}

Matrix::ConstRowIterator Matrix::ConstRowIterator::operator-(int amount) const {
    ConstRowIterator temp(*this);
    temp.row -= amount;
    return temp;

}

Matrix::ConstRowIterator::difference_type Matrix::ConstRowIterator::operator-(const ConstRowIterator& rhs) {
    return abs(row - rhs.row);
}

bool Matrix::ConstRowIterator::operator==(const ConstRowIterator& rhs) const {
    return(row==rhs.row&&matrix==rhs.matrix);
}

bool Matrix::ConstRowIterator::operator!=(const ConstRowIterator& rhs) const {
    return(row <rhs.row);
}

bool Matrix::ConstRowIterator::operator<(const ConstRowIterator& rhs) const {
    return(row < rhs.row);
}

bool Matrix::ConstRowIterator::operator<=(const ConstRowIterator& rhs) const {
    return(row <= rhs.row);
}

bool Matrix::ConstRowIterator::operator>(const ConstRowIterator& rhs) const {
    return(row > rhs.row);
}

bool Matrix::ConstRowIterator::operator>=(const ConstRowIterator& rhs) const {
    return(row >= rhs.row);
}



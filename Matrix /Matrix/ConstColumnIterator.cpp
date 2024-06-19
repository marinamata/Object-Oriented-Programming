//
// Created by mfbut on 11/17/2019.
//

#include "ConstColumnIterator.h"
#include "Matrix.h"

Matrix::ConstColumnIterator::ConstColumnIterator(const Matrix* matrix, int col) {
    this->matrix = matrix;
   this->col = col;
}


Matrix::ConstColumnIterator::value_type Matrix::ConstColumnIterator::operator*() const {
    return const_cast<const Matrix*>(matrix)->colAt(col);
}

Matrix::ConstColumnIterator::value_type Matrix::ConstColumnIterator::operator[](int offset) const {
    return const_cast<const Matrix*>(matrix)->colAt(col + offset);
}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator++() {
    col++;
    return *this;

}

const Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator++(int) {
    ConstColumnIterator temp(*this);
    ++temp.col;
    return temp;

}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator--() {
    col--;
    return *this;

}

const Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator--(int) {
    ConstColumnIterator temp(*this);
    --temp.col;
    return temp;

}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator+=(int amount) {
    col += amount;
    return *this;

}

Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator+(int amount) const {
    ConstColumnIterator temp(*this);
    temp.col += amount;
    return temp;

}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator-=(int amount) {
    col-= amount;
    return *this;

}

Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator-(int amount) const {
    ConstColumnIterator temp(*this);
    temp.col -= amount;
    return temp;

}

Matrix::ConstColumnIterator::difference_type Matrix::ConstColumnIterator::operator-(const ConstColumnIterator& rhs) {
    return abs(col - rhs.col);
}

bool Matrix::ConstColumnIterator::operator==(const ConstColumnIterator& rhs) const {
    return(col==rhs.col && matrix ==rhs.matrix);
}

bool Matrix::ConstColumnIterator::operator!=(const ConstColumnIterator& rhs) const {
    return(col<rhs.col);
}

bool Matrix::ConstColumnIterator::operator<(const ConstColumnIterator& rhs) const {
    return(col<rhs.col);
}

bool Matrix::ConstColumnIterator::operator<=(const ConstColumnIterator& rhs) const {
    return(col<=rhs.col);
}

bool Matrix::ConstColumnIterator::operator>(const ConstColumnIterator& rhs) const {
    return(col>rhs.col);
}

bool Matrix::ConstColumnIterator::operator>=(const ConstColumnIterator& rhs) const {
    return(col>=rhs.col);
}


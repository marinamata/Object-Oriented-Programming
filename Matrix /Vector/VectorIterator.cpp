//
// Created by mfbut on 11/14/2019.
//

#include "VectorIterator.h"
#include "ConstColumnIterator.h"

Matrix::VectorIterator::VectorIterator(BaseVector* vector, int pos) {
     vec = vector;
     position = pos;
}

Matrix::VectorIterator::operator ConstVectorIterator() const {
    ConstVectorIterator temp(vec, position);
    return temp;

}

Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator*() {
    return vec->at(position);
}

const Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator*() const {
    return vec->at(position);
}

const Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator[](int offset) const {
    return vec->at(position+offset);
}

Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator[](int offset) {
    return vec->at(position+offset);
}

Matrix::VectorIterator& Matrix::VectorIterator::operator++() {
    ++position;
    return *this;
}

const Matrix::VectorIterator Matrix::VectorIterator::operator++(int) {
    //int a = position+1;
    VectorIterator temp(*this);
    ++(*this);
    return temp;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator--() {
    --position;
    return *this;
}

const Matrix::VectorIterator Matrix::VectorIterator::operator--(int) {
    VectorIterator temp(*this);
    --(*this);
    return temp;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator+=(int amount) {
    position+= amount;
    return *this;
}

Matrix::VectorIterator Matrix::VectorIterator::operator+(int amount) const {
    VectorIterator temp(*this);
    temp.position+=amount;
    return temp;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator-=(int amount) {
    position-= amount;
    return *this;
}

Matrix::VectorIterator Matrix::VectorIterator::operator-(int amount) const {
    VectorIterator temp(*this);
    temp.position-=amount;
    return temp;
}

Matrix::VectorIterator::difference_type Matrix::VectorIterator::operator-(const VectorIterator& rhs) {
    return abs(position - rhs.position);
}

bool Matrix::VectorIterator::operator==(const VectorIterator& rhs) const {
    return(this==&rhs);
    /*
    if (this->vec != rhs.vec){
        return false;
    }else{
        return (this->position == rhs.position);
    }*/

}

bool Matrix::VectorIterator::operator!=(const VectorIterator& rhs) const {
    //return (this != &rhs);
    return (position < rhs.position);
}


bool Matrix::VectorIterator::operator<(const VectorIterator& rhs) const {
    return(position<rhs.position);
    /*if (this->vec != rhs.vec){
        return false;
    }else{
        return (this->position < rhs.position);
    }*/

}

bool Matrix::VectorIterator::operator<=(const VectorIterator& rhs) const {
    return(position<=rhs.position);
    //return(*this==rhs||*this<rhs);
}

bool Matrix::VectorIterator::operator>(const VectorIterator& rhs) const {
    return(position>rhs.position);
    /*if (this->vec != rhs.vec){
        return false;
    }else{
        return (this->position > rhs.position);
    }*/
}

bool Matrix::VectorIterator::operator>=(const VectorIterator& rhs) const {
    return(position>=rhs.position);
   // return(*this==rhs||*this>rhs);
}







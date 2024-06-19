//
// Created by mfbut on 11/14/2019.
//

#include "ConstVectorIterator.h"
#include "BaseVector.h"

Matrix::ConstVectorIterator::ConstVectorIterator(const ConstBaseVector* vector, int pos){
    constBaseVec = vector;
    position = pos;
}

const Matrix::ConstVectorIterator::value_type& Matrix::ConstVectorIterator::operator*() const {
    return constBaseVec->at(position);
}

const Matrix::ConstVectorIterator::value_type& Matrix::ConstVectorIterator::operator[](int offset) const {
    return constBaseVec->at(position + offset);
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator++() {
    ++position;
    return *this ;
}

const Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator++(int) {
    ConstVectorIterator temp(*this);
    ++(*this);
    return temp;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator--() {
    --position;
    return *this;
}

const Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator--(int) {
    ConstVectorIterator temp(*this);
    --(*this);
    return temp;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator+=(int amount) {
    position += amount;
    return *this;
}

Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator+(int amount) const {
    ConstVectorIterator temp(*this);
    temp.position -= amount;
    return temp;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator-=(int amount) {
    position -= amount;
    return *this;
}

Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator-(int amount) const {
    ConstVectorIterator temp(*this);
    temp.position -= amount;
    return temp;
}

Matrix::ConstVectorIterator::difference_type Matrix::ConstVectorIterator::operator-(const ConstVectorIterator& rhs) {
    return abs(position - rhs.position);
}

bool Matrix::ConstVectorIterator::operator==(const ConstVectorIterator& rhs) const {
    return(this==&rhs);
    /*if (this->constBaseVec != rhs.constBaseVec){
        return false;
    }else{
        return (this->position == rhs.position);
    }*/
}

bool Matrix::ConstVectorIterator::operator!=(const ConstVectorIterator& rhs) const {
    //return (this != &rhs);
    return (position < rhs.position);
}

bool Matrix::ConstVectorIterator::operator<(const ConstVectorIterator& rhs) const {
    return (position < rhs.position);/*
    if (this->constBaseVec != rhs.constBaseVec){
        return false;
    }else{
        return (this->position < rhs.position);
    }*/
}

bool Matrix::ConstVectorIterator::operator<=(const ConstVectorIterator& rhs) const {
    return (position <= rhs.position);
    //return(*this==rhs||*this<rhs);
}

bool Matrix::ConstVectorIterator::operator>(const ConstVectorIterator& rhs) const {
    return (position > rhs.position);
    /*
    if (this->constBaseVec != rhs.constBaseVec){
        return false;
    }else{
        return (this->position > rhs.position);
    };*/
}

bool Matrix::ConstVectorIterator::operator>=(const ConstVectorIterator& rhs) const {
    return (position >= rhs.position);
    return(*this==rhs||*this>rhs);
}

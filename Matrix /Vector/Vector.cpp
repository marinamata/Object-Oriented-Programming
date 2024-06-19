
//
// Created by mfbut on 11/14/2019.
//

#include "Vector.h"
#include <iostream>

Matrix::Vector::Vector(const ConstBaseVector& orig) {
    //std::cout << "Matrix::Vector::Vector(const ConstBaseVector& orig)\n";
    for(int i = 0; i < orig.size(); i++)
    {
        tmp.push_back(orig[i]);
    }
}

Matrix::Vector::Vector(int numElements, const BaseVector::value_type& value): tmp(numElements,value) {
    /*for(int i = 0; i < numElements; i++)
    {
        tmp.push_back(value);
    }*/
}

Matrix::Vector::Vector(int numElements): tmp(numElements,0) {
    /*for(int i = 0; i < numElements; i++)
    {
        tmp.push_back(0);
    }*/
}

Matrix::Vector::Vector(const std::vector<value_type>& values) {

    for( int i = 0; i<(int)values.size(); i++)
    {
        //std::cout << values.size() << std::endl;
        tmp.push_back(values.at(i));
    }
}

Matrix::Vector::Vector() {
    tmp.push_back(0);
}

int Matrix::Vector::size() const {
    return tmp.size();
}

Matrix::BaseVector::value_type& Matrix::Vector::at(int index) {
    return tmp.at(index);
}

const Matrix::BaseVector::value_type& Matrix::Vector::at(int index) const {
    return tmp.at(index);
}

Matrix::BaseVector::value_type& Matrix::Vector::operator[](int index) {
    return tmp.at(index);
}

const Matrix::BaseVector::value_type& Matrix::Vector::operator[](int index) const {
    return tmp.at(index);
}

Matrix::Vector& Matrix::Vector::operator=(const ConstBaseVector& rhs) {
    for(int i=0;i < rhs.size();i++)  {
        tmp.at(i) = rhs.at(i);
    }
    return *this;
}
std::vector<int> Matrix::Vector::getVector(){
    return tmp;
}











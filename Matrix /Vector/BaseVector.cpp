//
// Created by mfbut on 11/14/2019.
//

#include <functional>
#include <algorithm>
#include "BaseVector.h"
#include "Vector.h"
#include "ConstVectorIterator.h"
#include "VectorIterator.h"
#include "Matrix.h"

Matrix::BaseVector::operator Matrix() const {
//we think nothing goes here because constructor is already default
//you need to initialize private variable in the .h file and set it up in this function
// first
/*Matrix m(1, this->size());
auto this_itr = this->begin();
int i = 0;
for(;this_itr != this->end();  ++this_itr){
    m[0][i] = *this_itr ;
    i++;
 }*/
std::vector<std::vector<int>> m;
for(int i =0;i<(int)m.size();i++){
    m[0][i]= this->at(i);
}

    return Matrix(m);
}

Matrix::VectorIterator Matrix::BaseVector::begin() {
    return VectorIterator(this,0);
}

Matrix::VectorIterator Matrix::BaseVector::end() {
    return VectorIterator(this, size());
}

Matrix::ConstVectorIterator Matrix::BaseVector::begin() const {
    return ConstVectorIterator(this,0);
}

Matrix::ConstVectorIterator Matrix::BaseVector::end() const {
    return ConstVectorIterator(this, size());
}

Matrix::ConstVectorIterator Matrix::BaseVector::cbegin() const {        //ask at office hrs
    return this->begin();
}

Matrix::ConstVectorIterator Matrix::BaseVector::cend() const {           //ask at office hrs
    return this->end();
}

Matrix::BaseVector& Matrix::BaseVector::operator+=(const ConstBaseVector& rhs) { //you are adding the rhs to the left hand side
    // Vector addition(*this);
    /*auto this_itr = this->begin();
    auto rhs_itr = rhs.begin();
    for(;this_itr != this->end() and rhs_itr != rhs.end(); ++this_itr, ++rhs_itr){
        *this_itr += *rhs_itr;
    }*/
    for(int i=0;i<rhs.size();i++){
        this->at(i)+=rhs.at(i);
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator-=(const ConstBaseVector& rhs) {
    /*
    auto this_itr = this->begin();
    auto rhs_itr = rhs.begin();
    for(;this_itr != this->end() and rhs_itr != rhs.end(); ++this_itr, ++rhs_itr){
        *this_itr -= *rhs_itr;
    }*/
    for(int i=0;i<rhs.size();i++){
        this->at(i)-=rhs.at(i);
    }
    return *this;

}


Matrix::BaseVector& Matrix::BaseVector::operator+=(const BaseVector::value_type& rhs) { //rhs is the integer
    for (int i = 0; i < this->size(); i++) {
        this->at(i) += rhs;
    }
    return *this;

}
Matrix::BaseVector& Matrix::BaseVector::operator-=(const BaseVector::value_type& rhs) {//rhs is the integer
    for(int i=0;i<this->size();i++){
        this->at(i)-=rhs;
    }
    return *this;

}


Matrix::BaseVector& Matrix::BaseVector::operator*=(const BaseVector::value_type& rhs) { //rhs is the integer
    for(int i=0;i<this->size();i++){
        this->at(i)*=rhs;
    }
    return *this;
}
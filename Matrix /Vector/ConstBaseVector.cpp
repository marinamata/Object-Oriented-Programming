//
// Created by mfbut on 11/17/2019.
//

#include <algorithm>
#include "Vector.h"
#include <vector>
#include "ConstBaseVector.h"

Matrix::ConstVectorIterator Matrix::ConstBaseVector::begin() const {
    return ConstVectorIterator(this,0);
}

Matrix::ConstVectorIterator Matrix::ConstBaseVector::end() const {
    return ConstVectorIterator(this, size());
}



Matrix::Vector Matrix::ConstBaseVector::operator-() const {
    Vector negated(*this);
    //option 1
    for(int i=0; i< negated.size();i++){
        negated.at(i) = -negated.at(i);
    };
    /*//option2
    for(auto itr = negated.begin(); itr != negated.end(); ++itr){
        *itr =-*itr;
    }
    //option3
    for(auto&value:negated){
        value = -value;
    }*/
    return negated;
}

Matrix::Vector Matrix::ConstBaseVector::operator+(const ConstBaseVector& rhs) { //made a new vector that was the sum of two vectors,
    if(size() != rhs.size()){
        throw std::logic_error("Vector's must be the same size to add");
    }
    Vector sum(*this);
    //option 1
    for(int i=0; i< sum.size();i++){
        sum.at(i) += rhs.at(i);
    }
    return sum;
}
/*
vector sum(*this);
auto sum_itr = sum.begin();
auto rhs_itr = rhs.begin();
for(;sum_itr !=sum.end() and rhs_itr !=rhs.end(); ++sum_itr, ++rhs_itr){
    *sum_itr += *rhs_itr;
}
return sum;
sum +=rhs;
return sum;
}*/

Matrix::Vector Matrix::ConstBaseVector::operator-(const ConstBaseVector& rhs) {
    if(size() != rhs.size()){
        throw std::logic_error("Vector's must be the same size to subtract");
    }
    Vector difference(*this);
    for(int i=0; i < difference.size(); i++)
    {
        difference.at(i) -= rhs.at(i);
    }
    // auto difference_itr = difference.begin();
    // auto rhs_itr = rhs.begin();
    // for(;difference_itr != difference.end() and rhs_itr != rhs.end(); ++difference_itr, ++rhs_itr){
    //     *difference_itr -= *rhs_itr;
    // }
    return difference;
}

Matrix::Vector Matrix::ConstBaseVector::operator*(const ConstBaseVector& rhs) const {
    if(size() != rhs.size()){
        throw std::logic_error("Vector's must be the same size to multiply");
    }
    Vector multiply(*this);
    std::vector<int> dot;
    int sum=0;
    for(int i=0; i < multiply.size(); i++)
    {
        sum+=multiply.at(i) * rhs.at(i);
    }
    dot.push_back(sum);
    return Vector(dot);

    // auto multiply_itr = multiply.begin();
    // auto rhs_itr = rhs.begin();
    // for(;multiply_itr != multiply.end() and rhs_itr != rhs.end(); ++multiply_itr, ++rhs_itr){
    //     *multiply_itr *= *rhs_itr;
    // }
    //return multiply;

}

Matrix::Vector Matrix::ConstBaseVector::operator+(const ConstBaseVector::value_type& rhs) const { //same thing except right hand side is the value , left is the vector
    Vector addition(*this); //addition is the vector and rhs is the number, * this is the instance of the vector
    for(int i=0; i < addition.size(); i++)
    {
        addition.at(i) += rhs;
    }
    return addition;
}

Matrix::Vector Matrix::ConstBaseVector::operator-(const ConstBaseVector::value_type& rhs) const {
    Vector subtraction(*this); //addition is the vector and rhs is the number, * this is the instance of the vector
    for(int i=0; i < subtraction.size(); i++)
    {
        subtraction.at(i) -= rhs;
    }

    return subtraction;

}

Matrix::Vector Matrix::ConstBaseVector::operator*(const ConstBaseVector::value_type& rhs) const {
    Vector mult(*this); //addition is the vector and rhs is the number, * this is the instance of the vector
    for(int i=0; i < mult.size(); i++)
    {
        mult.at(i) *= rhs;
    }

    return mult;

}
bool Matrix::ConstBaseVector::operator==(const ConstBaseVector& rhs) const {
    Vector a(*this);
    int count = 0;
    for(int i =0;i<a.size();i++){
        if(a.at(i) == rhs.at(i)){
            count++;
        }
    }
    if(count==a.size()){
        return true;
    }
    return false;
}

bool Matrix::ConstBaseVector::operator!=(const ConstBaseVector& rhs) const {
    Vector b(*this);
    int count = 0;
    for(int i =0;i<b.size();i++){
        if(b.at(i) == rhs.at(i)){
            count++;
        }
    }
    if(count!=b.size()){
        return true;
    }
    return false;

}

Matrix::Vector Matrix::operator+(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    //auto lhs_itr= lhs.begin();
    Vector addition(rhs); //const base vector and we want a regular vector so that we can change it, and add to it and stuff
    //we are making a new vector called addition, const means that you cant change the values
    for(int i=0; i < addition.size(); i++)
    {
        addition.at(i)= lhs+addition.at(i);
    }

    return addition;
}

Matrix::Vector Matrix::operator-(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) { //subtracting a scalar from a vector
    Vector subtract(rhs); //rhs because its the const vector
    for(int i=0; i < subtract.size(); i++)
    {
        subtract.at(i) = lhs-subtract.at(i);
    }


    return subtract;
}

Matrix::Vector Matrix::operator*(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) { //multiplying a scalr to vector
    Vector multiply(rhs);//rhs because its the const vector
    for(int i=0; i < multiply.size(); i++)
    {
        multiply.at(i) = lhs*multiply.at(i);
    }
    return multiply;
}

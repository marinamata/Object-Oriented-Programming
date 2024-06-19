//
// Created by mfbut on 11/14/2019.
//

#include <algorithm>
#include <functional>
#include<iostream>
#include "Matrix.h"

Matrix::Matrix::Matrix(int numRows, int numCols, const Matrix::Matrix::element_type& val){
 rows = numRows;
 cols = numCols;
 //vec1.resize(rows);
 vec.resize(rows);
//vector<vector<int>> vec(row, vector<int>(col, 0));   //writing it to zero
    for(int i = 0; i < (int)vec.size(); i++)
    {
            //vec[i][j] = val;
            vec[i].resize(cols, val);
    }
}




Matrix::Matrix::Matrix(int numRows, int numCols) {
    rows = numRows;
    cols = numCols;
    vec.resize(rows);
    //vector<vector<int>> vec(row, vector<int>(col, 0));   //writing it to zero
    for (int i = 0; i < rows; i++) {

        vec[i].resize(cols, 0);
        //vec.reserve(0);//this is a vector


    }
}

Matrix::Matrix::Matrix(const std::vector<std::vector<Matrix::Matrix::element_type>>& values){
    rows = values.size();
    cols = values[0].size();
    vec.resize(rows);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        //vec[i][j] = val;
        vec[i].resize(cols,values[i].size());
    }

    for(int i = 0; i < rows; i++)
    {
       // vec[i].resize(cols, values[i]);
        for(int j =0;j<(int)values[i].size();j++) {
            vec[i][j] = values[i][j];
        }
    }

}

Matrix::Matrix::Matrix(const std::vector<Vector>& values) {
//at and bracket function doesnt work

    rows = values.size();
    cols = values[0].size();
    vec.resize(rows);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        //vec[i][j] = val;
        vec[i].resize(cols,values[i].size());
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j =0;j<(int)values[i].size();j++) {
            vec[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix::Matrix(const std::vector<ConstVectorRef>& values) {
    rows = values.size();
    cols = values[0].size();
    vec.resize(rows);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        //vec[i][j] = val;
        vec[i].resize(cols,values[i].size());
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j =0;j<(int)values[i].size();j++) {
            vec[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix::Matrix(const std::vector<VectorRef>& values) {
    rows = values.size();
    cols = values[0].size();
    vec.resize(rows);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        //vec[i][j] = val;
        vec[i].resize(cols,values[i].size());
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j =0;j<(int)values[i].size();j++) {
            vec[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix Matrix::Matrix::ident(int dim) { //identity matrix
    int row = dim;
    int col = dim;
    std::vector<std::vector<int>> vec1(row, std::vector<int>(col, 0));
    vec1.resize(row);//writing it to zero
    for(int i = 0; i < row; i++)
    {
        vec1[i][i] = 1;
    }
    return Matrix(vec1);
}

int Matrix::Matrix::getNumRows() const {
    return rows;
}

int Matrix::Matrix::getNumCols() const {
    return cols;
}

Matrix::Matrix::element_type& Matrix::Matrix::at(int row, int col) {  //given row and column, get that value
    return vec[row][col];
}

const Matrix::Matrix::element_type& Matrix::Matrix::at(int row, int col) const {
    return vec[row][col];
}

Matrix::VectorRef Matrix::Matrix::rowAt(int row) { //namespace, class, constructor
    VectorRef vecRef(*this, row);
    return vecRef;
}

Matrix::ConstVectorRef Matrix::Matrix::rowAt(int row) const {
    ConstVectorRef vecRef(*this, row);
    return vecRef;
}

Matrix::VectorRef Matrix::Matrix::colAt(int col) {
    VectorRef vecRef(*this, col);
    return vecRef;
}

Matrix::ConstVectorRef Matrix::Matrix::colAt(int col) const {
    ConstVectorRef vecRef(*this, col);
    return vecRef;
}

Matrix::VectorRef Matrix::Matrix::operator[](int row) {
    VectorRef vecRef(*this, row);
    return vecRef;
}

Matrix::ConstVectorRef Matrix::Matrix::operator[](int row) const {
    ConstVectorRef vecRef(*this, row);
    return vecRef;
}

Matrix::Matrix::const_iterator Matrix::Matrix::begin() const {
    ConstRowIterator temp(this, 0);
    return temp;// maybe put const vector iterator
}

Matrix::Matrix::const_iterator Matrix::Matrix::end() const {
    ConstRowIterator temp(this, rows-1);
    return temp;
}

Matrix::Matrix::iterator Matrix::Matrix::begin() {
    RowIterator temp(this, 0);
    return temp;
}

Matrix::Matrix::iterator Matrix::Matrix::end() {
    RowIterator temp(this, rows-1);
    return temp;
}

Matrix::Matrix::const_row_iterator Matrix::Matrix::rowBegin() const {
    ConstRowIterator temp(this, 0);
    return temp;
}

Matrix::Matrix::const_row_iterator Matrix::Matrix::rowEnd() const {
    ; ConstRowIterator temp(this, rows-1);
    return temp;
}

Matrix::Matrix::row_iterator Matrix::Matrix::rowBegin() {
   RowIterator temp(this, 0);
    return temp;
}

Matrix::Matrix::row_iterator Matrix::Matrix::rowEnd() {
    RowIterator temp(this, rows-1);
    return temp;
}

Matrix::Matrix::const_column_iterator Matrix::Matrix::colBegin() const {
    ConstColumnIterator temp(this, 0);
    return temp;
}

Matrix::Matrix::const_column_iterator Matrix::Matrix::colEnd() const {
    ConstColumnIterator temp(this, cols-1);
    return temp;
}

Matrix::Matrix::column_iterator Matrix::Matrix::colBegin() {
    ColumnIterator temp(this, 0);
    return temp;
}

Matrix::Matrix::column_iterator Matrix::Matrix::colEnd() {
   ColumnIterator temp(this, cols-1);
    return temp;
}

Matrix::Matrix Matrix::Matrix::operator-() const{
   // std::vector<int> tmpVec;
    Matrix tmpMat(*this);

    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] = -tmpMat[i][j];
        }
    }
    return tmpMat;
}

Matrix::Matrix& Matrix::Matrix::operator+=(const Matrix& rhs) {
    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            this[i][j] += rhs[i][j];
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator+(const Matrix& rhs) {
    Matrix tmpMat(*this);

    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] += rhs[i][j];
        }
    }
    return tmpMat;

}

Matrix::Matrix& Matrix::Matrix::operator-=(const Matrix& rhs) {
    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            this[i][j] -= rhs[i][j];
        }
    }
    return *this;

}

Matrix::Matrix Matrix::Matrix::operator-(const Matrix& rhs) {
    Matrix tmpMat(*this);

    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] -= rhs[i][j];
        }
    }
    return tmpMat;

}

Matrix::Matrix& Matrix::Matrix::operator*=(const Matrix& rhs) {
    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            this[i][j] -= rhs[i][j];
        }
    }
    return *this;

}

Matrix::Matrix Matrix::Matrix::operator*(const Matrix& rhs) {
    if(this->getNumCols() != rhs.getNumRows())
    {
        throw std::logic_error("Matrices must be compatible to multiply");
    }

    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            auto tmp = this[i][j];
            for(int k = 0; k < this->getNumCols(); k++) {
                this[i][j] += this[i][k] * rhs[k][j];
            }
            this[i][j] -= tmp;
        }
    }
    return *this;
}

Matrix::Matrix& Matrix::Matrix::operator+=(const element_type& rhs) {

    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            this[i][j] += rhs;
        }
    }
    return *this;

}

Matrix::Matrix Matrix::Matrix::operator+(const element_type& rhs) const {
    Matrix tmpMat(*this);
    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] += rhs;
        }
    }
    return tmpMat;

}

Matrix::Matrix& Matrix::Matrix::operator-=(const element_type& rhs) {
    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            this[i][j] -= rhs;
        }
    }
    return *this;

}

Matrix::Matrix Matrix::Matrix::operator-(const element_type& rhs) const{
    Matrix tmpMat(*this);
    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] -= rhs;
        }
    }
    return tmpMat;

}

Matrix::Matrix& Matrix::Matrix::operator*=(const element_type& rhs) {
    for(int i = 0; i < this->getNumRows() ; i++)
    {
        for(int j = 0; j < this->getNumCols(); j++)
        {
            this[i][j] *= rhs;
        }
    }
    return *this;

}

Matrix::Matrix Matrix::Matrix::operator*(const element_type& rhs) const{
    Matrix tmpMat(*this);
    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] *= rhs;
        }
    }
    return tmpMat;

}


Matrix::Matrix Matrix::operator+(const Matrix::element_type& lhs, const Matrix& rhs) {
    Matrix tmpMat(rhs);
    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] += lhs;
        }
    }
    return tmpMat;

}

Matrix::Matrix Matrix::operator-(const Matrix::element_type& lhs, const Matrix& rhs) {
    Matrix tmpMat(rhs);
    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] -= lhs;
        }
    }
    return tmpMat;

}

Matrix::Matrix Matrix::operator*(const Matrix::element_type& lhs, const Matrix& rhs) {
    Matrix tmpMat(rhs);
    for(int i = 0; i < tmpMat.getNumRows() ; i++)
    {
        for(int j = 0; j < tmpMat.getNumCols(); j++)
        {
            tmpMat[i][j] *= lhs;
        }
    }
    return tmpMat;

}





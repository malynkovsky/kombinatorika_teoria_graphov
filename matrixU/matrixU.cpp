#include "matrixU.h"
#include <iostream>

MatrixU::MatrixU():pData_{nullptr}{}

MatrixU::MatrixU(const int& nRow, const int& nCol){
    if (nRow <= 0 & nCol <= 0)
        throw std::invalid_argument("Arguments must be positive numbers");
    nRow_ = nRow;
    nCol_ = nCol;
    pData_ = new int[nRow*nCol]{ 0 };
}

void MatrixU::copy(const MatrixU& rhs) {
    nRow_ = rhs.nRow_;
    nCol_ = rhs.nCol_;
    pData_ = new int[nRow_*nCol_];
    pData_ = rhs.pData_;
}

MatrixU::MatrixU(const MatrixU& a){
    copy(a);
}

MatrixU& MatrixU::operator+=(const MatrixU& rhs){
    if ((nRow_ != rhs.nRow_) || (nCol_ != rhs.nCol_))
        throw std::invalid_argument("Dimensions of 1 and 2 matrixU must be equal");
    for (int iRow(0); iRow < length(); iRow += 1)
        pData_[iRow] += rhs.pData_[iRow];
    return *this;
}

MatrixU& MatrixU::operator-=(const MatrixU& rhs){
    if ((nRow_ != rhs.nRow_) || (nCol_ != rhs.nCol_))
        throw std::invalid_argument("Dimensions of 1 and 2 matrixU must be equal");
    for (int iRow(0); iRow < length(); iRow += 1)
        pData_[iRow] -= rhs.pData_[iRow];
    return *this;
}

MatrixU& MatrixU::operator*=(const MatrixU& rhs){
    if (nRow_ != rhs.nCol_)
        throw std::invalid_argument("Row nuber of 1 matrixU must be equal to Col number of 2 matrixU");
    MatrixU k(*this);
    for (int iRow(0); iRow < nRow_; iRow += 1)
        for (int iCol(0); iCol < rhs.nCol_; iCol += 1)
            at(iRow,iCol) += k.at(iRow, iCol)*rhs.at(iCol, iRow);
    return *this;
}

MatrixU& MatrixU::operator*=(const int& rhs){
    for (int i(0); i < length(); i += 1)
        pData_[i] *= rhs;
    return *this;
}

MatrixU& MatrixU::operator=(const MatrixU& rhs){
    copy(rhs);
    return *this;
}

int& MatrixU::at(const ptrdiff_t& iRow, const ptrdiff_t& iCol){
    if ((iRow < 0 & iCol < 0) || (iRow >= nRow_ & iCol >= nCol_))
        throw std::invalid_argument("Index is out of range, be more accurate :) ");
    return pData_[nCol_*iRow + iCol];
}

const int& MatrixU::at(const ptrdiff_t& iRow, const ptrdiff_t& iCol) const{
    if ((iRow < 0 & iCol < 0) || (iRow >= nRow_ & iCol >= nCol_))
        throw std::invalid_argument("Index is out of range, be more accurate :) ");
    return pData_[nCol_*iRow + iCol];
}

int MatrixU::length() const{
    return nRow_*nCol_;
}

int MatrixU::Rows() const{
    return nRow_;
}

int MatrixU::Cols() const{
    return nCol_;
}

std::ostream& MatrixU::writeTo(std::ostream& ostrm) const{
    
    for (int iRow(0); iRow < nRow_; iRow += 1){
        for (int iCol(0); iCol < nCol_; iCol += 1){
            ostrm << "A[" << iRow << ", " << iCol << "] = " << pData_[(nCol_*iRow) + iCol] << "   ";
        }
        ostrm << "\n";
    }
    return ostrm;
}

MatrixU& operator+(const MatrixU& lhs, const MatrixU& rhs){
    MatrixU sum(lhs);
    return sum += rhs;
}

MatrixU& operator-(const MatrixU& lhs, const MatrixU& rhs){
    MatrixU minus(lhs);
    return minus -= rhs;
}

MatrixU& operator*(const MatrixU& lhs, const MatrixU& rhs){
    MatrixU multiply(lhs);
    return multiply *= rhs;
}

MatrixU& operator*(const int& lhs, const MatrixU& rhs){
    MatrixU send(rhs);
    send *= lhs;
    return send;
}

MatrixU& operator*(const MatrixU& lhs, const int& rhs){
    MatrixU send(lhs);
    send *= rhs;
    return send;
}

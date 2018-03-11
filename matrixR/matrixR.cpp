#include "matrixR.h"
#include <iostream>

MatrixR::MatrixR() :pData_{new int*[nRow_]} {
}

MatrixR::MatrixR(const int & nRow, const int & nCol){
    if (nRow < 0 || nCol < 0)
        throw std::invalid_argument("Size of matrix can't be a negative number!");
    nRow_ = nRow;
    nCol_ = nCol;
    pData_ = new int*[nRow_];
    for (ptrdiff_t i(0); i < nRow_; i += 1)
        pData_[i] = new int[nCol_];

}

MatrixR::MatrixR(const MatrixR & a){
    copy(a);
}

MatrixR & MatrixR::operator=(const MatrixR & rhs)
{
    copy(rhs);
    //????????
    return *this;
}

MatrixR::~MatrixR(){
    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        delete[] pData_[i];
    }
    delete[] pData_;
    pData_ = nullptr;
    nRow_ = 0;
    nCol_ = 0;
}

void MatrixR::copy(const MatrixR & rhs){
    nRow_ = rhs.nRow_;
    nCol_ = rhs.nCol_;
    pData_ = new int *[nRow_];
    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {
        pData_[iRow] = new int[nCol_];
        for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {
            pData_[iRow][iCol] = rhs.pData_[iRow][iCol];
        }
    }
}

int & MatrixR::at(const ptrdiff_t & iRow, const ptrdiff_t & iCol){
    if ((iRow < 0 & iCol < 0) || (iRow >= nRow_ & iCol >= nCol_)) {
        throw std::out_of_range("Index is out of range");
    }
    return pData_[iRow][iCol];
}

const int & MatrixR::at(const ptrdiff_t & iRow, const ptrdiff_t & iCol) const
{
    if ((iRow < 0 & iCol < 0) || (iRow >= nRow_ & iCol >= nCol_)) {
        throw std::out_of_range("Index is out of range");
    }
    return pData_[iRow][iCol];
}

int MatrixR::length() const
{
    return nRow_*nCol_;
}

int MatrixR::Rows() const
{
    return nRow_;
}

int MatrixR::Cols() const
{
    return nCol_;
}

std::ostream & MatrixR::writeTo(std::ostream & ostrm) const{
    for (int iRow(0); iRow < nRow_; iRow += 1) {
        for (int iCol(0); iCol < nCol_; iCol += 1) {
            ostrm << "A[" << iRow << ", " << iCol << "] = " << pData_[iRow][iCol] << "   ";
        }
        ostrm << "\n";
    }
    return ostrm;
}

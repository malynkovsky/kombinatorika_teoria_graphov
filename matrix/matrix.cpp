#include "matrix.h"
#include <iostream>
#include <cassert>//???????????????????????

MatrixR::MatrixR(const int & nRow, const int & nCol) 
    :nRow_(nRow),nCol_(nCol)
{
    if ((nRow <= 0) || (nCol <= 0))
        throw std::invalid_argument("Error:  size must be >= 0"); 
    /*pData_ = new int*[nRow];
    pData_[0] = new int[nRow*nCol];
    for (int i(0); i < nRow-1; i++) 
    {
        pData_[i + 1] = pData_[i] + nCol_;
    }*/
}

MatrixR::MatrixR(const MatrixR & a)
{
    copy(a, *this);
}

MatrixR::~MatrixR()
{
    delete[] pData_[0];
    delete[] pData_;
    pData_ = nullptr;
}

void MatrixR::copy(const MatrixR & a, MatrixR & b)
{
    //b.pData_ = new int*[a.nRow_];
    //b.pData_[0]= a.pData_[0];//???
    //for (int i(0); i < a.nRow_ - 1; i++)
    //{
    //    b.pData_[i + 1] = b.pData_[i] + nCol_;
    //}
}

MatrixR & MatrixR::operator=(const MatrixR & rhs)
{
    copy(rhs, *this);
    return *this;
}

int & MatrixR::at(const ptrdiff_t & iRow, const ptrdiff_t & iCol)
{
    if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw std::invalid_argument("Error: Wrong index(<0)"); }// <= >=?????
    return pData_[iRow][iCol];
}

const int & MatrixR::at(const ptrdiff_t & iRow, const ptrdiff_t & iCol) const
{
    if ((iRow < 0) || (iCol < 0)||(iRow >= nRow_) || (iCol >= nCol_)) { throw std::invalid_argument("Error: Wrong index(<0)"); }// <= >=?????
    return pData_[iRow][iCol];
}

int MatrixR::length() const
{
    return nRow_*nCol_;
}

std::ostream & MatrixR::writeTo(std::ostream & ostrm) const
{
    for (int iRow(0); iRow < nRow_; iRow += 1){
        for (int iCol(0); iRow < nCol_; iCol++){
            ostrm << "A[" << iRow << ", " << iCol << "] = " << pData_[iRow][iCol] <<"   ";
        }
    }
    return ostrm;
}

MatrixU::MatrixU(const int & nRow, const int & nCol)
    
{
    if (nRow <= 0 & nCol <= 0)
        throw std::invalid_argument("Arguments must be positive numbers");
    nRow_ = nRow; 
    nCol_ = nCol;
    pData_ = new int[nRow_*nCol_];
}

MatrixU::MatrixU(const MatrixU & a)
{
    copy(a, *this);
}

MatrixU::~MatrixU()
{
    delete[] pData_;
    pData_ = nullptr;
    nRow_ = 0;
    nCol_ = 0;
}

void MatrixU::copy(const MatrixU & a, MatrixU& b)
{
    b.pData_ = new int[a.length()];
    for (int i(0); i < b.length(); i++) {
        b.pData_[i] = a.pData_[i];
    }
}

MatrixU & MatrixU::operator=(const MatrixU & rhs)
{
    copy(rhs, *this);
    return *this;
}

int & MatrixU::at(const ptrdiff_t & iRow, const ptrdiff_t & iCol)
{
    if ((iRow < 0 & iCol <= 0) || (iRow > nRow_ & iCol <= nCol_))
        throw std::invalid_argument("Index is out of range, be more accurate :) ");
    return pData_[nCol_*iRow + iCol];
}

const int & MatrixU::at(const ptrdiff_t & iRow, const ptrdiff_t & iCol) const
{
    if ((iRow < 0 & iCol <= 0) || (iRow > nRow_ & iCol <= nCol_))
        throw std::invalid_argument("Index is out of range, be more accurate :) ");
    return pData_[nCol_*iRow + iCol];
}

int MatrixU::length() const
{
    return nRow_*nCol_;
}

std::ostream & MatrixU::writeTo(std::ostream & ostrm) const
{
    for (int iRow(0); iRow < nRow_; iRow++){
        for (int iCol(0); iRow < nCol_; iCol += 1){
            ostrm << "A[" << iRow << ", " << iCol << "] = " << pData_[nCol_*iRow+iCol] << "   ";
        }
    }
    ostrm << "\n";
    return ostrm;
}

#ifndef MATRIX_KOSHKA
#define MATRIX_KOSHKA
#include <iostream>

class MatrixU
{
public:
    MatrixU() = default;
    MatrixU(const int& nRow, const int& nCol);
    MatrixU(const MatrixU& a);
    ~MatrixU();
    MatrixU& operator+=(const MatrixU& rhs);
    MatrixU& operator-=(const MatrixU& rhs);
    MatrixU& operator*=(const MatrixU& rhs);
    void copy(const MatrixU& a, MatrixU& b);
    MatrixU& operator=(const MatrixU& rhs);
    int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol);
    const int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol) const;
    int length() const;
    int det() const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int* pData_{ nullptr };
};

MatrixU& operator+(const MatrixU& lhs, const MatrixU& rhs);
MatrixU& operator-(const MatrixU& lhs, const MatrixU& rhs);
MatrixU& operator*(const MatrixU& lhs, const MatrixU& rhs);

class MatrixR
{
public:
    MatrixR() = default;
    MatrixR(const int& nRow, const int& nCol);
    MatrixR(const MatrixR& a);
    ~MatrixR();
    MatrixR& operator+=(const MatrixR& rhs);
    MatrixR& operator-=(const MatrixR& rhs);
    MatrixR& operator*=(const MatrixR& rhs);
    void copy(const MatrixR& a,MatrixR& b);
    MatrixR& operator=(const MatrixR& rhs);
    int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol);
    const int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol) const;
    int length() const;
    int det() const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int** pData_{ nullptr };
};

MatrixR& operator+(const MatrixR& lhs, const MatrixR& rhs);
MatrixR& operator-(const MatrixR& lhs, const MatrixR& rhs);
MatrixR& operator*(const MatrixR& lhs, const MatrixR& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, MatrixR& b)
{
    return b.writeTo(ostrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, MatrixU& b)
{
    return b.writeTo(ostrm);
}

#endif

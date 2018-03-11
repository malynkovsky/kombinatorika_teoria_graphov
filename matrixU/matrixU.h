#ifndef MATRIX_KOSHKA
#define MATRIX_KOSHKA
#include <iosfwd>

class MatrixU
{
public:
    MatrixU();
    MatrixU(const int& nRow, const int& nCol);
    MatrixU(const MatrixU& a);
    MatrixU& operator=(const MatrixU& rhs);
    ~MatrixU() = default;
    bool operator==(const MatrixU &rhs);
    bool operator!=(const MatrixU &rhs);
    MatrixU& operator+=(const MatrixU& rhs);
    MatrixU& operator-=(const MatrixU& rhs);
    MatrixU& operator*=(const MatrixU& rhs);
    MatrixU& operator/=(const MatrixU& rhs);
    MatrixU& operator*=(const int& rhs);
    void copy(const MatrixU& rhs);
    int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol);
    const int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol) const;
    int length() const;
    int Rows() const;
    int Cols() const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int* pData_{ nullptr };
};

MatrixU& operator+(const MatrixU& lhs, const MatrixU& rhs);
MatrixU& operator-(const MatrixU& lhs, const MatrixU& rhs);
MatrixU& operator*(const MatrixU& lhs, const MatrixU& rhs);
MatrixU& operator*(const int& lhs, const MatrixU& rhs);
MatrixU& operator*(const MatrixU& lhs, const int& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, MatrixU& b)
{
    return b.writeTo(ostrm);
}

#endif

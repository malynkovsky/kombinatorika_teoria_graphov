#ifndef MATRIX_KOSHKA_R
#define MATRIX_KOSHKA_R
#include <iosfwd>

class MatrixR
{
public:
    MatrixR();
    MatrixR(const int& nRow, const int& nCol);
    MatrixR(const MatrixR& a);
    MatrixR& operator=(const MatrixR& rhs);
    ~MatrixR();
    bool operator==(const MatrixR &rhs);
    bool operator!=(const MatrixR &rhs);
    MatrixR& operator+=(const MatrixR& rhs);
    MatrixR& operator-=(const MatrixR& rhs);
    MatrixR& operator*=(const MatrixR& rhs);
    MatrixR& operator/=(const MatrixR& rhs);
    MatrixR& operator*=(const int& rhs);
    void copy(const MatrixR& rhs);
    int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol);
    const int& at(const ptrdiff_t& iRow, const ptrdiff_t& iCol) const;
    int length() const;
    int Rows() const;
    int Cols() const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int** pData_{ nullptr };
};

MatrixR& operator+(const MatrixR& lhs, const MatrixR& rhs);
MatrixR& operator-(const MatrixR& lhs, const MatrixR& rhs);
MatrixR& operator*(const MatrixR& lhs, const MatrixR& rhs);
MatrixR& operator*(const int& lhs, const MatrixR& rhs);
MatrixR& operator*(const MatrixR& lhs, const int& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, MatrixR& b){
    return b.writeTo(ostrm);
}

#endif

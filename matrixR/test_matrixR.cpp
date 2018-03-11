#include "matrixR.h"
#include <iostream>
//#include <cassert>

int main() {
    using namespace std;
    MatrixR first(3, 3);

    try {
        MatrixR cat(-1, -1);
    }
    catch (invalid_argument err) {
        cout << "Index must be positive number  :) " << endl;
    }

    try {
        first.at(4, 4);
    }
    catch (invalid_argument err) {
        cout << "Index is out of range  :(  " << endl;
    }

    first.at(1, 2) = 5;
    cout << first << endl;
    for (int iRow(0); iRow < first.Rows(); iRow += 1)
        for (int iCol(0); iCol < first.Cols(); iCol += 1)
            first.at(iRow, iCol) = iRow * 2 + 4 - iCol * 5;
    cout << endl;
    cout << first << endl;
    cout << endl;
    MatrixR second(3, 3);
    for (int iRow(0); iRow < first.Rows(); iRow += 1)
        for (int iCol(0); iCol < first.Cols(); iCol += 1)
            second.at(iRow, iCol) = iRow * 6 - 10 + iCol;
    cout << second << endl;
    cout << endl;
    MatrixR copyq(first);
    cout << copyq << endl;
    /*copyq += second;
    cout << copyq << endl;
    cout << endl;
    copyq -= second;
    cout << copyq << endl;
    cout << endl;
    copyq *= second;
    cout << copyq << endl;
    cout << endl;
    copyq *= 2;
    cout << copyq << endl;
    cout << endl;*/
    int t(0);
    cin >> t;
    return 0;
}
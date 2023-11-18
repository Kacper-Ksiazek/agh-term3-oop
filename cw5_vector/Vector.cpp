#include "Vector.h"

Vector::Vector(int nSize, int nInitValue) {
    createVec(nSize);

    for(int i =0;i<nSize;i++){
//        m_pCoords[i] = nInitValue;
    }
}

istream &operator>>(istream &is, Vector &v) {
    return is;
}

ostream &operator<<(ostream &os, const Vector &v) {
    os << '[';
    for(int i = 0; i < v.getDim(); i++){
        os << v.m_pCoord[i] << (i == v.getDim() - 1 ? "" : ", ");
    }
    os << ']';
}

Vector::~Vector() {
    delete[] m_pCoord;
}



#include "iostream"
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int nRows, int nCols, int initValue) {
    m_nRows = nRows;
    m_data = new Vector[nRows];

    for (int i = 0; i < nRows; i++)
        m_data[i] = Vector(nCols, initValue);
}

Matrix::Matrix(const Matrix &m) {
    m_nRows = 0;
    m_data = NULL;
    *this = m;
}

Matrix::~Matrix() {
    delete[] m_data;
}

Matrix &Matrix::operator=(const Matrix &m) {
    if (this->getRowNo() != m.getRowNo()) {
        if (m_data) delete[] m_data;
        m_data = new Vector[m.m_nRows];
    }

    m_nRows = m.m_nRows;

    for (int i = 0; i < m_nRows; i++)
        m_data[i] = m.m_data[i];

    return *this;
}

int Matrix::getRowNo() const {
    return m_nRows;
}

int Matrix::getColNo() const {
    return m_data[0].getDim();
}

istream &operator>>(istream &in, Matrix &m) {
    for (int i = 0; i < m.getRowNo(); i++)
        in >> m.m_data[i];

    return in;
}

ostream &operator<<(ostream &out, const Matrix &m) {
    for (int i = 0; i < m.getRowNo(); i++)
        out << m.m_data[i] << endl;

    return out;
}

Vector &Matrix::operator[](int ix) {
    return m_data[ix];
}

const Vector &Matrix::operator[](int ix) const {
    return m_data[ix];
}

bool operator==(const Matrix &m1, const Matrix &m2) {
    if (m1.getRowNo() != m2.getRowNo()) return false;

    for (int i = 0; i < m1.getRowNo(); i++)
        if (m1.m_data[i] != m2.m_data[i]) return false;

    return true;
}

bool operator!=(const Matrix &m1, const Matrix &m2) {
    return !(m1 == m2);
}

Matrix operator*(const Matrix &m1, const Matrix &m2) {
    if (m1.getColNo() != m2.getRowNo()) {
        cout << "Nie mozna pomnozyc macierzy" << endl;
        exit(1);
    }

    Matrix result(m1.getRowNo(), m2.getColNo());

    for (int i = 0; i < m1.getRowNo(); i++)
        for (int j = 0; j < m2.getColNo(); j++)
            for (int k = 0; k < m1.getColNo(); k++)
                result[i][j]+= m1[i][k] * m2[k][j];

    return result;
}

Vector operator*(const Matrix &m, const Vector &v) {
    if (m.getColNo() != v.getDim()) {
        cout << "Nie mozna pomnozyc macierzy przez wektor" << endl;
        exit(1);
    }

    Vector result(m.getRowNo());

    for (int i = 0; i < m.getRowNo(); i++)
        for (int j = 0; j < m.getColNo(); j++)
            result[i]+= m[i][j] * v[j];

    return result;
}




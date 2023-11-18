#pragma once

#include <iostream>
#include <memory>

using namespace std;

class Vector {
    // Constructor && Descructors
public:
    Vector(int nSize = 2, int nInitValue = 0);

    Vector(const Vector &v);

    virtual ~Vector();

public:


private:
    int m_nDim; // Wymiar wektora

    void createVec(int nDim);
    void copyVec(const Vector &v);
public:
    int getDim() const;
    double *getCoords() const;


    // Operatory:

    // Przypisanie
    Vector& operator = (const Vector &v); // v1 = v2

    // Wyjscie wejscie
    friend istream &operator>>(istream &is, Vector &v); // cin >>
    friend ostream &operator<<(ostream &os, const Vector &v); // cout <<

    // Dodawanie
    friend const Vector operator + (const Vector &v1, const Vector &v2); // v1 + v2
    friend const Vector operator + (const Vector &v, double x); // v + x
    friend const Vector operator + (double x, const Vector &v); // x + v
    Vector& operator += (const Vector &v); // v1 += v2
    Vector& operator += (double x); // v += x

    // Odejmowanie
    friend const Vector operator - (const Vector &v1, const Vector &v2); // v1 - v2
    friend const Vector operator - (const Vector &v, double x); // v - x
    friend const Vector operator - (double x, const Vector &v); // x - v
    Vector& operator -= (const Vector &v); // v1 -= v2
    Vector& operator -= (double x); // v -= x

    // Jednoargumentowe mnozenie
    friend const Vector operator - (const Vector &v); // -v

    // Mnozenie
    friend const Vector operator * (const Vector &v1, const Vector &v2); // v1 * v2
    friend const Vector operator * (const Vector &v, double x); // v * x

    // Skalarne mnozenie
    friend double operator * ( const Vector& v1, const Vector& v2 )

    // Indexowanie
    double& operator [] (int ix);
    const double& operator [] (int ix) const;

    // Porownanie
    friend bool operator == (const Vector &v1, const Vector &v2); // v1 == v2
    friend bool operator != (const Vector &v1, const Vector &v2); // v1 != v2

    // Rzutowanie
    operator double* () const;

private:
    double *m_pCoord; // Wspolrzedne wektora

};


inline int Vector::getDim() const {
    return m_nDim;
}


Vector::operator double *() const {
    return m_pCoord;
}

inline void Vector::createVec(int nDim){
    if( nDim< 2 ) {
        nDim = 0;
        cerr << "invalid vector size";
    }
    m_pCoord = new(nothrow) double [m_nDim = nDim];

    if( !m_pCoord){
        cerr<< "createVec: Allocation error";
    }
}

inline void Vector::copyVec(const Vector &v) {
    memcpy(m_pCoord, (double *)v, m_nDim * sizeof(double));
}

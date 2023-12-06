#pragma once
#include "Vector.h"

class Matrix {

private:
    // Ilosc wierszy i kolumn
    int m_nRows;
    // Tablica wektorow
    Vector* m_data;

public:
    // Konstruktor domyslny
    Matrix(int nRows=2, int nCols=2, int initValue=0);
    // Konstruktor kopiujacy
    Matrix(const Matrix& m);
    // Destruktor
    virtual ~Matrix();

    // Operator =
    Matrix& operator = ( const Matrix& m );

    // Gettery
    int getColNo() const;
    int getRowNo() const;

    // Operatory strumieniowe
    friend istream& operator >> ( istream& in, Matrix& m );
    friend ostream& operator << (ostream& out, const Matrix& m );

    // Operatory indexowania
    Vector& operator[]( int ix );
    const Vector& operator[]( int ix ) const;


    // Operator rzutowania na wskaznik do wektora
    operator Vector*() const {
        return m_data;
    }

    // Operatory logiczne
    friend bool operator == ( const Matrix& m1, const Matrix& m2 );
    friend bool operator != ( const Matrix& m1, const Matrix& m2 );

    // Mnozenie macierzy
    friend Matrix operator * ( const Matrix& m1, const Matrix& m2 );

    // Mnozenie macierzy przez wektor
    friend Vector operator * ( const Matrix& m, const Vector& v );
};



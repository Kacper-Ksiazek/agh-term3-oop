#pragma once

#include <iostream>
using namespace std;
#include <memory.h>

class Vector
{

    //construction/destruction
public:
    Vector( int nSize=2, int nInitVal=0 );
    Vector( const Vector& v );
    virtual ~Vector();

public:
    int getDim() const;

    //assignment
    Vector& operator = ( const Vector& v ); //v1=v

    //input/output
    friend istream& operator >> ( istream& in, Vector& v ); //cin>>v
    friend ostream& operator << ( ostream& out, const Vector& v ); //cout<<v

    //addition
    friend Vector operator + ( const Vector& v1, const Vector& v2 ); //v1+v2
    friend Vector operator + ( const Vector& v, double x ); //v1+x
    friend Vector operator + ( double x, const Vector& v ); //x+v1
    Vector& operator += ( const Vector& v ); //v1+=v2
    Vector& operator += ( double x ); //v+=x

    //substraction
    friend Vector operator - ( const Vector& v1, const Vector& v2 ); //v1-v2
    friend Vector operator - ( const Vector& v, double x ); //v1-x
    Vector& operator -= ( const Vector& v ); //v1-=v2
    Vector& operator -= ( double x ); //v-=x

    //unary minus
    friend Vector operator - ( const Vector& v ); //-v

    //multiplication
    friend Vector operator * ( const Vector& v, double x );//v*x
    friend Vector operator * ( double x, const Vector& v );//x*v

    Vector& operator *= ( double x ); //v*=x

    //scalar multiplication
    friend double operator * ( const Vector& v1, const Vector& v2 );

    //indexation
    double& operator[]( int ix ); //v[2]=3
    const double& operator[]( int ix ) const; //double x=v[1]

    //comparision
    friend bool operator == ( const Vector& v1, const Vector& v2 ); //v1==v2?
    friend bool operator != ( const Vector& v1, const Vector& v2 ); //v1!=v2?

    //cast
    operator double*() const; //double* p=(double*)v;

private:
    void createVec( int nDim );
    void copyVec( const Vector& v );

private:
    int m_nDim;     //rozmiar wektora
    double* m_pCoord;   //wspolrzedne wektora - dynamiczna tablica
};

//INLINE
inline int Vector::getDim() const {
    return m_nDim;
}
inline Vector::operator double*() const {
    return m_pCoord;
}
inline void Vector::createVec( int nDim ) {
    if ( nDim < 2 ) {
        nDim=2;
        cerr << "Invalid vector size\n";
    }
    m_pCoord = new( nothrow ) double [ m_nDim = nDim ];
    if( !m_pCoord )
        cerr << "createVec: Allocation error!\n";
}
inline void Vector::copyVec( const Vector& v ) {
    //for( int i=0; i<getDim(); i++ )
    //	m_pCoord[i] = v.m_pCoord[i];
    memcpy( m_pCoord, ( double* )v, getDim()*sizeof( double ) );
}
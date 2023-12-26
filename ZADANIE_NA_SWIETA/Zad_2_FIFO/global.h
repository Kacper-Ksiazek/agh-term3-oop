#pragma once

#include <iostream>

using namespace std;

// Stala preprocessora
#define FQINFO FQInfo

struct FQInfo {
    //
    int nKey;

    // Tablica dynamiczna p zawierajaca 2 inty
    int *p;

    // Konstruktor z parametrem
    inline FQInfo(int nKey, int a, int b){
        this->nKey = nKey;
        // Zaalokowanie pamieci na tablice 2 intow
        this->p = new (nothrow) int[2];
        // Przypisanie wartosci
        this->p[0] = a;
        this->p[1] = b;
    }

    // Wirtualny destructor
    virtual ~FQInfo() {
        delete[] p;
    }

    // Operator outstream
    friend ostream &operator<<(ostream &os, const FQInfo &info) {
        // Java lombok toString() notation
        os << "FQInfo( nKey: " << info.nKey << ", p: [" << info.p[0] << ", " << info.p[1] << "] )";
        return os;
    }
};
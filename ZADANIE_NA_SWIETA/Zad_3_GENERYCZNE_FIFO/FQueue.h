#pragma once

#include <iostream>
#include "FifoItem.h"
#include "FifoException.h"

using namespace std;

//
// Autorska funkcja obslugujaca wyjatki
//
static void handleFifoException(FifoException *exception) {
    cout << exception->getReason() << endl;
    exit(exception->errCode);
}
// ===================================

//
// Klasa reprezentujaca kolejke FIFO
//

template <typename T>
class FQueue {
    // Wlasciwosci
private:
    FifoItem<T> *m_pHead;
    FifoItem<T> *m_pTail;

    // Konstruktory i destruktory
public:
    // Konstruktor domyslny
    inline FQueue() {
        m_pHead = nullptr;
        m_pTail = nullptr;
    };

    // Konstruktor kopiujacy
    inline FQueue(FQueue &queue) {
        m_pHead = queue.m_pHead;
        m_pTail = queue.m_pTail;
    };

    // Destruktor
    inline virtual ~FQueue() = default;

    // Gettery i settery
public:
    inline FifoItem<T> *getHead() const {
        return this->m_pHead;
    }

    inline void setHead(FifoItem<T> *pHead) {
        this->m_pHead = pHead;
    }

    inline FifoItem<T> *getTail() const {
        return this->m_pTail;
    }

    inline void setTail(FifoItem<T> *pTail) {
        this->m_pTail = pTail;
    }

// Publiczne metody obslugi kolejki
public:
    inline bool FQEmpty() {
        return (this->getHead() == nullptr);
    }

    inline int FQEnqueue(T *pItem) {
        FifoItem<T> *pNew = new(nothrow) FifoItem(pItem);

        // Jesli nie udalo sie zaalokowac pamieci dla nowego elementu kolejki
        if (pNew == nullptr) handleFifoException(new FifoException(FIFO_ALLOCATION_ERROR));

        // Jesli kolejka jest pusta to ustawiamy glowe na nowy element
        if (this->FQEmpty()) {
            this->setHead(pNew);
        }
            // W przeciwnym wypadku ustawiamy wskaznik na nastepny element ostatniego elementu na nowy element
        else {
            this->getTail()->setNext(pNew);
        }

        // Dodajemy nowy element na koniec kolejki
        this->setTail(pNew);

        return 0;
    }

    inline T *FQDequeue() {
        // Jesli kolejka jest pusta to nie ma czego zdejmowac
        if (this->FQEmpty()) handleFifoException(new FifoException(FIFO_QUEUE_EMPTY));

        // Zapamietujemy wskaznik na glowe kolejki
        T *wynik = this->getHead()->getItem();

        // Kasujemy zdjety element z kolejki i zastepujemy go nastepnym elementem
        this->FQDel();

        // Zwracamy zdjety wartosc zdjetego elementu
        return wynik;
    }

    inline void FQClear() {
        // Jesli kolejka jest pusta to nie ma co czyscic
        if (this->FQEmpty()) return;

        // Dopoki kolejka nie jest pusta
        while (!this->FQEmpty()) {
            // Kasujemy elementy jak leci
            this->FQDel();
        }

    }

// Prywatne metody obslugi kolejki
private:
    // Metoda ktora kasuje pierwszy do odczytu element z kolejki
    inline void FQDel() {
        // Jesli kolejka jest pusta to nie ma co usuwac
        if (this->FQEmpty()) handleFifoException(new FifoException(FIFO_QUEUE_EMPTY));

        // Zapamietujemy wskaznik na glowe kolejki
        FifoItem<T> *pTemp = this->getHead();

        // Ustawiamy glowe kolejki na nastepny element
        this->setHead(this->getHead()->getNext());

        // Kasujemy zapamietany wczesniej element
        delete pTemp;

        // Sprawdzamy czy kolejka jest pusta i jesli tak to ustawiamy ogon na nullptr
        if (this->FQEmpty()) this->setTail(nullptr);
    }
};


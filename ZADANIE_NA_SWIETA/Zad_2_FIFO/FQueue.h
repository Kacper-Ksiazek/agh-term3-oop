#pragma once

#include "global.h"

#define FIFO_ALLOCATION_ERROR  0x01
#define FIFO_QUEUE_EMPTY 0x04
#define OTHER_ERROR      0x10

// ===================================
// Wcześniejsze deklaracje, zeby mozna bylo zadeklarowac przyjaciela
// 1.
class FifoException;

// 2.
class FQueue;

// 3.
class FifoItem;
// ===================================

//
// Klasa pomocnicza reprezentujaca element kolejki FIFO
//
class FifoItem {
// Przyjaciele
friend class FQueue;

// Wlasciwosci
private:
    FQINFO *m_pItem;
    FifoItem *m_pNext;

// Konstruktory i destruktory
private:
    // Konstruktor domyslny
    inline FifoItem(FQINFO *pItem = nullptr) : m_pItem(pItem), m_pNext(nullptr) {};

    // Konstruktor kopiujacy
    inline FifoItem(FifoItem &item) : m_pItem(item.m_pItem), m_pNext(item.m_pNext) {};

    // Destruktor
    inline virtual ~FifoItem() = default;

// Gettery i settery
private:
    inline FQINFO *getItem() const {
        return this->m_pItem;
    }

    inline void setItem(FQINFO *pItem) {
        this->m_pItem = pItem;
    }

    inline FifoItem *getNext() const {
        return this->m_pNext;
    }

    inline void setNext(FifoItem *pNext) {
        this->m_pNext = pNext;
    }
};
// ===================================

//
// Klasa do obslugi wyjatkow
//
class FifoException {
    // Wlasnosci
public:
    int errCode;

    // Konstruktor
public:
    inline FifoException(int iErrorCode = OTHER_ERROR) : errCode(iErrorCode) {};

    // Metody
public:
    // Metoda wyswietlajaca powod bledu i konczaca dzialanie programu
    inline char *getReason() const {
        // Bez tego rzutowania program mi sie nie kompilowal i CLION krzyczal:
        // ``` ISO C++11 does not allow conversion from string literal to 'char *' ```
        switch (this->errCode) {
            case FIFO_ALLOCATION_ERROR:
                return (char *) "ERROR: Nie udalo sie zaalokowac pamieci dla kolejki FIFO";

            case FIFO_QUEUE_EMPTY:
                return (char *) "ERROR: Kolejka FIFO jest pusta";

            default:
                return (char *) "ERROR: Nieznany blad";
        }
    }
};

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

class FQueue {
    // Wlasciwosci
private:
    FifoItem *m_pHead;
    FifoItem *m_pTail;

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
private:
    inline FifoItem *getHead() const {
        return this->m_pHead;
    }

    inline void setHead(FifoItem *pHead) {
        this->m_pHead = pHead;
    }

    inline FifoItem *getTail() const {
        return this->m_pTail;
    }

    inline void setTail(FifoItem *pTail) {
        this->m_pTail = pTail;
    }

// Publiczne metody obslugi kolejki
public:
    inline bool FQEmpty() {
        return (this->getHead() == nullptr);
    }

    inline int FQEnqueue(FQINFO *pItem) {
        FifoItem *pNew = new(nothrow) FifoItem(pItem);

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

    inline FQINFO *FQDequeue() {
        // Jesli kolejka jest pusta to nie ma czego zdejmowac
        if (this->FQEmpty()) handleFifoException(new FifoException(FIFO_QUEUE_EMPTY));

        // Zapamietujemy wskaznik na glowe kolejki
        FQINFO *wynik = this->getHead()->getItem();

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
        FifoItem *pTemp = this->getHead();

        // Ustawiamy glowe kolejki na nastepny element
        this->setHead(this->getHead()->getNext());

        // Kasujemy zapamietany wczesniej element
        delete pTemp;

        // Sprawdzamy czy kolejka jest pusta i jesli tak to ustawiamy ogon na nullptr
        if (this->FQEmpty()) this->setTail(nullptr);
    }

// Autorskie metody publiczne
public:
    void printQueue() const {
        cout << "Zawartosc kolejki: " << endl;
        FifoItem *item = this->getHead();

        int i = 0;
        while (item != nullptr) {
            cout << ++i << ". " << *item->getItem() << endl;
            item = item->getNext();
        }
    }
};


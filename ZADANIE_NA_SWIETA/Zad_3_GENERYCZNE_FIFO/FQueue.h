#pragma once

#include <iostream>

#define FIFO_ALLOCATION_ERROR  0x01
#define FIFO_QUEUE_EMPTY 0x04
#define OTHER_ERROR      0x10

// ===================================
// Wcześniejsze deklaracje, zeby mozna bylo zadeklarowac przyjaciela
// 1.
class FifoException;

// 2.
template<typename T>
class FQueue;

// 3.
template<typename T>
class FifoItem;
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
// Klasa pomocnicza reprezentujaca element kolejki FIFO
//
template<typename T>
class FifoItem {
// Przyjaciele
friend class FQueue<T>;

// Wlasciwosci
private:
    T *m_pItem;
    FifoItem<T> *m_pNext;

// Konstruktory i destruktory
private:
    // Konstruktor domyslny
    inline FifoItem(T *pItem = nullptr) : m_pItem(pItem), m_pNext(nullptr) {};

    // Konstruktor kopiujacy
    inline FifoItem(const FifoItem<T> &item) : m_pItem(item.m_pItem), m_pNext(item.m_pNext) {};

    // Destruktor
    inline virtual ~FifoItem() = default;

// Gettery i settery
private:
    inline T *getItem() const {
        return this->m_pItem;
    }

    inline void setItem(T *pItem) {
        this->m_pItem = pItem;
    }

    inline FifoItem<T> *getNext() const {
        return this->m_pNext;
    }

    inline void setNext(FifoItem<T> *pNext) {
        this->m_pNext = pNext;
    }
};

//
// Klasa reprezentujaca kolejke FIFO
//

template<typename T>
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
private:
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
    // Metoda ktora kasuje pierwszy do odczytu element z kolejki ( tylko 1 element )
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

// Autorskie metody publiczne
public:
    void printQueue(){
        cout << "Zawartosc kolejki: " << endl;
        FifoItem<T> *item = this->getHead();

        int i = 0;
        while (item != nullptr) {
            cout << ++i << ". " << *item->getItem() << endl;
            item = item->getNext();
        }
    }
};


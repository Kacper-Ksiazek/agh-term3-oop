#pragma once

//
// Klasa pomocnicza reprezentujaca element kolejki FIFO
//
template <typename T>
class FifoItem {

// Wlasciwosci
private:
    T *m_pItem;
    FifoItem<T> *m_pNext;

// Konstruktory i destruktory
public:
    // Konstruktor domyslny
    inline FifoItem(T *pItem = nullptr) : m_pItem(pItem), m_pNext(nullptr) {};

    // Konstruktor kopiujacy
    inline FifoItem(const FifoItem<T> &item) : m_pItem(item.m_pItem), m_pNext(item.m_pNext) {};

    // Destruktor
    inline virtual ~FifoItem() = default;

// Gettery i settery
public:
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

#pragma once

#include "global.h"

//
// Klasa pomocnicza reprezentujaca element kolejki FIFO
//
class FifoItem {

// Wlasciwosci
private:
    FQINFO *m_pItem;
    FifoItem *m_pNext;

// Konstruktory i destruktory
public:
    // Konstruktor domyslny
    inline FifoItem(FQINFO *pItem = nullptr) : m_pItem(pItem), m_pNext(nullptr) {};

    // Konstruktor kopiujacy
    inline FifoItem(FifoItem &item) : m_pItem(item.m_pItem), m_pNext(item.m_pNext) {};

    // Destruktor
    inline virtual ~FifoItem() = default;

// Gettery i settery
public:
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

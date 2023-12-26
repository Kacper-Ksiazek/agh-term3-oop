#pragma once

#include "global.h"
#include "FifoItem.h"
#include "FifoException.h"

class FQueue {
    // Wlasciwosci
private:
    FifoItem *m_pHead;
    FifoItem *m_pTail;

    // Konstruktory i destruktory
public:
    // Konstruktor domyslny
    inline FQueue() : m_pHead(nullptr), m_pTail(nullptr) {};

    // Konstruktor kopiujacy
    inline FQueue(FQueue &queue) : m_pHead(queue.m_pHead), m_pTail(queue.m_pTail) {}

    // Destruktor
    inline virtual ~FQueue() = default;

    // Gettery i settery
public:
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

    inline int FQEnqueue(FQINFO *pItem);

    inline FQINFO *FQDequeue();

    inline void FQClear();

// Prywatne metody obslugi kolejki
private:
    // Metoda ktora kasuje pierwszy do odczytu element z kolejki
    inline void FQDel();
};
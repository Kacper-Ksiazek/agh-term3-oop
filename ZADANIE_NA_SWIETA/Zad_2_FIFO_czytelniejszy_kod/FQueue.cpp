#include "FQueue.h"

//
// Autorska funkcja obslugujaca wyjatki
//
static void handleFifoException(FifoException *exception) {
    cout << exception->getReason() << endl;
    exit(exception->errCode);
}

int FQueue::FQEnqueue(FQInfo *pItem) {
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

FQINFO *FQueue::FQDequeue() {
    // Jesli kolejka jest pusta to nie ma czego zdejmowac
    if (this->FQEmpty()) handleFifoException(new FifoException(FIFO_QUEUE_EMPTY));

    // Zapamietujemy wskaznik na glowe kolejki
    FQINFO *wynik = this->getHead()->getItem();

    // Kasujemy zdjety element z kolejki i zastepujemy go nastepnym elementem
    this->FQDel();

    // Zwracamy zdjety wartosc zdjetego elementu
    return wynik;
}

void FQueue::FQClear() {
    // Jesli kolejka jest pusta to nie ma co czyscic
    if (this->FQEmpty()) return;

    // Dopoki kolejka nie jest pusta
    while (!this->FQEmpty()) {
        // Kasujemy elementy jak leci
        this->FQDel();
    }

}

void FQueue::FQDel() {
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


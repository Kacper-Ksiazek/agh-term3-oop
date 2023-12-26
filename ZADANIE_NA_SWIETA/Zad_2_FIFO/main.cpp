#include <iostream>

#include "global.h"
#include "FQueue.h"

using namespace std;

// ⚠️ WAZNA INFORMACJA ⚠️
// W pliku FQueue.h znajdują się zarówno DEKLARACJE jak i DEFINICJE metod WSZYSTKICH 3 klas.
// Ze wzgledu na wymog zadania polegajacy na utworzeniu 3 klas w jednym pliku, clion wariuje.

// Jako dodatek zalacze wersje projektu, w ktorym kod podzielony jest na 6 plikow: 3 klasy + 3 pliki naglowkowe

// WAZNA INFORMACJA

void printFQueue(FQueue *queue);
void printSeparator();


int main() {
    auto queue = new FQueue();

    queue->FQEnqueue(new FQINFO(1, 3, 4));
    queue->FQEnqueue(new FQINFO(2, 5, 6));
    queue->FQEnqueue(new FQINFO(3, 7, 8));
    queue->FQEnqueue(new FQINFO(4, 9, 10));

    printFQueue(queue);

    auto zdjetyElement = queue->FQDequeue();

    printSeparator();
    cout << "Zdjety element: " << *zdjetyElement << endl;

    printFQueue(queue);


    printSeparator();
    cout << "Wywolanie funkcji FQClear" << endl;
    queue->FQClear();

    printFQueue(queue);

    return 0;
}

void printFQueue(FQueue *queue) {
    cout << "Zawartosc kolejki: " << endl;
    FifoItem *item = queue->getHead();

    int i = 0;
    while (item != nullptr) {
        cout << ++i << ". " << *item->getItem() << endl;
        item = item->getNext();
    }
}
void printSeparator() {
    cout << endl << "============================" << endl;
}

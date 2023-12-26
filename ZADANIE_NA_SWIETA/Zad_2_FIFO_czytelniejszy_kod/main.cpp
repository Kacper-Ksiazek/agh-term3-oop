#include <iostream>

#include "FifoItem.h"
#include "global.h"
#include "FQueue.h"
#include "FifoException.h"

using namespace std;

// ⚠️ WAZNA INFORMACJA ⚠️
//
// Jest to ALTERNATYWNA wersja zadania z wykorzystaniem MOJEJ struktury plikow.
// Doslownie JEDYNA roznica to rozdzielenie ~200 linijek z pliku naglowkowego na lacznie 4 pliki.
//

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
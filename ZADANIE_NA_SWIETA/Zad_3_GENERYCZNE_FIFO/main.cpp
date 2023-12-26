#include <iostream>

#include "FQueue.h"

// Wlasne typy
#include "Person.h"


using namespace std;

// ⚠️ WAZNA INFORMACJA ⚠️
// W pliku FQueue.h znajdują się zarówno DEKLARACJE jak i DEFINICJE metod WSZYSTKICH 3 klas.
// Ze wzgledu na wymog zadania polegajacy na utworzeniu 3 klas w jednym pliku, clion wariuje i nie kompiluje biedak.

template<typename T>
void printFQueue(FQueue<T> *queue);

void printSeparator();


int main() {
    auto Kacper = new Person("Kacper", 21, true, Gender::Male);

    auto queue = new FQueue<Person>();

    queue->FQEnqueue(Kacper);
    queue->FQEnqueue(new Person("Bartek", 25, true, Gender::Male));
    queue->FQEnqueue(new Person("Antalya", 19, false, Gender::Female));
    queue->FQEnqueue(new Person("Ania", 30, true, Gender::Female));


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

template<typename T>
void printFQueue(FQueue<T> *queue) {
    cout << "Zawartosc kolejki: " << endl;
    FifoItem<T> *item = queue->getHead();

    int i = 0;
    while (item != nullptr) {
        cout << ++i << ". " << *item->getItem() << endl;
        item = item->getNext();
    }
}

void printSeparator() {
    cout << endl << "============================" << endl;
}

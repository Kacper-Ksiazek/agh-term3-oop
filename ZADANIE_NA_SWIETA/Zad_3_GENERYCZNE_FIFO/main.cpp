#include <iostream>

#include "FQueue.h"

// Wlasne typy
#include "Person.h"


using namespace std;

// ⚠️ WAZNA INFORMACJA ⚠️
// W pliku FQueue.h znajdują się zarówno DEKLARACJE jak i DEFINICJE metod WSZYSTKICH 3 klas.
// Ze wzgledu na wymog zadania polegajacy na utworzeniu 3 klas w jednym pliku, clion wariuje i nie kompiluje biedak.

void printSeparator();


int main() {
    auto Kacper = new Person("Kacper", 21, true, Gender::Male);

    auto queue = new FQueue<Person>();

    queue->FQEnqueue(Kacper);
    queue->FQEnqueue(new Person("Bartek", 25, true, Gender::Male));
    queue->FQEnqueue(new Person("Antalya", 19, false, Gender::Female));
    queue->FQEnqueue(new Person("Ania", 30, true, Gender::Female));


    queue->printQueue();

    auto zdjetyElement = queue->FQDequeue();

    printSeparator();
    cout << "Zdjety element: " << *zdjetyElement << endl;

    queue->printQueue();


    printSeparator();
    cout << "Wywolanie funkcji FQClear" << endl;
    queue->FQClear();

    queue->printQueue();

    return 0;
}

void printSeparator() {
    cout << endl << "============================" << endl;
}

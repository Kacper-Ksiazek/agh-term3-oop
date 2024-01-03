#include <iostream>

#include "global.h"
#include "FQueue.h"

using namespace std;

void printSeparator();


int main() {
    auto queue = new FQueue();

    queue->FQEnqueue(new FQINFO(1, 3, 4));
    queue->FQEnqueue(new FQINFO(2, 5, 6));
    queue->FQEnqueue(new FQINFO(3, 7, 8));
    queue->FQEnqueue(new FQINFO(4, 9, 10));

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

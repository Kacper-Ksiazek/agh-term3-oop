//
// ⚠️ WAZNE:
// Testy do czesci pierwszej- tej z SchoolGirl i SchoolBoy znajduja sie w pliku "part_1_main.txt"
//

#include <iostream>

#include "Admin.h"
#include "Teacher.h"


using namespace std;

#define WORKERS_COLLECTION_SIZE 9

void printWorkersCollection(Worker **workers);


int main() {
    Worker *workers[9] = {nullptr};

    workers[0] = new Teacher("Koper Adam", 45, 40000, 0, MATEMATYKA);
    workers[1] = new Teacher("Banan Karolina", 34, 4000, 6, NIEMIECKI);
    workers[2] = new Teacher("Kowalski Karol", 29, 3000, 1, POLSKI);
    workers[3] = new Teacher("Nowak Klaudia", 51, 9000, 23, ANGIELSKI, "3b");
    workers[4] = new Teacher("Wiadro Zbigniew", 60, 8000, 32, MATEMATYKA, "1c");
    workers[5] = new Teacher("Gruszka Anna", 35, 4000, 8, NIEMIECKI);
    workers[6] = new Admin("Ogorek Halina", 61, 6000, 26, STARSZY_SPECJALISTA);
    workers[7] = new Admin("Piotrowski Jan", 43, 4000, 15, SPECJALISTA);
    workers[8] = new Admin("Wasowski Henryk", 35, 3000, 5, MLODSZY_SPECJALISTA);

    printWorkersCollection(workers);

    return 0;
}

void printWorkersCollection(Worker **workers) {
    for (int i = 0; i < WORKERS_COLLECTION_SIZE; i++) {
        workers[i]->print();
        cout << endl << endl;
    }
}

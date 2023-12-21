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
    Worker *workersCollection[9] = {nullptr};

    workersCollection[0] = new Teacher(
            "Jan Kowalski",
            30,
            9000,
            30,
            POLSKI,
            "4Tic"
    );

    workersCollection[1] = new Teacher(
            "Piotr Wisniewski",
            35,
            2400,
            28,
            ANGIELSKI
    );

    workersCollection[2] = new Teacher(
            "Michal Lewandowski",
            40,
            10000,
            32,
            CHEMIA,
            "5D"
    );

    workersCollection[3] = new Admin(
            "Adam Kowalski",
            30,
            6500,
            30,
            MLODSZY_SPECJALISTA
    );

    workersCollection[4] = new Teacher(
            "Anna Nowak",
            28,
            8500,
            25,
            MATEMATYKA
    );

    workersCollection[5] = new Teacher(
            "Katarzyna Dabrowska",
            32,
            1400,
            27,
            FIZYKA,
            "1C"
    );

    workersCollection[6] = new Admin(
            "Adam Nowak",
            28,
            8500,
            25,
            SPECJALISTA
    );

    workersCollection[7] = new Admin(
            "Kacper Wisniewski",
            35,
            4700,
            28,
            STARSZY_SPECJALISTA
    );

    workersCollection[8] = new Teacher(
            "Magdalena Zajac",
            29,
            8700,
            26,
            INFORMATYKA
    );


    printWorkersCollection(workersCollection);

    return 0;
}

void printWorkersCollection(Worker **workers) {
    for (int i = 0; i < WORKERS_COLLECTION_SIZE; i++) {
        workers[i]->print();
        cout << endl << endl;
    }
}

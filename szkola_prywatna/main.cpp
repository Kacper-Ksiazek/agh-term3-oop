#include <iostream>

#include "SchoolBoy.h"
#include "SchoolGirl.h"

#include "Admin.h"
#include "Teacher.h"

#define MAXPUPIL 9 // 9 pupili w klasie (tablicy)

using namespace std;

void printPupils(Pupil **tab, int size);

void sortPupils(Pupil **tab, int size);

int main() {
//    Pupil *pupils[MAXPUPIL] = {nullptr};
//    Pupil *v = nullptr;
//
//    pupils[0] = v = new SchoolGirl("Jablko Anna", 12, "3A");
//
//    v->setNote(POLSKI, 4);
//    v->setNote(MATEMATYKA, 3);
//    v->setNote(FIZYKA, 3);
//    v->setNote(CHEMIA, 5);
//    v->setNote(INFORMATYKA, 5);
//    v->setNote(ANGIELSKI, 4);
//
////    sortPupils(pupils, 1);
//    printPupils(pupils, 1);

    Worker *ekipa[9] = {nullptr};

    Teacher *Maro = new Teacher(
            "Maro",
            30,
            9000,
            30,
            POLSKI
    );

    Maro->printFinancialSummary();


    return 0;
}

void printPupils(Pupil **tab, int size) {
    for (int i = 0; i < size; i++) {
        tab[i]->printPupil();
    }
}

void sortPupils(Pupil **tab, int size) {
    for (int i = 0; i < size; i++) {
        int j = i - 1;
        Pupil *v = tab[i];

        while (j > 0 && tab[j]->getName() < v->getName()) {
            tab[j + 1] = tab[j--];
        }

        tab[j + 1] = v;
    }
}

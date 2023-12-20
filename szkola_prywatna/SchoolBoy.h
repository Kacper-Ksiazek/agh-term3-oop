#pragma once

#include "Pupil.h"


class SchoolBoy : public Pupil {

// Konstruktor
public:
    SchoolBoy(string name, int age, string className) noexcept;

// Operatory
public:
    SchoolBoy &operator=(const SchoolBoy &schoolGirlToCopy) = default;

// Metody
public:
    void printOutfit() override;
};



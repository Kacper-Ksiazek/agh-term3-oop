#pragma once

#include "Pupil.h"

class SchoolGirl : public Pupil {

// Konstruktor
public:
    SchoolGirl(string name, int age, string className) noexcept;

// Operatory
public:
    SchoolGirl &operator=(const SchoolGirl &schoolGirlToCopy) = default;

// Metody
public:
    void printOutfit() override;
};



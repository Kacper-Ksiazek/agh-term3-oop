#pragma once

#include "Pupil.h"


class SchoolBoy : public Pupil {
public:
    SchoolBoy(string name, int age, string className, int average) : Pupil(name, age, className, average) {}

    virtual ~SchoolBoy() = default;

    SchoolBoy &operator=(const SchoolBoy &schoolGirlToCopy) = default;

    virtual void printOutfit() const override;
};



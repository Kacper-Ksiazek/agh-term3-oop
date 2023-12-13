#pragma once

#include "Pupil.h"

class SchoolGirl : public Pupil {
public:
    // Konstruktor
    explicit SchoolGirl(string name, int age, string className, int average) noexcept;

    virtual ~SchoolGirl() = default;

    SchoolGirl &operator=(const SchoolGirl &schoolGirlToCopy) = default;

    virtual void printOutfit() const override;
};



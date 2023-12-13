#pragma once

#include "Pupil.h"


class SchoolBoy : public Pupil {
public:
    explicit SchoolBoy(string name, int age, string className, int average) noexcept;

    virtual ~SchoolBoy() = default;

    SchoolBoy &operator=(const SchoolBoy &schoolGirlToCopy) = default;

    virtual void printOutfit() const override;
};



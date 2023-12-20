#pragma once

#include "Worker.h"

enum Role {
    MLODSZY_SPECJALISTA,
    SPECJALISTA,
    STARSZY_SPECJALISTA
};

class Admin : public Worker {
// Wlasciwosci
private:
    Role m_Role;
// Konsktruktor
public:
    Admin(string name,
          int age,
          double salary,
          int workExperienceInYears,
          Role role
    ) noexcept;

    string getRole() const;

    double computeTax() const override;

    double getGrossIncome() const override;
};



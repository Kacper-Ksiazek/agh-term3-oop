#pragma once

#include "Worker.h"

enum Role {
    MLODSZY_SPECJALISTA,
    SPECJALISTA,
    STARSZY_SPECJALISTA
};

class Admin : public Worker {
private:
    Role m_Role;

// Gettery
public:
    string getRole() const;

};



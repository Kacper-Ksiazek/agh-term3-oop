#include "Admin.h"

string Admin::getRole() const {
    switch (m_Role) {
        case MLODSZY_SPECJALISTA:
            return "mlodszy specjalista";
        case SPECJALISTA:
            return "specjalista";
        case STARSZY_SPECJALISTA:
            return "starszy specjalista";
    }
}

Admin::Admin(string name,
             int age,
             double salary,
             int workExperienceInYears,
             Role role) noexcept: Worker(name,
                                         age,
                                         salary,
                                         workExperienceInYears) {
    m_Role = role;
}

double Admin::computeSalary() const {
    return 0;
}

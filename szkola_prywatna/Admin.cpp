#include "Admin.h"


Admin::Admin(string name,
             int age,
             double salary,
             int workExperienceInYears,
             Role role) noexcept: Worker(std::move(name),
                                         age,
                                         salary,
                                         workExperienceInYears) {
    m_Role = role;
}

double Admin::getPIT() const {
    return Worker::computeTax(getSalary(),
                              OPERATION_COSTS,
                              TAX_FREE_ALLOWANCE,
                              INCOME_TAX_RATE);
}

double Admin::getGrossIncome() const {
    return getSalary();
}

string Admin::getJobPosition() const {
    switch (m_Role) {
        case MLODSZY_SPECJALISTA:
            return "mlodszy specjalista";
        case SPECJALISTA:
            return "specjalista";
        case STARSZY_SPECJALISTA:
            return "starszy specjalista";
    }
}

void Admin::setRole(Role role) {
    m_Role = role;
}

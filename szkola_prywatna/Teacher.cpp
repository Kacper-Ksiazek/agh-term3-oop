#include "Teacher.h"


Teacher::Teacher(string name,
                 int age,
                 double salary,
                 int workExperienceInYears,
                 Subject subject,
                 string className) noexcept: Worker(name,
                                                    age,
                                                    salary,
                                                    workExperienceInYears) {
    m_subject = subject;
    m_className = className;
}

bool Teacher::isClassTeacher() const {
    return m_className != EMPTY_CLASS_NAME;
}

double Teacher::computeTax() const {
    double gross = getSalary() + getBonusBasedOnExperience() + getBonusBasedOnBeingClassTeacher();
    double operationCosts = getSalary() * 0.8 * 0.5 + OPERATION_COSTS;

    return Worker::computeTax(gross,
                              operationCosts,
                              TAX_FREE_ALLOWANCE,
                              INCOME_TAX_RATE);

}

double Teacher::getBonusBasedOnExperience() const {
    int workExperienceInYears = getWorkExperienceInYears();

    if (workExperienceInYears < 5) return 0;
    else if (workExperienceInYears >= 20) return 0.2 * getSalary();
    else return getSalary() * workExperienceInYears / 100;
}

double Teacher::getBonusBasedOnBeingClassTeacher() const {
    return isClassTeacher() ? BONUS_FOR_BEING_CLASS_TEACHER : 0;
}

#include "Teacher.h"


Teacher::Teacher(string name,
                 int age,
                 double salary,
                 int workExperienceInYears,
                 Subject subject,
                 string className) noexcept: Worker(std::move(name),
                                                    age,
                                                    salary,
                                                    workExperienceInYears) {
    m_subject = subject;
    m_className = std::move(className);
}


bool Teacher::isClassTeacher() const {
    return m_className != EMPTY_CLASS_NAME;
}

double Teacher::getPIT() const {
    double gross = getGrossIncome();
    double operationCosts = gross * 0.8 * 0.5;

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

double Teacher::getGrossIncome() const {
    return getSalary() + getBonusBasedOnExperience() + getBonusBasedOnBeingClassTeacher();
}

string Teacher::getJobPosition() const {
    // Podstawowa informacja o nauczycielu zawiera informacje o przedmiocie, ktorego uczy
    string base = "Nauczyciel, przedmiot: " + this->getSubject();

    // Jesli jest wychowawca klasy, to dodajemy informacje o klasie, ktora wychowuje
    if (this->isClassTeacher()) {
        return base + ", wychowawca klasy: " + this->getClassName();
    }

    // Jesli nie jest wychowawca klasy, to zwracamy tylko podstawowa informacje
    return base;
}

string Teacher::getClassName() const {
    return this->m_className;
}

string Teacher::getSubject() const {
    switch (this->m_subject) {
        case POLSKI:
            return "polski";
        case MATEMATYKA:
            return "matematyka";
        case FIZYKA:
            return "fizyka";
        case CHEMIA:
            return "chemia";
        case INFORMATYKA:
            return "informatyka";
        case ANGIELSKI:
            return "angielski";
        case NIEMIECKI:
            return "niemiecki";
        default:
            return "przedmiot nieznany";
    }
}

void Teacher::setClassName(string className) {
    this->m_className = std::move(className);
}

void Teacher::setSubject(Subject subject) {
    this->m_subject = subject;
}

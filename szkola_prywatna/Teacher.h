#pragma once

#include "Pupil.h"
#include "Worker.h"

#define BONUS_FOR_BEING_CLASS_TEACHER 400.0
#define EMPTY_CLASS_NAME "NONE"

class Teacher : public Worker {
private:
    double m_baseSalary; // Pensja brutto bez jakiejkolwiek premii
    Subject m_subject;
    string m_className = EMPTY_CLASS_NAME; // Nazwa klasy, ktorej jest wychowaca
public:
    Teacher(string name,
            int age,
            double salary,
            int workExperienceInYears,
            Subject subject,
            string className = EMPTY_CLASS_NAME
    ) noexcept;

    bool isClassTeacher() const;

    double computeTax() const override;

    double getGrossIncome() const override;


private:
    double getBonusBasedOnExperience() const;

    double getBonusBasedOnBeingClassTeacher() const;
};



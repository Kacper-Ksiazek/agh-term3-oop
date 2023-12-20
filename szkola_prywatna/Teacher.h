#pragma once

#include "Pupil.h"
#include "Worker.h"

#define EMPTY_CLASS_NAME "NONE"

class Teacher : public Worker {
private:
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

    double computeSalary() const override;
};



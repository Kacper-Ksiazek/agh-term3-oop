#pragma once

#include "Pupil.h"
#include "Worker.h"

#define BONUS_FOR_BEING_CLASS_TEACHER 400.0
#define EMPTY_CLASS_NAME "NONE"

class Teacher : public Worker {

// Wlasciwosci
private:
    Subject m_subject;
    string m_className = EMPTY_CLASS_NAME; // Nazwa klasy, ktorej jest wychowaca

// Konstruktor
public:
    Teacher(string name,
            int age,
            double salary,
            int workExperienceInYears,
            Subject subject,
            string className = EMPTY_CLASS_NAME
    ) noexcept;

// Gettery
public:
    string getClassName() const;

    string getSubject() const;

// Settery
public:
    void setClassName(string className);

    void setSubject(Subject subject);

// Publiczne metody wlasne
public:
    bool isClassTeacher() const;

// Implementacja metod wirtualnych
public:
    double getPIT() const override;

    double getGrossIncome() const override;

    string getJobPosition() const override;


// Metody pomocnicze
private:
    double getBonusBasedOnExperience() const;

    double getBonusBasedOnBeingClassTeacher() const;
};



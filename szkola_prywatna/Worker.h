#pragma once

#include "Person.h"

class Worker : public Person {
private:
    double m_Salary;
    int m_workExperienceInYears;
// Konstruktor
public:
    Worker(string name, int age, double salary, int workExperienceInYears) noexcept;

// Destruktor
public:
    virtual ~Worker();

// Operatory
    Worker &operator=(const Worker &personToCopy) = default;

// Gettery
public:
    double getSalary() const;

    int getWorkExperienceInYears() const;

// Settery
public:
    void setSalary(double salary);

    void setWorkExperienceInYears(int workExperienceInYears);

// Metody wirutalne
public:
    virtual double computeSalary() const = 0;
};



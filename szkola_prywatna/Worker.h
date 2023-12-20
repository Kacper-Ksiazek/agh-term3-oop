#pragma once

#include "Person.h"

#define INCOME_TAX_RATE 0.18
#define TAX_FREE_ALLOWANCE 556.02
#define OPERATION_COSTS 111.25

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

// Metody
public:
    void printSalary();

// Metody statyczne
    static double computeTax(double grossSalary,
                             double operationCosts,
                             double taxFreeAllowance,
                             double incomeTaxRate);

// Metody wirutalne
public:
    virtual double computeTax() const = 0;
};



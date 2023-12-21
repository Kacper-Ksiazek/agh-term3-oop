#pragma once

#include "Person.h"

#define INCOME_TAX_RATE 0.18
#define TAX_FREE_ALLOWANCE 556.02
#define OPERATION_COSTS 111.25

class Worker : public Person {
private:
    double m_Salary; // Wynagrodzenie podstawowe brutto
    int m_workExperienceInYears;
// Konstruktor
public:
    Worker(string name, int age, double salary, int workExperienceInYears) noexcept;

// Destruktor
public:
    virtual ~Worker() = default;

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
    // Wyswietla informacje o pracowniku: imie + nazwisko, stanowisko
    void print() const;

    void printPersonalDetails() const;

    void printFinancialSummary() const;

// Metody statyczne
    static double computeTax(double grossSalary,
                             double operationCosts,
                             double taxFreeAllowance,
                             double incomeTaxRate);

    static double computeNetIncome(double grossSalary,
                                   double tax);

// Metody wirutalne
public:
    // Oblicza i zwraca Personal Income Tax
    virtual double getPIT() const = 0;

    // Oblicza i zwraca zarobki brutto z uwzglednieniem dodatkow takich jak premia za staz, premia za wychowawstwo itp.
    virtual double getGrossIncome() const = 0;

    // Zwraca dokladnie na jakim stanowisku pracuje dana osoba
    virtual string getJobPosition() const = 0;
};



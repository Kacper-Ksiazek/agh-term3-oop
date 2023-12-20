#include "Worker.h"

Worker::Worker(string name, int age, double salary, int workExperienceInYears) noexcept: Person(name, age), {
    m_Salary = salary;
    m_workExperienceInYears = workExperienceInYears;
}

double Worker::getSalary() const {
    return m_Salary;
}

int Worker::getWorkExperienceInYears() const {
    return m_workExperienceInYears;
}

void Worker::setSalary(double salary) {
    m_Salary = salary;
}

void Worker::setWorkExperienceInYears(int workExperienceInYears) {
    m_workExperienceInYears = workExperienceInYears;
}

double Worker::computeTax(double grossSalary,
                          double operationCosts,
                          double taxFreeAllowance,
                          double incomeTaxRate) {
    double tax = ( grossSalary - operationCosts) * incomeTaxRate - taxFreeAllowance;

    return tax > 0 ? tax : 0;
}

double Worker::computeNetIncome(double grossSalary, double tax) {
    return grossSalary - tax;
}

void Worker::printFinancialSummary() const {
    double gross = getGrossIncome();
    double tax = computeTax();
    double net = computeNetIncome(gross, tax);

    cout << "Pracownik: " << getName() << endl;
    cout << "----------" << endl;
    cout << "Kwota brutto: " << gross << endl;
    cout << "Kwota podatku: " << tax << endl;
    cout << "Kwota netto: " << net << endl;
}

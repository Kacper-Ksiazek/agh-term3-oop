#pragma once

#include "Person.h"

class Worker : public Person {
private:
    double m_Salary;
public:
    explicit Worker(string salary) noexcept;

    virtual ~Worker();

    Worker &operator=(const Worker &personToCopy) = default;

};



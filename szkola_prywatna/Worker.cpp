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

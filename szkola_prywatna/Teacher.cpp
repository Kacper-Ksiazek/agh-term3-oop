#include "Teacher.h"

Teacher::Teacher(string name,
                 int age,
                 double salary,
                 int workExperienceInYears,
                 Subject subject,
                 string className) noexcept: Worker(name,
                                                    age,
                                                    salary,
                                                    workExperienceInYears) {
    m_subject = subject;
    m_className = className;
}

bool Teacher::isClassTeacher() const {
    return m_className != EMPTY_CLASS_NAME;
}

double Teacher::computeSalary() const {
    //
    return 0;
}

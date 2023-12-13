#include "Pupil.h"
#include "string.h"


// Statyczne pola klasy
int Pupil::m_BaseID = 1000;

Pupil::Pupil(string name, int age, string className, int average) noexcept: Person(name, age) {
    m_className = className;
    m_Ave = average;
    m_ID = to_string(m_BaseID);
}

string Pupil::getID() const {
    return this->m_ID;
}

string Pupil::getClassName() const {
    return this->m_className;
}

double Pupil::getAve() const {
    return this->m_Ave;
}

void Pupil::setClassName(string className) {
    this->m_className = className;
}

void Pupil::setNote(Subject subject, double note) {
    this->m_Notes[subject] = note;
}


#include "Person.h"

Person::Person(string name, int age) {
    m_Name = name;
    m_Age = age;
}

int Person::getAge() const {
    return m_Age;
}

string Person::getName() const {
    return m_Name;
}

void Person::setAge(int age) {
    m_Age = age;
}

void Person::setName(string name) {
    m_Name = name;
}

void Person::setPerson(string name, int age) {
    m_Name = name;
    m_Age = age;
}
#pragma once

#include <iostream>

using namespace std;

class Person {
private:
    string m_Name;
    int m_Age;
public:
    // Konstruktor
    Person(string name, int age);

    virtual ~Person() = default;

    Person &operator=(const Person &personToCopy) = default;

    // Gettery
    int getAge() const;

    string getName() const;

    // Settery
    inline void setAge(int age);

    inline void setName(string name);

    inline void setPerson(string name, int age);

};



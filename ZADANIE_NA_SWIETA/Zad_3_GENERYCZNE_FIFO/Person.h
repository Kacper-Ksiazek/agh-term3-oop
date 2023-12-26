#pragma once

#include <iostream>

// Moja autorska struktura do testowania parametrow generycznych

// Definiujemy sobie enuma
enum Gender {
    Male, Female
};

// Override'ujemy operator << dla enuma
std::ostream &operator<<(std::ostream &os, const Gender &gender) {
    switch (gender) {
        case Gender::Male:
            os << "Male";
            break;

        case Gender::Female:
            os << "Gender";
            break;

        default:
            os << "Unknown";
            break;
    }
    return os;
}

struct Person {
    // Wlasnosci
    std::string name;
    int age;
    bool fromPoland;
    Gender gender;

    // Konstruktor domyslny
    inline Person(const std::string name,
                  const int age,
                  const bool fromPoland,
                  const Gender gender) {
        this->name = name;
        this->age = age;
        this->fromPoland = fromPoland;
        this->gender = gender;
    }

    // Wirtualny destructor
    virtual ~Person() = default;

    // Operator outstream
    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "Person( name: " << person.name <<
           ", age: " << person.age <<
           ", fromPoland: " << (person.fromPoland ? "YES" : "NO") <<
           ", gender: " << person.gender << " )";
        return os;
    }
};


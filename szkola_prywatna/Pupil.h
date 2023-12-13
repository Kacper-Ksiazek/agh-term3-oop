#pragma once

#include "Person.h"

enum Subject {
    POLSKI,
    MATEMATYKA,
    FIZYKA,
    CHEMIA,
    INFORMATYKA,
    ANGIELSKI,
    NIEMIECKI
};

#define SUBJECTS_COUNT 7

class Pupil : public Person {
private:
    string m_className;
    double m_Ave;

    static int m_BaseID;

    double m_Notes[SUBJECTS_COUNT];
protected:
    string m_ID;


public:
    // Konstruktor
    explicit Pupil(string name, int age, string className, int average) noexcept;

    virtual ~Pupil() = default;

    Person &operator=(const Person &personToCopy) = default;

    // Gettery
    inline string getID() const;

    inline string getClassName() const;

    inline double getAve() const;

    // Settery
    inline void setClassName(string className);

    inline void setNote(Subject subject, double note);

    inline void clearNotes();

    inline void calcAve();

    // Metody zwykle
    void printPupil();

    // Metody wirtualne
    virtual void printOutfit() const;
};



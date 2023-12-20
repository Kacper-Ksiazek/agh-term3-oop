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

protected:
    // Id osoby
    string m_ID;

private:
    // Baza do generowania ID
    static int m_BaseID;

    // Klasa do ktorej uczeszcza uczen
    string m_className;

    // Srednia ocen
    double m_Ave = 0;

    // Tablica ocen, w kolejnosci jak w enumie Subject
    double m_Notes[SUBJECTS_COUNT];


public:
    // Konstruktor
    Pupil(string name, int age, string className) noexcept;

    // Destruktor
    virtual ~Pupil();


// Gettery
public:
    inline string getID() const;

    inline string getClassName() const;

    inline double getAve() const;

// Settery
public:
    // Ustawia klase do ktorej uczeszcza uczen
    inline void setClassName(string className);

    // Ustawia ocene z konkretnego przedmiotu
    void setNote(Subject subject, double note);

// Metody zwyczajne
public:
    inline void clearNotes();

    inline double calcAve();

    void printPupil();

// Metody wirtualne
public:
    virtual void printOutfit() = 0;
};



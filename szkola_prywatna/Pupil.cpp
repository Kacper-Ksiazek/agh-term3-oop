#include "Pupil.h"
#include "string.h"


// Statyczne pola klasy
int Pupil::m_BaseID = 10000;

Pupil::Pupil(const string name, int age, const string className) noexcept
        : m_className(className),
          Person(name, age) {
    // Wywołanie tej metody odpowiada za zaalokowanie pamięci na tablicę ocen
    clearNotes();

    // Wygenerowanie podstawy id
    m_ID = to_string(m_BaseID++);
}

Pupil::~Pupil() {
    free(this->m_Notes);
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

void Pupil::setClassName(const string className) {
    this->m_className = className;
}

void Pupil::clearNotes() {
    memset(this->m_Notes, 0, sizeof(this->m_Notes));
}

double Pupil::calcAve() {

    double sum = 0;
    for (double m_Note: this->m_Notes) {
        sum += m_Note;
    }

    // Jeżeli suma ocen jest równa 0, to średnia też jest równa 0
    if (sum == 0) {
        this->m_Ave = 0;
        return 0; // Kończymy działanie funkcji
    }

    // Jeżeli suma ocen jest różna od 0, to średnia jest równa sumie ocen podzielonej przez ilość ocen
    this->m_Ave = sum / SUBJECTS_COUNT;

    return getAve();
}

void Pupil::printPupil() {
    cout << getID() << ' ' << getName() << ' ' << " (" << getClassName() << "),  " << getAge() << " lat" << endl;
    cout << "average=" << calcAve() << endl;
    cout << "outfit: ";
    printOutfit();
}

void Pupil::setNote(Subject subject, double note) {
    if (note < 2 || note > 5) {
        cout << "Ocena musi byc z przedzialu 1-6" << endl;
        exit(1);
    }
    if (subject < 0 || subject >= SUBJECTS_COUNT) {
        cout << "Nie ma takiego przedmiotu" << endl;
        exit(1);
    }

    this->m_Notes[subject] = note;

}


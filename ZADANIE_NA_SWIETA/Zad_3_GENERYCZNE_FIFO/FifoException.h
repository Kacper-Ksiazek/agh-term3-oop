#pragma once

#define FIFO_ALLOCATION_ERROR  0x01
#define FIFO_QUEUE_EMPTY 0x04
#define OTHER_ERROR      0x10

//
// Klasa do obslugi wyjatkow
//
class FifoException {
    // Wlasnosci
public:
    int errCode;

    // Konstruktor
public:
    inline FifoException(int iErrorCode = OTHER_ERROR) : errCode(iErrorCode) {};

    // Metody
public:
    // Metoda wyswietlajaca powod bledu i konczaca dzialanie programu
    inline char *getReason() const {
        // Bez tego rzutowania program mi sie nie kompilowal i CLION krzyczal:
        // ``` ISO C++11 does not allow conversion from string literal to 'char *' ```
        switch (this->errCode) {
            case FIFO_ALLOCATION_ERROR:
                return (char *) "ERROR: Nie udalo sie zaalokowac pamieci dla kolejki FIFO";

            case FIFO_QUEUE_EMPTY:
                return (char *) "ERROR: Kolejka FIFO jest pusta";

            default:
                return (char *) "ERROR: Nieznany blad";
        }
    }
};




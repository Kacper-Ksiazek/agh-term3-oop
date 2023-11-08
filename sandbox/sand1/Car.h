#pragma once

#include "Vehicle.h"

#include <iostream>
using namespace std;

class Car: public Vehicle {
private:
public:
    Car(FuelType fuelType, unsigned short maxSpeed, char producer[], short numberOfDoors, short numberOfSeats);

    short getNumberOfDoors() const;

    void setNumberOfDoors(short doors);

    short getNumberOfSeats() const;

    void setNumberOfSeats(short numberOfSeats);

    const char *getProducer() const;

private:
    char producer[100];
    short numberOfDoors;
    short numberOfSeats;
};


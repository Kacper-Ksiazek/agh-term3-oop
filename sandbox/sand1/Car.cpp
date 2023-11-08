#include "Car.h"
#include <string.h>

Car::Car(FuelType fuelType, unsigned short maxSpeed, char producer[], short numberOfDoors, short numberOfSeats) :
        Vehicle(fuelType, maxSpeed) {
    strcpy(this->producer, producer);
    this->numberOfDoors = numberOfDoors;
    this->numberOfSeats = numberOfSeats;
}


short Car::getNumberOfDoors() const {
    return numberOfDoors;
}

void Car::setNumberOfDoors(short doors) {
    numberOfDoors = doors;
}

short Car::getNumberOfSeats() const {
    return numberOfSeats;
}

void Car::setNumberOfSeats(short newNumberOfSeats) {
    numberOfSeats = newNumberOfSeats;
}

const char *Car::getProducer() const {
    return producer;
}


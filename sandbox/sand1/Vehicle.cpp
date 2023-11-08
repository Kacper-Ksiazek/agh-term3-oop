#include "Vehicle.h"

ostream &operator<<(ostream &os, const FuelType& fuelType){
    switch(fuelType){
        case Petrol:
            os << "Petrol";
            break;
        case Diesel:
            os << "Diesel";
            break;
        case LPG:
            os << "LPG";
            break;
        case Electric:
            os << "Electric";
            break;
        case Jet:
            os << "Jet";
            break;
    }

    return os;
}


void Vehicle::switchEngineOn() {
    engineIsRunning = true;
}

void Vehicle::switchEngineOff() {
    engineIsRunning = false;
}

void Vehicle::accelerate() {
    if (isEngineRunning() && currentSpeed < maxSpeed) {
        currentSpeed += 10;
    }
}

void Vehicle::decelerate() {
    if (isEngineRunning() && currentSpeed > 0) {
        currentSpeed -= 10;
    }
}

ostream &operator<<(ostream &os, const Vehicle &vehicle) {
    os << "Printing vehicle: " << endl;
    os << "- Fuel type: " << vehicle.getFuelType() << endl;
    os << "- Engine is running: " << vehicle.isEngineRunning() << endl;
    os << "- Max speed: " << vehicle.getMaxSpeed() << endl;

    return os;
}

FuelType Vehicle::getFuelType() const {
    return fuelType;
}

bool Vehicle::isEngineRunning() const {
    return engineIsRunning;
}

unsigned short Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

unsigned short Vehicle::getCurrentSpeed() const {
    return currentSpeed;
}

Vehicle::Vehicle(FuelType fuelType, unsigned short maxSpeed) {
    this->fuelType = fuelType;
    this->maxSpeed = maxSpeed;
}



#pragma once

#include <iostream>
using namespace std;

enum FuelType {
    Petrol,
    Diesel,
    LPG,
    Electric,
    Jet,
};

class Vehicle {
public:
    // Getters
    virtual FuelType getFuelType() const;
    virtual bool isEngineRunning() const;
    virtual unsigned short getMaxSpeed() const;
    virtual unsigned short getCurrentSpeed() const;

    // Methods
    virtual void switchEngineOn();
    virtual void switchEngineOff();
    virtual void accelerate();
    virtual void decelerate();

    Vehicle(FuelType fuelType, unsigned short maxSpeed);

protected:
    FuelType fuelType;
    bool engineIsRunning = false;
    unsigned short maxSpeed;
    unsigned short currentSpeed = 0;

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);

};


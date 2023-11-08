#include <iostream>

#include "Vehicle.h"
#include "Car.h"

using namespace std;

int main() {
    Vehicle vehicle = Vehicle(Petrol, 200);

    Car car = Car(Petrol, 200, "BMW", 5, 5);



    cout << vehicle;

    cout << car.getProducer();

    return 0;
}

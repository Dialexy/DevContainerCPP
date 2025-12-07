#include "Flight.h"
#include <iostream>
#include <stdexcept>

Flight::Flight(std::string flightNum, int capacity) {
    this->flightNum = flightNum;
    this->capacity = capacity;
}

Flight::Flight(const Flight &other) {
    this->flightNum = other.flightNum;
    this->capacity = other.capacity;
    this->passengers = other.passengers;
}

void Flight::addPassenger(const Passenger &passenger) {
    if (findPassenger(passenger.getPassportNum()) != nullptr) {
        throw std::invalid_argument("Passenger with passport number " + 
                                  passenger.getPassportNum() + 
                                  " is already on this flight.");
    }

    if (passengers.size() < capacity) {
        passengers.push_back(passenger);
    }
    else {
        throw std::invalid_argument("There are no more available seats.");
    }
}

void Flight::removePassenger(const std::string &passportNum) {
    for (auto it = passengers.begin(); it != passengers.end(); it++) {
        if (it->getPassportNum() == passportNum) {
            passengers.erase(it);
            return;
        }
    }
    throw std::invalid_argument("The passenger with passport number: " + passportNum + " cannot be found");
}

Passenger* Flight::findPassenger(const std::string &passportNum) {
    for (auto &passenger : passengers) {
        if (passenger.getPassportNum() == passportNum) {
            return &passenger;
        }
    }
    return nullptr;
}

void Flight::listPassengers() const {
    for (const auto &passenger : passengers) {
        std::cout << "Name: " << passenger.getName()
            << ", Passport number: " << passenger.getPassportNum()
            << ", Seat number: " << passenger.getSeatNum() << std::endl;
    }
}

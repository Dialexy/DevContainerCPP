#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "Passenger.h"

class Flight {
    private:
        std::string flightNum;
        int capacity;
        std::vector<Passenger> passengers;
    public:
        Flight(std::string flightNum, int capacity);
        Flight(const Flight &other);
        void addPassenger(const Passenger &passenger);
        void removePassenger(const std::string &passportNum);
        Passenger* findPassenger(const std::string &passportNum);
        void listPassengers() const;
};

#endif

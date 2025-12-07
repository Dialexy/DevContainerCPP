#include "Passenger.h"

Passenger::Passenger(std::string name, std::string passportNum, std::string seatNum) {
    this->name = name;
    this->passportNum = passportNum;
    this->seatNum = seatNum;
}

std::string Passenger::getName() const {
    return name;
}

std::string Passenger::getPassportNum() const {
    return passportNum;
}

std::string Passenger::getSeatNum() const {
    return seatNum;
}

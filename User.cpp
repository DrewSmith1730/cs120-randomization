//
// Created by Jack McGowan on 3/15/21.
//

#include <iostream>
#include <iomanip>
#include "User.h"

/* Constructors */
User::User() {
    name = "John Doe";
    idNum = 9500000;
    hidden = false;
    tracking = false;
}

User::User(string name) {
    this->name = name;
    idNum = 9500000;
    hidden = false;
    tracking = false;
}

User::User(string name, int idNum) {
    this->name = name;
    idNum < 9500000 || idNum > 9599999 ? this->idNum = 9500000 : this->idNum = idNum;
    hidden = false;
    tracking = false;
}

User::User(string name, int idNum, bool tracking) {
    this->name = name;
    idNum < 9500000 || idNum > 9599999 ? this->idNum = 9500000 : this->idNum = idNum;
    hidden = false;
    this->tracking = tracking;
}

/* Getters */
string User::getName() const {
    return name;
}

int User::getIdNum() const {
    return idNum;
}

bool User::getTracking() const {
    return tracking;
}

/* Setters */
void User::setName(string name) {
    this->name = name;
}

void User::setIdNum(int idNum) {
    this->idNum = idNum;
}

void User::setTracking(bool track) {
    this->tracking = track;
}

/* Makes the idNum either visible or not */
bool User::makePrivate() {
    bool passed = false;
    if (!hidden) {
        hidden = true;
        passed = true;
    }
    return passed;
}

bool User::makePublic() {
    bool passed = false;
    if (hidden) {
        hidden = false;
        passed = true;
    }
    return passed;
}

/* Overloaded output operator */
ostream& operator << (ostream& outs, const User& u) {
    outs << "| " <<std::left << std::setw(18) << u.name << " | ";
    outs << std::left << std::setw(7);

    if (u.hidden) {
        std::cout << "private" << " |";
    }
    else {
        std::cout << u.getIdNum() << " |";
    }
    return outs;
}

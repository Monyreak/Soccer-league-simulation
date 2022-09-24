//
//  Player.cpp
//  Project
//
//  Created by Kimtaiyo Mech on 11/25/19.
//  Copyright © 2019 MKT. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
#include <iomanip>

Player::Player() {
    name = ""; position = ""; age = 0; nationality = ""; salary = 0; key = 1;
}

Player::Player(std::string n, std::string pos, int a, std::string nat, int sal, int k) {
    name = n; position = pos; age = a; nationality = nat; salary = sal; key = k;
}

void Player::setName(std::string n) {
    name = n;
}
void Player::setPosition(std::string pos) {
    position = pos;
}
void Player::setAge(int a) {
    age = a;
}
void Player::setNationality(std::string nat) {
    nationality = nat;
}
void Player::setSalary(double sal) {
    salary = sal;
}
void Player::setKey(int k) {
    key = k;
}

std::string Player::getName() {
    return name;
}
std::string Player::getPosition() {
    return position;
}
int Player::getAge() {
    return age;
}
std::string Player::getNationality() {
    return nationality;
}
double Player::getSalary() {
    return salary;
}

int Player::getKey() {
    return key;
}

bool Player::operator == (Player& p) {
    switch (key) {
        case 1:
            return (name == p.getName());
            
        case 2:
            return (position == p.getPosition() && name == p.getName());
            
        case 3:
            return (age == p.getAge() && name == p.getName());
    }
    return false;
}

bool Player::operator != (Player& p) {
    return !(*this == p);
}

bool Player::operator > (Player& p){
    switch(key){
        case 1:
            return (this->name > p.name);
        case 2:
            return (this->position > p.position);
        case 3:
            return (this->age > p.age);
    }
    return false;
}

bool Player::operator < (Player& p){
    switch(key){
        case 1:
            return (this->name < p.name);
        case 2:
            return (this->position < p.position);
        case 3:
            return (this->age < p.age);
    }
    return false;
}

bool Player::operator >= (Player& p){
    switch(key){
        case 1:
            return (this->name > p.name || this->name == p.name);
        case 2:
            return (this->position > p.position || this->position == p.position);
        case 3:
            return (this->age > p.age || this->age == p.age);
    }
    return false;
}

bool Player::operator <= (Player& p){
    switch(key){
        case 1:
            return (this->name < p.name || this->name == p.name);
        case 2:
            return (this->position < p.position || this->position == p.position);
        case 3:
            return (this->age < p.age || this->age == p.age);
    }
    return false;
}

std::ostream &operator << (std::ostream &strm, Player &p) {
    strm << std::left << std::setw(25) << p.getName() << std::setw(13) << p.getPosition() << std::setw(5) << p.getAge() << std::setw(14) << p.getNationality() << "$" << p.getSalary() << " million";
    return strm;
}
std::istream &operator >> (std::istream &strm, Player &p) {
    std::string temp;
    int temp2;
    std::cout << "Name: ";
    getline(strm, temp);
    p.setName(temp);
    std::cout << "Position: ";
    strm >> temp;
    p.setPosition(temp);
    std::cout << "Age: ";
    strm >> temp2;
    p.setAge(temp2);
    std::cout << "Nationality: ";
    strm >> temp;
    p.setNationality(temp);
    std::cout << "Salary: ";
    strm >> temp2;
    p.setSalary(temp2);
    return strm;
}

void Player::operator = (Player &p) {
    name = p.getName();
    position = p.getPosition();
    age = p.getAge();
    nationality = p.getNationality();
    salary = p.getSalary();
    key = p.getKey();
}

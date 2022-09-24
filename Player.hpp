//
//  Player.hpp
//  Project
//
//  Created by Kimtaiyo Mech on 11/25/19.
//  Copyright © 2019 MKT. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    std::string position;
    int age;
    std::string nationality;
    double salary;
    int key;
public:
    Player();
    Player(std::string n, std::string pos, int a, std::string nat, int sal, int k);
    
    void setName(std::string n);
    void setPosition(std::string pos);
    void setAge(int a);
    void setNationality(std::string nat);
    void setSalary(double sal);
    void setKey(int k);
    
    std::string getName();
    std::string getPosition();
    int getAge();
    std::string getNationality();
    double getSalary();
    int getKey();
    
    
    void operator = (Player& p);
    
    bool operator == (Player& p);
    bool operator != (Player& p);
    bool operator > (Player& p);
    bool operator < (Player& p);
    bool operator >= (Player& p);
    bool operator <= (Player& p);
    
    friend std::ostream &operator << (std::ostream &, Player &p);
    friend std::istream &operator >> (std::istream &, Player &p);
};


#endif /* Player_hpp */

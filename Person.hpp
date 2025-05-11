#ifndef PERSON_HPP

#define PERSON_HPP
#include <iostream>
using namespace std;

struct Person{
        string name;
        string surname;
        int phoneNumber;
        string email;
        Person* next;
        Person(string n, string s, int p,string e){
            name = n;
            surname = s;
            phoneNumber = p;
            email = e ;
            next = nullptr;
        }
    };



#endif
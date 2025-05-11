#ifndef LISTMANAGER_HPP
#define LISTMANAGER_HPP
#include "Person.hpp"

void addPerson(Person*& head,string name,string surname,int phoneNumber,string email){
    Person* newPerson = new Person(name,surname,phoneNumber,email);
}

#endif




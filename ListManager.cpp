#include "Person.hpp"
#include <iostream>
#include "ListManager.hpp"
using namespace std;


void addPerson(Person*& head,string name,string surname,int phoneNumber,string email){
        Person* newPerson = new Person(name,surname,phoneNumber,email);
        newPerson ->next = head;
        head = newPerson;

}

void printList(Person* head){
    while(head->next != nullptr)
    {
    printf("Name: %s ,Surname: %s ,Phone-Number: %d ,Email: %s\n", head->name,head->surname,head->phoneNumber,head->email);
    head = head->next;
    }
}

void deletePerson(Person*& head, string name) {
    Person* prev = nullptr;
    Person* current = head;

    while (current != nullptr) {
        if (current->name == name) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return;  
        }
        prev = current;
        current = current->next;
    }
}

void clearList(Person*& head) {
    Person* current = head;
    while (current != nullptr) {
        Person* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

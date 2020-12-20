//
// Created by strukovsky on 13.12.2020.
//

#ifndef LAB7_NEW_PREPOD_H
#define LAB7_NEW_PREPOD_H


#include "Person.h"
#include <string>
#include <iostream>
using namespace std;



class Prepod {
    Person person;
    string subject;
public:
    Prepod(char *_surname, char *_name, char *_patronymic, char* _subject):
    person(_surname, _name, _patronymic), subject(_subject)
    {

    }
    Prepod();

    Prepod(const Prepod& other);

    Person& get_person();
    string get_subject() const;
    
    
    friend istream& operator>>(istream& i, Prepod& p);
    friend ostream& operator<<(ostream& o, Prepod& p);

    bool operator==(const Person& p)const;
    
    

    
};


#endif //LAB7_NEW_PREPOD_H

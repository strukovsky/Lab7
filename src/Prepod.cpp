//
// Created by strukovsky on 13.12.2020.
//

#include "../header/Prepod.h"

istream &operator>>(istream &i, Prepod &p) {
    i>>p.person;
    i>>p.subject;
    return i;
}

bool Prepod::operator==(const Person &p) const {
    return p.compare(person) == 0;
}

Prepod::Prepod() {
    person = Person("","","");
    subject = "";
}

ostream &operator<<(ostream &o, Prepod &p) {
    o<<p.person<<" "<<p.subject;
    return o;
}

Prepod::Prepod(const Prepod &other) {
    person = other.person;
    subject = other.subject;
}

Person& Prepod::get_person() {
    return person;
}

string Prepod::get_subject() const{
    return subject;
}

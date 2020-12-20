//
// Created by strukovsky on 13.12.2020.
//

#ifndef LAB7_NEW_DATABASE_H
#define LAB7_NEW_DATABASE_H


#include "Prepod.h"
#include <list>
#include <algorithm>

using namespace std;
class Database {
    list<Prepod>* data;
public:
    Database();

    void add_to_start(Prepod p)
    ;

    void add_to_end(Prepod p);

    bool is_empty(){return data->empty();}

    void remove_at(int index);

    void describe(ostream& o);


    void read(istream& i);

    Prepod* search(const Person& query);

    void sort();

    int size();
};


#endif //LAB7_NEW_DATABASE_H

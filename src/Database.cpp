//
// Created by strukovsky on 13.12.2020.
//

#include "../header/Database.h"
#include "../header/PrepodComparer.h"

Database::Database() {
    data = new list<Prepod>;
}

void Database::add_to_start(Prepod p) {
    data->push_back(p);
}

void Database::add_to_end(Prepod p) {
    data->push_front(p);
}

void Database::remove_at(int index) {
    if(index < 0 || index > data->size())
        cerr<<"Bad index\n";
    else
    {
        auto iter = data->begin();
        advance(iter, index);
        data->erase(iter);
    }
}

void Database::describe(ostream &o) {
    for(auto& q: *data)
    {
        o<<q;
        o<<"\n";
    }
}


Prepod* Database::search(const Person &query) {
    Prepod* result = nullptr;
    for(auto& q: *data)
    {
        if(query.compare(q.get_person()) == 0)
        {
            result = &q;
            break;
        }
    }
    return result;
}

void Database::sort() {
    data->sort(PrepodComparer());
}

void Database::read(istream &i) {
    int n;
    i>>n;
    for (int j = 0; j < n; ++j)
    {
        char surname[4096];
        i>>surname;
        char name[4096];
        i>>name;
        char patronymic[4096];
        i>>patronymic;
        char subject[4096];
        i>>subject;
        Prepod p(surname, name, patronymic, subject);
        data->push_back(p);
    }
}

int Database::size() {
    return data->size();
}

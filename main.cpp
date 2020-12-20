#include <iostream>
#include "header/Prepod.h"
#include "header/Database.h"
#include <fstream>

using namespace std;
Database b;
string filename = "db.txt";

int enter_integer()
{
    int i;
    cin>>i;
    if(cin.fail() || i < 0)
        throw exception();
    return i;
}

void add(bool to_end=false)
{
    cout<<"Enter amount of entries you want to add\n";
    int n = enter_integer();
    for (int i = 0; i < n; ++i) {
        cout<<"Enter data in following format:\nsurname name patronymic subject\n";
        Prepod p;
        cin>>p;
        if(to_end)
            b.add_to_end(p);
        else
        b.add_to_start(p);
    }
}

void remove()
{

    cout<<"Enter index to remove\n";
    int index = enter_integer();
    b.remove_at(index);

}

void search()
{
    cout<<"Enter query to search: surname name patronymic\n";
    Person p;
    cin>>p;
    auto *result = b.search(p);
    if(result == nullptr)
        cout<<"No entry found for your query\n";
    else cout<<*result;

}

void finish(){
    ofstream writer(filename, ios::out);
    writer<<b.size();
    b.describe(writer);
    writer.close();
}

int main() {



    ifstream reader(filename, ios::in);
    b.read(reader);
    reader.close();

    if(b.is_empty())
    {
        add();
    }
    b.describe(cout);

    int command = 0;
    bool execute = true;
    while(execute)
    {
        cout<<"Enter command number\n";
        cout<<"1 - add Prepods to begin of list\n";
        cout<<"3 - add Prepods to end of list\n";
        cout<<"3 - delete record by index\n";
        cout<<"4 - print table\n";
        cout<<"5 - sort\n";
        cout<<"6 - find by fio\n";
        cout<<"7 - quit\n";
        cin>>command;
        while(cin.fail() || command <= 0 || command > 8)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            cout<<"Failed on entering command! Try again.\n";
            cin>>command;
        }
        switch(command)
        {
            case 1:
                 add();
                break;
            case 2:
                add(true);
                break;
            case 3:
                remove();
                break;
            case 4:
                b.describe(cout);
                break;
            case 5:
                b.sort();
                break;
            case 6:
                search();
                break;
            case 7:
                finish();
                execute = false;
                break;

        }
    }


    return 0;
}

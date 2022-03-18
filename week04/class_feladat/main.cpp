#include "../../std_lib_facilities.h"

struct Person{
    Person(){};
    Person(string fn, string ln, int n) : f_name(fn), l_name(ln), age{n} {
        if(age < 0 || age > 150)    error("Invalid age!");
        for (auto i : f_name){
            if (!isalpha(i))    error("Invalid character!");
        }
        for (auto i : l_name){
            if (!isalpha(i))    error("Invalid character!");
        }
    }

    string get_f_name() const {return f_name;}
    string get_l_name() const {return l_name;}
    int get_age() const {return age;}

private:
    string f_name, l_name;
    int age;
};
istream& operator>>(istream& is, Person& p){
    string f_name, l_name;
    int age;

    is >> f_name >> l_name >> age;
    p = Person(f_name, l_name, age);
    return is;
}

ostream& operator<<(ostream& os, Person& p){
    return os << p.get_f_name() << " " << p.get_l_name() << " " << p.get_age() << endl;
}

vector<Person> emberek;

int main(){

    Person p {"Goofy", "", 63};
    cout << p << endl;

    cout << "Type persons first and last name and age."<< endl;
    cout << "To quit write \"Exit\" then a sting and a number!\n" << endl;

    for(Person p; cin >> p;){
        if(p.get_f_name() == "Exit")
            break;
        emberek.push_back(p);
    }

    cout << "\nResult:";

    for(auto i : emberek){
        cout << i;
    }

    return 0;
}
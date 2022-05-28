#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:

    string name;
    string surname;
    size_t age;

public:

    Person (string name, string surname, size_t age) {
        name = name;
        surname = surname;
        age = age;
    }

    Person () {
        name = "";
        surname = "";
        age = 0;
    }

    ~Person () {
        name = "";
        surname = "";
        age = 0;
    }

    string GetName () {
        return name;
    }

    string GetSurname () {
        return surname;
    }

    size_t GetAge () {
        return age;
    }

    bool operator>(const Person &a) {
        if ((this->name > a.name) && (this->surname > a.surname) && (this->age > a.age)) return true;
        else return false;
    }

    bool operator<(const Person &a) {
        if ((this->name < a.name) && (this->surname < a.surname) && (this->age < a.age)) return true;
        else return false;
    }

    bool operator==(const Person &a) {
        if ((this->name == a.name) && (this->surname == a.surname) && (this->age == a.age)) return true;
        else return false;
    }

    bool operator!=(const Person &a) {
        if ((this->name != a.name) && (this->surname != a.surname) && (this->age != a.age)) return true;
        else return false;
    }

    void operator=(const Person &a) {
        this->Resize(a.name, a.surname, a.age);
    }

    void Resize(string n_name, string n_surname, size_t n_age) {
        name = n_name;
        surname = n_surname;
        age = n_age;
    }

    void Random () {
        age = rand() % 100;
        name = StringRand();
        surname = StringRand();
    }

    void Print () {
        cout << "(" << name << " " << surname << " " << age << " years) ";
    }

    string StringRand() {
        char symbols[53]  = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char a[11] = {0};
        int random;
        int i;
        for (i = 0; i < 11; i++) {
        random = rand()%(52);
        a[i] = symbols[random];
    }
    a[10] = '\0';
    return a;
    }
};
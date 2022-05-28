#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

template <class T> class ComplexNum 
{
private:

    struct complex {
        T real;
        T imaginary;
    };

    complex item = {0, 0};

public:

    ComplexNum () {}

    ComplexNum (T real, T imaginary) {
        item.real = real;
        item.imaginary = imaginary;
    }

    ComplexNum (ComplexNum<T> &new_item) {
        item.real = new_item.item.real;
        item.imaginary = new_item.item.imaginary;
    }

    ~ComplexNum () {
        item.real = 0;
        item.imaginary = 0;
    }

    T GetReal () {
        return item.real;
    }

    T GetImag () {
        return item.imaginary;
    }

    ComplexNum<T> operator+(const ComplexNum<T> &item) {
        ComplexNum<T> tmp(this->item.real + item.item.real, this->item.imaginary + item.item.imaginary);
        return tmp;
    }

    ComplexNum<T> operator+(const T &item) {
        ComplexNum<T> tmp(this->item.real + item, this->item.imaginary);
        return tmp;
    }

    ComplexNum<T> operator-(const ComplexNum<T> &item) {
        ComplexNum<T> tmp(this->item.real - item.item.real, this->item.imaginary - item.item.imaginary);
        return tmp;
    }

    void operator=(const ComplexNum<T> &item) {
        Resize(item.item.real, item.item.imaginary);
    }

    bool operator==(const ComplexNum<T> &item) {
        if (((int)(item.item.real * 100) == (int)(this->item.real * 100)) && 
            ((int)(item.item.imaginary * 100) == (int)((this->item.imaginary) * 100))) {
            return true;
        } else {return false;}
    }

    bool operator>(const ComplexNum<T> &item) {
        if ((item.item.real < this->item.real) && (item.item.imaginary < this->item.imaginary)) {
            return true;
        } else {return false;}
    }

    bool operator<(const ComplexNum<T> &item) {
        if ((item.item.real > this->item.real) && (item.item.imaginary > this->item.imaginary)) {
            return true;
        } else {return false;}
    }

    bool operator!=(const ComplexNum<T> &item) {
        if (((int)(item.item.real * 100) != (int)(this->item.real * 100)) && 
            ((int)(100 * item.item.imaginary) != (int)(100 * (this->item.imaginary)))) {
            return true;
        } else {return false;}
    }

    ComplexNum<T> operator* (const ComplexNum<T> &item) {
        ComplexNum<T> tmp(this->item.real*item.item.real - this->item.imaginary*item.item.imaginary,
                this->item.real*item.item.imaginary + item.item.real*this->item.imaginary);
        return tmp;
    }

    ComplexNum<T> operator* (const T &scal) {
        ComplexNum<T> tmp((int)(this->item.real*scal), (int)(this->item.imaginary*scal));
        return tmp;
    }

    void Print () {
        if (item.imaginary == 0) {
            std::cout << item.real;
        }
        if (item.imaginary > 0) {
            std::cout << "(" << item.real << "+" << item.imaginary << "i)";
        } 
        if (item.imaginary < 0) {
            std::cout << "(" << item.real << item.imaginary << "i)";
        }
    }

    void Resize (T real, T imaginary) {
        item.real = real;
        item.imaginary = imaginary;
    }

    ComplexNum<T> SqrtComplex () {
        T modul = (T)(sqrt(item.real*item.real + item.imaginary*item.imaginary));
        T x = modul * (T)(cos(std::atan(item.imaginary / item.real)));
        T y = modul * (T)(sin(std::atan(item.imaginary / item.real)));
        ComplexNum<T> tmp(x, y);
    }

    void Random () {
        if (sizeof(T) == sizeof(int)) { 
            item.real = rand() % 1000;
            item.imaginary = rand() % 1000;
        } else {
            item.real = (double)(rand() % 10000) / 1000;
            item.imaginary = (double)(rand() % 10000) / 1000;
        }
    }

};
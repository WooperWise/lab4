#include <iostream>
#include <iomanip>
#include "Tree.hpp"
#include <string>

using namespace std;

template<class T> T Sum10 (T item) {
    return item + 10;
}

template<class T> T Mult10 (T item) {
    return item * 10;
}

template<class T> T Square (T item) {
    return item*item;
}

template<class T> T Sqrt (T item) {
    return (T)(sqrt(item));
}

template <class T> bool h (T item) {
    if (item > 5) return true;
    else return false;
}


int main() {
    //Function<int> *fun;
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 15};
    BinaryNode<int> a(items, 10);
    BinaryNode<int> b;

    a.where(h<int>, a.GetPtrRoot(), b);
    b.Print(RoLR);

}

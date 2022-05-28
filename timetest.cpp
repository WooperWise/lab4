#include "ComplexNumber.hpp"
#include "Tree.hpp"
#include <string>
#include "Person.hpp"
#include <ctime>

int Mult10 (int item) {return item * 10;}
bool Even (int item) {
    if ((item % 2) == 0) return true;
    else return false;
}

void add_time1(){
    BinaryNode<int> timetree;
    int start, end, diff;
    start = clock();

    for(int i = 0; i < 10000; i++){
        timetree.AddItem(rand() % 100);
    }

    end = clock();
    diff = (end - start) / 1000.0;
    cout << "The time of add on 10^4 ranges: " << diff << " s\n";
}

void add_time2 () {
    BinaryNode<int> timetree;
    int start, end, diff;
    start = clock();

    for(int i = 0; i < 1000000; i++){
        timetree.AddItem(rand() % 1000);
    }

    end = clock();
    diff = (end - start) / 1000.0;
    cout << "The time of add on 10^6 ranges: " << diff << " s\n";
}

void map_time1 () {
    BinaryNode<int> timetree, b;
    timetree.Random(10000);
    int start, end, diff;
    start = clock();

    timetree.map(Mult10, timetree.GetPtrRoot(), b);

    end = clock();
    diff = (end - start) / 1000.0;
    
    cout << "The time of map on 10^4 ranges: " << diff << " s\n";
}

void map_time2 (){
    int start, end, diff;
    BinaryNode<int> timetree, b;
    timetree.Random(1000000);
    start = clock();

    timetree.map(Mult10, timetree.GetPtrRoot(), b);

    end = clock();
    diff = (end - start) / 1000.0;
    
    cout << "The time of map on 10^6 ranges: " << diff << " s\n";
}

void where_time1 () {
    BinaryNode<int> timetree, b;
    timetree.Random(10000);
    int start, end, diff;
    start = clock();

    timetree.where(Even, timetree.GetPtrRoot(), b);

    end = clock();
    diff = (end - start) / 1000.0;
    
    cout << "The time of where on 10^4 ranges: " << diff << " s\n";
}

void where_time2 () {
    BinaryNode<int> timetree, b;
    timetree.Random(1000000);
    int start, end, diff;
    start = clock();

    timetree.where(Even, timetree.GetPtrRoot(), b);

    end = clock();
    diff = (end - start) / 1000.0;
    
    cout << "The time of where on 10^6 ranges: " << diff << " s\n";
}

void merge_time1 () {
    BinaryNode<int> timetree, b;
    timetree.Random(10000);
    b.Random(10000);
    int start, end, diff;
    start = clock();

    timetree.Merge(b.GetPtrRoot());

    end = clock();
    diff = (end - start) / 1000.0;
    
    cout << "The time of merge on 10^4 ranges: " << diff << " s\n";

}

void merge_time2 () {
    BinaryNode<int> timetree, b;
    timetree.Random(1000000);
    b.Random(1000000);
    int start, end, diff;
    start = clock();

    timetree.Merge(b.GetPtrRoot());

    end = clock();
    diff = (end - start) / 1000.0;
    
    cout << "The time of merge on 10^6 ranges: " << diff << " s\n";

}

int main () {
    add_time1();
    add_time2();
    map_time1();
    map_time2();
    where_time1();
    where_time2();
    merge_time1();
    merge_time2();

    return 0;
}

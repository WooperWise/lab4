#include <cstddef>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

#include "ComplexNumber.hpp"
#include "Person.hpp"
#include "Tree.hpp"
#include "Print.hpp"

using namespace std;

template<class T> T Sum10 (T item) {return item + 10;}
template<class T> T Mult10 (T item) {return item * 10;}
template<class T> T Square (T item) {return item*item;}
template<class T> T Sqrt (T item) {return (T)(sqrt(item));}

template <class T> bool Even (T item) {
    if (((int)(item*100) % 2) == 0) return true;
    else return false;
}
template <class T> bool Del5 (T item) {
    if (((int)(item*100) % 5) == 0) return true;
    else return false;
}
template <class T> bool Del3 (T item) {
    if (((int)(item*100) % 3) == 0) return true;
    else return false;
}
template <class T> bool Odd (T item) {
    if (((int)(item*100) % 2) != 0) return true;
    else return false;
}


string SumHello (string item) {return (item += "Hello");}
string Char (string item) {
    item.resize(1);
    return item;
    }

bool CharA (string item) {
    if (item.find("a") != string::npos) return true;
    else return false;
}
bool CharABC (string item) {
    if (item.find("abc") != string::npos) return true;
    else return false;
}


Person NamePiter (Person item) {
    item.Resize("Piter", item.GetSurname(), item.GetAge());
    return item;
}
Person SurnameParker (Person item) {
    item.Resize(item.GetName(), "Parker", item.GetAge());
    return item;
}

Person Age69 (Person item) {
    item.Resize(item.GetName(), item.GetSurname(), 69);
    return item;
}


int main() {
    srand(time(NULL));

    Print print;
    int exit[2] = {1, 1};
    char command[3] = {0, 0, 0};
    char flag = 0;

    print.Hello();

    while (exit[0]) {
        print.Choose(); cin >> command[0];

        switch (command[0]) {
        case '1': {
            print.Enter(); cin >> flag;
            int* items; size_t count; int item = 0;
            BinaryNode<int> tree; 
            
            if (flag == 'Y') {
                print.Count(); cin >> count; print.Items();
                items = new int[count];
                for (int i = 0; i < count; i++) {
                    cin >> items[i];
                    tree.AddItem(items[i]);
                }
                delete [] items;
            } else {
                print.Count(); cin >> count;
                tree.Random(count);
                print.Good();
            }

            exit[1] = 1;
            while(exit[1]) {
                print.Info(); cin >> command[1];

                switch (command[1]) {
                case 'i': {
                    print.Menue();
                    break;
                } case '1': {
                    print.Item(); cin >> item;
                    tree.AddItem(item);
                    break;
                } case '2': {
                    print.Find(); cin >> item;
                    if (tree.FindItem(item, tree.GetPtrRoot())) print.Good();
                    else print.NotFind();
                    break;
                } case '3': {
                    tree.DeleteTree(); print.Good();
                    break;
                } case '4': {
                    print.Order(); cin >> command[2];

                    switch (command[2]) {
                    case '1': {
                        tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.Print(RoRL);
                        break;
                    } case '3': {
                        tree.Print(LRRo);
                        break;
                    } case '4': {
                        tree.Print(LRoR);
                        break;
                    } case '5': {
                        tree.Print(RLRo);
                        break;
                    } case '6': {
                        tree.Print(RRoL);
                        break;
                    }}
                    break;
                } case '5': {
                    print.Count(); cin >> count; print.Items();
                    items = new int[count];
                    tree.DeleteTree();
                    for (int i = 0; i < count; i++) {
                        cin >> items[i];
                        tree.AddItem(items[i]);
                    }
                    print.Good();
                    delete [] items;
                    break;
                } case '0': {
                    print.Count(); cin >> count;
                    tree.Random(count);
                    print.Good();
                    break;
                } case '6': {
                    print.Item(); cin >> item;
                    BinaryNode<int> sub_tree(tree.GetSubTree(item, tree.GetPtrRoot()));
                    if ((*sub_tree.GetPtrRoot()) != nullptr) sub_tree.Print(RoLR);
                    else print.NotFind();
                    break;
                } case '8': {
                    print.MapNum(); cin >> command[2];
                    BinaryNode<int> map_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.map(Sum10<int>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.map(Mult10<int>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '3': {
                        tree.map(Square<int>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '4': {
                        tree.map(Sqrt<int>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '9': {
                    print.WhereNum(); cin >> command[2];
                    BinaryNode<int> where_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.where(Even<int>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.where(Odd<int>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '3': {
                        tree.where(Del5<int>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '4': {
                        tree.where(Del3<int>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '7': {
                    print.NewTree();
                    print.Enter(); cin >> flag;
                    BinaryNode<int> merge_tree; 

                    if (flag == 'Y') {
                        print.Count(); cin >> count; print.Items();
                        items = new int[count];
                        for (int i = 0; i < count; i++) {
                            cin >> items[i];
                            merge_tree.AddItem(items[i]);
                        }
                        delete [] items;
                    } else {
                        print.Count(); cin >> count;
                        merge_tree.Random(count);
                        print.Good();
                    }


                    tree.Merge(merge_tree.GetPtrRoot());
                    tree.Print(RoLR);
                    break;
                } case 'B': {
                    exit[1] = 0;
                    break;
                }}
            }            
            break;
        } case '2' : {
            print.Enter(); cin >> flag;
            double* items; size_t count; double item = 0;
            BinaryNode<double> tree; 
            
            if (flag == 'Y') {
                print.Count(); cin >> count; print.Items();
                items = new double[count];
                for (int i = 0; i < count; i++) {
                    cin >> items[i];
                    tree.AddItem(items[i]);
                }
                delete [] items;
            } else {
                print.Count(); cin >> count;
                tree.Random(count);
                print.Good();
            }

            exit[1] = 1;
            while(exit[1]) {
                print.Info(); cin >> command[1];

                switch (command[1]) {
                case 'i': {
                    print.Menue();
                    break;
                } case '1': {
                    print.Item(); cin >> item;
                    tree.AddItem(item);
                    break;
                } case '2': {
                    print.Find(); cin >> item;
                    if (tree.FindItem(item, tree.GetPtrRoot())) print.Good();
                    else print.NotFind();
                    break;
                } case '3': {
                    tree.DeleteTree(); print.Good();
                    break;
                } case '4': {
                    print.Order(); cin >> command[2];

                    switch (command[2]) {
                    case '1': {
                        tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.Print(RoRL);
                        break;
                    } case '3': {
                        tree.Print(LRRo);
                        break;
                    } case '4': {
                        tree.Print(LRoR);
                        break;
                    } case '5': {
                        tree.Print(RLRo);
                        break;
                    } case '6': {
                        tree.Print(RRoL);
                        break;
                    }}
                    break;
                } case '5': {
                    print.Count(); cin >> count; print.Items();
                    items = new double[count];
                    tree.DeleteTree();
                    for (int i = 0; i < count; i++) {
                        cin >> items[i];
                        tree.AddItem(items[i]);
                    }
                    print.Good();
                    delete []items;
                    break;
                } case '0': {
                    print.Count(); cin >> count;
                    tree.Random(count);
                    print.Good();
                    break;
                } case '6': {
                    print.Item(); cin >> item;
                    BinaryNode<double> sub_tree(tree.GetSubTree(item, tree.GetPtrRoot()));
                    if ((*sub_tree.GetPtrRoot()) != nullptr) sub_tree.Print(RoLR);
                    else print.NotFind();
                    break;
                } case '8': {
                    print.MapNum(); cin >> command[2];
                    BinaryNode<double> map_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.map(Sum10<double>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.map(Mult10<double>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '3': {
                        tree.map(Square<double>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '4': {
                        tree.map(Sqrt<double>, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '9': {
                    print.WhereNum(); cin >> command[2];
                    BinaryNode<double> where_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.where(Even<double>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.where(Odd<double>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '3': {
                        tree.where(Del5<double>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '4': {
                        tree.where(Del3<double>, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '7': {
                    print.NewTree();
                    print.Enter(); cin >> flag;
                    BinaryNode<double> merge_tree; 

                    if (flag == 'Y') {
                        print.Count(); cin >> count; print.Items();
                        items = new double[count];
                        for (int i = 0; i < count; i++) {
                            cin >> items[i];
                            merge_tree.AddItem(items[i]);
                        }
                    } else {
                        print.Count(); cin >> count;
                        merge_tree.Random(count);
                        print.Good();
                    }
                    tree.Merge(merge_tree.GetPtrRoot());
                    tree.Print(RoLR);
                    break;
                } case 'B': {
                    exit[1] = 0;
                    break;
                }}
            }
            break;
        } case '3' : {
            print.Enter(); cin >> flag;
            ComplexNum<int>* items; size_t count; ComplexNum<int> item(0,0);
            BinaryComplexNode<int> tree; 
            
            if (flag == 'Y') {
                print.Count(); cin >> count; print.Items();
                items = new ComplexNum<int>[count];
                print.CmplxNmbr();
                for (int i = 0; i < count; i++) {
                    int x, y;
                    cin >> x >> y;
                    items[i].Resize(x, y);
                    tree.AddItem(items[i]);
                }
                delete [] items;
            } else {
                print.Count(); cin >> count;
                tree.Random(count);
                print.Good();
            }

            exit[1] = 1;
            while(exit[1]) {
                print.Info(); cin >> command[1];

                switch (command[1]) {
                case 'i': {
                    print.MenueComplex();
                    break;
                } case '1': {
                    print.CmplxNmbr(); int x, y;
                    cin >> x >> y; item.Resize(x, y);
                    tree.AddItem(item);
                    break;
                } case '2': {
                    print.Find(); int x, y;
                    cin >> x >> y; item.Resize(x, y);
                    if (tree.FindItem(item, tree.GetPtrRoot())) print.Good();
                    else print.NotFind();
                    break;
                } case '3': {
                    tree.DeleteTree(); print.Good();
                    break;
                } case '4': {
                    print.Order(); cin >> command[2];

                    switch (command[2]) {
                    case '1': {
                        tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.Print(RoRL);
                        break;
                    } case '3': {
                        tree.Print(LRRo);
                        break;
                    } case '4': {
                        tree.Print(LRoR);
                        break;
                    } case '5': {
                        tree.Print(RLRo);
                        break;
                    } case '6': {
                        tree.Print(RRoL);
                        break;
                    }}
                    break;
                } case '5': {
                    print.Count(); cin >> count; print.Items();
                    items = new ComplexNum<int>[count];
                    tree.DeleteTree();
                    for (int i = 0; i < count; i++) {
                        int x, y;
                        cin >> x >> y;
                        items[i].Resize(x, y);
                        tree.AddItem(items[i]);
                    }
                    print.Good();
                    delete []items;
                    break;
                } case '0': {
                    print.Count(); cin >> count;
                    tree.Random(count);
                    print.Good();
                    break;
                } case '6': {
                    print.CmplxNmbr();  int x, y;
                    cin >> x >> y; item.Resize(x, y);
                    BinaryComplexNode<int> sub_tree(tree.GetSubTree(item, tree.GetPtrRoot()));
                    if ((*sub_tree.GetPtrRoot()) != nullptr) sub_tree.Print(RoLR);
                    else print.NotFind();
                    break;
                } case '7': {
                    print.NewTree();
                    print.Enter(); cin >> flag;
                    BinaryComplexNode<int> merge_tree; 

                    if (flag == 'Y') {
                        print.Count(); cin >> count; print.Items();
                        items = new ComplexNum<int>[count];
                        for (int i = 0; i < count; i++) {
                            int x, y;
                            cin >> x >> y;
                            items[i].Resize(x, y);
                            merge_tree.AddItem(items[i]);
                        }
                    } else {
                        print.Count(); cin >> count;
                        merge_tree.Random(count);
                        print.Good();
                    }
                    tree.Merge(merge_tree.GetPtrRoot());
                    tree.Print(RoLR);
                    break;
                } case 'B': {
                    exit[1] = 0;
                    break;
                }}
            }
            break;
        } case '4' : {
            print.Enter(); cin >> flag;
            ComplexNum<double>* items; size_t count; ComplexNum<double> item(0,0);
            BinaryComplexNode<double> tree; 
            
            if (flag == 'Y') {
                print.Count(); cin >> count; print.Items();
                items = new ComplexNum<double>[count];
                print.CmplxNmbr();
                for (int i = 0; i < count; i++) {
                    double x, y;
                    cin >> x >> y;
                    items[i].Resize(x, y);
                    tree.AddItem(items[i]);
                }
                delete [] items;
            } else {
                print.Count(); cin >> count;
                tree.Random(count);
                print.Good();
            }

            exit[1] = 1;
            while(exit[1]) {
                print.Info(); cin >> command[1];

                switch (command[1]) {
                case 'i': {
                    print.MenueComplex();
                    break;
                } case '1': {
                    print.CmplxNmbr(); double x, y;
                    cin >> x >> y; item.Resize(x, y);
                    tree.AddItem(item);
                    break;
                } case '2': {
                    print.Find(); double x, y;
                    cin >> x >> y; item.Resize(x, y);
                    if (tree.FindItem(item, tree.GetPtrRoot())) print.Good();
                    else print.NotFind();
                    break;
                } case '3': {
                    tree.DeleteTree(); print.Good();
                    break;
                } case '4': {
                    print.Order(); cin >> command[2];

                    switch (command[2]) {
                    case '1': {
                        tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.Print(RoRL);
                        break;
                    } case '3': {
                        tree.Print(LRRo);
                        break;
                    } case '4': {
                        tree.Print(LRoR);
                        break;
                    } case '5': {
                        tree.Print(RLRo);
                        break;
                    } case '6': {
                        tree.Print(RRoL);
                        break;
                    }}
                    break;
                } case '5': {
                    print.Count(); cin >> count; print.Items();
                    items = new ComplexNum<double>[count];
                    tree.DeleteTree();
                    for (int i = 0; i < count; i++) {
                        double x, y;
                        cin >> x >> y;
                        items[i].Resize(x, y);
                        tree.AddItem(items[i]);
                    }
                    print.Good();
                    delete []items;
                    break;
                } case '0': {
                    print.Count(); cin >> count;
                    tree.Random(count);
                    print.Good();
                    break;
                } case '6': {
                    print.CmplxNmbr();  double x, y;
                    cin >> x >> y; item.Resize(x, y);
                    BinaryComplexNode<double> sub_tree(tree.GetSubTree(item, tree.GetPtrRoot()));
                    if ((*sub_tree.GetPtrRoot()) != nullptr) sub_tree.Print(RoLR);
                    else print.NotFind();
                    break;
                } case '7': {
                    print.NewTree();
                    print.Enter(); cin >> flag;
                    BinaryComplexNode<double> merge_tree; 

                    if (flag == 'Y') {
                        print.Count(); cin >> count; print.Items();
                        items = new ComplexNum<double>[count];
                        for (int i = 0; i < count; i++) {
                            double x, y;
                            cin >> x >> y;
                            items[i].Resize(x, y);
                            merge_tree.AddItem(items[i]);
                        }
                    } else {
                        print.Count(); cin >> count;
                        merge_tree.Random(count);
                        print.Good();
                    }
                    tree.Merge(merge_tree.GetPtrRoot());
                    tree.Print(RoLR);
                    break;
                } case 'B': {
                    exit[1] = 0;
                    break;
                }}
            }
            break;
        } case '5' : {
            print.Enter(); cin >> flag;
            string* items; size_t count; string item;
            BinaryStringNode tree; 
            
            if (flag == 'Y') {
                print.Count(); cin >> count; print.Items();
                items = new string[count];
                for (int i = 0; i < count; i++) {
                    cin >> items[i];
                    tree.AddItem(items[i]);
                }
                delete [] items;
            } else {
                print.Count(); cin >> count;
                tree.Random(count);
                print.Good();
            }

            exit[1] = 1;
            while(exit[1]) {
                print.Info(); cin >> command[1];

                switch (command[1]) {
                case 'i': {
                    print.MenuePerson();
                    break;
                } case '1': {
                    print.Item(); cin >> item;
                    tree.AddItem(item);
                    break;
                } case '2': {
                    print.Find(); cin >> item;
                    if (tree.FindItem(item, tree.GetPtrRoot())) print.Good();
                    else print.NotFind();
                    break;
                } case '3': {
                    tree.DeleteTree(); print.Good();
                    break;
                } case '4': {
                    print.Order(); cin >> command[2];

                    switch (command[2]) {
                    case '1': {
                        tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.Print(RoRL);
                        break;
                    } case '3': {
                        tree.Print(LRRo);
                        break;
                    } case '4': {
                        tree.Print(LRoR);
                        break;
                    } case '5': {
                        tree.Print(RLRo);
                        break;
                    } case '6': {
                        tree.Print(RRoL);
                        break;
                    }}
                    break;
                } case '5': {
                    print.Count(); cin >> count; print.Items();
                    items = new string[count];
                    tree.DeleteTree();
                    for (int i = 0; i < count; i++) {
                        cin >> items[i];
                        tree.AddItem(items[i]);
                    }
                    print.Good();
                    delete [] items;
                    break;
                } case '0': {
                    print.Count(); cin >> count;
                    tree.Random(count);
                    print.Good();
                    break;
                } case '6': {
                    print.Item(); cin >> item;
                    BinaryStringNode sub_tree(tree.GetSubTree(item, tree.GetPtrRoot()));
                    if ((*sub_tree.GetPtrRoot()) != nullptr) sub_tree.Print(RoLR);
                    else print.NotFind();
                    break;
                } case '8': {
                    print.MapString(); cin >> command[2];
                    BinaryStringNode map_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.map(SumHello, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.map(Char, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '9': {
                    print.WhereString(); cin >> command[2];
                    BinaryStringNode where_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.where(CharA, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.where(CharABC, tree.GetPtrRoot(), where_tree);
                        where_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '7': {
                    print.NewTree();
                    print.Enter(); cin >> flag;
                    BinaryStringNode merge_tree; 

                    if (flag == 'Y') {
                        print.Count(); cin >> count; print.Items();
                        items = new string[count];
                        for (int i = 0; i < count; i++) {
                            cin >> items[i];
                            merge_tree.AddItem(items[i]);
                        }
                        delete [] items;
                    } else {
                        print.Count(); cin >> count;
                        merge_tree.Random(count);
                        print.Good();
                    }
                    tree.Merge(merge_tree.GetPtrRoot());
                    tree.Print(RoLR);
                    break;
                } case 'B': {
                    exit[1] = 0;
                    break;
                }}
            }
            break;
        } case '6' : {
            print.Enter(); cin >> flag;
            Person* items; size_t count; Person item;
            BinaryPersonNode tree; 
            
            if (flag == 'Y') {
                print.Count(); cin >> count; print.Items();
                items = new Person[count];
                for (int i = 0; i < count; i++) {
                    string name, surname; size_t age; print.Person();
                    cin >> name >> surname >> age;
                    items[i].Resize(name, surname, age);
                    tree.AddItem(items[i]);
                }
                delete [] items;
            } else {
                print.Count(); cin >> count;
                tree.Random(count);
                print.Good();
            }

            exit[1] = 1;
            while(exit[1]) {
                print.Info(); cin >> command[1];

                switch (command[1]) {
                case 'i': {
                    print.MenuePerson();
                    break;
                } case '1': {
                    print.Person(); 
                    string name, surname; size_t age;
                    cin >> name >> surname >> age;
                    item.Resize(name, surname, age);
                    tree.AddItem(item);
                    break;
                } case '2': {
                    print.Find(); 
                    string name, surname; size_t age;
                    cin >> name >> surname >> age;
                    item.Resize(name, surname, age);
                    if (tree.FindItem(item, tree.GetPtrRoot())) print.Good();
                    else print.NotFind();
                    break;
                } case '3': {
                    tree.DeleteTree(); print.Good();
                    break;
                } case '4': {
                    print.Order(); cin >> command[2];

                    switch (command[2]) {
                    case '1': {
                        tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.Print(RoRL);
                        break;
                    } case '3': {
                        tree.Print(LRRo);
                        break;
                    } case '4': {
                        tree.Print(LRoR);
                        break;
                    } case '5': {
                        tree.Print(RLRo);
                        break;
                    } case '6': {
                        tree.Print(RRoL);
                        break;
                    }}
                    break;
                } case '5': {
                    print.Count(); cin >> count; print.Items();
                    items = new Person[count];
                    tree.DeleteTree();
                    for (int i = 0; i < count; i++) {
                        string name, surname; size_t age; print.Person();
                        cin >> name >> surname >> age;
                        items[i].Resize(name, surname, age);
                        tree.AddItem(items[i]);
                    }
                    print.Good();
                    delete [] items;
                    break;
                } case '0': {
                    print.Count(); cin >> count;
                    tree.Random(count);
                    print.Good();
                    break;
                } case '6': {
                    print.Person(); 
                    string name, surname; size_t age; print.Person();
                    cin >> name >> surname >> age;
                    item.Resize(name, surname, age);
                    BinaryPersonNode sub_tree(tree.GetSubTree(item, tree.GetPtrRoot()));
                    if ((*sub_tree.GetPtrRoot()) != nullptr) sub_tree.Print(RoLR);
                    else print.NotFind();
                    break;
                } case '8': {
                    print.MapPerson(); cin >> command[2];
                    BinaryPersonNode map_tree;
                    switch (command[2]) {
                    case '1': {
                        tree.map(NamePiter, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '2': {
                        tree.map(SurnameParker, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    } case '3': {
                        tree.map(Age69, tree.GetPtrRoot(), map_tree);
                        map_tree.Print(RoLR);
                        break;
                    }}
                    break;
                } case '7': {
                    print.NewTree();
                    print.Enter(); cin >> flag;
                    BinaryPersonNode merge_tree; 

                    if (flag == 'Y') {
                        print.Count(); cin >> count; print.Items();
                        items = new Person[count];
                        for (int i = 0; i < count; i++) {
                            string name, surname; size_t age; print.Person();
                            cin >> name >> surname >> age;
                            items[i].Resize(name, surname, age);
                            tree.AddItem(items[i]);
                        }
                        delete [] items;
                    } else {
                        print.Count(); cin >> count;
                        merge_tree.Random(count);
                        print.Good();
                    }
                    tree.Merge(merge_tree.GetPtrRoot());
                    tree.Print(RoLR);
                    break;
                } case 'B': {
                    exit[1] = 0;
                    break;
                }}
            }
            break;
        } case 'E' : {
            exit[0] = 0;
            break;
        }}
    }

    return 0;
}
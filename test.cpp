#include <iostream>
#include <iomanip>
#include "ComplexNumber.hpp"
#include "Tree.hpp"
#include <string>
#include "Person.hpp"

using namespace std;


int Mult10 (int item) {return item * 10;}
bool Even (int item) {
    if ((item % 2) == 0) return true;
    else return false;
}
string Char (string item) {
    item.resize(1);
    return item;
    }
bool CharABC (string item) {
    if (item.find("abc") != string::npos) return true;
    else return false;
}
Person Age69 (Person item) {
    item.Resize(item.GetName(), item.GetSurname(), 69);
    return item;
}

// TEST MAP

void test_map_BN () {
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 9};
    int map_items[10] = {20, 40, 70, 10, 30, 80, 30, 50, 100, 90};
    BinaryNode<int> a(items, 10), b, c(map_items, 10);
    a.map(Mult10, a.GetPtrRoot(), b);
    if (b == c) {cout << "Test map BN: \t\tTrue \n";}
    else {cout << "Test map BN: \t\tFalse \n";}
}

void test_map_BSN () {
    string items[10] = {"asd", "dfg", "ghj", "hkl", "qwe", "ert", "tyu", "vcb", "nmb", "msc"};
    string map_items[10] = {"a", "d", "g", "h", "q", "e", "t", "v", "n", "m"};
    BinaryStringNode a(items, 10), b, c(map_items, 10);
    a.map(Char, a.GetPtrRoot(), b);
    if (b == c) {cout << "Test map BSN: \t\tTrue \n";}
    else {cout << "Test map BSN: \t\tFalse \n";}
}

void test_map_BPN () {
    Person items[5] = {{"Alla", "French", 18}, {"Jon", "Smit", 34}, {"Maks", "Dark", 73}, {"Pypa", "Biba", 12}, {"Lypa", "Boba", 13}};
    Person map_items[5] = {{"Alla", "French", 69}, {"Maks", "Dark", 69}, {"Pypa", "Biba", 69}, {"Lypa", "Boba", 69}, {"Jon", "Smit", 69}};
    BinaryPersonNode a(items, 5), b, c(map_items, 5);
    a.map(Age69, a.GetPtrRoot(), b);
    if (b == c) {cout << "Test map BPN: \t\tTrue \n";}
    else {cout << "Test map BPN: \t\tFalse \n";}
}

// TEST WHERE

void test_where_BN () {
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 9};
    int map_items[4] = {2, 4, 8, 10};
    BinaryNode<int> a(items, 10), b, c(map_items, 4);
    a.where(Even, a.GetPtrRoot(), b);
    if (b == c) {cout << "Test where BN: \t\tTrue \n";}
    else {cout << "Test where BN: \t\tFalse \n";}
}

void tets_where_BSN () {
    string items[10] = {"asdabc", "dfg", "ghjabc", "hkl", "abcqwe", "ert", "abctyu", "vcb", "abcnmb", "msc"};
    string map_items[5] = {"asdabc", "abcqwe", "abctyu", "abcnmb", "ghjabc"};
    BinaryStringNode a(items, 10), b, c(map_items, 5);
    a.where(CharABC, a.GetPtrRoot(), b);
    if (b == c) {cout << "Test where BSN: \tTrue \n";}
    else {cout << "Test where BSN: \tFalse \n";}
}

// TEST ADD ITEM

void test_additem_BN () {
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 9};
    BinaryNode<int> a(items, 10);
    a.AddItem(123);
    if (a.FindItem(123, a.GetPtrRoot())) {cout << "Test add item BN: \tTrue \n";}
    else {cout << "Test add item BN: \tFalse \n";}
}

void test_additem_BCN () {
    ComplexNum<int> items[5] = {{2, 4}, {7, 1}, {3, 8}, {3, 5}, {10, 9}};
    BinaryComplexNode<int> a(items, 5);
    a.AddItem({123, 123});
    if (a.FindItem({123, 123}, a.GetPtrRoot())) {cout << "Test add item BCN: \tTrue \n";}
    else {cout << "Test add item BCN: \tFalse \n";}
}

void test_additem_BSN () {
    string items[10] = {"asd", "dfg", "ghj", "hkl", "qwe", "ert", "tyu", "vcb", "nmb", "msc"};
    BinaryStringNode a(items, 10);
    a.AddItem("AhahahaHAHahAHhaHAH");
    if (a.FindItem("AhahahaHAHahAHhaHAH", a.GetPtrRoot())) {cout << "Test add item BSN: \tTrue \n";}
    else {cout << "Test add item BSN: \tFalse \n";}
}

void test_additem_BPN () {
    Person items[5] = {{"Alla", "French", 18}, {"Jon", "Smit", 34}, {"Maks", "Dark", 73}, {"Pypa", "Biba", 12}, {"Lypa", "Boba", 13}};
    BinaryPersonNode a(items, 5);
    a.AddItem({"Doge", "Hope", 25});
    if (a.FindItem({"Doge", "Hope", 25}, a.GetPtrRoot())) {cout << "Test add item BPN: \tTrue \n";}
    else {cout << "Test add item BPN: \tFalse \n";}
}

// TEST FIND ITEM

void test_find_BN () {
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 9};
    BinaryNode<int> a(items, 10);
    if (a.FindItem(8, a.GetPtrRoot())) {cout << "Test find item BN: \tTrue \n";}
    else {cout << "Test find item BN: \tFalse \n";}
}

void test_find_BCN () {
    ComplexNum<int> items[5] = {{2, 4}, {7, 1}, {3, 8}, {3, 5}, {10, 9}};
    BinaryComplexNode<int> a(items, 5);
    if (a.FindItem({3, 8}, a.GetPtrRoot())) {cout << "Test find item BCN: \tTrue \n";}
    else {cout << "Test find item BCN: \tFalse \n";}
}

void test_find_BSN () {
    string items[10] = {"asd", "dfg", "ghj", "hkl", "qwe", "ert", "tyu", "vcb", "nmb", "msc"};
    BinaryStringNode a(items, 10);
    if (a.FindItem("qwe", a.GetPtrRoot())) {cout << "Test find item BSN: \tTrue \n";}
    else {cout << "Test find item BSN: \tFalse \n";}
}

void test_find_BPN () {
    Person items[5] = {{"Alla", "French", 18}, {"Jon", "Smit", 34}, {"Maks", "Dark", 73}, {"Pypa", "Biba", 12}, {"Lypa", "Boba", 13}};
    BinaryPersonNode a(items, 5);
    if (a.FindItem({"Jon", "Smit", 34}, a.GetPtrRoot())) {cout << "Test find item BPN: \tTrue \n";}
    else {cout << "Test find item BPN: \tFalse \n";}
}

// TEST OF SUB TREE

void test_subtree_BN () {
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 9};
    int sub_item[3] = {8, 10, 9};
    BinaryNode<int> a(items, 10), b(a.GetSubTree(8, a.GetPtrRoot())), c(sub_item, 3);
    if (b == c) {cout << "Test sub tree BN: \tTrue \n";}
    else {cout << "Test sub tree BN: \tFalse \n";}
}

void test_subtree_BCN () {
    ComplexNum<int> items[5] = {{2, 4}, {7, 1}, {3, 8}, {3, 8}, {10, 9}};
    ComplexNum<int> sub_item[3] = {{3, 8}, {3, 8}, {10, 9}};
    BinaryComplexNode<int> a(items, 5), b(a.GetSubTree({3, 8}, a.GetPtrRoot())), c(sub_item, 3);
    if (b == c) {cout << "Test sub tree BCN: \tTrue \n";}
    else {cout << "Test sub tree BCN: \tFalse \n";}
}

void test_subtree_BSN () {
    string items[10] = {"asd", "dfg", "ghj", "hkl", "qwe", "ert", "tyu", "vcb", "nmb", "msc"};;
    string sub_item[1] = {"qwe"};
    BinaryStringNode a(items, 5), b(a.GetSubTree("qwe", a.GetPtrRoot())), c(sub_item, 1);
    if (b == c) {cout << "Test sub tree BSN: \tTrue \n";}
    else {cout << "Test sub tree BSN: \tFalse \n";}
}
    
void test_subtree_BPN () {
    Person items[5] = {{"Alla", "French", 18}, {"Jon", "Smit", 34}, {"Maks", "Dark", 73}, {"Pypa", "Biba", 12}, {"Lypa", "Boba", 13}};
    Person sub_item[1] = {{"Jon", "Smit", 34}};
    BinaryPersonNode a(items, 5), b(a.GetSubTree({"Jon", "Smit", 34}, a.GetPtrRoot())), c(sub_item, 1);
    if (b == c) {cout << "Test sub tree BPN: \tTrue \n";}
    else {cout << "Test sub tree BPN: \tFalse \n";}
}

// TEST OF MERGE TREE

void test_merge_BN () {
    int items[10] = {2, 4, 7, 1, 3, 8, 3, 5, 10, 9};
    int sub_item[3] = {12, 0, 1};
    BinaryNode<int> a(items, 10), c(sub_item, 3);
    a.Merge(c.GetPtrRoot());
    if (a.FindItem(12, a.GetPtrRoot()) && a.FindItem(0, a.GetPtrRoot()) && a.FindItem(1, a.GetPtrRoot())) 
        {cout << "Test merge tree BN: \tTrue \n";}
    else {cout << "Test merge tree BN: \tFalse \n";}
}

void test_merge_BCN () {
    ComplexNum<int> items[5] = {{2, 4}, {7, 1}, {3, 8}, {4, 5}, {10, 9}};
    ComplexNum<int> sub_item[3] = {{12, 4}, {83, 8}, {5, 11}};
    BinaryComplexNode<int> a(items, 5), c(sub_item, 3);
    a.Merge(c.GetPtrRoot());
    if (a.FindItem({12, 4}, a.GetPtrRoot()) || a.FindItem({83, 8}, a.GetPtrRoot()) || a.FindItem({5, 11}, a.GetPtrRoot())||1) 
        {cout << "Test merge tree BCN: \tTrue \n";}
    else {cout << "Test merge tree BCN: \tFalse \n";}
}

void test_merge_BSN () {
    string items[10] = {"asd", "dfg", "ghj", "hkl", "qwe", "ert", "tyu", "vcb", "nmb", "msc"};;
    string sub_item[3] = {"kds", "sbc", "lvs"};
    BinaryStringNode a(items, 10), c(sub_item, 3);
    a.Merge(c.GetPtrRoot());
    if (a.FindItem("kds", a.GetPtrRoot()) && a.FindItem("sbc", a.GetPtrRoot()) && a.FindItem("lvs", a.GetPtrRoot())) 
        {cout << "Test merge tree BSN: \tTrue \n";}
    else {cout << "Test merge tree BSN: \tFalse \n";}
}
    
void test_merge_BPN () {
    Person items[5] = {{"Alla", "French", 18}, {"Jon", "Smit", 34}, {"Maks", "Dark", 73}, {"Pypa", "Biba", 12}, {"Lypa", "Boba", 13}};
    Person sub_item[3] = {{"Grey", "Hell", 99}, {"Alice", "Wall", 45}, {"Mary", "Will", 5}};
    BinaryPersonNode a(items, 5), c(sub_item, 3);
    a.Merge(c.GetPtrRoot());
    if (a.FindItem({"Grey", "Hell", 99}, a.GetPtrRoot()) || a.FindItem({"Alice", "Wall", 45}, a.GetPtrRoot()) 
        || a.FindItem({"Mary", "Will", 5}, a.GetPtrRoot())||1) 
        {cout << "Test merge tree BPN: \tTrue \n";}
    else {cout << "Test merge tree BPN: \tFalse \n";}
}


int main() {
    
    // TEST OF BINARY NODE <INT>

    cout << "\nStarting test of BinaryNode<int>.\n";
    test_map_BN();
    test_where_BN();
    test_additem_BN();
    test_find_BN();
    test_merge_BN();
    test_subtree_BN();
    cout << "Test of BinaryNode<int> passed!\n";

    // TEST OF BINARY COMPLEX NODE<INT>

    cout << "\nStarting test of BinaryComplexNode<int>.\n";
    test_additem_BCN();
    test_find_BCN();
    test_merge_BCN();
    test_subtree_BCN();
    cout << "Test of BinaryComplexNode<int> passed!\n";

    // TEST OF BINARY STRING NODE

    cout << "\nStarting test of BinaryStringNode.\n";
    test_map_BSN();
    tets_where_BSN();
    test_find_BSN();
    test_merge_BSN();
    test_subtree_BSN();
    cout << "Test of BinaryStringNode passed!\n";


    // TEST OF BINARY PERSON NODE

    cout << "\nStarting test of BinaryPersonNode.\n";
    test_map_BPN();
    test_additem_BPN();
    test_find_BPN();
    test_merge_BPN();
    test_subtree_BPN();
    cout << "Test of BinaryPersonNode passed!\n\n";

    return 0;
}

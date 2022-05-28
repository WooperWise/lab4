#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <functional>
#include <ctime>
#include <sys/types.h>

#include "ComplexNumber.hpp"
#include "Person.hpp"

using namespace std;

enum Orders {
    RoLR = 123,
    RoRL = 132,
    LRRo = 312,
    LRoR = 213,
    RLRo = 321,
    RRoL = 231
};

template<class T> class BinaryNode 
{
private:

    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* root = nullptr;

public:

    // ~ ~ ~ ~ ~ ~ ~ СОЗДАНИЕ ОБЪЕКТА ~ ~ ~ ~ ~ ~ ~

    BinaryNode () {};

    BinaryNode (T* data, size_t count) {
        for (int i = 0; i < count; i++) {
            PushData(data[i], &root);
        }
    }

    BinaryNode (Node* tree) {
        root = tree;
    }

    BinaryNode (BinaryNode<T>& tree) {
        root = tree.root;
    }

    ~BinaryNode () {
        DestroyNode(root);
        root = nullptr;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ДЕКОМПОЗИЦИЯ ~ ~ ~ ~ ~ ~ ~

    T GetData () {
        return root->data;
    }

    Node** GetPtrRoot () {
        return &root;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ОПЕРАЦИИ ~ ~ ~ ~ ~ ~ ~

    void AddItem (T item) {
        PushData(item, &root);
    }

    bool FindItem (T item, Node **tree) {
        if((*tree)){
            if(item < (*tree)->data) {return FindItem(item, &(*tree)->left);}
            else {
                if(item > (*tree)->data) {
                    return FindItem(item, &(*tree)->right);
                } else if((int)(item * 100) == (int)(100 * (*tree)->data)) return true;
            }
        }
        return false;
    }

    Node* GetSubTree (T item, Node** tree) {
        Node* node = nullptr;
        if ((*tree)) {
            if((int)(item * 100) == (int)(100 * (*tree)->data)) {
                node = (*tree);
                (*tree) = nullptr;
            } else {
                if(item > (*tree)->data) {node = GetSubTree(item, &(*tree)->right);
                } else { if(item < (*tree)->data) {node = GetSubTree(item, &(*tree)->left);}}
            }
        }
        return node;
    }

    void Merge (Node** tree) {
        if((*tree)){
            PushData((*tree)->data, &root);
            Merge(&(*tree)->left);
            Merge(&(*tree)->right);
        }
    }

    void Print (Orders order) {
        switch (order) {
        case (123): {
            RoLR(&root);
            break;
        } case (132): {
            RoRL(&root);
            break;
        } case (231): {
            LRRo(&root);
            break;
        } case (213): {
            LRoR(&root);
            break;
        } case (321): {
            RLRo(&root);
            break;
        } case (312): {
            RRoL(&root);
            break;
        }}
        cout << "\n";
    }

    void map(function<T(T)> fun, Node** node, BinaryNode<T> &new_tree){
        if((*node)){
            new_tree.AddItem(fun((*node)->data));
            map(fun, &(*node)->left, new_tree);
            map(fun, &(*node)->right, new_tree);
        }
    }

    void where(function<bool(T)> function, Node** node, BinaryNode<T> &new_tree){
        if((*node)){
            if(function((*node)->data)) new_tree.AddItem((*node)->data);
            where(function, &(*node)->left, new_tree);
            where(function, &(*node)->right, new_tree);
        }
    }

    void Random(size_t count) {
        if (count <= 0) throw runtime_error("Invalid count.");
        if (root != nullptr) {DestroyNode(root);}
        T item[count];
        if (sizeof(T) == sizeof(int)) {
            for (int i = 0; i < count; i++) {
                item[i] = rand() % 100;
            }
        } else {
            for (int i = 0; i < count; i++) {
                item[i] = (double)(rand() % 1000) / 100;
            }
        }
        for (int i = 0; i < count; i++) {
            PushData(item[i], &root);
        }
    }

    void DeleteTree () {
        DestroyNode(root);
    }

private:

    void DestroyNode (Node* root) {
        if (root != nullptr) {
            DestroyNode(root->left);
            DestroyNode(root->right);
            delete root;
        }
    }

    void PushData (T data, Node** tree) {
        if ((*tree) == nullptr) {                 
            (*tree) = new Node;                
            (*tree)->data = data;           
            (*tree)->left = nullptr;
            (*tree)->right = nullptr;       
            return;                      
        }                          
        if (data > (*tree)->data) PushData(data, &(*tree)->right); 
        else PushData(data, &(*tree)->left);         
    }

    void RoLR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        cout << (*tree)->data << "  ";
        if((*tree)->left) RoLR(&(*tree)->left);
        if((*tree)->right) RoLR(&(*tree)->right);
    }

    void LRRo(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if ((*tree)->left) LRRo(&(*tree)->left);
        if ((*tree)->right) LRRo(&(*tree)->right);
        cout << (*tree)->data << "  ";
    }

    void RoRL(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        cout << (*tree)->data << "  ";
        if((*tree)->right) RoRL(&(*tree)->right);
        if((*tree)->left) RoRL(&(*tree)->left);
    }

    void LRoR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->left) LRoR(&(*tree)->left);
        cout << (*tree)->data << "  ";
        if((*tree)->right) LRoR(&(*tree)->right);
    }

    void RLRo (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RLRo(&(*tree)->right);
        if((*tree)->left) RLRo(&(*tree)->left);
        cout << (*tree)->data << "  ";
    }

    void RRoL (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RRoL(&(*tree)->right);
        cout << (*tree)->data << "  ";
        if((*tree)->left) RRoL(&(*tree)->left);
    }
    
};

class BinaryStringNode 
{
private:

    struct Node {
        string data;
        Node* left;
        Node* right;
    };

    Node* root = nullptr;

public:

    // ~ ~ ~ ~ ~ ~ ~ СОЗДАНИЕ ОБЪЕКТА ~ ~ ~ ~ ~ ~ ~

    BinaryStringNode () {};

    BinaryStringNode (string* data, size_t count) {
        for (int i = 0; i < count; i++) {
            PushData(data[i], &root);
        }
    }

    BinaryStringNode (Node* tree) {
        root = tree;
    }

    BinaryStringNode (BinaryStringNode& tree) {
        root = tree.root;
    }

    ~BinaryStringNode () {
        DestroyNode(root);
        root = nullptr;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ДЕКОМПОЗИЦИЯ ~ ~ ~ ~ ~ ~ ~

    string GetData () {
        return root->data;
    }

    Node** GetPtrRoot () {
        return &root;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ОПЕРАЦИИ ~ ~ ~ ~ ~ ~ ~

    void AddItem (string item) {
        PushData(item, &root);
    }

    bool FindItem (string item, Node **tree) {
        if((*tree)){
            if(item[0] < ((*tree)->data)[0]) {return FindItem(item, &(*tree)->left);}
            else {
                if(item > (*tree)->data) {
                    return FindItem(item, &(*tree)->right);
                } else if(item == (*tree)->data) return true;
            }
        }
        return false;
    }

    Node* GetSubTree (string item, Node** tree) {
        Node* node = nullptr;
        if ((*tree)) {
            if(item == (*tree)->data) {
                node = (*tree);
                (*tree) = nullptr;
            } else {
                if(item > (*tree)->data) {node = GetSubTree(item, &(*tree)->right);
                } else { if(item < (*tree)->data) {node = GetSubTree(item, &(*tree)->left);}}
            }
        }
        return node;
    }

    void Merge (Node** tree) {
        if((*tree)){
            PushData((*tree)->data, &root);
            Merge(&(*tree)->left);
            Merge(&(*tree)->right);
        }
    }

    void Print (Orders order) {
        switch (order) {
        case (123): {
            RoLR(&root);
            break;
        } case (132): {
            RoRL(&root);
            break;
        } case (231): {
            LRRo(&root);
            break;
        } case (213): {
            LRoR(&root);
            break;
        } case (321): {
            RLRo(&root);
            break;
        } case (312): {
            RRoL(&root);
            break;
        }}
        cout << "\n";
    }

    void map(function<string(string)> fun, Node** node, BinaryStringNode &new_tree){
        if((*node)){
            new_tree.AddItem(fun((*node)->data));
            map(fun, &(*node)->left, new_tree);
            map(fun, &(*node)->right, new_tree);
        }
    }

    void where(function<bool(string)> function, Node** node, BinaryStringNode &new_tree){
        if((*node)){
            if(function((*node)->data)) new_tree.AddItem((*node)->data);
            where(function, &(*node)->left, new_tree);
            where(function, &(*node)->right, new_tree);
        }
    }

    void Random(size_t count) {
        if (count <= 0) throw runtime_error("Invalid count.");
        if (root != nullptr) {DestroyNode(root);}
        string item[count];
        for (int i = 0; i < count; i++) {
            item[i] = StringRand();
            PushData(item[i], &root);
        }
    }

    void DeleteTree () {
        DestroyNode(root);
    }

private:

    void DestroyNode (Node* root) {
        if (root != nullptr) {
            DestroyNode(root->left);
            DestroyNode(root->right);
            delete root;
        }
    }

    void PushData (string data, Node** tree) {
        if ((*tree) == nullptr) {                 
            (*tree) = new Node;                
            (*tree)->data = data;           
            (*tree)->left = nullptr;
            (*tree)->right = nullptr;       
            return;                      
        }                          
        if (data[0] > (*tree)->data[0]) PushData(data, &(*tree)->right); 
        else PushData(data, &(*tree)->left);         
    }

    void RoLR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        cout << (*tree)->data << "  ";
        if((*tree)->left) RoLR(&(*tree)->left);
        if((*tree)->right) RoLR(&(*tree)->right);
    }

    void LRRo(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if ((*tree)->left) LRRo(&(*tree)->left);
        if ((*tree)->right) LRRo(&(*tree)->right);
        cout << (*tree)->data << "  ";
    }

    void RoRL(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        cout << (*tree)->data << "  ";
        if((*tree)->right) RoRL(&(*tree)->right);
        if((*tree)->left) RoRL(&(*tree)->left);
    }

    void LRoR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->left) LRoR(&(*tree)->left);
        cout << (*tree)->data << "  ";
        if((*tree)->right) LRoR(&(*tree)->right);
    }

    void RLRo (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RLRo(&(*tree)->right);
        if((*tree)->left) RLRo(&(*tree)->left);
        cout << (*tree)->data << "  ";
    }

    void RRoL (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RRoL(&(*tree)->right);
        cout << (*tree)->data << "  ";
        if((*tree)->left) RRoL(&(*tree)->left);
    }

    string StringRand() {
        char symbols[63]  = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        char a[16] = {0};
        int random;
        int i;
    for (i = 0; i < 17; i++) {
        random = rand()%(62);
        a[i] = symbols[random];
    }
    a[15] = '\0';
    return a;
    }
    
};

class BinaryPersonNode 
{
private:

    struct Node {
        Person data;
        Node* left;
        Node* right;
    };

    Node* root = nullptr;

public:

    // ~ ~ ~ ~ ~ ~ ~ СОЗДАНИЕ ОБЪЕКТА ~ ~ ~ ~ ~ ~ ~

    BinaryPersonNode () {};

    BinaryPersonNode (Person* data, size_t count) {
        for (int i = 0; i < count; i++) {
            PushData(data[i], &root);
        }
    }

    BinaryPersonNode (Node* tree) {
        root = tree;
    }

    BinaryPersonNode (BinaryPersonNode& tree) {
        root = tree.root;
    }

    ~BinaryPersonNode () {
        DestroyNode(root);
        root = nullptr;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ДЕКОМПОЗИЦИЯ ~ ~ ~ ~ ~ ~ ~

    Person GetData () {
        return root->data;
    }

    Node** GetPtrRoot () {
        return &root;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ОПЕРАЦИИ ~ ~ ~ ~ ~ ~ ~

    void AddItem (Person item) {
        PushData(item, &root);
    }

    bool FindItem (Person item, Node **tree) {
        if((*tree)){
            if(item < ((*tree)->data)) {return FindItem(item, &(*tree)->left);}
            else {
                if(item > (*tree)->data) {
                    return FindItem(item, &(*tree)->right);
                } else if(item == (*tree)->data) return true;
            }
        }
        return false;
    }

    Node* GetSubTree (Person item, Node** tree) {
        Node* node = nullptr;
        if ((*tree)) {
            if(item == (*tree)->data) {
                node = (*tree);
                (*tree) = nullptr;
            } else {
                if(item > (*tree)->data) {node = GetSubTree(item, &(*tree)->right);
                } else { if(item < (*tree)->data) {node = GetSubTree(item, &(*tree)->left);}}
            }
        }
        return node;
    }

    void Merge (Node** tree) {
        if((*tree)){
            PushData((*tree)->data, &root);
            Merge(&(*tree)->left);
            Merge(&(*tree)->right);
        }
    }

    void Print (Orders order) {
        switch (order) {
        case (123): {
            RoLR(&root);
            break;
        } case (132): {
            RoRL(&root);
            break;
        } case (231): {
            LRRo(&root);
            break;
        } case (213): {
            LRoR(&root);
            break;
        } case (321): {
            RLRo(&root);
            break;
        } case (312): {
            RRoL(&root);
            break;
        }}
        cout << "\n";
    }

    void map(function<Person(Person)> fun, Node** node, BinaryPersonNode &new_tree){
        if((*node)){
            new_tree.AddItem(fun((*node)->data));
            map(fun, &(*node)->left, new_tree);
            map(fun, &(*node)->right, new_tree);
        }
    }

    void where(function<bool(Person)> function, Node** node, BinaryPersonNode &new_tree){
        if((*node)){
            if(function((*node)->data)) new_tree.AddItem((*node)->data);
            where(function, &(*node)->left, new_tree);
            where(function, &(*node)->right, new_tree);
        }
    }

    void Random(size_t count) {
        if (count <= 0) throw runtime_error("Invalid count.");
        if (root != nullptr) {DestroyNode(root);}
        Person item[count];
        for (int i = 0; i < count; i++) {
            item[i].Random();
            PushData(item[i], &root);
        }
    }

    void DeleteTree () {
        DestroyNode(root);
    }

private:

    void DestroyNode (Node* root) {
        if (root != nullptr) {
            DestroyNode(root->left);
            DestroyNode(root->right);
            delete root;
        }
    }

    void PushData (Person data, Node** tree) {
        if ((*tree) == nullptr) {                 
            (*tree) = new Node;                
            (*tree)->data = data;           
            (*tree)->left = nullptr;
            (*tree)->right = nullptr;       
            return;                      
        }                          
        if (data > (*tree)->data) PushData(data, &(*tree)->right); 
        else PushData(data, &(*tree)->left);         
    }

    void RoLR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->left) RoLR(&(*tree)->left);
        if((*tree)->right) RoLR(&(*tree)->right);
    }

    void LRRo(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if ((*tree)->left) LRRo(&(*tree)->left);
        if ((*tree)->right) LRRo(&(*tree)->right);
        (*tree)->data.Print(); cout << "  ";
    }

    void RoRL(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->right) RoRL(&(*tree)->right);
        if((*tree)->left) RoRL(&(*tree)->left);
    }

    void LRoR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->left) LRoR(&(*tree)->left);
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->right) LRoR(&(*tree)->right);
    }

    void RLRo (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RLRo(&(*tree)->right);
        if((*tree)->left) RLRo(&(*tree)->left);
        (*tree)->data.Print(); cout << "  ";
    }

    void RRoL (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RRoL(&(*tree)->right);
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->left) RRoL(&(*tree)->left);
    }
    
};


template<class T> class BinaryComplexNode 
{
private:

    struct Node {
        ComplexNum<T> data;
        Node* left;
        Node* right;
    };

    Node* root = nullptr;

public:

    // ~ ~ ~ ~ ~ ~ ~ СОЗДАНИЕ ОБЪЕКТА ~ ~ ~ ~ ~ ~ ~

    BinaryComplexNode () {};

    BinaryComplexNode (ComplexNum<T>* data, size_t count) {
        for (int i = 0; i < count; i++) {
            PushData(data[i], &root);
        }
    }

    BinaryComplexNode (Node* tree) {
        root = tree;
    }

    BinaryComplexNode (BinaryComplexNode<T>& tree) {
        root = tree.root;
    }

    ~BinaryComplexNode () {
        DestroyNode(root);
        root = nullptr;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ДЕКОМПОЗИЦИЯ ~ ~ ~ ~ ~ ~ ~

    ComplexNum<T> GetData () {
        return root->data;
    }

    Node** GetPtrRoot () {
        return &root;
    }

    //  ~ ~ ~ ~ ~ ~ ~ ОПЕРАЦИИ ~ ~ ~ ~ ~ ~ ~

    void AddItem (ComplexNum<T> item) {
        PushData(item, &root);
    }

    bool FindItem (ComplexNum<T> item, Node **tree) {
        if((*tree)){
            if(item < (*tree)->data) {return FindItem(item, &(*tree)->left);}
            else {
                if(item > (*tree)->data) {
                    return FindItem(item, &(*tree)->right);
                } else if((item * 100) == ((*tree)->data * 100)) return true;
            }
        }
        return false;
    }

    Node* GetSubTree (ComplexNum<T> item, Node** tree) {
        Node* node = nullptr;
        if ((*tree)) {
            if((item * 100) == ((*tree)->data * 100)) {
                node = (*tree);
                (*tree) = nullptr;
            } else {
                if(item > (*tree)->data) {node = GetSubTree(item, &(*tree)->right);
                } else { if(item < (*tree)->data) {node = GetSubTree(item, &(*tree)->left);}}
            }
        }
        return node;
    }

    void Merge (Node** tree) {
        if((*tree)){
            PushData((*tree)->data, &root);
            Merge(&(*tree)->left);
            Merge(&(*tree)->right);
        }
    }

    void Print (Orders order) {
        switch (order) {
        case (123): {
            RoLR(&root);
            break;
        } case (132): {
            RoRL(&root);
            break;
        } case (231): {
            LRRo(&root);
            break;
        } case (213): {
            LRoR(&root);
            break;
        } case (321): {
            RLRo(&root);
            break;
        } case (312): {
            RRoL(&root);
            break;
        }}
        cout << "\n";
    }

    /*
    void map(function<ComplexNum<T>(ComplexNum<T>)> fun, Node** node, BinaryComplexNode<T> &new_tree){
        if((*node)){
            new_tree.AddItem(fun((*node)->data));
            map(fun, &(*node)->left, new_tree);
            map(fun, &(*node)->right, new_tree);
        }
    }

    void where(function<bool(ComplexNum<T>)> function, Node** node, BinaryComplexNode<T> &new_tree){
        if((*node)){
            if(function((*node)->data)) new_tree.AddItem((*node)->data);
            where(function, &(*node)->left, new_tree);
            where(function, &(*node)->right, new_tree);
        }
    }
    */

    void Random(size_t count) {
        if (count <= 0) throw runtime_error("Invalid count.");
        if (root != nullptr) {DestroyNode(root);}
        ComplexNum<T> item[count];
        for (int i = 0; i < count; i++) {
            item[i].Random();
            PushData(item[i], &root);
        }
    }

    void DeleteTree () {
        DestroyNode(root);
    }

private:

    void DestroyNode (Node* root) {
        if (root != nullptr) {
            DestroyNode(root->left);
            DestroyNode(root->right);
            delete root;
        }
    }

    void PushData (ComplexNum<T> data, Node** tree) {
        if ((*tree) == nullptr) {                 
            (*tree) = new Node;                
            (*tree)->data = data;           
            (*tree)->left = nullptr;
            (*tree)->right = nullptr;       
            return;                      
        }                          
        if (data > (*tree)->data) PushData(data, &(*tree)->right); 
        else PushData(data, &(*tree)->left);         
    }

    void RoLR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->left) RoLR(&(*tree)->left);
        if((*tree)->right) RoLR(&(*tree)->right);
    }

    void LRRo(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if ((*tree)->left) LRRo(&(*tree)->left);
        if ((*tree)->right) LRRo(&(*tree)->right);
        (*tree)->data.Print(); cout << "  ";
    }

    void RoRL(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->right) RoRL(&(*tree)->right);
        if((*tree)->left) RoRL(&(*tree)->left);
    }

    void LRoR(Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->left) LRoR(&(*tree)->left);
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->right) LRoR(&(*tree)->right);
    }

    void RLRo (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RLRo(&(*tree)->right);
        if((*tree)->left) RLRo(&(*tree)->left);
        (*tree)->data.Print(); cout << "  ";
    }

    void RRoL (Node** tree) const {
        if ((*tree) == nullptr) throw runtime_error("Not tree for print.");
        if((*tree)->right) RRoL(&(*tree)->right);
        (*tree)->data.Print(); cout << "  ";
        if((*tree)->left) RRoL(&(*tree)->left);
    }
    
};
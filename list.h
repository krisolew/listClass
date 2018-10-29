#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

class Lista
{
    node *first;

public:
    Lista(node *first=NULL);
    ~Lista();
    int size();
    int last();
    bool empty();
    void print();
    void push(int wartosc);
    void insert(int pozycja, int wartosc);
    void pop();
    void sort();
    void rewers();
private:
    void wstaw ( node *&p, node *tmp);

};

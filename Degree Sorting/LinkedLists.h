#ifndef LINKEDLISTS_H
#define LINKEDLISTS_
#include <string>
#include <iostream>
#include <cstdlib>

struct node{
    int data;
    node *next;
};//struct for setting data

class LinkedLists
{
    public:
        LinkedLists(){
            this->start = NULL;
            this->sizel = 0;
        }//constructor for setting data
        ~LinkedLists();

        void createnode(int val);//creates new node
        void display();//displays list

    protected:

    private:
        node *start;
        int sizel;
};

#endif // LINKEDLISTS_H

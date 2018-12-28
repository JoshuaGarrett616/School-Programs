#include "LinkedLists.h"
#include <iostream>

void LinkedLists::createnode(int val){

    node* hold=new node;//adds new node to list and increases size
    hold->data=val;
    hold->next=this->start;
    this->start=hold;
    this->sizel++;

}

void LinkedLists::display(){

    node* start=this->start;
    for(int i = 0; i < sizel; i++){
        std::cout << start->data << " ";
        start = start->next;
    }//runs through list
}

LinkedLists::~LinkedLists()
{
    //dtor
}

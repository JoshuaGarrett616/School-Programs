#include "BucketLists.h"

void BucketLists::createnode(int val){

    bnode* hold=new bnode;//adds new node and increases size
    hold->data=val;
    hold->next=this->start;
    this->start=hold;
    this->sizel++;

}

void BucketLists::display(){

    bnode* start=this->start;
    for(int i = 0; i < sizel; i++){
        std::cout << start->data << " ";
        start = start->next;
    }//runs through list
}

BucketLists::~BucketLists()
{
    //dtor
}

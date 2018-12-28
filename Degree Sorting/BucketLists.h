#ifndef BUCKETLISTS_H
#define BUCKETLISTS_H
#include <string>
#include <iostream>
#include <cstdlib>

struct bnode{
    int data;
    bnode *next;
};//struct for setting data


class BucketLists
{
    public:

        BucketLists(){
            start = NULL;
            sizel = 0;
        }//constructor for setting data
        ~BucketLists();

        void createnode(int val);//creates a new node
        void display();//displays list
        bool check(){
            if(sizel > 0) return true;
            return false;
        }

    protected:

    private:
        bnode *start;
        int sizel;
};

#endif // BUCKETLISTS_H

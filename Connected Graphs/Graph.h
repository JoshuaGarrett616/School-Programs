#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

const int MAX = 1000;

using namespace std;

class Graph
{
    public:
        Graph(){
            seen.resize(MAX);
	    connect = 1;
        }
        void AddNode(int x, int y, int z);
        void BFS();
        bool connected();
        int components();


    protected:

    private:
        vector<int> vert;
        vector<int> track;
        vector<int> lists[MAX];
        vector<bool> seen;
        int pnum, num, hold, onum, curv;
        int connect;
};

#endif // GRAPH_H

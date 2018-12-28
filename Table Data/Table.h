#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <cstdlib>
#include <cctype>

using namespace std;

class Table
{
    public:
    void Resize(int num);
    void LoadIn(string filename, int inum);
    void Insert(string var, int inum);
    void Update(string var, int inum);
    void Delete(string var, int inum);
    void Select(string var, int inum);
    void Write(int inum);
    bool CheckString(string var);
    bool CheckKey(string num, int inum);
    bool CheckOkey(string var1, string var2, int inum);
    int Shash(string var);
    int Ihash(int var);

    protected:

    private:
    vector<vector<vector<string> > > first;
    vector<vector<vector<string> > > second;
    vector<vector<vector<string> > > third;
    vector<vector<vector<string> > > fourth;
    vector<vector<vector<string> > > fifth;
    vector<vector<string> > head;
    vector<string> whole;
    vector<string> save;
    ifstream write;
    ofstream read;
    string word, push;
};

#endif // TABLE_H

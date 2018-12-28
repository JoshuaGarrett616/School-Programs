#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Functions
{
    public:
        Functions();//loads in language
        void Allocate(string var, int lplace, int place);//allocates words
        void Tracking(string var1, string var2);//traversal
        bool Checking(string var1, string var2);//checks if words are real

        vector<vector<string> > language;//holds language according to size
        vector<string> whole;//holds everything
        vector<vector<vector<int> > > connections;//stores connections
        vector<int> length;//stores lengths

    protected:

    private:
        string filename, word;
        ifstream write;
        stringstream stream;
        int placing1, placing2;//for number value of words we're traversing
};

#endif // FUNCTIONS_H

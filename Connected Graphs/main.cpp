/*Joshua Garrett
Joshua.Garrett@unt.edu
Connected Graph Program
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Graph.h"

using namespace std;

bool checking(string word){
    char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i < 9; i++){
      if(word[0] == nums[i]) return true;
    }

    return false;
}//checks if there is a blank space

int main()
{
    stringstream stream;//stream members
    int check = 0;//various ints for checking
    int x = 0;
    int pnum, num, graphs;
    int hold = 0;
    string word;
	
	cout << "How many graphs would you like to test: ";
	cin >> graphs;//prompt for number of graphs
	
	Graph G[graphs];

    ifstream write;
    ofstream read;

    write.open("data3.txt");
    read.open("out3.txt");

    if(write){
        while(getline(write, word)){

            if(checking(word)){
                istringstream stream(word);
                while(getline(stream, word, ' ')){
                   istringstream(word) >> num;

                   if(num > hold) hold = num;

                   if(check == 0) pnum = num;
                   else G[x].AddNode(pnum, num, hold);//adds a node

                   check++;
                }//delimits space
            }
            else{
                x++;
                hold = 0;
            }
            check = 0;
        }
    }
    x++;


    for(int i = 0; i < x; i++) G[i].BFS();

    for(int i = 0; i < x; i++){
        if(G[i].connected()) read << "Graph " << i+1 << " is connected" << endl;
        else read << "Graph " << i+1 << " is not connected there are " << G[i].components() << " components" << endl;
    }//displays results

    write.close();
    read.close();

    return 0;
}

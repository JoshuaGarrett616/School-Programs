/*Joshua Garrett
Joshua.Garrett@unt.edu
Degree Sorting Program
*/

#include <iostream>
#include "LinkedLists.h"
#include "BucketLists.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000;//maximum amount of nodes
const int SET = 10;//maximum amount of graphs

void BucketSort(int arr[], int sizel, int graph){
    int counter[sizel];//creates buckets
    int j = 0;

    for(int i = 0; i < sizel; i++) counter[i] = 0;//sets elements to 0
    for(int i = 0; i < sizel; i++) (counter[arr[i]])++;//sorts buckets
    for(int i = 0; i < sizel; i++){
        for(; counter[i] > 0; (counter[i])--){
            arr[j++] = i;
        }
    }//reads into array
}//sorts array

bool checking(string word){
    char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for(int i = 0; i < 9; i++){
      if(word[0] == nums[i]) return true;
    }
    return false;
}//checks if there is a blank space

int main()
{
    LinkedLists G[SET][MAX];//creates members for classes
    BucketLists Buckets[SET][MAX];

    vector<vector<int> > nodes;//stores nodes
    nodes.resize(SET);

    for(int i = 0; i < nodes.size(); i++) nodes[i].resize(MAX);

    int j = 0;//multiple ints for counting
    int coun = 0;
    int connect = 0;
    int num;
    int ocoun = 0;
    int place = 0;
    bool check = false;
    string word;
    int arr[MAX];//array for sorting

    stringstream stream;//for altering file
    ifstream write;
    ofstream read;

    write.open("data2.txt");//open file
    read.open("out2.txt");//creates out file

    if(write){
        while(getline(write, word)){

            if(!checking(word)){
                int *oarr = new int[ocoun];//creates array
                for(int i = 0; i < ocoun; i++) oarr[i] = arr[i];//loads in array
                coun++;
                BucketSort(oarr, ocoun, coun);//sorts array
                if(read){
                    read << "Sorted degrees for graph " << coun << " are: ";
                    for(int i = 0; i < ocoun; i++){
                        read << oarr[i] << ",";
                    }
                    read << endl;
                }//reads into out file
                delete [] oarr;//delete array
                ocoun = 0;
            }//checks to see if line has numbers in it

            else{
                istringstream stream(word);
                while(getline(stream, word, ' ')){
                    istringstream(word) >> num;

                    if(place == 0) nodes[coun][ocoun] = num;//stores first num of line
                    else{
                        G[coun][nodes[coun][ocoun]].createnode(num);//stores connections to num
                        connect++;
                    }//stores connections
                    place++;
                }//delim ' '
                Buckets[coun][connect].createnode(nodes[coun][ocoun]);//stores number of connections to node
                arr[ocoun] = connect;
                connect = 0;
                place = 0;
                ocoun++;
            }//runs if not a blank line

        }//while to getline
    }//check if file is open

    int *oarr = new int[ocoun];//following lines does sorting for last graph
    for(int i = 0; i < ocoun; i++) oarr[i] = arr[i];
    coun++;
    BucketSort(oarr, ocoun, coun);

    if(read){
        read << "Sorted degrees for graph " << coun << " are: ";
        for(int i = 0; i < ocoun; i++){
            read << oarr[i] << ",";
        }
        read << endl;
    }//reads in to file

    delete [] oarr;

    read.close();//closes files
    write.close();

    return 0;
}

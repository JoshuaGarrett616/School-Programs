/*Joshua Garrett
Joshua.Garrett@unt.edu
Table Data Program
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <cstdlib>
#include "Table.h"

using namespace std;

struct Directions {
    vector<string> filenames;
    vector<string> tables;
    vector<string> action;
    vector<string> attributes;
    vector<string> table;
};

int main()
{
    int j = 0;//multiple ints for counting
    int coun = 0;
    int num;
    int ocoun = 0;
    bool check = false;    string filename, word;//reading in

    Directions direct;//member for struct
    Table tab;//member for table 1
    stringstream stream;
    ifstream write;

    cout << "Please enter a filename: ";
    cin >> filename;

    write.open(filename.c_str());//open file

    if(write){
        while(getline(write,word)){
            if(word.length() == 0) j++;
            istringstream stream(word);

            if(j == 0){
                while(getline(stream, word, ' ')){
                    if(coun % 2 == 0) direct.filenames.push_back(word);
                    else direct.tables.push_back(word);
                    coun++;
                }//delimit ' '
            }//for first set

            if(j > 0){
                while(getline(stream, word, '(')){
                    istringstream stream(word);
                    while(getline(stream, word, ')')){

                        if(ocoun == 0){
                            if(word == "INSERT" || word == "UPDATE" || word == "DELETE" || word == "SELECT") direct.action.push_back(word);//runs if valid
                            else if(word == "WRITE"){
                                direct.action.push_back(word);
                                break;
                            }//runs if write is hit
                            else ocoun = 3;
                        }//runs when ocoun is 0

                        if(ocoun == 1) direct.attributes.push_back(word);//runs when ocoun is 1

                        if(ocoun == 2){
                            if(word[0] == ','){
                                word.erase(word.begin());
                                for(int i = 0; i < direct.tables.size(); i++){
                                    if(word.compare(direct.tables[i]) == 0){
                                        check = true;
                                        direct.table.push_back(word);
                                        break;
                                    }
                                }
                                if(!check){
                                    direct.action.pop_back();
                                    direct.attributes.pop_back();
                                }//deletes invalid operations
                            }//deletes comma at beginning
                        }//runs for ocoun 2

                        ocoun++;
                        if(ocoun > 2) ocoun = 0;//runs when ocoun has reached limit

                    }//delimit (
                }// delimits )
            }//runs for second set

        }//delimits \n
    }//checks if file is open

	else{
		cout << "FILE DOES NOT EXISTS" << endl;
		return 0;
	}//throws fail state

    write.close();

    tab.Resize(direct.filenames.size());
		
	for(int i = 0; i < direct.filenames.size(); i++) tab.LoadIn(direct.filenames[i], i);

	for(int i = 0; i < direct.action.size(); i++){
		check = false;
		
		if(direct.action[i] == "WRITE") check = true;
		
		if(!check){
			for(int j = 0; j < direct.tables.size(); j++){
				if(direct.tables[j] == direct.table[i]){
					cout << direct.table[i] << " ";
					num = j;
				}
			}
		}	

        cout << direct.action[i] << ": ";
        if(direct.action[i] == "INSERT") tab.Insert(direct.attributes[i], num);
        else if(direct.action[i] == "UPDATE") tab.Update(direct.attributes[i], num);
        else if(direct.action[i] == "DELETE") tab.Delete(direct.attributes[i], num);
        else if(direct.action[i] == "SELECT") tab.Select(direct.attributes[i], num);
		else if(direct.action[i] == "WRITE"){
			for(int j = 0; j < direct.filenames.size(); j++) tab.Write(j);
		}
        else cout << "INVALID" << endl << endl;
			
	}//runs for table 1

    return 0;
}

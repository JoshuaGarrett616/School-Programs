/*Joshua Garrett
Joshua.Garrett@unt.edu
Dictionary Path Program
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Functions.h"

using namespace std;

int main()
{
    string start, goal;//words to find link
	char ans;//answer
	bool loop = true;//for looping
    bool check = false;
    Functions func;
	
	while(loop){
		cout << "Please enter the stating word: ";
		cin >> start;
		cout << "Please enter the goal word: ";
		cin >> goal;

		if(start == goal){
			cout << start << " to " << goal << endl;
			cout << start << " - " << goal << endl;
		}//runs if they're the same word

		else{
			if(start.length() == goal.length()){
				if(func.Checking(start, goal)) func.Tracking(start, goal);//checks and runs traversal
				else cout << "The strings cannot be found in the language" << endl;//runs if words do not exists
			}//runs if they are the same size
			else cout << "The strings are not the same length and therefore cannot be transformed into each other" << endl;//runs if strings aren't the same size
		}//runs if words are different
		
		cout << "Would your like to run another test(Y/N): ";
		cin >> ans;
		
		if(ans == 'y' || ans == 'Y');
		else loop = false;
	}//loops while the user is still using

    return 0;
}

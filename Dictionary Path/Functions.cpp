#include "Functions.h"

Functions::Functions()
{
    unsigned int siz = 0;

    cout << "Computer Science and Engineering" << endl;
    cout << "CSCE 2110" << endl;
    cout << "Project 3" << endl;
	cout << "Joshua Garrett, Joshua.Garrett@unt.edu" << endl << endl;

    cout << "Please enter your language file: ";
    cin >> filename;//prompts for file name

    write.open(filename.c_str());

    cout << "Loading language..." << endl;
    if(write){
        while(getline(write,word)) whole.push_back(word);
    }//loads in if file exists
	else {
		cout << "File cannot be found in directory";
		exit(0);
	}//runs if file does not exists

    for(unsigned int i = 0; i < whole.size(); i++){
        if(whole[i].length() > siz){
            siz = whole[i].length();
            language.resize(siz);
            length.resize(siz);
            connections.resize(siz);
        }//resizes everything
    }//runs through dictionary

    for(unsigned int i = 0; i < whole.size(); i++) language[whole[i].length() - 1].push_back(whole[i]);//allocates language

    for(unsigned int i = 0; i < language.size(); i++) connections[i].resize(language[i].size());//creates connections

    cout << "Creating graph..." << endl;
    for(unsigned int i = 0; i < connections.size(); i++){
        cout << "Loading in words with size of: " << i+1 << endl;
        for(unsigned int j = 0; j < connections[i].size(); j++){
            connections[i][j].resize(connections[i].size());
            Allocate(language[i][j], i, j);
        }//runs connections of certain length
    }//runs through connections
}

void Functions::Allocate(string var, int lplace, int place){
    unsigned int coun = 0;

    for(unsigned int i = 0; i < connections[lplace].size(); i++){
        if(language[lplace][i] == var) connections[lplace][place][i] = 0;
        else{
            coun = 0;
            for(unsigned int j = 0; j < lplace; j++) if(language[lplace][i][j] == var[j]) coun++;
            if(coun == lplace - 1) connections[lplace][place][i] = 1;//connects if chars differ by 1
        }//runs if words are not the same
    }//runs through connections of certain length
}

void Functions::Tracking(string var1, string var2){
	vector<int> vert;
	vector<string> track;
	vector<string> rtrack;
	vector<int> seen;
	bool seeit;
	int curv;
	int counter = 0;
	string order;
	
	for(unsigned int i = 0; i < language[var1.length()].size(); i++){
		if(connections[var1.length()][placing1][i] == 1) vert.push_back(i);//holds vert if ther is a connection
		if(connections[var1.length()][placing1][placing2] == 1){
			cout << var1 << "->"  << var2 << endl;
			return;
		}//runs if it can automatically find a connection
	}
	
	seen.push_back(placing1);
	track.push_back(language[var1.length()][placing1]);
	
	cout << "Tracking using BFS method..." << endl;
	
	while(!vert.empty()){
		curv = vert.front();//sets current vert
		
		vert.erase(vert.begin());//erases current from vector
		
		if(connections[var1.length()][curv][placing2] == 1){
			track.push_back(language[var1.length()][curv]);//hold current
			track.push_back(language[var1.length()][placing2]);//hold final
			order = language[var1.length()][placing2];
			rtrack.push_back(order);
			for(int i = track.size() - 2; i > -1; i--){
				counter = 0;
				for(int j = 0; j < order.length(); j++){
					if(order[j] == track[i][j]) counter++;
				}//check length
				if(counter == order.size() - 1){
					order = track[i];
					rtrack.push_back(order);
				}//filters out tracking
			}//reorder the tracking
			cout << rtrack[rtrack.size() - 1];
			for(int i = rtrack.size() - 2; i > - 1; i--){
				cout << endl;
				cout << "->" << rtrack[i];
			}//displays the traversal
			cout << endl;
			return;
		}//runs if connection has been found
		
		else{
			seeit = true;
			seen.push_back(curv);
			track.push_back(language[var1.length()][curv]);
			
			for(unsigned int i = 0; i < language[var1.length()].size(); i++){
				if(connections[var1.length()][curv][i] == 1){
					for(unsigned int j = 0; j < seen.size(); j++){
						if(seen[j] == i) seeit = false;
					}//checks if vert has been seen
					
					if(!vert.empty()){
						for(unsigned int j  = 0; j < vert.size(); j++){
							if(vert[j] == i) seeit = false;
						}//checks if vert has been seen
					}//runs if vert is empty
					
					if(seeit) vert.push_back(i);
					else seeit = true;
				}//runs if connection is found
			}//runs through language of certain length
		}//runs if connection has not been found
	}
	cout << "A connection could not be found" << endl;
	return;
}

bool Functions::Checking(string var1, string var2){
    bool check = false;
	unsigned int coun = 0;
    cout << "Checking for words in the language..." << endl;

	for(unsigned int i = 0; i < language[var1.length()].size(); i++){
		coun = 0;
		for(unsigned int j = 0; j < language[var1.length()][i].length(); j++){
			if(var1[j] == language[var1.length()][i][j]) coun++;
			else break;
		}//checks characters
		if(coun == var1.length()){
			check = true;
			placing1 = i;
			break;
		}//runs if word is real
	}//runs through words of certain length
	
	if(!check) return false;//throws false if word does not exists
	
	for(unsigned int i = 0; i < language[var1.length()].size(); i ++){
		coun = 0;
		for(unsigned int j = 0; j < language[var1.length()][i].length(); j++){
			if(var2[j] == language[var1.length()][i][j]) coun++;
			else break;
		}//checks characters
		
		if(coun == var1.length()){
			placing2 = i;
			return true;
		}//runs if word is real
	}//runs through words of certain length
	
	return false;
}


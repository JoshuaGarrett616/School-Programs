#include "Table.h"

void Table::Resize(int num){
    first.resize(num);
    second.resize(num);
    third.resize(num);
    fourth.resize(num);
    fifth.resize(num);

    for(int i = 0; i < num; i++){
        first[i].resize(10);
        second[i].resize(10);
        third[i].resize(10);
        fourth[i].resize(10);
        fifth[i].resize(10);
    }

    head.resize(num);
    return;
}//resizes everything

void Table::LoadIn(string filename, int inum){
    write.open(filename.c_str());//open file
    save.push_back(filename);
    int i = 0;//counting
    int num = 0;//creating number
    int check = 0;//others for counting
    int j = 0;
    string key, opush;//

    if(write){
        while(getline(write, word)){
            whole.push_back(word);
        }//delimits \n
    }//if file is open

    else{
        cout << "FILE DOES NOT EXISTS" << endl;
        exit(0);
    }//throws fail state

    write.close();

    for(int i = 0; i < 2; i++) head[inum].push_back(whole[i]);

    for(int i = 2; i < whole.size(); i++){
        num = 0;
        j = 0;
        while(whole[i][j] != '|'){
            push += whole[i][j];
            j++;
        }//reads name

        if(isdigit(push[0])){
            stringstream stream(push);//creates id
            stream >> num;
            first[inum][Ihash(num)].push_back(push);
            push.clear();
            j++;

            while(whole[i][j] != '|'){
                push += whole[i][j];
                j++;
            }//reads name

            second[inum][Ihash(num)].push_back(push);
            push.clear();
            j++;

            while(whole[i][j] != '|'){
                push += whole[i][j];
                j++;
            }//reads type

            third[inum][Ihash(num)].push_back(push);
            push.clear();
            j++;

            while(whole[i][j] != '|'){
                push += whole[i][j];
                j++;
            }//reads strong

            fourth[inum][Ihash(num)].push_back(push);
            push.clear();
            j++;

            while(j < whole[i].length()){
                push += whole[i][j];
                j++;
            }

            fifth[inum][Ihash(num)].push_back(push);
            push.clear();

        }

        else{
            j++;

            while(whole[i][j] != '|'){
                opush += whole[i][j];
                j++;
            }//reads last name

            key = push + opush;
            first[inum][Shash(key)].push_back(push);
            second[inum][Shash(key)].push_back(opush);
            push.clear();
            opush.clear();
            j++;

            while(whole[i][j] != '|'){
                push += whole[i][j];
                j++;
            }//reads age

            third[inum][Shash(key)].push_back(push);
            push.clear();
            j++;

            while(whole[i][j] != '|'){
                push += whole[i][j];
                j++;
            }//reads badges

            fourth[inum][Shash(key)].push_back(push);
            push.clear();
            j++;

            while(j < whole[i].length()){
                push += whole[i][j];
                j++;
            }//reads pokemon

            fifth[inum][Shash(key)].push_back(push);
            push.clear();

        }

    }
    whole.clear();
    return;
}

bool Table::CheckString(string var){
	string str = "||";
	if(var.find(str) != string::npos) return false;//runs if string is nonvalid
	return true;//runs if string is valid
}

bool Table::CheckOkey(string var1, string var2, int inum){
	string key;
	key = var1 + var2;//creates key

    if(first[inum][Shash(key)].size() == 0) return true;//checks if key is valid

	else if(first[inum][Shash(key)].size() == 1){
        if(first[inum][Shash(key)][0] == var1) return false;//if first name is found
        else return true;//throws passing state
    }//checks if key is valid

    else{
        for(int j = 0; j < first[inum][Shash(key)].size(); j++){
            if(first[inum][Shash(key)][j] == var1) return false;//if first name is found
        }//runs through first names
		return true;//throws pass state
    }//runs if chaining has been used
}

bool Table::CheckKey(string num, int inum){
	int x = 0;
	stringstream stream(num);
	stream >> x;
	
    if(first[inum][Ihash(x)].size() == 0){
        return true;
    }//checks if id exists

    else if(first[inum][Ihash(x)].size() == 1){
        if(first[inum][Ihash(x)][0] == num) return false;//runs if id is found
        else return true;//outputs passing state state
    }//also checks if id exists

    else{
        for(int j = 0; j < first[inum][Ihash(x)].size(); j++){
            if(first[inum][Ihash(x)][j] == num) return false;//runs if num is reached
        }//runs through chain
        return true;//outputs passing state
    }//checks if chaining has been used
}

void Table::Insert(string var, int inum){
	if(CheckString(var)){
		int i = 0;
		int num = 0;
		string key, opush;
		int check = 0;
		int j = 0;
		push.clear();

		while(var[i] != '|'){
			push += var[i];
			i++;
		}//reads in id

		if(isdigit(push[0])){
            stringstream stream(push);
            stream >> num;
            if(!CheckKey(push, inum)){
                cout << "FAILED" << endl << endl;
                return;
            }//checks if id exists
            first[inum][Ihash(num)].push_back(push);
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//reads name

            second[inum][Ihash(num)].push_back(push);
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//reads type

            third[inum][Ihash(num)].push_back(push);
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//reads strong

            fourth[inum][Ihash(num)].push_back(push);
            push.clear();
            i++;

            while(i < var.length()){
                push += var[i];
                i++;
            }//reads weak

            fifth[inum][Ihash(num)].push_back(push);
            push.clear();
        }//checks if querie is valid

	else{
        i++;

		while(var[i] != '|'){
			opush += var[i];
			i++;
		}//reads in last name

		if(!CheckOkey(push, opush, inum)){
			cout << "FAILED" << endl << endl;
			push.clear();
			return;
		}//checks if key exists

		key = push + opush;
		first[inum][Shash(key)].push_back(push);
		second[inum][Shash(key)].push_back(opush);
		push.clear();
		i++;

		while(var[i] != '|'){
			push += var[i];
			i++;
		}//reads age

		third[inum][Shash(key)].push_back(push);
		push.clear();
		i++;

		while(var[i] != '|'){
			push += var[i];
			i++;
		}//reads badges

		fourth[inum][Shash(key)].push_back(push);
		push.clear();
		i++;

		while(i < var.length()){
			push += var[i];
			i++;
		}//reads pokemon

		fifth[inum][Shash(key)].push_back(push);
		push.clear();
	}
	}

	else{
		cout << "FAILED" << endl << endl;
		return;
	}//throws back if querie is not valid
	cout << "COMPLETED" << endl << endl;
	return;
}

void Table::Update(string var, int inum){
	if(CheckString(var)){
		int i = 0;
		int num = 0;
		int placer, oplacer;
		bool check = false;
		string opush, key;
		push.clear();
		
		while(var[i] != '|'){
            push += var[i];
            i++;
        }//reads in id

		if(isdigit(push[0])){

            stringstream stream(push);
            stream >> num;

            if(first[inum][Ihash(num)].size() == 0){
                cout << "FAILED" << endl << endl;
                return;
            }//checks if id exists

            else if(first[inum][Ihash(num)].size() == 1){
                if(first[inum][Ihash(num)][0] == push){
                    placer = Ihash(num);
                    oplacer = 0;
                }//runs if id is found
                else{
                    cout << "FAILED" << endl << endl;
                    return;
                }//outputs failing state
            }//also checks if id exists

            else{
                for(int j = 0; j < first[inum][Ihash(num)].size(); j++){
                    if(first[inum][Ihash(num)][j] == push){
                        placer = Ihash(num);
                        oplacer = j;
                        check = true;
                        break;
                    }//runs if num is reached
                }//runs through chain
                if(check == false){
                    cout << "FAILED" << endl << endl;
                    return;
                }//outputs failing state
            }//checks if chaining has been used

            first[inum][placer][oplacer] = push;
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//changes name

            second[inum][placer][oplacer] = push;
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//changes type

            third[inum][placer][oplacer] = push;
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//changes strength

            fourth[inum][placer][oplacer] = push;
            push.clear();
            i++;

            while(i < var.length()){
                push += var[i];
                i++;
            }//changes weakness

            fifth[inum][placer][oplacer] = push;
            push.clear();
		}

		else{
            i++;

            while(var[i] != '|'){
                opush += var[i];
                i++;
            }//reads in last name

            key = push + opush;//creates key

            if(first[inum][Shash(key)].size() == 0){
                cout << "FAILED" << endl << endl;
                push.clear();
                return;
            }//checks if key is valid

            else if(first[inum][Shash(key)].size() == 1){
                if(first[inum][Shash(key)][0] == push){
				placer = Shash(key);
				oplacer = 0;
			}//if first name is found
                else{
                    cout << "FAILED" << endl << endl;
                    push.clear();
                    return;
                }//throws failed state
            }//checks if key is valid

            else{
                for(int j = 0; j < first[inum][Shash(key)].size(); j++){
                    if(first[inum][Shash(key)][j] == push){
                        placer = Shash(key);
                        oplacer = j;
                        check = true;
                        break;
                    }//if first name is found
                }//runs through first names
                if(check == false){
                    cout << "FAILED" << endl << endl;
                    push.clear();
                    return;
                }//throws fail state
            }//runs if chaining has been used

            first[inum][placer][oplacer] = push;
            second[inum][placer][oplacer] = opush;
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//reads age

            third[inum][placer][oplacer] = push;
            push.clear();
            i++;

            while(var[i] != '|'){
                push += var[i];
                i++;
            }//reads badges

            fourth[inum][placer][oplacer] = push;
            push.clear();
            i++;

            while(i < var.length()){
                push += var[i];
                i++;
            }//reads pokemon

            fifth[inum][placer][oplacer] = push;
            push.clear();
        }

    }//runs if querie is valid

	else{
		cout << "FAILED" << endl << endl;
		return;
	}//throws error if invalid

	cout << "COMPLETED" << endl << endl;
	return;
}

void Table::Delete(string var, int inum){
	if(CheckString(var)){
		int i = 0;
		int num = 0;
		int placer, oplacer;
		bool check = false;
		bool ocheck;
		string key, opush;
		push.clear();

		while(var[i] != '|'){
			push += var[i];
			i++;
		}//reads in id

		if(isdigit(push[i])){
            stringstream stream(push);
            stream >> num;

            if(first[inum][Ihash(num)].size() == 0){
                cout << "FAILED" << endl << endl;
                return;
            }//checks if id exists

            else if(first[inum][Ihash(num)].size() == 1){
                if(first[inum][Ihash(num)][0] == push){
                    placer = Ihash(num);
                    oplacer = 0;
                    ocheck = true;
                }//runs if num is reached
                else{
                    cout << "FAILED" << endl << endl;
                    return;
                }//throws failed state
            }//also checks if id exists

            else{
                for(int j = 0; j < first[inum][Ihash(num)].size(); j++){
                    if(first[inum][Ihash(num)][j] == push){
                        placer = Ihash(num);
                        oplacer = j;
                        check = true;
                        break;
                    }//runs if id has been reached
                }//runs through vector space
                if(check == false){
                    cout << "FAILED" << endl << endl;
                    return;
                }
            }//checks if chaining has been used

            if(ocheck){
                first[inum][placer][oplacer] = "";
                second[inum][placer][oplacer] = "";
                third[inum][placer][oplacer] = "";
                fourth[inum][placer][oplacer] = "";
                fifth[inum][placer][oplacer] = "";
                cout << "COMPLETED" << endl << endl;
                return;
            }//empties the vector area

            first[inum][placer].erase(first[inum][placer].begin()+oplacer);//deletes if chaining has been used
            second[inum][placer].erase(second[inum][placer].begin()+oplacer);
            third[inum][placer].erase(third[inum][placer].begin()+oplacer);
            fourth[inum][placer].erase(fourth[inum][placer].begin()+oplacer);
            fifth[inum][placer].erase(fifth[inum][placer].begin()+oplacer);
		}

		else{
            i++;

            while(var[i] != '|'){
                opush += var[i];
                i++;
            }//reads in last name

            key = push + opush;//sets key

            if(first[inum][Shash(key)].size() == 0){
                cout << "FAILED" << endl << endl;
                push.clear();
                return;
            }//checks if key is valid

            else if(first[inum][Shash(key)].size() == 1){
                if(first[inum][Shash(key)][0] == push){
                    placer = Shash(key);
                    oplacer = 0;
                    ocheck = true;
                }//runs if first name is found
                else{
                    cout << "FAILED" << endl << endl;
                    push.clear();
                    return;
                }//throws false state
            }//checks if key is valid

            else{
                for(int j = 0; j < first[inum][Shash(key)].size(); j++){
                    if(first[inum][Shash(key)][j] == push){
                        placer = Shash(key);
                        oplacer = j;
                        check = true;
                        break;
                    }//runs if first name is valid
                }//goes through first names
                if(check == false){
                    cout << "FAILED" << endl << endl;
                    push.clear();
                    return;
                }//throws failed state
            }//runs if chaining is used

            push.clear();

            if(ocheck){
                first[inum][placer][oplacer] = "";
                second[inum][placer][oplacer] = "";
                third[inum][placer][oplacer] = "";
                fourth[inum][placer][oplacer] = "";
                fifth[inum][placer][oplacer] = "";
            }//runs if no chaining is used

            first[inum][placer].erase(first[inum][placer].begin()+oplacer);
            second[inum][placer].erase(second[inum][placer].begin()+oplacer);
            third[inum][placer].erase(third[inum][placer].begin()+oplacer);
            fourth[inum][placer].erase(fourth[inum][placer].begin()+oplacer);
            fifth[inum][placer].erase(fifth[inum][placer].begin()+oplacer);
        }

	}//runs if querie is valid

	else{
		cout << "FAILED" << endl << endl;
		return;
	}//runs if querie is invalid

	cout << "COMPLETED" << endl << endl;
	return;
}

void Table::Select(string var, int inum){
	if(CheckString(var)){
		int i = 0;
		int num = 0;
		int placer, oplacer;
		bool check = false;
		string key, opush;
		bool ocheck;
		push.clear();

		while(var[i] != '|'){
			push += var[i];
			i++;
		}//reads in id
		

		if(isdigit(push[0])){
            stringstream stream(push);
            stream >> num;

            if(first[inum][Ihash(num)].size() == 0){
			cout << "FAILED" << endl << endl;
			return;
			}//checks if id exists

			else if(first[inum][Ihash(num)].size() == 1){
				if(first[inum][Ihash(num)][0] == push){
					placer = Ihash(num);
					oplacer = 0;
				}//runs if id has been reached
				else{
					cout << "FAILED" << endl << endl;
					return;
				}//throws fail state
			}

		else{
			for(int j = 0; j < first[inum][Ihash(num)].size(); j++){
				if(first[inum][Ihash(num)][j] == push){
					placer = Ihash(num);
					oplacer = j;
					check = true;
					break;
				}//runs if id is reached
			}//runs through ids
			if(check == false){
				cout << "FAILED" << endl << endl;
				return;
			}//throws fail state
		}//runs if chaining has been used

		cout << first[inum][placer][oplacer] << "|"  << second[inum][placer][oplacer] << "|" << third[inum][placer][oplacer] << "|" << fourth[inum][placer][oplacer] << "|" << fifth[inum][placer][oplacer] << endl << endl;
		return;
		}

		else{
            i++;

            while(var[i] != '|'){
                opush += var[i];
                i++;
            }//reads last name

            key = push + opush;//creates key

            if(first[inum][Shash(key)].size() == 0){
                cout << "FAILED" << endl << endl;
                push.clear();
                return;
            }//checks if key is valid

            else if(first[inum][Shash(key)].size() == 1){
                if(first[inum][Shash(key)][0] == push){
                    placer = Shash(key);
                    oplacer = 0;
                }//checks if first name is found
                else{
                    cout << "FAILED" << endl << endl;
                    push.clear();
                    return;
                }//throws fail state
            }//checks if key is valid

            else{
                for(int j = 0; j < first[inum][Shash(key)].size(); j++){
                    if(first[inum][Shash(key)][j] == push){
                        placer = Shash(key);
                        oplacer = j;
                        check = true;
                        break;
                    }//checks if first name is found
                }//runs through first names
                if(check == false){
                    cout << "FAILED" << endl << endl;
                    push.clear();
                    return;
                }//throws fail state
            }//runs if chaining is used

            push.clear();
            cout << first[inum][placer][oplacer] << "|"  << second[inum][placer][oplacer] << "|" << third[inum][placer][oplacer] << "|" << fourth[inum][placer][oplacer] << "|" << fifth[inum][placer][oplacer] << endl << endl;
            return;
        }

	}//runs if valid

	else{
		cout << "FAILED" << endl << endl;
		return;
	}//throws failed state

}

int Table::Ihash(int var){
    int mod;

    mod = var%10;

    return mod;
}//returns hash

int Table::Shash(string var){
    int mod = 0;
	int placer;

	for(int i = 0; i < var.length(); i++){
		placer = (int)var[i];
		mod = mod + placer;
	}//does multi string

    mod = mod%10;

    return mod;
}//returns hash

void Table::Write(int inum){
	string filename;
    cout << "Please choose a name for "<< save[inum] << ": ";
	cin >> filename;

	read.open(filename.c_str());

	for(int i = 0; i < head[inum].size(); i++) read << head[inum][i] << endl;

	for(int i = 0; i < first[inum].size(); i++){

        if(first[inum][i].size() > 1){
            for(int j = 0; j < first[inum][i].size(); j++){
				if(first[inum][i][j] != "") read << first[inum][i][j] << "|" << second[inum][i][j] << "|" << third[inum][i][j] << "|" << fourth[inum][i][j] << "|" << fifth[inum][i][j] << endl;
            }
        }

        else if(first[inum][i].size() > 0){
            if(first[inum][i][0] != "") read << first[inum][i][0] << "|" << second[inum][i][0] << "|" << third[inum][i][0] << "|" << fourth[inum][i][0] << "|" << fifth[inum][i][0] << endl;
        }

    }
	read.close();
	cout << "Your data has been stored in: " << filename << endl;
}

#include <fstream>		//for file use
#include <iostream>		//for input and output
#include <string>		//for strings
#include <vector>		//for vectors (dynamic arrays)
#include <ctime>		//to get the time from windows
#include <algorithm>	//for the swap function

using namespace std;

int main(){
	//define variables
	string ReadName;

	//define vector of strings
	vector<string> names;

	//define vector for place numbers
	vector<int> a;

	//create instance of file stream
	fstream List;

	//generate random seed
	srand((int)time(0));

	//access file if possible
	if (List.is_open() == true){
		cout << "\n\nFile could not be accessed!\n\n";
	}
	else
	{
		//open file
		List.open("List.txt");

		//while loop line by line til end of file
		while (getline(List, ReadName)){
			//get line and save in string Name
			names.push_back(ReadName);
		}

		//close file
		List.close();
	}

	//check if list contains any lines
	if (names.size() == 0){
		cout << "\nList doesn't contain any names.\n\n";
	}
	else{
		//create array for places
		for (unsigned int i = 0; i < names.size(); i++){
			a.push_back(i);
		}

		//shuffle place list
		for (unsigned int j = 0; j < names.size(); j++){
			swap(a[j], a[rand() % names.size()]);
		}

		//print the list
		for (int k = 0; k < names.size(); k++){
			cout << endl << k+1 << "  " << names[a[k]] << endl;
		}

	}

	//clear list
	names.clear();

	//to hold console open
	cin.get();

	return 0;
}
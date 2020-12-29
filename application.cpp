//
//  application.cpp
//  <Your header goes here.>
//

#include "AutocompleteList.h"
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

using namespace std;

int main() {
	string filename;
	string search = "";
	char command;

	cout << "Enter filename: ";
	getline(cin, filename);

	AutocompleteList list(filename);
	// get the command
	cout << "Enter s-search or c-creative search: ";
	cin >> command;
	cin.clear();
	cin.ignore();
	// 2 modes
	if(command == 's') {
		cout << "Welcome!\n";
		cout << "Type your search below, press enter for autocomplete ";
		cout << "(# to stop).\n";
		while(true) {
			// get the search prefix
			cout << "Search: ";
			getline(cin, search);
			
			if(search == "#") {
				break;
			}

			AutocompleteList matchList = list.allMatches(search);
			matchList.print();
		}
	}
	if(command == 'c') {
		cout << "Welcome!\n";
		cout << "We are making a line with 5 searches with the highest weight";
		cout << " that's in the that we found. \n";
		string line = "";
		// Search 5 times, it has to be a have a result from search.
		cout << "///////////////////////////////////////////////\n";
		for( int i = 0; i < 5; i++)	{
			cout << "Search #" << i + 1 << ": ";
			getline(cin, search);
			
			if(search == "#") {
				break;
			}
			AutocompleteList matchList = list.allMatches(search);
			if(matchList.getSize() == 0) {
				cout << "We didn't find anything let's try again!\n";
				i--;
				continue;
			}
			cout << "The top suggested is: \n";
			cout << "---> " <<matchList[0].query << endl;
			line += matchList[0].query + " ";
		}
		cout << "///////////////////////////////////////////////\n";
		cout << "The line that we made was: \n-->";
		cout << line << endl;
	}
    return 0;
}

// AutocompleteList.h
//
// <Insert your header here>
//
#pragma once

#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

struct Term {
    string query;
    long long int weight;
    // need this for autograding
    bool operator==(const Term& term) const {
        return (query == term.query && weight == term.weight);
    }
};

//
// AutocompleteList
//
class AutocompleteList {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, terms, to store a list of
    // Terms.  As a result, you must also keep track of the number of elements
    // stored (size).
    //
    Term* terms;  // pointer to a C-style array
    int size;  // number of elements in the array
    string sortType;  // records how list is sorted

    //
    // Private member function.
    // Returns the index of the first word in terms[] that contains the prefix,
    // or -1 if there are no words containing the prefix. This search should be
    // implemented using a variation of the binary search algorithm.
    // Performance requirement: O(logn), n is size.
    //

    int firstIndexOf(string prefix) {
        // TODO: Write this function (optional).
        int low = 0;
        int high = this->size - 1;
        int index = 2147483647;  // set it to a very large number.
        string substr = "";
        
        // get the prefix len to find sub string.
        while (high >= low) {
        	int mid = (low + high) / 2;
        	substr = terms[mid].query.substr(0, prefix.size());

        	if (prefix < substr) {
                high = mid - 1;

            } else if (prefix > substr) {
                low = mid + 1;

            } else {
            	if (mid < index) {
            		index = mid;
            	}
                high = mid - 1;
            }
        }

        // if did not find anything.
        if (index == 2147483647) {
        	//set index back to -1 to know that
        	// it didn't find anything
        	return -1;
        }

        return index;
    }

    //
    // Private member function.
    // Returns the index of the last word in terms[] that contains the prefix,
    // or -1 if there are no words containing the prefix. This search should be
    // implemented using a variation of the binary search algorithm.
    // Performance requirement: O(logn), n is size.
    //
    int lastIndexOf(string prefix) {
        // TODO: Write this function (optional).
        int low = 0;
        int high = this->size - 1;
        int index = -1;  // set it to a very large number.
        // get the prefix len to find sub string.
        while (high >= low) {
        	int mid = (low + high) / 2;
        	if (prefix < terms[mid].query.substr(0, prefix.size())) {
                high = mid - 1;

            } else if (prefix > terms[mid].query.substr(0, prefix.size())) {
                low = mid + 1;

            } else {
            	if (mid < index) {
            		index = mid;
            	}
                low = mid + 1;
            }
        }

        return index;
    }

    //
    // Private member function.
    // This function sorts the terms array by lexicographic order of the query
    // string.
    // Set sortType to "lex".
    // Performance requirement: O(nlogn), n is size.
    //
    static bool myCompLex(Term &term, Term &term2) {
    	return term.query < term2.query;
    }
    static bool myCompWeight(Term &term, Term &term2) {
    	return term.weight > term2.weight;
    }

    void sortByLexOrder() {
        // TODO: Write this function (optional).
        sort(this->terms, this->terms + this->size, myCompLex);
        this->sortType = "lex";
    }
    //
    // Private member function.
    // This function sorts the terms array by decreasing weight order.
    // Set the sortType to "weight".
    // Performance requirement: O(nlogn), n is size.
    //

    void sortByWeightOrder() {
        // TODO: Write this function.
        sort(this->terms, this->terms + this->size, myCompWeight);
        this->sortType = "weight";
    }

 public:
    //
    // default constructor:
    //
    // Called automatically by C++ to create a AutocompleteList.
    // When this is called, intialize terms to a nullptr and set size to 0.
    // Set sortType to "none".
    // Performance requirement: O(1)
    //
    AutocompleteList() {
        // TODO: Write this constructor (required).
        this->terms = NULL;
        this->size = 0;
        this->sortType = "none";
    }

    //
    // a second constructor:
    //
    // Parameter passed in determines size of terms.
    // When this is called, allocate memory for n Terms and
    // set size accordingly.
    // Set sortType to "none".
    // Performance requirement: O(1)
    //
    AutocompleteList(int n) {
        // TODO: Write this constructor (required).
        this->terms = new Term[n];
        this->size = n;
        this->sortType = "none";
    }

    //
    // a third constructor:
    //
    // Parameter passed in is name of file to read in.
    // This constructor will build Autocomplete list from file.
    // Assume file format is:
    // line 1: "<size>"
    // lines 2 thru size+1: "weight query"
    // The list should be sorted lexicographic order by the query string.
    // Set sortType to "lex".
    // Performance requirement: O(nlogn), n is size.
    //
    AutocompleteList(string filename) {
        // TODO: Write this constructor (required).
        ifstream file(filename);

		string theLine;
		string weight;
		long long int w;
		string query;

		// get the first line which contains the size
		getline( file, theLine, '\n');

		// set the size to the size at the top of file
		size = stoi(theLine);
		terms = new Term[size];

		// loop through the file.
		int i = 0;
		getline( file, theLine, '\n');
		while(!file.eof()) {
			// string stream the line.
			stringstream sStream(theLine);

			// get the weight and convert it to int.
			getline(sStream, weight, '\t');
			w = stoll(weight);
			terms[i].weight = w;

			// get the query
			getline(sStream, query, '\t');
			terms[i].query = query;

			getline( file, theLine, '\n');
			i++;
		}

		sortByLexOrder();
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an AutocompleteList that contains
    // a copy of an existing AutocompleteList.  Example: this occurs when
    // passing AutocompleteList as a parameter by value.
    // Performance requirement: O(n), n is size.
    //
    AutocompleteList(const AutocompleteList& other) {
        // TODO: Write this constructor (required).

        this->terms = new Term[other.size];
        this->size = other.size;
		this->sortType = other.sortType;
		
        for(int i = 0; i < other.size; ++i) {
        	this->terms[i] = other.terms[i];
        	
        }
    }

    //
    // copy operator=
    //
    // Called when you assign one AutocompleteList into another,
    // i.e. this = other;
    // Performance requirement: O(n), n is size.
    //
    AutocompleteList& operator=(const AutocompleteList& other) {
        // so starter code compiles
        // TODO: Write this function (required).
        if (this == &other) {
    		return *this;
        }
    	delete[] terms;

    	this->terms = new Term[other.size];
    	this->size = other.size;
		this->sortType = other.sortType;
		
        for(int i = 0; i < other.size; ++i) {
        	this->terms[i] = other.terms[i];
        	
        }

        return *this;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the Term.
    //
    virtual ~AutocompleteList() {
        // TODO: Write this destructor (required).
        if (terms != NULL) {
        	delete[] terms;
        }
    }

    //
    // Public member function.
    // Returns the size of the AutocompleteList.
    // Performance requirement: O(1).
    //
    int getSize() {
        // TODO: Write this function (required).
        return this->size;
    }

    //
    // Public member function.
    // Returns Term element in AutocompleteList.
    // This gives public access to Terms stored in the AutocompleteList.
    // If i is out of bounds, throw an out_of_range error message:
    // "AutocompleteList: i out of bounds"
    // Note:  This public function does not necessarily fit the design of this
    // abstraction but we are having you write it for testing purposes.
    // Performance requirement: O(1).
    //
    Term& operator[](int i) {
        Term result = {};  // TODO: remove this is here so starter code compiles
        // TODO: Write this function (required).
        if (i < 0 || i >= size)
	    {
	      throw out_of_range("AutocompleteList: i out of bounds");
	    }
        return terms[i];  // TODO: update
    }
    // Public member function.
    // Returns an AutocompleteList which stores a list of all Terms that
    // start with the prefix.  The AutocompleteList returned should be sorted
    // in descending order by weight.  Set the returned AutocompleteList's
    // sortType to "weight".
    // If prefix is empty string, return an empty AutocompleteList;
    // If there are no words in the list the start with the prefix, return an
    // empty AutocompleteList.
    // If *this* AutocompleteList's sortType does not equal "lex", then return
    // an empty AutocompleteList.  In other words, allMatches should only be
    // called on an AutocompleteList that is sorted in lexicographic order by
    // the query string.
    // Performance requirement: O(mlogm+logn), n is size and
    // where m is the number of matching terms.
    //
    AutocompleteList allMatches(string prefix) {
        // so starter code compiles
        // TODO: Write this function (required).
        int newSize = numberOfMatches(prefix);
        int indexFound = firstIndexOf(prefix);
        
        if (prefix.empty()) {
        	AutocompleteList x;
        	return x;
        }
        if (newSize == 0) {
        	AutocompleteList x;
        	return x;
        }
        if (this->sortType != "lex") {
        	AutocompleteList x;
        	return x;
        }

        // create a empty list that has the size of how many matches that are in
        // the list currently.
        AutocompleteList matches(newSize);
    	int i = 0;
    	// use i + newSize to get the right query
        while(terms[i+indexFound].query.substr(0, prefix.size()) == prefix) {
        	matches[i] = terms[i+indexFound];
        	i++;
        	if(i+indexFound >= this->size) {
	        	break;
	        }
        }
        
        matches.sortByWeightOrder();
        
        return matches;  // TODO: update
    }
    // Public member function.
    // Returns the number of Terms that start with the given prefix.
    // If prefix is empty, return 0.
    // If *this* AutocompleteList's sortType does not equal "lex",
    // then return 0.
    // Performance requirement: O(logn), n is size.
    //
    int numberOfMatches(string prefix) {
        // TODO: Write this function (required).
        if (prefix.empty()) {
        	return 0;
        }
        if (this->sortType != "lex") {
        	return 0;
        }
        int index = firstIndexOf(prefix);
        int count = 0;
        // if index is a valid index.
        if ( index > 0) {
	        while(terms[index].query.substr(0, prefix.size()) == prefix) {
	        	count++;
	        	index++;
	        	if(index >= this->size) {
	        		break;
	        	}
	        }
        }
        return count;  // TODO: update
    }
    //
    // Public member function.
    // Prints the AutocompleteList.
    // Pad the front of the print with 8 spaces for nicely formatted search:
    // print: "        query, weight".
    // NOTE:  This is also useful for debugging purposes.
    // Performance requirement: O(n), n is size
    //
    void print() {
        // TODO: Write this function (required).
        for(int i = 0; i < this->size; i++) {
        	cout << "        " << this->terms[i].query;
        	cout << ", " << this->terms[i].weight << endl;
        }
    }

    ///////////////////////////
    // FOR TESTING SORTS !
    void sortWeightTest() {
    	sortByWeightOrder();
    }
    void sortLexTest() {
    	sortByLexOrder();
    }
    // FOR TESTING INDEX FIND
    int firstIndex(string prefix) {
    	return firstIndexOf(prefix);
    }
    string getSortType() {
    	return this->sortType;
    }
    /////////////////////////
};

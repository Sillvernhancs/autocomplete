//
//  tests.cpp
//  <Put your header here>
//

#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include "AutocompleteList.h"

using namespace std;

// Tests getSize() on first constructor
bool size_test1() {
    AutocompleteList  list;  // empty list
    if (list.getSize() == 0) {
        return true;
    }
    return false;
}
// Tests getSize() on second constructor
bool size_test2() {
    int n = 10;
    AutocompleteList  list(n);  // empty list
    if (list.getSize() == 10) {
        return true;
    }
    return false;
}
// tests sortByWeightOrder() ability to sort tiny.txt
bool sortWeight() {
	AutocompleteList  list("tiny.txt");
	list.sortWeightTest();
	if(list[0].weight != 20) { return false; }
	if(list[1].weight != 15) { return false; }
	if(list[2].weight != 12) { return false; }
	if(list[3].weight != 10) { return false; }
	if(list[4].weight != 7) { return false; }
	if(list[5].weight != 5) { return false; }
	return true;
}
// tests sortByLexOrder() ability to sort tiny.txt
bool sortLex() {
	AutocompleteList  list("tiny.txt");
	list.sortLexTest();
	if(list[0].query != "buck") { return false; }
	if(list[1].query != "sad") { return false; }
	if(list[2].query != "smog") { return false; }
	if(list[3].query != "spit") { return false; }
	if(list[4].query != "spite") { return false; }
	if(list[5].query != "spy") { return false; }
	return true;
}
// Test getSize() on third constructor using tiny.txt
bool size_test3() {
	AutocompleteList  list("tiny.txt");  
    if (list.getSize() == 6) {
        return true;
    }
    return false;
}
// Test getSize() on copy constructor from first constructor
bool size_test4() {
    AutocompleteList  list;  // empty list
    AutocompleteList A(list);
    if (A.getSize() == 0) {
        return true;
    }
    return false;
}
// Test getSize() on copy constructor from second constructor
bool size_test5() {
    int n = 10;
    AutocompleteList  list(n);  // empty list
    AutocompleteList A(list);
    if (A.getSize() == 10) {
        return true;
    }
    return false;
}
// Test getSize() on copy constructor from third constructor 
// using tiny.txt
bool size_test6() {
    AutocompleteList  list("tiny.txt");  
    AutocompleteList A(list);
    if (A.getSize() == 6) {
        return true;
    }
    return false;
}
// Test getSize() on third constructor using tiny.txt
bool size_test7() {
    AutocompleteList  list("tiny.txt"); 
    if (list.getSize() == 6) {
        return true;
    }
    return false;
}
// Test getSize() on copy operator = from first constructor
bool size_test8() {
    AutocompleteList  list; 
    AutocompleteList A = list;
    if (A.getSize() == 0) {
        return true;
    }
    return false;
}
// Test getSize() on copy operator = from second constructor
bool size_test9() {
    AutocompleteList  list(15); 
    AutocompleteList A = list;
    if (A.getSize() == 15) {
        return true;
    }
    return false;
}
// Test getSize() on copy operator = from third constructor
// using tiny.txt
bool size_test10() {
    AutocompleteList  list("tiny.txt"); 
    AutocompleteList A = list;
    if (A.getSize() == 6) {
        return true;
    }
    return false;
}
// Tests query for 3rd constructor.
// using tiny.txt
bool query_test1() {
	AutocompleteList  list("tiny.txt");
	if(list[0].query != "buck") { return false; }
	if(list[1].query != "sad") { return false; }
	if(list[2].query != "smog") { return false; }
	if(list[3].query != "spit") { return false; }
	if(list[4].query != "spite") { return false; }
	if(list[5].query != "spy") { return false; }
	return true;
}
// Test query for copy constructor from third constructor
// using cities.txt
bool query_test2() {
	AutocompleteList list("cities.txt");
	AutocompleteList A(list);
	for(int i = 0; i < list.getSize(); i++) {
		if(A[i].query != list[i].query) { return false; }
	}
	
	return true;
}
// Test query for copy operator = from third constructor
// using cities.txt
bool query_test3() {
	AutocompleteList list("cities.txt");
	AutocompleteList A = list;
	AutocompleteList B(A);
	for(int i = 0; i < list.getSize(); i++) {
		if(A[i].query != list[i].query) { return false; }
		if(B[i].query != A[i].query) { return false; }
	}
	return true;
}
// Test query for copy operator = from third constructor
// using wiktionary.txt
bool query_test4() {
	AutocompleteList list("wiktionary.txt");
	AutocompleteList A = list;
	AutocompleteList B(A);
	for(int i = 0; i < list.getSize(); i++) {
		if(A[i].query != list[i].query) { return false; }
		if(B[i].query != A[i].query) { return false; }
	}
	return true;
}
// Test weight for copy operator = from third constructor
// using wiktionary.txt
bool weight_test5() {
	AutocompleteList list("wiktionary.txt");
	AutocompleteList A = list;
	AutocompleteList B(A);
	for(int i = 0; i < list.getSize(); i++) {
		if(A[i].weight != list[i].weight) { return false; }
		if(B[i].weight != A[i].weight) { return false; }
	}
	return true;
}
// Test sortType for copy constructor from third constructor
bool sortyType_test_third() {
	AutocompleteList list("cities.txt");
	AutocompleteList A(list);
	if(A.getSortType() != list.getSortType()) {
		return false;
	}
	return true;
}
// Test sortType for copy = operator from third constructor
bool sortyType_test_equal() {
	AutocompleteList list("cities.txt");
	AutocompleteList A = list;
	if(A.getSortType() != list.getSortType()) {
		return false;
	}
	return true;
}
// TEST FIRST INDEX OF FUNCTION
// 3rd constructor must work
bool firs_index_test() {
	AutocompleteList list("tiny.txt");
	if(list.firstIndex("sp") == 3) {
		return true;
	}
	return false;
}
// test numberOfMatches(string prefix)
bool numberOfMatches() {
	AutocompleteList list("tiny.txt");
	if(list.numberOfMatches("sp") == 3) {
		return true;
	}
	return false;
}
// test all Matches query
bool allMatches_q() {
	AutocompleteList list("tiny.txt");
	AutocompleteList A = list.allMatches("sp");
	if (A[0].query != "spite") { return false; }
	if (A[1].query != "spit") { return false; }
	if (A[2].query != "spy") { return false; }
	return true;
}
// test all Matches weight
bool allMatches_w() {
	AutocompleteList list("tiny.txt");
	AutocompleteList A = list.allMatches("sp");
	if(A[0].weight != 20) { return false; }
	if(A[1].weight != 15) { return false; }
	if(A[2].weight != 7) { return false; }
	return true;
}
/////////////////////////////////////////////////////////////
// MAIN 
///////////////////
int main() {
    // TODO:  Write lots of tests.  Here are two very simple examples.
    // You need to write a lot more than this.
    int passed = 0;
    int failed = 0;
    // Run tests
    /////////////////////////////////////////////
    // Get Size tests
    // I nested if commands so I can collapse it
    // for a clarity
    if(true) {
	    if (size_test1()) {
	        passed++;
	    } else {
	        cout << "size_test1 failed" << endl;
	        failed++;
	    }
	    if (size_test2()) {
	        passed++;
	    } else {
	        cout << "size_test2 failed" << endl;
	        failed++;
	    }
	    if (size_test3()) {
	        passed++;
	    } else {
	        cout << "size_test3 failed" << endl;
	        failed++;
	    }
	    if (size_test4()) {
	        passed++;
	    } else {
	        cout << "size_test4 failed" << endl;
	        failed++;
	    }
	    if (size_test5()) {
	        passed++;
	    } else {
	        cout << "size_test5 failed" << endl;
	        failed++;
	    }
	    if (size_test6()) {
	        passed++;
	    } else {
	        cout << "size_test6 failed" << endl;
	        failed++;
	    }
	    if (size_test7()) {
	        passed++;
	    } else {
	        cout << "size_test7 failed" << endl;
	        failed++;
	    }
	    if (size_test8()) {
	        passed++;
	    } else {
	        cout << "size_test8 failed" << endl;
	        failed++;
	    }
	    if (size_test9()) {
	        passed++;
	    } else {
	        cout << "size_test9 failed" << endl;
	        failed++;
	    }
	    if (size_test10()) {
	        passed++;
	    } else {
	        cout << "size_test10 failed" << endl;
	        failed++;
	    }
    }
    // end of Size test
    
    /////////////////////////////////////////////
    // query tests
    if(true) {
	    if (query_test1()) {
	        passed++;
	    } else {
	        cout << "query_test1 failed" << endl;
	        failed++;
	    }
	    if (query_test2()) {
	        passed++;
	    } else {
	        cout << "query_test2 failed" << endl;
	        failed++;
	    }
	    if (query_test3()) {
	        passed++;
	    } else {
	        cout << "query_test3 failed" << endl;
	        failed++;
	    }
	    if (query_test3()) {
	        passed++;
	    } else {
	        cout << "query_test3 failed" << endl;
	        failed++;
	    }
	    if (query_test4()) {
	        passed++;
	    } else {
	        cout << "query_test4 failed" << endl;
	        failed++;
	    }
	    if (weight_test5()) {
	        passed++;
	    } else {
	        cout << "weight_test5() failed" << endl;
	        failed++;
	    }
    }
    /////////////////////////////////////////////
	// SORT TEST
	// CONSTRUCTOR 3 MUST BE WORKING
	if(true) {
	    if (sortWeight()) {
	        passed++;
	    } else {
	        cout << "sortByWeightOrder failed" << endl;
	        failed++;
	    }
	    
	    if (sortLex()) {
	        passed++;
	    } else {
	        cout << "sortByLexOrder failed" << endl;
	        failed++;
	    }
	}
	// end of sort test.
	/////////////////////////////////////////////
	// Sort Type tests
	if(true) {
		if (sortyType_test_third()) {
	        passed++;
	    } else {
	        cout << "sortyType_test_third() failed" << endl;
	        failed++;
	    }
	    if (sortyType_test_equal()) {
	        passed++;
	    } else {
	        cout << "sortyType_test_equal() failed" << endl;
	        failed++;
	    }
		
	}
	/////////////////////////////////////////////
	// FIRST AND LAST INDEX TEST
	if(true) {
		if(firs_index_test()) {
	        passed++;
	    } else {
	        cout << "firs_index_test() failed" << endl;
	        failed++;
	    }
	}	
	// end of first and last indextest
	/////////////////////////////////////////////
	// numberOfMatches
	if(true) {
		if(numberOfMatches()) {
		        passed++;
		} else {
		        cout << "numberOfMatches() failed" << endl;
		        failed++;
		}
		// all matches query
		if(allMatches_q()) {
			passed++;
		} else {
			cout << "allMatches() query failed" << endl;
		        failed++;
		}
		// all matches weight
		if(allMatches_w()) {
			passed++;
		} else {
			cout << "allMatches() weight failed" << endl;
		        failed++;
		}
	}
    /////////////////////////////////////////////
    cout << "\n\n//////////////////\n";
    cout << "Tests passed: " << passed << endl;
    cout << "Tests failed: " << failed << endl;
    cout << "//////////////////\n";
    /////////////////////////////////////////////
    return 0;
}

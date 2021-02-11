// biblereader.cpp
// main function for Project 1

#include "Ref.h"
#include "Verse.h"
#include "Bible.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

main (int argc, char **argv) {
	// Create Bible object to process the raw text file
	Bible webBible("/home/class/csc3004/Bibles/web-complete");
	
	Verse verse;
	int b, c, v;
	LookupResult result;
	cout << "Using Bible from: ";
	webBible.display();
	// Prompt for input: get reference to lookup
	// This is good for testing your classes quickly for the first milestone.
	// TODO: your final program should get input from command line arguments instead.
	cout << "Enter 3 integers for book, chapter and verse to find: " << flush;
	cin >> b >> c >> v;	

	// Create a reference from the numbers
	Ref ref(b, c, v);

	// Use the Bible object to retrieve the verse by reference
	cout << "Looking up reference: ";
	ref.display();
	cout << endl;

	verse = webBible.lookup(ref, result);
	
	cout << "Result status: " << result << endl;
	
	if (result == SUCCESS)
	{
		verse.display();
	}
	
	cout << endl;
}

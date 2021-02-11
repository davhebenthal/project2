// Bible class function definitions
// Computer Science, MVNU

#include "Ref.h"
#include "Verse.h"
#include "Bible.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Bible::Bible() { // Default constructor
	infile = "/home/class/csc3004/Bibles/web-complete";
}

// Constructor – pass bible filename
Bible::Bible(const string s) { infile = s; }

// REQUIRED: lookup finds a given verse in this Bible
const Verse Bible::lookup(Ref ref, LookupResult& status) { 
    // TODO: scan the file to retrieve the line with ref ...
	
	string verseText;
	bool searchDone = false;
	bool verseFound = false;
	
	instream.open(infile.c_str(), ios::in);			//open the file contained in Bible.infile
	instream.unsetf(ios::skipws);
	
	if (ref.book < 1 || ref.book > 66)				//if the book number is not valid (1-66), don't bother searching
	{
		this.status = NO_BOOK;
		searchDone = true;
	}
	
	while (searchDone == false)						//while we still haven't found the appropriate verse
	{
		getline(this.infile, verseText);			//read the next line of text in the Bible object (starting with the first line in the file)
	
		Verse currentVerse = new Verse(verseText);	//create new verse based on that line
	
		if(currentVerse::getRef == ref)				//if this is the verse we're looking for (checked by ref), end the loop, if not, then loop again (check the next verse)
		{
			searchDone = true;
			verseFound = true;
			this.status = SUCCESS;
		}
		
		if(ref.getBook() < currentVerse.getRef().getBook())	//if this funciton has scanned through to a higher book number, then that means the specified chapter must not exist
		{
			searchDone = true;
			this.status = NO_CHAPTER;
		}
		
		if(ref::getChap() < currentVerse.getRef().getChap())
		{
			searchDone = true;
			this.status = NO_VERSE;
		}
		
	}
	
    // update the status variable
	//status = OTHER; // placeholder until retrieval is attempted
	
	// return the verse object
    return(currentVerse);
}

// REQUIRED: Return the reference after the given ref
const Ref next(const Ref ref, LookupResult& status) {};

// OPTIONAL: Return the reference before the given ref
const Ref prev(const Ref ref, LookupResult& status) {};

// Return an error message string to describe status
const string Bible::error(LookupResult status) {};

void Bible::display() {
	cout << "Bible file: " << infile << endl;
}

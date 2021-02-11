// Verse class function definitions
// Computer Science, MVNU

#include "Verse.h"
#include <iostream>
using namespace std;

Verse::Verse() {  	// Default constructor
    verseText = "Uninitialized Verse!";
    verseRef = Ref();
} 

// REQUIRED: Parse constructor - pass verse string from file
Verse::Verse(const string s) {
	// use Ref constructor to create verseRef
	// store the remainder of the string in verseText
	Ref thisVerseRef;
	
	thisVerseRef.book = atoi(Ref::getNextToken(s).c_str());
	thisVerseRef.chap = atoi(Ref::getNextToken(s).s_str());
	thisVerseRef.verse = atoi(Ref::getNextToken(s).s_str());
	
	verseRef = thisVerseRef;
	verseText = s;
}



// REQUIRED: Accessors
string Verse::getVerse() {
	   return this;
}

Ref Verse::getRef() {
	return this.verseRef;
}

// display reference and verse
void Verse::display() {
    verseRef.display();
    cout << " " << verseText;
 }

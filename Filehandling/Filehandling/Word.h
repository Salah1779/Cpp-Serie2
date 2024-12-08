#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Word
{
	string w;
	int count;
	
	
 public :
	
	 Word(string w);
	 int getcount() const;
	 string getword() const;
	 void increment();
	 void tollower();
	 void display()const;
	/* int findWord(vector<Word> words);*/
	 bool operator==(const Word word)const ;


};


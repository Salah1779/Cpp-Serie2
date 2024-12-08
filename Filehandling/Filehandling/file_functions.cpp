
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include "Word.h"

using namespace std;



//function to create a file
static void createFile(string filename) {
	ofstream file(filename);
	file.close();
}

//function to write to a file
static void writeToFile(string filename, string text)
{
	ofstream file(filename);
	file << text;
	file.close();
}

//function to read from a file a line at a time and extract the words
static vector<string> readFromFile(string filename) {
	ifstream file(filename);
	vector<string> words;
	string word;
	while (file >> word) {
		words.push_back(word);
	}
	file.close();
	return words;
}


//function to display the contents of a file
static void displayFileContent(string filename) {
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}


//function to calculate the word number
static int wordCounter(string filename) {
	int count = 0;
	ifstream file(filename);
	string word ;
	while (file >> word) {
		count++;
	}
	file.close();
	return count;
}

//function to find a string and return its count
static int findString(string filename, string text) {
	int count = 0;
	ifstream file(filename);
	string word;
	while (file >> word) {
		if (word == text) {
			count++;
		}
	}
	file.close();
	return count;
}


static string eliminatePonctuation(string text) {
	size_t start = 0, end = text.length();

	
	while (start < end && ispunct(text[start])) {
		start++;
	}

	while (end > start && ispunct(text[end - 1])) {
		end--;
	}

	
	text = text.substr(start, end - start);

	
	transform(text.begin(), text.end(), text.begin(), ::tolower);

	return text;
}

static map<char, vector<Word>> storeFileContentByAlphabet(const string& filename) {
	map<char, vector<Word>> map;
	ifstream file(filename);

	if (file.is_open()) {
		string word;
		while (file >> word) {
			
			//word = eliminatePonctuation(word);
			if (word.empty()) continue;

			
			char key = tolower(word[0]);

			
			Word w(word);
			w.tollower();

			
			if (map.find(key) == map.end()) {
				map[key] = vector<Word>();
			}

			auto& vec = map[key];

			
			auto it = find(vec.begin(), vec.end(), w);
			if (it != vec.end()) {
				it->increment(); 
			}
			else {
				vec.push_back(w); 
			}
		}
		file.close();
	}
	else {
		cerr << "Erreur : impossible d'ouvrir le fichier " << filename << endl;
	}

	return map;
}

static void displayMap(const map<char, vector<Word>>& table) {
	for (const auto& pair : table) {
		cout << pair.first << " : ";
		for (const auto& word : pair.second) {
			word.display();
		}
		cout <<"\n\n";
	}
}


static int findWord(const map<char, vector<Word>>& table, const string& tofind) {
	Word w(tofind);
	w.tollower();

	auto it = find(table.at(tolower(tofind[0])).begin(), table.at(tolower(tofind[0])).end(), w);

	if (it != table.at(tolower(tofind[0])).end()) {
		return it->getcount();
	}

	return 0;
}



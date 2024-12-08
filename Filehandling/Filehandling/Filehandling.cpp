// Filehandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "file_functions.cpp"


int main()
{
   string filename ="FileTest.txt";
  // string input = "salah anas a b zahir";*/

   //createFile(filename);
   //writeToFile(filename, input);
 
   //cout << "File Content : ";
   //displayFileContent(filename);
   //cout << "Word count : " << wordCounter(filename) << endl;

   //vector<string> words = readFromFile(filename);
  // sort(begin(words), end(words));

   //int count = findString(filename, "anas");
   /*(!count) 
	 ? cout << "string not found\n" : 
	   cout << "string found , count : "<< count << endl;*/
  

 /* cout << "\nSorted text :";
   for (const string word : words)
   {
	   cout << word + " ";
   }
   cout << "\n";*/

   map<char, vector<Word>> Dictionnary;

   Dictionnary = storeFileContentByAlphabet(filename);
   displayMap(Dictionnary);
  

   int countWord=findWord(Dictionnary, "question");

   (!countWord)?
	   cout<<"word not found\n"
	   : cout<<"word found , count : "<<countWord<<endl;

   

   return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

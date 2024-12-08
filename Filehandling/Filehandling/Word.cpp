#include "Word.h"

Word::Word(string w)
{
    this->w = w;
    this->count = 1;
}

int Word::getcount() const 
{
    return count;
}

string Word::getword() const 
{
    return w;
}

void Word::increment()
{
    count++;
}

void Word::tollower()
{
    for (int i=0; i<w.length(); i++)
    {
       w[i] = tolower(w[i]);
    }
   
}


void Word::display() const
{
    cout <<"("<< w << " , " << count << ") ";
}

bool Word::operator==(const Word word) const
{
    return w==word.w;
}

//find a word using built in method find 

//int Word::findWord(vector<Word> words) const
//{
//    auto it = find(words.begin(), words.end(), w);
//
//   
//}

//Nick Widmer
//lab 2 

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "WordList.hpp"

using std::string;

//class wordOccurence

WordOccurrence::WordOccurrence(const string& word, int num){
    word_ = word;
    num_ = num;

}

bool WordOccurrence::matchWord(const string& word){ //returns true if words are the same
    if(word == word_){
        return true;
    }else{
        return false;
    }
}

void WordOccurrence::increment(){ //increments # of occurrences
    ++num_;
}

string WordOccurrence::getWord() const{ //returns the current word
    return word_;
}

int WordOccurrence::getNum() const{ //returns the number of occurrences
    return num_;
}


//classWordList


//copy constructor
WordList::WordList(const WordList& copy){
    size_ = copy.size_;
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i < size_; ++i){
        wordArray_[i] = copy.wordArray_[i];
        
    }
}

//assignment overload
WordList& WordList::operator=(WordList rhs){
      if (this == &rhs){
        return *this;                                    //protection against these cases
      }
      if (wordArray_ != nullptr){
        delete[] wordArray_;
      }
      size_ = rhs.size_;
      wordArray_ = new WordOccurrence[size_];

      for (int i = 0; i < size_; ++i){
        wordArray_[i] = rhs.wordArray_[i];
      }
      return *this;
    
}

//destructor
WordList::~WordList(){
    delete [] wordArray_;
}


bool equal(const WordList& lhs, const WordList& rhs){
    if(lhs.size_ != rhs.size_){
        return false;
    }
    for(int i = 0; i < lhs.size_; ++i){ //comparing the wordArray to both arguments
    if(lhs.wordArray_[i].getWord() != rhs.wordArray_[i].getWord()){
        return false;
    }
    if(lhs.wordArray_[i].getNum() != rhs.wordArray_[i].getNum()){ //comparing occurrences of the num
        return false;
    }
 }
return true;
}


void WordList::print(){
    std::cout << "Word Count Assignment" << std::endl;
    std::cout << "Word" << "\t" << "Occurrence" << std::endl;
    std::cout << "-------------------" << std::endl;
   
    std::sort(wordArray_, wordArray_ + size_);                  //using sort function to get order. Created < operator in WordOccurrence
    for(int i = 0; i < size_; ++i){
      std::cout << wordArray_[i].getWord() << "\t" << wordArray_[i].getNum() << std::endl;
      }
}


void WordList::addWord(const string& word){
    for(int i = 0; i < size_; ++i){ //iterate through the list
    if(wordArray_[i].matchWord(word)){
        wordArray_[i].increment();
        return;
    }
    }
     WordOccurrence* tmp = wordArray_;
     wordArray_ = new WordOccurrence[size_ + 1];
     for(int i = 0; i < size_; ++i){
         wordArray_[i] = tmp[i]; //put values from tmp back into wordArray
     }
     delete [] tmp;        //delete tmp array and add word to end
     wordArray_[size_] = WordOccurrence(word,1);
     size_++; 
}

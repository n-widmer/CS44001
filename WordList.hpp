//Nick Widmer
//lab2

#include <iostream>
#include <string>
#include <fstream>
#ifndef WordList_HPP
using std::string;
using std::endl;


class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const; 
    int getNum() const;
    bool operator<(const WordOccurrence& temp){
        return temp.num_ > num_;
    }

private:
    string word_;
    int num_;
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList(){
    wordArray_ = new WordOccurrence[size_];
    int size_ = 0;
    }

    ~WordList();
    WordList(const WordList&);
    WordList& operator=(WordList);

    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &);
    void print();

    // Only use for testing purposes
    WordOccurrence * getWords() const {return wordArray_;};
    int getSize() const {return size_;};
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

#endif
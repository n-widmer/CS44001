

// vector and list algorithms
// nick widmer
// lab4

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;

// reading a list from a fileName
void readRoster(list<list<string>>& roster, string fileName);  

// printing a list out
void printRoster(const list<list<string>>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ 
      cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" 
      << endl; exit(1);
   }

   list<list<string>> roster;
   for(int i=1; i < argc; ++i){
      readRoster(roster, argv[i]);  
   }
   printRoster(roster);
}

// reading in a file of names into a list of strings
void readRoster(list<list<string>>& roster, string fileName){
   ifstream course(fileName);                                   // opneing the file to read from
   string first, last;
   string courseName = fileName;
   bool check;
   courseName.erase(courseName.begin()+3, courseName.end());    // extracting first 3 characters from coursename
   while(course >> first >> last){                              //read first and last name from students in file 
      string str= first + ' ' + last;
      check = true;
      for(auto &list : roster){ 
        if(list.front() == str){                                // if a student already exists in roster it adds current courses to their record
          list.push_back(courseName);                           //
          check = false;
          break;
          }
        }
        if(check){
          list<string> newStudent;                              // if no matching student is found it creates a new student and adds it to roster
          newStudent.push_back(str);                            //
          newStudent.push_back(courseName);
          roster.push_back(newStudent);       
         }
       } 
   course.close();
}

// printing a list out
void printRoster(const list<list<string>>& roster){
  cout << "\nStudents and Course List\n\n";
  for(auto it = roster.begin(); it != roster.end(); ++it){  //iterate through entire roster
  for(auto& str : *it) cout << str << " "; // dereference and print out first and last names
  cout << endl;
  }
  cout << endl;
}
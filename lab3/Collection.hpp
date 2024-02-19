//Nick Widmer
//lab 3
#ifndef Collection_H_
#define Collection_H_
#include <iostream>
#include "list.hpp"



//definitions to avoid problems (specialized template from Nesterenko)
//forward class definition
template <typename T>
class Collection;

//forward function definition  
template <typename T>
bool equal(const Collection<T>&, const Collection<T>&);

template<typename T>
class Collection{
    public:
    Collection();
        void add(const T& item);
        void remove(const T& item);
        T last();
        void print();
        friend bool equal <T>(const Collection&, const Collection&);

    private:
        node<T> *head;
};

template<typename T>
Collection<T>::Collection(){
    head = nullptr; //creating an empty list
}

template<typename T>
void Collection<T>::add(const T& item){
    node<T> *newnode; //creating a pointer to newnode
    newnode = new node<T>; //setting that pointer to a new node
    newnode->setData(item); //putting the item into that node
    newnode->setNext(head);
    head = newnode;

}
template<typename T>
void Collection<T>::remove(const T& item){
    //check to see if the list is empty
    if(head == nullptr){
        std::cout << "the list is empty" << std::endl;
        return;
    }
    //check to see if there is only a head in the list
    while(head != nullptr && head->getData() == item){
        node<T> *temp = head;
        head = head->getNext();
        delete temp;
    }
    //traversing an entire list to see all occurrences and deleting
    node<T> *current = head;
    while(current != nullptr && current->getNext() != nullptr){
        if(current->getNext()->getData() == item){
            node<T> *temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
        }else{
            current = current->getNext();
        }
    }


}

template<typename T>
bool equal(const Collection<T>& l1, const Collection<T>& l2){
    node<T> *list1 = l1.head;
    node<T> *list2 = l2.head;

    while(list1 != nullptr && list2 != nullptr){ //aking sure the lists are not empty
        if(list1->getData() != list2->getData()){ //seeing if the data of both lists are the same
            return false;
        }
        list1 = list1->getNext(); //getting next node in each list
        list2 = list2->getNext();

    }
    return true;
}


template<typename T>
T Collection<T>::last(){
    return head->getData();
}

template<typename T>
void Collection<T>::print(){
    node<T> *current = head;
    while(current != nullptr){
        std::cout << current->getData() << " "; //print data pf current node
        current = current->getNext(); //move current to the next node
    }
    std::cout << std::endl; //newline for better formatting
}



#endif
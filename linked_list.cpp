#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
        first = NULL;
        current = NULL;
        last = NULL;
}

template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
        current = first;
        while (current != NULL) {
                first = first->next;
                delete current;
                current = first;
        }
        current = last = first = NULL;
}
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList) {
        //Fill in the copy constructor
        ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
        temp = originalList.first;
        while(temp != nullptr) {
            InsertRear(temp->data);
            temp = temp->next;
        }
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value) {
    
    if(value == first->data && first->next == nullptr){
        value = first->data;
        delete first;
        current = nullptr;
        first = nullptr;
        last = nullptr;
    }
    else if(value == first->data){
        value = first->data;
        current = first;
        first = current->next;
        delete current;
    }
    else if(value == last->data) {
        value = last->data;
        current = first;
        while(current->next != last) {
            current = current->next;
        }
      
        delete last;
        last = current;
        current->next = nullptr;
    }
    else{
        current = first;
        while(current->next != nullptr && current->next->data != value) {
          current = current->next;
        }
        if(current == nullptr) {
            return false;
        }
        else {
            ListNode<NODETYPE>*temp = new ListNode<NODETYPE>;
            temp = current->next;
            value = temp->data;
             current->next = temp->next;
            delete temp;
        }
   }
   return true;

    //if the value equals the first data and it is the last node in the linked last
        //set value to first data
        //remove the node and set current last and first to nullptr
    //else if the value equals the first data
        //set value to first data
        //set current to first
        //move first to the next node
        //delete current
    //else if the value equals the last data
        //set value to last data
        //set current to first
        //use a while loop to set current to one before last
        //delete last
        //set last to current
        //set current next to nullptr
    //else
        //set current to first
        //use a while loop to check for current does not equal null and current next data does not equal value
        //if current equals null
        //return false
        //else
            //set temp pointer the node you will be deleting
            //set value to the temp data
            //set current next to temp next
            //delete temp
    //return true
}

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value){
    ListNode<NODETYPE>* temp = new ListNode<NODETYPE>;
    temp->data = value;
    
    if(temp != nullptr) {
        if(first == nullptr) {
            InsertFront(value);
        }
   
        else if(temp->data < first->data){
            InsertFront(value);
        }
   
        else if(temp->data > last->data) {
            InsertRear(value);
        }else{
            current = first;
            while(current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
        
            temp->next = current->next;
            current->next = temp;
      
        }
    
    }else{
       return false;
    }
    return true;


    //Declare a new node
    //New the node
    //if the new node is not nullptr continue with the insert in order
    //else return false
    
    //if this is the first node you are inserting the linked list
        //call either insertFront or insertRear
    //else if the new node data is less than first data
        //call insertFront
    //else if the new node data is greater than last data
        //call insertRear
    //else
        //set current to first
        //use a while loop to set current to the node before where you want to insert the new node
        //connect the new node next to current next
        //connect current next to the new node
    
    //return true
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
    //cout<<"0\n";
    current = new ListNode<NODETYPE>;
    
    if(current == nullptr) {
      return false;
    }
    else{
        //cout << "1.\n";
        current->data = value;
        //cout << "2. "<<current->data<<" data is printed\n";
        if(first == nullptr) {
            //cout << "3.\n";
            first = current;
            last = current;
            //cout << "4.\n";
            current->next = nullptr;
        }else{
            //cout << "5.\n";
            current->next = first;
            first = current;
            //cout << "6.\n";
        }
        //cout << "7.\n";
    }
    //cout << "8.Shit \n";
    return true;
       
    //New a new node with current
    //if current equal nullptr return false
    //else
        //set current data to value
        //if this is the first node in the linked list
            //set first to current
            //set last to current
            //set current next to nullptr
        //else
            //set current next to first
            //set first to current
    //return true;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
    
    ListNode<NODETYPE>* current = new ListNode<NODETYPE>;
    
    if(current == nullptr) {
        return false;
    }else{
        current->data = value;
        if(first == nullptr) {
            first = current;
            last = current;
            current->next = nullptr;
        }else{
            last->next = current;
            current->next = nullptr;
            last = current;
        }
    }    
    return true;
    //New a new node with current
    //if current equal nullptr return false
    //else
        //set current data to value
        //if this is the first node in the linked list
            //set first to current
            //set last to current
            //set current next to nullptr
        //else
            //set last next to current
            //set current next to nullptr
            //set last to current
    //return true;
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
        return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE &value) {
    
     
    if(first == nullptr) {
      return false;
    }else {
        current = first;
        while(current != nullptr && current->data != value) {
            current = current->next;
        }
        if(current == nullptr){
            return false;
        }
        else{
            value=current->data;
            return true;
        }
       
     }  

        //if the list is empty return false
        //else
            //set current to first
            //use a while loop to check not for nullptr and not for current data not equal to the value
            //if current equals null not found
                //return false
            //else
                //return true
}


template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
    
   if(first != nullptr){
        current = first;
        while(current != nullptr) { 
          cout <<current->data << endl;
          current = current->next;
        }

    //if not empty
        //set current to first
        //use a while loop to check for not equal to nullptr
            //print out data
            //move current over

    }
}
#endif


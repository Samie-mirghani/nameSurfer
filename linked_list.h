/// The specification of a template class of a linked list of type NODETYPE.                                              
#ifndef linked_list_H
#define linked_list_H
#include "single_node.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
class linked_list{

	public:
		linked_list();
		~linked_list();
		linked_list(linked_list<NODETYPE> &originalList);
		bool InsertRear(NODETYPE value);
		bool InsertFront(NODETYPE value);
		bool InsertInOrder(NODETYPE value);
		bool Remove(NODETYPE & value);
		bool Search(NODETYPE &value);
		bool IsEmpty() const;
		void PrintAll();
	private:
		ListNode<NODETYPE> *first;
		ListNode<NODETYPE> *current;
		ListNode<NODETYPE> *last;
		string name;
		int rank [11];

};

#include "linked_list.cpp"
#endif

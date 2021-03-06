// CLC Linked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct item {
	int data;
	item *next;
};

class LinkedList {
private:
	item * head, *tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void createNode(int value) {
		// create a new list item using the passed value
		item *n = new item;
		n->data = value;
		n->next = NULL;

		// if head is null, tail must equal head: instantiate new list
		if (head == NULL) {
			head = n;
			tail = n;
			n = NULL;
		}

		// else, add to end and update tail
		else {
			tail->next = n;
			tail = n;
		}
	}
	void display()
	{
		// create an item to move through the list, head to tail
		item *pos = new item;
		pos = head;

		// while the current node exists, output the item's data and increment the node position.
		while (pos != NULL)
		{
			cout << pos->data << "\t" << endl;
			pos = pos->next;
		}
	}
	void copyList(LinkedList list) {
		LinkedList *listP = new LinkedList;
		*listP = list;
		// create an item to move through the passed-in list, head to tail
		item *pos = new item;
		pos = listP->head;

		// while the current node exists, copy the item into the list and update position.
		while (pos != NULL) {
			this->createNode(pos->data);
			pos = pos->next;
		}
	}

	void reverse()
	{
		item * cItem, * nItem, * pItem, * temp;

		// the current item (NULL->[ head ]->next->...->tail->NULL)
		cItem = head;

		// the next item (NULL->head->[ next ]->...->tail->NULL)
		nItem = head->next;

		// the previous item ([ NULL ]->head->next->...->tail->NULL)
		pItem = NULL;

		// while there is another item
		while (nItem != tail) {
		
			// set the new next for the current item (c->n) => (p<-c) Status: (p<-c n->?)
			cItem->next = pItem;

			// move the previous item to the current item (p = c) Status: (?<-c|p n->?)
			pItem = cItem;
			
			// move the current item to the next item (c = n) Status: (?<-p c|n->?)
			cItem = nItem;

			// move the next item to the next's next (n = n->?) Status: (?<-p c->n->?)
			nItem = nItem->next;
		}
		// flip the last two (?<-p c->n->?) => (?<-p<-c<-n)
		cItem->next = pItem;
		nItem->next = cItem;

		// juggle to swap head and tail
		tail->next = cItem;
		temp = tail;
		tail = head;
		head = temp;

	}

};


int main()
{
	LinkedList listA, listB;

	listA.createNode(1);
	listA.createNode(2);
	listA.createNode(3);
	listA.createNode(4);
	listA.createNode(50);
	listA.display();
	listB.copyList(listA);
	listB.display();
	listB.reverse();
	listB.display();
}
#pragma once
#include <list>


typedef struct SinglyLinkedNode
{
	struct SinglyLinkedNode* mNext;
}SinglyLinkedNode;

typedef struct DoublyLinkedNode
{
	struct DoublyLinkedNode* mNext;
	struct DoublyLinkedNode* mPrevious;
}DoublyLinkedNode;


class Questions_3_2
{
public: 
	void SwapSinglyLinkedList(SinglyLinkedNode* pNode)
	{ 
		SinglyLinkedNode* grandson = pNode->mNext->mNext;
		pNode->mNext = pNode;
		pNode = grandson;

	}


	void SwapDoublyLinkedList(DoublyLinkedNode* pNode)
	{
		DoublyLinkedNode* tail = pNode->mNext->mNext;
		DoublyLinkedNode* head = pNode->mPrevious;

		head->mNext = pNode->mNext;
		head->mNext->mNext = pNode;
		head->mNext->mPrevious = head;

		pNode->mNext = tail;
		pNode->mPrevious = head->mNext;
		tail->mPrevious = pNode;
	}

};
#include "DoubleList.h"
#include <iostream>
namespace DoubleListSpace {

	listNode *listHead = nullptr;
	listNode *listTail = nullptr;


	void addHead(int data){
		listNode *newNode = new listNode();
		newNode->data = data;




		//�ƹ��͵� ������ tail�� ����Ű�� ���� Ȯ��
		if (listHead == nullptr) {
			listTail = newNode;
		}
		else {
			listHead->prevNode = newNode;
		}

		newNode->nextNode = listHead;
		listHead = newNode;



	}

	void addTail(int data){
		


		listNode *newNode = new listNode();
		newNode->data = data;




		//�ƹ��͵� ������ tail�� ����Ű�� ���� Ȯ��
		if (listTail == nullptr) {
			listHead = newNode;
		}
		else {
			listTail->nextNode = newNode;
		}

		newNode->prevNode = listTail;
		listTail = newNode;

	}

	void deleteHead(){
		if (listHead == nullptr) {
			return;
		}



		listNode *tmpNode = listHead->nextNode;
		delete listHead;
		listHead = tmpNode;


		if (listHead == nullptr) {
			listTail = nullptr;
		}
		else {
			listHead->prevNode = nullptr;
		}
	}

	void deleteTail(){
	

		if (listTail == nullptr) {
			return;
		}



		listNode *tmpNode = listTail->prevNode;
		delete listTail;
		listTail = tmpNode;


		if (listTail == nullptr) {
			listHead = nullptr;
		}
		else {
			listTail->nextNode = nullptr;
		}

	}

	void printInformation(){
		std::cout << "doublie list node(head����) : ";


		listNode *searchNode = listHead;

		while (searchNode != nullptr) {

			std::cout << searchNode->data << "  ";
			searchNode = searchNode->nextNode;

		}


		std::cout << "\n";
	}


}
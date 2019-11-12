#include "DoubleList.h"
#include <iostream>
namespace DoubleList {

	DoubleListNode *listHead = {};
	DoubleListNode *listTail = {};


	void AddHead(const int& data){
		DoubleListNode *newNode = new DoubleListNode();
		newNode->data = data;

		//�ƹ��͵� ������ tail�� ����Ű�� �����ε� ����
		if (listHead == nullptr) {
			listTail = newNode;
		}
		else {
			listHead->dpPrevNode = newNode;
		}

		newNode->dpNextNode = listHead;
		listHead = newNode;



	}

	void AddTail(const int& data){
		
		DoubleListNode *newNode = new DoubleListNode();
		newNode->data = data;


		//�ƹ��͵� ������ Head�� ����Ű�� �����ε� ����
		if (listTail == nullptr) {
			listHead = newNode;
		}
		else {
			listTail->dpNextNode = newNode;
		}

		newNode->dpPrevNode = listTail;
		listTail = newNode;

	}

	void DeleteHead(){
		if (listHead == nullptr) {
			return;
		}



		DoubleListNode *tmpNode = listHead->dpNextNode;
		delete listHead;
		listHead = tmpNode;

		
		if (listHead == nullptr) {
			listTail = {};
		}
		else {
			listHead->dpPrevNode = {};
		}
	}

	void DeleteTail(){
	

		if (listTail == nullptr) {
			return;
		}



		DoubleListNode *tmpNode = listTail->dpPrevNode;
		delete listTail;
		listTail = tmpNode;


		if (listTail == nullptr) {
			listHead = nullptr;
		}
		else {
			listTail->dpNextNode = {};
		}

	}

	void PrintInformation(){
		std::cout << "doublie list node(head����) : ";


		DoubleListNode *searchNode = listHead;

		while (searchNode != nullptr) {

			std::cout << searchNode->data << "  ";
			searchNode = searchNode->dpNextNode;

		}


		std::cout << "\n";
	}


}
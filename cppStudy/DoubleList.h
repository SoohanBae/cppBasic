namespace DoubleListSpace {


	// ����ü�� �������� �Ľ�Į
	struct listNode {
		int data;
		// Raw Pointer�� �밡��ü��
		// Raw Pointer
		//   1. ������ �ѱ� �� ����� �ٸ���. &
		//   2. ������ 
		listNode *nextNode = nullptr;
		listNode *prevNode = nullptr;
	};




	// �Լ��� �Ľ�Į ü
	void addHead(int data);
	void addTail(int data);
	void deleteHead();
	void deleteTail();

	void printInformation();
}
namespace DoubleList {


	// ����ü�� �������� �Ľ�Į
	struct DoubleListNode {
		int data = {};
		// Raw Pointer�� �밡��ü��
		// Raw Pointer
		//   1. ������ �ѱ� �� ����� �ٸ���. &
		//   2. ������ 
		DoubleListNode *dpNextNode = {};
		DoubleListNode *dpPrevNode = {};
	};




	// �Լ��� �Ľ�Į ü
	void AddHead(const int& data);
	void AddTail(const int& data);
	void DeleteHead();
	void DeleteTail();

	void PrintInformation();
}
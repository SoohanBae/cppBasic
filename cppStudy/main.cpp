
#include "Stack.h"
#include "DoubleList.h"

#include "Vector.h"
#include "List.h"
#include "VectorManager.h" //���ø��� ����Ϸ��� cpp�� import �ؾ� �Ѵ�?


#include <iostream>
#include <memory>





int main() 
{
	//List ����

	/*{
		std::unique_ptr<vectorListSpace::Base<int>> test = std::make_unique<vectorListSpace::List<int>>();


		test->AddData(1);
		test->AddData(2);


		test->PrintData();

		std::cout << "ListSize : " << test->GetSize() << std::endl;



		if (!test->AddData(2)) {
			std::cout << "�Է� ����\n";
		}
		test->DeleteData(2);


		if (!test->DeleteData(2)) {
			std::cout << "���� ����\n";
		}

		test->PrintData();

		std::cout << "ListSize : " << test->GetSize() << std::endl;


		test->AddData(3);

		test->AddData(5);

		test->PrintData();

		std::cout << "ListSize : " << test->GetSize() << std::endl;

	}*/


	////Vector ����
	//{
	//	std::unique_ptr<vectorListSpace::Base> test2 = std::make_unique<vectorListSpace::Vector>();


	//	test2->AddData(1);
	//	test2->AddData(2);
	//	test2->AddData(3);

	//	test2->PrintData();

	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;



	//	if (!test2->AddData(2)) {
	//		std::cout << "�Է� ����\n";
	//	}
	//	test2->DeleteData(2);

	//	

	//	if (!test2->DeleteData(1)) {
	//		std::cout << "���� ����\n";
	//	}

	//	test2->PrintData();

	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;


	//	test2->AddData(2);
	//	
	//	test2->AddData(4);
	//	test2->AddData(5);
	//	test2->AddData(6);
	//	test2->AddData(7);
	//	test2->AddData(8);
	//	test2->AddData(9);
	//	test2->AddData(10);
	//	test2->PrintData();
	//	test2->AddData(11);

	//	test2->PrintData();
	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;

	//	test2->DeleteData(11);
	//	test2->DeleteData(10);
	//	test2->DeleteData(9);

	//	test2->PrintData();
	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;
	//	
	//}



	////stack ����
	//{
	//	StackSpace::stackPop();
	//	StackSpace::stackPush(1);
	//	StackSpace::stackPush(2);
	//	StackSpace::stackPush(4);
	//	std::cout << "���� ������ : "<< StackSpace::getSize() << std::endl;
	//	StackSpace::printInformation();

	//	StackSpace::stackPop();
	//	StackSpace::printInformation();

	//	StackSpace::stackPush(7);
	//	StackSpace::stackPush(10);

	//	StackSpace::printInformation();

	//}


	////list ����
	//{
	//	DoubleListSpace::deleteHead();
	//	DoubleListSpace::addHead(1);
	//	DoubleListSpace::addHead(2);
	//	DoubleListSpace::addHead(4);
	//	DoubleListSpace::printInformation();

	//	DoubleListSpace::deleteTail();
	//	DoubleListSpace::printInformation();

	//	DoubleListSpace::addHead(7);
	//	DoubleListSpace::addTail(10);

	//	DoubleListSpace::printInformation();

	//	DoubleListSpace::deleteHead();
	//	DoubleListSpace::printInformation();

	//}




	////Manager ����
	{
		// namespace naming snake �ҹ���_
		VectorList::Base<int> *t1 = new VectorList::List<int>();
		VectorList::Base<int> *t2 = new VectorList::List<int>();
		VectorList::Base<int> *t3 = new VectorList::List<int>();
		VectorList::Base<int> *t4 = new VectorList::List<int>();
		VectorList::Base<int> *t5 = new VectorList::List<int>();
		VectorList::Base<int> *t6 = new VectorList::List<int>();

		std::unique_ptr<Manager::DataManager<int>> d1 = std::make_unique<Manager::DataManager<int>>();

		

		d1->NewVectorList(t1);
		d1->NewVectorList(t2);
		d1->NewVectorList(t3);
		d1->NewVectorList(t4);
		d1->NewVectorList(t5);
		d1->NewVectorList(t6);

		d1->AddData(1, 1);
		d1->AddData(1, 2);
		d1->AddData(1, 3);
		d1->AddData(2, 1);
		d1->AddData(3, 2);
		d1->AddData(4, 1);
		d1->AddData(5, 1);
		d1->AddData(0, 1);
		d1->AddData(3, 1);
		d1->AddData(7, 1);

		std::cout << "size : " << d1->GetSize() << " \n";
		d1->PrintData();

		d1->DeleteData(1, 2);
		d1->DeleteData(1, 3);

		std::cout << "size : " << d1->GetSize() << " \n";
		d1->PrintData();



	}



	return 0;

}
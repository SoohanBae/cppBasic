#include "Base.hpp"
#include <iostream>
#include <algorithm>

namespace VectorList {

	constexpr int DATA_SIZE = 10;
	constexpr int NOT_FOUND_INDEX = -1;



	template <typename ElementType>
	class Vector : public Base<ElementType> {



	public:


		Vector();
		~Vector();


		bool AddData(const ElementType& data);
		bool DeleteData(const ElementType& data);
		int GetSize() const;

		void PrintData() const;
		virtual Vector<ElementType>& operator=(Vector<ElementType>& right);

		void Copy(Base<ElementType>* right);

	private:
		
		int GetDataIndex(const ElementType& data) const;
		bool ShiftLeftData(const int& index);
		ElementType GetData(const int& index) const;

		int m_cnt;
		ElementType *m_pData;



	};


	template <typename ElementType>
	Vector<ElementType>::Vector()
	{

		m_pData = new ElementType[DATA_SIZE];

		m_cnt = 0;

	}
	template <typename ElementType>
	Vector<ElementType>::~Vector()
	{
		std::cout << "����?";

		free(m_pData);

	}


	template <typename ElementType>
	bool Vector<ElementType>::AddData(const ElementType& data) {

		if (GetDataIndex(data) != NOT_FOUND_INDEX) {
			return false;
		}


		//�����Ͱ� �� ã�� ��쿡 �迭 ũ�� ����
		if (m_cnt % DATA_SIZE == 0) {

			int changeSize = m_cnt + DATA_SIZE;

			m_pData = (ElementType *)realloc(m_pData, sizeof(ElementType) * changeSize);



		}

		m_pData[m_cnt] = data;
		m_cnt++;


		return true;
	}
	template <typename ElementType>
	bool Vector<ElementType>::DeleteData(const ElementType& data) {


		int index = GetDataIndex(data);

		if (index == NOT_FOUND_INDEX) {
			return false;
		}

		ShiftLeftData(index);

		m_cnt--;




		//������ĭ���� �پ��� �Ǹ� ������ ����
		if (m_cnt % DATA_SIZE == 0) {

			int changeSize = m_cnt;


			m_pData = (ElementType *)realloc(m_pData, sizeof(ElementType) * changeSize);

		}




		return true;
	}
	template <typename ElementType>
	int Vector<ElementType>::GetSize() const{

		return m_cnt;
	}

	template <typename ElementType>
	void Vector<ElementType>::PrintData() const{

		std::cout << "VectorData : ";

		/*for (int i = 0; i < m_cnt; i++) {
			std::cout << m_pData[i] << "  ";
		}
*/
		//���ٸ� ���

		std::for_each(m_pData, &m_pData[m_cnt], [](int& number) {
			std::cout << number << "  ";
		});
	
		std::cout << "\n";

	}

	template <typename ElementType>
	int Vector<ElementType>::GetDataIndex(const ElementType& data) const{

		for (int i = 0; i < m_cnt; i++) {
			if (m_pData[i] == data) {
				return i;
			}
		}

		return NOT_FOUND_INDEX;

	}
	template <typename ElementType>
	bool Vector<ElementType>::ShiftLeftData(const int& index)
	{
		if (index < 0 || index >= m_cnt) {
			return false;
		}

		for (int i = index; i < m_cnt - 1; i++) {
			m_pData[i] = m_pData[i + 1];
		}

		m_pData[m_cnt - 1] = {};

		return true;
	}

	template<typename ElementType>
	ElementType Vector<ElementType>::GetData(const int & index) const
	{
		return m_pData[index];
	}


	template<typename ElementType>
	Vector<ElementType>& Vector<ElementType>::operator=(Vector & right)
	{
		Copy(&right);
		return *this;
	}


	template<typename ElementType>
	void Vector<ElementType>::Copy(Base<ElementType>* right)
	{
		//������ �ִ� �����͸� �����
		free(m_pData);
		m_pData = new ElementType[DATA_SIZE];

		m_cnt = 0;


		Vector<ElementType> *original = static_cast<Vector<ElementType>*>(right); //�ٿ�ĳ����
		for (int i = 0; i < original->GetSize(); i++)
		{
			AddData(original->GetData(i));
		}
	}


}
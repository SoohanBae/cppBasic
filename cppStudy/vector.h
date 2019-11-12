#include "Base.h"
#define VECTOR_DATA_SIZE 10
#define VECTOR_NOT_FOUND_INDEX -1


namespace VectorList {





	template <typename T>
	class Vector : public Base<T> {



	public:


		Vector();
		~Vector();


		bool AddData(T data);
		bool DeleteData(T data);
		int GetSize() const;

		void PrintData() const;



	private:
		
		int GetDataIndex(T data);
		bool ShiftLeftData(int index);
		
		int m_cnt;
		T *m_data;



	};


	template <typename T>
	Vector<T>::Vector()
	{

		m_data = (T *)malloc(sizeof(T) * VECTOR_DATA_SIZE);

		m_cnt = 0;

	}
	template <typename T>
	Vector<T>::~Vector()
	{
		std::cout << "����?";

		free(m_data);
	}


	template <typename T>
	bool Vector<T>::AddData(T data) {

		if (getDataIndex(data) != VECTOR_NOT_FOUND_INDEX) {
			return false;
		}


		//�����Ͱ� �� ã�� ��쿡 �迭 ũ�� ����
		if (m_cnt % VECTOR_DATA_SIZE == 0) {

			int changeSize = m_cnt + VECTOR_DATA_SIZE;

			m_data = (T *)realloc(m_data, sizeof(T) * changeSize);



		}

		m_data[m_cnt] = data;
		m_cnt++;


		return true;
	}
	template <typename T>
	bool Vector<T>::DeleteData(T data) {


		int index = getDataIndex(data);

		if (index == VECTOR_NOT_FOUND_INDEX) {
			return false;
		}

		leftShiftData(index);

		m_cnt--;




		//������ĭ���� �پ��� �Ǹ� ������ ����
		if (m_cnt % VECTOR_DATA_SIZE == 0) {

			int changeSize = m_cnt;


			m_data = (T *)realloc(m_data, sizeof(T) * changeSize);

		}




		return true;
	}
	template <typename T>
	int Vector<T>::GetSize() const{

		return m_cnt;
	}

	template <typename T>
	void Vector<T>::PrintData() const{

		std::cout << "���";
		std::cout << "VectorData : ";

		for (int i = 0; i < m_cnt; i++) {
			std::cout << m_data[i] << "  ";
		}

		std::cout << "\n";

	}

	template <typename T>
	int Vector<T>::GetDataIndex(T data) {

		for (int i = 0; i < m_cnt; i++) {
			if (m_data[i] == data) {
				return i;
			}
		}

		return VECTOR_NOT_FOUND_INDEX;

	}
	template <typename T>
	bool Vector<T>::ShiftLeftData(int index)
	{
		if (index < 0 || index >= m_cnt) {
			return false;
		}

		for (int i = index; i < m_cnt - 1; i++) {
			m_data[i] = m_data[i + 1];
		}

		m_data[m_cnt - 1] = {};

		return true;
	}

}
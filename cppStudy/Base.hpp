#pragma once
namespace VectorList{

	template <typename ElementType>
	class Base {



	public:

		Base();
		virtual ~Base();

		virtual bool AddData(const ElementType& data);
		virtual bool DeleteData(const ElementType& data);
		virtual int GetSize() const;

		virtual void PrintData() const;



		virtual void Copy(Base<ElementType>* right);
		virtual Base<ElementType>& operator=(Base<ElementType>& right);
		

	private:
		
	};



	template <typename ElementType>
	Base<ElementType>::Base()
	{
	}

	template <typename ElementType>
	Base<ElementType>::~Base()
	{
	}

	template <typename ElementType>
	bool Base<ElementType>::AddData(const ElementType& data)
	{
		return false;
	}

	template <typename ElementType>
	bool Base<ElementType>::DeleteData(const ElementType& data)
	{
		return false;
	}

	template <typename ElementType>
	int Base<ElementType>::GetSize() const
	{
		return 0;
	}

	template <typename ElementType>
	void Base<ElementType>::PrintData() const
	{
		return void();
	}

	template<typename ElementType>
	void Base<ElementType>:: Copy(Base<ElementType>* right) {
		return void();
	}

	template<typename ElementType>
	Base<ElementType>& Base<ElementType>::operator=(Base & right)
	{
		std::cout << "�������� �̿��� ������ ���� �͹����µ� ��� �ұ�\n";
		Copy(&right);
		return *this;
	}



}
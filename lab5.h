#ifndef LAB5_H
#define LAB5_H
#include <iostream>
using namespace std;

class CSingleLinkedList {
private:
		double m_d_Num;
		CSingleLinkedList* mp_sll_Next;
public:
		CSingleLinkedList();

		CSingleLinkedList(double Num);
		
		CSingleLinkedList(double Num1, double Num2);

		CSingleLinkedList(const CSingleLinkedList& other);
		
		CSingleLinkedList(CSingleLinkedList&& other) noexcept;

		~CSingleLinkedList();

		double GetFirst();

		double GetLast();

		double GetMax();
		
		double GetMin();
		
		double GetAvg();
		
		int GetCount();

		void AddToStart(double Num);

		void AddToEnd(double Num);

		void RemoveFirst();

		void RemoveLast();
		
		void RemoveAll();

		void SortBySample();

		void SortByBable();

		friend ostream& operator<<(ostream& out, const CSingleLinkedList& element);

		friend CSingleLinkedList& operator+(CSingleLinkedList& element, double Num);

		friend CSingleLinkedList& operator+(double Num, CSingleLinkedList& element);

		friend CSingleLinkedList& operator-(CSingleLinkedList& element, int iCount);

		friend CSingleLinkedList& operator-(int iCount, CSingleLinkedList& element);

		double& operator[](unsigned int i);

		CSingleLinkedList& operator=(const CSingleLinkedList& other);
		
		CSingleLinkedList& operator=(CSingleLinkedList&& other) noexcept;

};


#endif // !LAB5_h

#include <iostream>
#include <cstring>
#include "lab5.h"

using	namespace std;

CSingleLinkedList::CSingleLinkedList() {
		mp_sll_Next = nullptr;
		m_d_Num = NAN;
}

CSingleLinkedList::CSingleLinkedList(double Num) {
		m_d_Num = NAN;
		mp_sll_Next = new CSingleLinkedList;
		mp_sll_Next->m_d_Num = Num;
		mp_sll_Next->mp_sll_Next = nullptr;
}

CSingleLinkedList::CSingleLinkedList(double Num1, double Num2) {
		m_d_Num = NAN;
		mp_sll_Next = new CSingleLinkedList;
		mp_sll_Next->m_d_Num = Num1;
		mp_sll_Next->mp_sll_Next = new CSingleLinkedList;
		mp_sll_Next->mp_sll_Next->m_d_Num = Num2;
		mp_sll_Next->mp_sll_Next->mp_sll_Next = nullptr;
}

CSingleLinkedList::CSingleLinkedList(const CSingleLinkedList& other) {

		if(other.mp_sll_Next == nullptr) {
				mp_sll_Next = nullptr;
				m_d_Num = NAN;
		} else {
				CSingleLinkedList* pCurent = other.mp_sll_Next;
				CSingleLinkedList* pNew = new CSingleLinkedList;
				mp_sll_Next = pNew;
				m_d_Num = NAN;
				while(pCurent->mp_sll_Next != nullptr) {
						pNew->m_d_Num = pCurent->m_d_Num;
						CSingleLinkedList* pNext = new CSingleLinkedList;
						pNew->mp_sll_Next = pNext;
						pCurent = pCurent->mp_sll_Next;
						pNew = pNew->mp_sll_Next;
				}
				pNew->m_d_Num = pCurent->m_d_Num;
				pNew->mp_sll_Next = nullptr;
		}
}

CSingleLinkedList::CSingleLinkedList(CSingleLinkedList&& other) noexcept {
		*this = CSingleLinkedList(other);
		other.RemoveAll();
}

CSingleLinkedList::~CSingleLinkedList() {
		cout <<" ooooooooooooooooo ";
		this->RemoveAll();
}

double CSingleLinkedList::GetFirst() {
		if(mp_sll_Next == nullptr) return NAN;
		return mp_sll_Next->m_d_Num;
}

double CSingleLinkedList::GetLast() {
		CSingleLinkedList* pCurent = mp_sll_Next;
		if(mp_sll_Next == nullptr) return NAN;
		while(pCurent->mp_sll_Next != nullptr) {
				pCurent = pCurent->mp_sll_Next;
		}
		return pCurent->m_d_Num;

}

int CSingleLinkedList::GetCount() {
		CSingleLinkedList* pCurent = mp_sll_Next;
		if(mp_sll_Next == nullptr) return 0;
		int iCount = 1;
		while(pCurent->mp_sll_Next != nullptr) {
				pCurent = pCurent->mp_sll_Next;
				iCount++;
		}
		return iCount;

}

double CSingleLinkedList::GetMax() {
		CSingleLinkedList* pCurent = mp_sll_Next;
		if(mp_sll_Next == nullptr) return NAN;
		double dMax = mp_sll_Next->m_d_Num;
		while(pCurent->mp_sll_Next != nullptr) {
				if(dMax < pCurent->m_d_Num) {
						dMax = pCurent->m_d_Num;
				}
				pCurent = pCurent->mp_sll_Next;
		}
		if(dMax < pCurent->m_d_Num) {
				dMax = pCurent->m_d_Num;
		}
		return dMax;
}

double CSingleLinkedList::GetMin() {
		CSingleLinkedList* pCurent = mp_sll_Next;
		if(mp_sll_Next == nullptr) return NAN;
		double dMin = mp_sll_Next->m_d_Num;
		while(pCurent->mp_sll_Next != nullptr) {
				if(dMin > pCurent->m_d_Num) {
						dMin = pCurent->m_d_Num;
				}
				pCurent = pCurent->mp_sll_Next;
		}
		if(dMin > pCurent->m_d_Num) {
				dMin = pCurent->m_d_Num;
		}
		return dMin;
}

double CSingleLinkedList::GetAvg() {
		CSingleLinkedList* pCurent = mp_sll_Next;
		if(mp_sll_Next == nullptr) return NAN;
		double dCount = 1, dSum = 0;
		while(pCurent->mp_sll_Next != nullptr) {
				dCount += 1;
				dSum += pCurent->m_d_Num;
				pCurent = pCurent->mp_sll_Next;
		}
		dSum += pCurent->m_d_Num;
		dSum = dSum / dCount;
		return dSum;
}

void CSingleLinkedList::AddToStart(double Num) {
		CSingleLinkedList* pCurent = new CSingleLinkedList;
		pCurent->m_d_Num = Num;
		pCurent->mp_sll_Next = mp_sll_Next;
		mp_sll_Next = pCurent;
}

void CSingleLinkedList::AddToEnd(double Num) {
		CSingleLinkedList* pLast = new CSingleLinkedList;
		pLast->m_d_Num = Num;
		pLast->mp_sll_Next = nullptr;
		CSingleLinkedList* pCurent = mp_sll_Next;
		if(pCurent == nullptr) {
				mp_sll_Next = pLast;
				return;
		}
		while(pCurent->mp_sll_Next != nullptr) pCurent = pCurent->mp_sll_Next;
		pCurent->mp_sll_Next = pLast;
}

void CSingleLinkedList::RemoveFirst() {
		CSingleLinkedList* pDelete = mp_sll_Next;
		if(this->mp_sll_Next == nullptr) return;
		mp_sll_Next = pDelete->mp_sll_Next;
		cout << endl << mp_sll_Next->m_d_Num << endl;

		delete pDelete;
		return;
}

void CSingleLinkedList::RemoveAll() {
		while(mp_sll_Next != nullptr) {
				this->RemoveLast();
		}
}

void CSingleLinkedList::RemoveLast() {
		if(mp_sll_Next == nullptr) return;
		if(mp_sll_Next->mp_sll_Next == nullptr) {
				mp_sll_Next->m_d_Num = NAN;
				delete mp_sll_Next;
				mp_sll_Next = nullptr;
				return;
		}
		CSingleLinkedList* pPrevios = mp_sll_Next, * pCurent = pPrevios->mp_sll_Next;
		while(pCurent->mp_sll_Next != nullptr) {
				pPrevios = pPrevios->mp_sll_Next;
				pCurent = pCurent->mp_sll_Next;
		}
		pCurent->m_d_Num = NAN;
		delete pCurent;
		pPrevios->mp_sll_Next = nullptr;
}

void CSingleLinkedList::SortByBable() {
		if(mp_sll_Next == nullptr) return;
		if(mp_sll_Next->mp_sll_Next == nullptr) return;
		int iCount = this->GetCount();
		for(int i = 0; i < iCount; i++) {
				CSingleLinkedList* pFirst = mp_sll_Next, * pSecond = pFirst->mp_sll_Next,
						* pPre = mp_sll_Next;
				for(int j = 0; j < iCount - 1; j++) {
						if(pFirst->m_d_Num > pSecond->m_d_Num) {
								CSingleLinkedList* pTemp = pSecond->mp_sll_Next;
								pSecond->mp_sll_Next = pFirst;
								pFirst->mp_sll_Next = pTemp;

								if(j == 0) mp_sll_Next = pSecond;
								else pPre->mp_sll_Next = pSecond;
						}

						if(j == 0) pPre = mp_sll_Next;
						else pPre = pPre->mp_sll_Next;

						pFirst = pPre->mp_sll_Next;
						pSecond = pFirst->mp_sll_Next;
				}
		}
}

void CSingleLinkedList::SortBySample() {
		if(mp_sll_Next == nullptr) return;
		if(mp_sll_Next->mp_sll_Next == nullptr) return;
		int iCount = this->GetCount();

		CSingleLinkedList* pCurent = mp_sll_Next, * pPre = mp_sll_Next,
				* pTemp = pCurent, * pSwap = mp_sll_Next;

		for(int i = 0; i < iCount; i++) {
				double dMax = pCurent->m_d_Num;

				for(int j = i; j < iCount - 2; j++) {
						if(pTemp->mp_sll_Next->m_d_Num > dMax) {
								dMax = pTemp->mp_sll_Next->m_d_Num;
								pSwap = pTemp;
						}
						pTemp = pTemp->mp_sll_Next;

				}
				if(i == 0) {
						CSingleLinkedList* pTempl = pCurent;
						mp_sll_Next = pSwap->mp_sll_Next;
						pSwap->mp_sll_Next = pCurent;
						pCurent->mp_sll_Next = pSwap->mp_sll_Next->mp_sll_Next;

				}
				pCurent = pCurent->mp_sll_Next;
		}
}

ostream& operator<<(ostream& out, const CSingleLinkedList& element) {
		CSingleLinkedList* pCurent = element.mp_sll_Next;
		while(pCurent != nullptr) {
				out << pCurent->m_d_Num << " ";
				pCurent = pCurent->mp_sll_Next;
		}
		return out;
}

CSingleLinkedList& operator+(CSingleLinkedList& element, double Num) {
		element.AddToEnd(Num);
		return element;
}

CSingleLinkedList& operator+(double Num, CSingleLinkedList& element) {
		element.AddToStart(Num);
		return element;
}

CSingleLinkedList& operator-(CSingleLinkedList& element, int iCount) {
		for(int i = 0; i < iCount; i++) {
				element.RemoveLast();
		}
		return element;
}

CSingleLinkedList& operator-(int iCount, CSingleLinkedList& element) {
		for(int i = 0; i < iCount; i++) {
				element.RemoveFirst();
		}
		return element;
}

double& CSingleLinkedList::operator[](unsigned int i) {
		if(mp_sll_Next == nullptr) return m_d_Num;
		CSingleLinkedList* pCurent = mp_sll_Next;
		int iCount = 0;
		while(pCurent->mp_sll_Next != nullptr) {
				if(iCount == i) return pCurent->m_d_Num;
				iCount++;
				pCurent = pCurent->mp_sll_Next;
		}
		if(iCount == i) return pCurent->m_d_Num;
		return m_d_Num;
}

CSingleLinkedList& CSingleLinkedList::operator=(const CSingleLinkedList& other) {
		if(this == &other) return *this;
		if(other.mp_sll_Next == nullptr) {
				mp_sll_Next = nullptr;
				m_d_Num = NAN;
		} else {
				CSingleLinkedList* pCurent = other.mp_sll_Next;
				CSingleLinkedList* pNew = new CSingleLinkedList;
				mp_sll_Next = pNew;
				m_d_Num = NAN;
				while(pCurent->mp_sll_Next != nullptr) {
						pNew->m_d_Num = pCurent->m_d_Num;
						CSingleLinkedList* pNext = new CSingleLinkedList;
						pNew->mp_sll_Next = pNext;
						pCurent = pCurent->mp_sll_Next;
						pNew = pNew->mp_sll_Next;
				}
				pNew->m_d_Num = pCurent->m_d_Num;
				pNew->mp_sll_Next = nullptr;
		}
		return *this;
}

CSingleLinkedList& CSingleLinkedList::operator=(CSingleLinkedList&& other) noexcept {
		if(this == &other) return *this;
		this->RemoveAll();
		*this = other;
		other.RemoveAll();
}
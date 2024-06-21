#pragma once
using namespace std;
template <typename T> class Tlist
{
	struct TNode
	{
		T value;
		TNode* pNext = nullptr;
	};
	TNode* pFirst;
	size_t sz;
public:
	Tlist() : pFirst(nullptr), sz(0) { };

	Tlist(const Tlist& A) {
		pFirst = A.pFirst;
		sz = A.sz;
		TNode* pNew = pFirst = new TNode{ *A.pFirst };
		for (; pNew->pNext != nullptr; pNew = pNew->pNext)
			pNew->pNext = new TNode{ *pNew->pNext };
	};

	//	Tlist(Tlist&& l)  {
	//		pFirst = nullptr;
	//		swap(*this, l);
	//	};

	T& operator[](size_t pos)
	{
		TNode* p = ToPos(pos);
		return p->value;
	};

	bool operator == (Tlist l)
	{
		if (sz != l.sz)
			return 0;
		TNode* p1;
		for (int i = 0; i < sz; i++)
		{
			p1 = ToPos(i);
			if ((p1->value) != l[i])
				return 0;
		}

		return 1;
	}

	bool operator != (Tlist l)
	{
		return(!(*this == l));
	}

	Tlist& operator=(const Tlist& A) {
		if (this != &A) {
			pFirst = A.pFirst;
			sz = A.sz;
			TNode* pNew = pFirst = new TNode{ *A.pFirst };
			for (; pNew->pNext != nullptr; pNew = pNew->pNext)
				pNew->pNext = new TNode{ *pNew->pNext };
		}
		return(*this);
	}

	~Tlist()
	{
		TNode* p;
		while (pFirst != nullptr) {
			p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
		}
	};
	size_t size() const {
		return sz;
	};
	bool IsEmpty() const {
		return sz == 0;
	};
	T& Front() {
		return pFirst->value;
	};
	void PushFront(const T& val)
	{
		TNode* node = new TNode{ val, pFirst };
		pFirst = node;
		sz++;
	};
	void PushBack(const T& val)
	{
		TNode New{ val, nullptr };
		TNode* pNew = &New;
		TNode* p = ToPos(sz);
		p->pNext = pNew;
		sz++;
	}
	void PopFront() {
		TNode* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		sz--;
	};

	void Pop(size_t i)
	{
		if ((i != 0) && (i != this->size() - 1))
		{
			TNode* pl = ToPos(i - 1);
			TNode* pr = ToPos(i + 1);
			TNode* p = ToPos(i);
			pl->pNext = pr;
			delete p;
			sz--;
		}
		else if (i == 0)
			this->PopFront();
		else if (i == this->size() - 1)
		{
			TNode* p = ToPos(i);
			delete p;
			TNode* pl = ToPos(i - 1);
			pl->pNext = nullptr;
			sz--;
		}
	}


	void PushAfter(size_t pos, const T& val)
	{
		TNode* p = ToPos(pos);
		TNode* pNew = new TNode{ val, p->pNext };
		p->pNext = pNew;
		sz++;
	};
	TNode* ToPos(size_t pos)
	{
		TNode* res = pFirst;
		for (int i = 1; i <= pos; i++)
		{
			res = res->pNext;
		}
		return res;
	};
	void Check_Value(size_t pos)
	{
		TNode p = *ToPos(pos);
		cout << p.value;
	};
	void EraseAfter(size_t pos)
	{
		TNode* p = ToPos(pos);
		TNode* pDel = p->pNext;
		p->pNext = pDel->pNext;
		delete pDel;
		sz--;
	};
};



#include <iostream>
#include <cmath>
using namespace std;

template <class ValType>
class TVector
{
public:
	TVector(int size = 10, int startindex = 0);
	TVector(const TVector& v);
	~TVector();
	int GetSize() {return Size; }
	int GetIndex() {return this->StartIndex; }
	ValType& GetValue(int pos);
	ValType& operator[](int pos) const;
	bool operator==(const TVector& v)const;
	TVector& operator=(const TVector& v);
	TVector operator+(const ValType& val);
	TVector operator-(const ValType& val);
	TVector operator*(const ValType& val);
	TVector operator+(const TVector& v);
	TVector operator-(const TVector& v);
	double operator*(const TVector& v);

	void pushBack(const ValType& v);
	void popBack();
	double search_module(const TVector& v);
	double s_cos(const TVector& a, const TVector& b);


	friend istream& operator>>(istream& in, TVector<ValType>& V) {
		for (int i = 0; i < V.Size; i++)
			in >> V.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector<ValType>& V) {
		cout << '|';
		for (int i = 0; i < V.StartIndex; i++)
			out << "  ";
		for (int i = 0; i < V.Size; i++)
		{
			out << V.pVector[i];
			if (i != V.Size - 1)
				cout << ',';
		}
		cout << '|';
		return out;
	}


protected:
	int Size;
	int StartIndex;
	ValType* pVector;
};

template<class ValType>
inline TVector<ValType>::TVector(int size, int startindex)
{
	pVector = new ValType[size];
	Size = size;
	StartIndex = startindex;
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = 0;
	}
}

template<class ValType>
inline TVector<ValType>::TVector(const TVector<ValType>& v)
{
	Size = v.Size;
	pVector = new ValType[Size];
	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
}

template<class ValType>
inline TVector<ValType>::~TVector()
{
	Size = 0;
	StartIndex = 0;
	delete[] pVector;
	pVector = nullptr;
}

template<class ValType>
inline ValType& TVector<ValType>::GetValue(int i)
{
	if (i > Size || i < 0)
		throw invalid_argument("different size");
	return pVector[i];
}

template<class ValType>
inline ValType& TVector<ValType>::operator[](int pos) const
{
	return pVector[pos - StartIndex];
}





template<class ValType>
inline bool TVector<ValType>::operator==(const TVector& v) const
{
	if (Size == v.Size)
	{
		for (int i = 0; i < Size; i++)
			if (!(pVector[i] == v.pVector[i]))
				return false;
	}
	else
		return false;
			
	return true;
}

template<class ValType>
inline TVector<ValType> &TVector<ValType>::operator=(const TVector& v)
{
	if (this != &v) {
		if (Size != v.Size)
		{
			delete[] pVector;
			pVector = new ValType[v.Size];
		}
		Size = v.Size;
		StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
		return *this;
	}
	return *this;

}



template<class ValType>
TVector<ValType>TVector<ValType>::operator+(const ValType& v)
{
	TVector tmp(Size, StartIndex);
	tmp = *this;
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = pVector[i] + v;
	}
	return tmp;
}

template<class ValType>
TVector<ValType>TVector<ValType>::operator-(const ValType& v)
{
	
	TVector tmp(Size, StartIndex);
	tmp = *this;

	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = pVector[i] - v;
	}
	return tmp;
}

template<class ValType>
inline TVector<ValType> TVector<ValType>::operator*(const ValType& v)
{
	TVector tmp(Size, StartIndex);
	tmp = *this;
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = pVector[i] * v;
	}
	return tmp;

}

template<class ValType>
TVector<ValType>TVector<ValType>::operator+(const TVector& v)
{
	if (Size != v.Size)
		throw invalid_argument("different size");
	TVector tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		tmp.pVector[i] = pVector[i] + v.pVector[i];
	return tmp;
}

template<class ValType>
TVector<ValType>TVector<ValType>::operator-(const TVector& v)
{
	if (Size != v.Size)
		throw invalid_argument("different size");
	TVector tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		tmp.pVector[i] = pVector[i] - v.pVector[i];
	return tmp;
}

template<class ValType>
inline double TVector<ValType>::operator*(const TVector& v)
{
	if (Size != v.Size)
		throw invalid_argument("different size");
	double mod_a = 0.0, mod_b = 0.0, ser_cos = 0.0;
	mod_a = search_module(*this);
	mod_b = search_module(v);
	ser_cos = s_cos(*this, v);
	return mod_a * mod_b * ser_cos;
}



template<class ValType>
inline void TVector<ValType>::pushBack(const ValType& v)
{
	ValType* vec = new ValType[Size + 1];
	for (int i = 0; i < Size; i++)
		vec[i] = pVector[i];
	vec[Size] = v;
	Size++;
	delete[] pVector;
	pVector = vec;
}

template<class ValType>
inline void TVector<ValType>::popBack()
{
	ValType* vec = new ValType[Size-1];
	for (int i = 0; i < Size-1; i++)
		vec[i] = pVector[i];
	Size--;
	delete[] pVector;
	pVector = vec;
}

template<class ValType>
inline double TVector<ValType>::search_module(const TVector& v)
{
	double tmp = 0.0;
	for (int i = 0; i < Size; i++)
	{
		tmp += pow(v.pVector[i],2);
	}
	tmp = sqrt(tmp);
	return tmp;
}

template<class ValType>
inline double TVector<ValType>::s_cos(const  TVector& a, const TVector& b)
{
	double tmp_cos = 0, chisl = 0;
	for (int i = 0; i < Size; i++)
		chisl += a.pVector[i] * b.pVector[i];
	tmp_cos = chisl / (search_module(a) * search_module(b));
	return tmp_cos;
}








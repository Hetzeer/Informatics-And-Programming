#include "vec.h"
template <class ValType>
class TMatrix: public TVector<TVector<ValType>>
{
public:

	TMatrix(int n = 10);
	TMatrix(const TMatrix& mt);
	explicit TMatrix(const TVector<TVector<ValType>>& mt);
	bool operator ==(const TMatrix &mt)const;
	TMatrix& operator =(const TMatrix &mt);
	TMatrix operator +(const TMatrix& mt);
	TMatrix operator -(const TMatrix& mt);
	TMatrix operator *(const TMatrix& mt);

	template< typename T >friend istream& operator >> (istream& in, const TMatrix<T>& mt) {
		for (int i = 0; i < mt.Size; i++)
		{
			in >> mt.pVector[i];
		}
		return in;
	}
	template< typename T >friend ostream& operator << (ostream& out, TMatrix<T>& mt) {
		for (int i = 0; i < mt.Size; i++)
		{
			out << mt.pVector[i] << "\n";
		}

		return out;
	}

};

template<class ValType>
inline TMatrix<ValType>::TMatrix(int n):TVector<TVector<ValType>>(n)
{
	for (int i = 0; i < n; i++)
	{
		this->pVector[i] = TVector<ValType>(n-i,i);
	}
}

template<class ValType>
inline TMatrix<ValType>::TMatrix(const TMatrix& mt) :TVector<TVector<ValType>>(mt)
{
}

template<class ValType>
inline TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>&mt) : TVector<TVector<ValType>>(mt)
{
}


template<class ValType>
inline bool TMatrix<ValType>::operator==(const TMatrix& mt) const
{
	return (TVector<TVector<ValType>>::operator==(mt));

}

template<class ValType>
inline TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (&mt != this)
	{
		delete[] this->pVector;
		this->pVector = new TVector<ValType>[mt.Size];
		this->Size = mt.Size;
		this->StartIndex = mt.StartIndex;
		for (int i = 0; i < this->Size; i++)
		{
			this->pVector[i] = mt.pVector[i];
		}
		
	}
	return *this;
}


template<class ValType>
inline TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return (TMatrix(TVector<TVector<ValType>>::operator+(mt)));
}

template<class ValType>
inline TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return (TMatrix(TVector<TVector<ValType>>::operator-(mt)));

}

template<class ValType>
inline TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt)
{
	if (this->GetSize() != mt.Size)
		throw invalid_argument("different size");
	else {

		TMatrix<ValType> matr(mt.Size);
		TMatrix<ValType> _mt(mt);
		TVector<int> vec,vec1, vec2;
		for (int i = 0; i < mt.Size; i++)
		{
			vec = mt.pVector[i];
			for (int j = vec.GetIndex(); j < mt.Size; j++)
			{
				vec2 = mt.pVector[j];
				for (int k = vec.GetIndex(); k < vec2.GetIndex() + 1; k++)
				{
					matr.pVector[i][j] += this->pVector[i][k] * _mt.pVector[k][j];
				}

			}
		}
		return matr;
	}
}


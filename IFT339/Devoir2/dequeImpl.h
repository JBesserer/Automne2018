//
//  Nom du fichier dequeImpl.h
//  Description : deque-circulaire
//
//  Auteur : Jean Goulet 
//  Date :   2016-12-27
//  Copyleft 2016 UdeS
//
//  Modifié par : Vincent Ducharme, Janvier 2018
//
// =============================================
//
//  Nom de l'étudiant : Jeremy Besserer-Lemay 11 049 439
//  Nom de l'étudiant :	Christopher Brown	  18 106 345
//
// =============================================

#ifndef _dequeImpl_h
#define _dequeImpl_h

/////////////////////////////////////////////////////////////////
//code a completer pour le devoir

template <typename TYPE>
deque<TYPE>::deque(const deque& source):deque(source.size())
{		
	ZERO = source.ZERO;
	SIZE = source.SIZE;
	if(source.SIZE != source.CAP)
		reserve(source.CAP);
	for (size_t i = 0; i < source.SIZE; ++i) {
		(*this)[i] = source[i];
	}
}

template <typename TYPE>
void deque<TYPE>::resize(size_t nSIZE)
{
	if (nSIZE > size()) {
		deque<TYPE> tempDequeResize(*this);
		tempDequeResize.reserve(nSIZE);
		swap(tempDequeResize);
		//Finishes inputing default data in allocated data address
		for (size_t i = SIZE; i < nSIZE; ++i)
			push_back(TYPE());
	}
	else
	{
		for (int i = size(); i > nSIZE; --i) {
			pop_back();
		}
	}
}

template <typename TYPE>
void deque<TYPE>::reserve(size_t nCAP)
{
	if (nCAP > CAP) {
		//Prep work for Deque with longer CAP than SIZE
		deque<TYPE> tempDequeReserve(0);
		tempDequeReserve.SIZE = SIZE;
		tempDequeReserve.CAP = nCAP;
		tempDequeReserve.DEBUT = new TYPE*[nCAP];
		for (size_t i = 0; i < SIZE; ++i)
			tempDequeReserve.DEBUT[i] = new TYPE(TYPE());
		
		//Moves ZERO back to 0 on reserve to simplify value input
		int j;
		for (size_t i = 0; i < tempDequeReserve.CAP; ++i) {
			j = (tempDequeReserve.CAP + i - tempDequeReserve.ZERO) % tempDequeReserve.CAP;
			if (j < size())
				tempDequeReserve[i] = (*this)[(i + ZERO) % CAP];

		}
		swap(tempDequeReserve);
	}
}

template <typename TYPE>
TYPE& deque<TYPE>::operator[](size_t i)
{
	return *(DEBUT[((i + ZERO) + CAP) % CAP]);
}

template <typename TYPE>
TYPE& deque<TYPE>::at(size_t i)
{
	if (i < size())
	{
		return *(DEBUT[i]);
	}
	throw std::invalid_argument("Index out of range");
}

template <typename TYPE>
const TYPE& deque<TYPE>::operator[](size_t i)const
{
	return *(DEBUT[((i + ZERO)+CAP) % CAP]);
}

template <typename TYPE>
const TYPE& deque<TYPE>::at(size_t i)const
{
	if (i < size())
	{
		return *(DEBUT[i]);
	}
	throw std::invalid_argument("Index out of range");
}

template <typename TYPE>
void deque<TYPE>::push_back(const TYPE& VAL)
{
	if (SIZE != CAP)
	{
		DEBUT[(size() + ZERO) % CAP] = new TYPE(VAL);
		++SIZE;
	}
	else
	{
		reserve(2 * (CAP) + 1);
		push_back(VAL);
	}
}

template <typename TYPE>
void deque<TYPE>::pop_back()
{
	if (!empty())
	{
		delete DEBUT[((size()-1) + ZERO) % CAP];
		--SIZE;
	}
}

template <typename TYPE>
void deque<TYPE>::push_front(const TYPE& VAL)
{
	if (SIZE != CAP)
	{
		DEBUT[((ZERO-1)+ CAP) % CAP] = new TYPE(VAL);
		ZERO = ((ZERO - 1) + CAP) % CAP;

		++SIZE;
	}
	else
	{
		reserve(2 * (CAP)+1);
		push_front(VAL);
	}
}

template <typename TYPE>
void deque<TYPE>::pop_front()
{
	if (!empty())
	{
		delete DEBUT[ZERO];
		ZERO = ((ZERO + 1) + CAP) % CAP;
		--SIZE;
	}
}


#endif // dequeImpl_h

//
//  Nom du fichier : vectorImpl.h
//
//  Auteur : Jean Goulet
//  Date :   2016-01-05
//
//  Modifié par : Vincent Ducharme, Janvier 2018
//
// =============================================
//
//  Nom de l'étudiant : Jeremy Besserer-Lemay 11 049 439
//  Nom de l'étudiant :	Christopher Brown	  18 106 345
//
// =============================================

#ifndef _vectorImpl_h
#define _vectorImpl_h


///////////////////////////////////////////////////
//clear (vide la memoire dynamique)

template <typename TYPE>
void vector<TYPE>::clear()
{
	delete[]DEBUT;
	DEBUT = FIN_DIM = FIN_CAP = nullptr;
}

///////////////////////////////////////////////////
//resize (modifie la dimension)

template <typename TYPE>
void vector<TYPE>::resize(size_t nDIM)
{
	if (nDIM > size()) {
		vector<TYPE> tempVect(0);
		for (int i = 0; i < nDIM; ++i) {
			if (i < size())
				tempVect.push_back(DEBUT[i]);
			else {
				tempVect.push_back(TYPE());
			}
		}
		swap(tempVect);
	}
	else
	{
		for (int i = size(); i > nDIM; --i) {
			pop_back();
		}
	}
}


///////////////////////////////////////////////////
//reserve (modifie la capacite)

template <typename TYPE>
void vector<TYPE>::reserve(size_t nCAP)
{
	size_t capacity = FIN_CAP - DEBUT;
	if (nCAP > capacity) {
		vector<TYPE> tempVect(nCAP);
		for (size_t i = 0; i < tempVect.size(); ++i) {
			if (i < size())
				tempVect[i] = DEBUT[i];
			else {
				break;
			}
		}
		TYPE * newDIM = tempVect.DEBUT + (FIN_DIM - DEBUT);
		swap(tempVect);
		FIN_DIM = newDIM;
	}
}

///////////////////////////////////////////////////
//fonctions d'acces a un element sauf front et back
//push_back
//pop_back
//operator[]
//operator[]const
//at
//at const

template <typename TYPE>
void vector<TYPE>::push_back(const TYPE& x)
{
	if (FIN_DIM != FIN_CAP) 
	{
		DEBUT[size()] = x;
		++FIN_DIM;
	}
	else 
	{
		reserve(2 * (FIN_CAP - DEBUT) + 1);
		push_back(x);
	}
}

template <typename TYPE>
void vector<TYPE>::pop_back()
{
	if (!empty()) 
	{
		//Prevents destruction and reintialization of dynamic array, with dynamic component instead
		TYPE * tempDIM = FIN_DIM;
		tempDIM = new TYPE();
		delete tempDIM;
		FIN_DIM--;
	}
}

template <typename TYPE>
TYPE& vector<TYPE>::operator[](size_t i)
{
	return DEBUT[i];
}

template <typename TYPE>
const TYPE& vector<TYPE>::operator[](size_t i)const
{
	return DEBUT[i];
}

template <typename TYPE>
TYPE& vector<TYPE>::at(size_t i)
{
	assert(i < size());
	return DEBUT[i];
}
template <typename TYPE>
const TYPE& vector<TYPE>::at(size_t i)const
{
	assert(i < size());
	return DEBUT[i];
}


#endif // vectorImpl_h

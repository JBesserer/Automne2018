/**
* \file Array.h
* \author Jeremy Besserer-Lemay 11 049 439
* \author Christopher Brown 18 106 345
* \brief This file contains a reimplementation of an array based on the Standard Library.
*/
#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdexcept>

/**
* \brief Reimplementation of an array which includes most of it's standard functions
*/
template <typename T, size_t N>
class Array
{
private:
	T *tab;
public:
	/**
	* \brief Implementation of a class to iterate through the array
	*/
	class iterator
	{
	private:
		T *ptr;
	public:
		iterator(T *ptr);
		iterator(const iterator& source);
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		T& operator*();


	};
	/**
	* \brief Implementation of a class to iterate with constant pointers to prevent value modification
	*/
	class const_iterator
	{
	private:
		const T *cptr;
	public:
		const_iterator(const T *ptr);
		const_iterator(const const_iterator& source);
		const_iterator& operator++();
		const_iterator operator++(int);
		const_iterator& operator--();
		const_iterator operator--(int);
		const T& operator*();

	};
	//Trinity methods
	Array();
	~Array();
	Array(const Array<T, N>& source);
	
	//Get methods
	int size()const;
	bool empty()const;
	T& front()const;
	T& back()const;
	const T& front();
	const T& back();

	//Mutating methods
	void fill(const T o);
	void swap(Array<T, N>& o);
	template <size_t M>
	Array<T, N+M> fusion(const Array<T, M>& o);
	template <size_t M>
	Array<T, M> subset(size_t start);

	//Accessing methods
	T at(size_t)const;
	T& operator[](size_t);
	T operator[](size_t)const;

	//Move semantics methods
	Array(Array<T, N>&& o);
	Array<T, N>& operator=(Array<T, N>&& o);
	Array<T, N>& operator=(const Array<T, N>& source);

	//Iterator Get methods
	iterator begin()const;
	iterator end()const;
	const_iterator cbegin()const;
	const_iterator cend()const;
};

/**
* \brief Iterator constructor
* \param [in] pointer used to initialize the implicit iterator
*/
template <typename T, size_t N>
Array<T, N>::iterator::iterator(T *ptr) {
	this->ptr = ptr;
}

/**
* \brief Iterator copy constructor
* \param [in] Another iterator used to initialize the implicit iterator
*/
template <typename T, size_t N>
Array<T, N>::iterator::iterator(const iterator& source) {
	ptr = source.ptr;
}

/**
* \brief const_iterator constructor
* \param [in] pointer used to initialize the implicit const_iterator
*/
template <typename T, size_t N>
Array<T, N>::const_iterator::const_iterator(const T *ptr) {
	this->cptr = ptr;
}

/**
* \brief const_iterator copy constructor
* \param [in] Another const_iterator used to initialize the implicit const_iterator
*/
template <typename T, size_t N>
Array<T, N>::const_iterator::const_iterator(const const_iterator& source) {
	cptr = source.cptr;
}

/**
* \brief iterator pre increment method
* \return iterator at the new position
*/
template <typename T, size_t N>
typename Array<T, N>::iterator& Array<T, N>::iterator::operator++()
{
	++ptr;
	return *this;
}

/**
* \brief iterator post increment method, increments and returns the old position
* \return iterator at the old position
*/
template <typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::iterator::operator++(int idx)
{
	iterator it(*this);
	++ptr;
	return it;
}

/**
* \brief const_iterator pre increment method
* \return const_iterator at the new position
*/
template <typename T, size_t N>
typename Array<T, N>::const_iterator& Array<T, N>::const_iterator::operator++()
{
	++cptr;
	return *this;
}

/**
* \brief const_iterator post increment method, increments and returns the old position
* \return const_iterator at the old position
*/
template <typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::const_iterator::operator++(int idx)
{
	const_iterator it(*this);
	++cptr;
	return it;
}

/**
* \brief iterator pre decrement method
* \return iterator at the new position
*/
template <typename T, size_t N>
typename Array<T, N>::iterator& Array<T, N>::iterator::operator--()
{
	--ptr;
	return *this;
}

/**
* \brief iterator post decrement method, decrements and returns the old position
* \return iterator at the old position
*/
template <typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::iterator::operator--(int idx)
{
	iterator it(*this);
	--ptr;
	return it;
}

/**
* \brief const_iterator pre decrement method
* \return const_iterator at the new position
*/
template <typename T, size_t N>
typename Array<T, N>::const_iterator& Array<T, N>::const_iterator::operator--()
{
	--cptr;
	return *this;
}

/**
* \brief const_iterator post decrement method, decrements and returns the old position
* \return const_iterator at the old position
*/
template <typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::const_iterator::operator--(int idx)
{
	const_iterator it(*this);
	--cptr;
	return it;
}

/**
* \brief iterator accessor method to value in the pointer
* \return reference value to be able to modify it on the fly
*/
template <typename T, size_t N>
typename T& Array<T, N>::iterator::operator*()
{
	return *ptr;
}

/**
* \brief const_iterator accessor method to value in the pointer
* \return const reference value is returned, does not permit modification
*/
template <typename T, size_t N>
typename const T& Array<T, N>::const_iterator::operator*()
{
	return *cptr;
}

/**
* \brief Gets the iterator at the first element of the array
* \return iterator to first element of the array
*/
template <typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::begin()const
{
	return iterator(tab);
}

/**
* \brief Gets the iterator after the last element of the array
* \return iterator after the last element of the array
*/
template <typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::end()const
{
	return iterator(tab + N);
}

/**
* \brief Gets the const_iterator at the first element of the array
* \return const_iterator to first element of the array
*/
template <typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cbegin()const
{
	return const_iterator(tab);
}

/**
* \brief Gets the const_iterator after the last element of the array
* \return const_iterator after the last element of the array
*/
template <typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cend()const
{
	return const_iterator(tab + N);
}

/**
* \brief Array empty constructor, intialized with template size data
*/
template <typename T, size_t N>
Array<T, N>::Array()
{
	tab = new T[N];
}

/**
* \brief Array destructor, removes dynamically allocated memory
*/
template <typename T, size_t N>
Array<T, N>::~Array()
{
	delete[] tab;
}

/**
* \brief Array copy constructor, uses implicit array and param array of size N to copy values
* \param[in] const array which its values are used to copy into the implicit array
*/
template <typename T, size_t N>
Array<T, N>::Array(const Array<T, N>& source)
{
	for (int i = 0; i < N; ++i)
	{
		tab[i] = source.tab[i];
	}
}

/**
* \brief Finds N size of the array
* \return int containing the size of the array
*/
template <typename T, size_t N>
int Array<T, N>::size()const
{
	return N;
}

/**
* \brief Determines if the array is empty or not (N == 0 or tab == nullptr would have worked too)
* \return bool determining if the array is empty or not
*/
template <typename T, size_t N>
bool Array<T, N>::empty()const
{
	return (N == 0);
}

/**
* \brief Attempts to get the value of the first element in the array
* \return reference T value of the first element in the array
*/
template <typename T, size_t N>
T& Array<T, N>::front()const
{
	return tab[0];
}

/**
* \brief Attempts to get the value of the last element in the array
* \return reference T value of the last element in the array
*/
template <typename T, size_t N>
T& Array<T, N>::back()const
{
	return tab[N - 1];
}

/**
* \brief Attempts to get the value of the first element in the array
* \return const reference T value of the first element in the array
*/
template <typename T, size_t N>
const T& Array<T,N>::front()
{
    return tab[0];
}

/**
* \brief Attempts to get the value of the last element in the array
* \return const reference T value of the last element in the array
*/
template <typename T, size_t N>
const T& Array<T,N>::back()
{
    return tab[N-1];
}

/**
* \brief Fills the array with a param T value
* \param[in] const value T to fill the array with
*/
template <typename T, size_t N>
void Array<T, N>::fill(const T o)
{
	for (int i = 0; i < N; ++i)
		tab[i] = o;
}

/**
* \brief Swaps the variables for the implicit array and the param array
* \param[in] reference array to be able to swap and maintain the swap
*/
template <typename T, size_t N>
void Array<T, N>::swap(Array<T, N>& o)
{
	T *tempPtr = tab;
	tab = o.tab;
	o.tab = tempPtr;
}

/**
* \brief Fuses the implicit array of N size and a param array of M size to make an array of N+M size
* \param[in] const reference array to be able fill the M part of the new array
* \return fused array of type T and size N+M
*/
template <typename T, size_t N> template <size_t M>
Array<T, N+M> Array<T, N>::fusion(const Array<T, M>& o)
{
	Array<T, N + M> outArray;
	for (int i = 0; i < N; ++i)
	{
		outArray[i] = tab[i];
	}
	for (int i = 0; N + i < N + M; ++i)
	{
		outArray[N + i] = o[i];
	}

	return outArray;
}

/**
* \brief Extracts a subset of an array with template param of size M and an index start point in the implicit array
* \param[in] index start point in the implicit array 
* \return subset array of size M
*/
template <typename T, size_t N> template <size_t M>
Array<T, M> Array<T, N>::subset(size_t start)
{
	Array<T, M> outArray;

	//Assumes that the user knows the end of the implicit array(or crash if overflow)
	for (int i = 0; i + start < start + M; ++i)
	{
		outArray[i] = tab[i + start];
	}

	return outArray;

}

/**
* \brief Affects param array to implicit array
* \param[in] const reference array to copy and affect to implicit array
* \return reference to new *this values
*/
template <typename T, size_t N>
Array<T, N>& Array<T, N>::operator=(const Array<T, N>& source)
{
	Array<T, N> o(source);
	std::swap(*this, o);
	return *this;
}

/**
* \brief Move semantics to apply to implicit array and render param array void
* \param[in] array address used to swap with implicit array
* \return reference to new *this values
*/
template <typename T, size_t N>
Array<T, N>& Array<T, N>::operator=(Array<T, N>&& o)
{
	std::swap(o.tab, tab);
	return *this;
}

/**
* \brief Finds value using param index or gives an error
* \param[in] index in the implicit array
* \return value T at the index of the array
*/
template <typename T, size_t N>
T Array<T, N>::at(size_t idx)const
{
	if (idx < N)
	{
		return tab[idx];
	}
	throw std::invalid_argument("Index out of range");
}

/**
* \brief Finds value using param index or compilation error
* \param[in] index in the implicit array
* \return reference value T at the index of the array for modification
*/
template <typename T, size_t N>
T& Array<T, N>::operator[](size_t idx)
{
	return tab[idx];
}

/**
* \brief Finds value using param index or compilation error
* \param[in] index in the implicit array
* \return value T at the index of the array
*/
template <typename T, size_t N>
T Array<T, N>::operator[](size_t idx)const
{
	return tab[idx];
}

/**
* \brief Move semantics to apply to implicit array and render param array void
* \param[in] array address used to swap with implicit array
*/
template <typename T, size_t N>
Array<T, N>::Array(Array<T, N>&& o)
{
	tab = o.tab;
	o.tab = nullptr;
}

#endif

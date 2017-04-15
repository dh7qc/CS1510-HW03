//Dennis Hahn CS1510 Section B Assignment 3
//LinkedList 

#include <iostream>
#include <string>
using namespace std; 

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
	LinkedList<T> *tmp = new LinkedList<T>;

	tmp-> m_data = this-> m_data;
	tmp-> m_next = this-> m_next;
	this-> m_data = x;
	this-> m_next = tmp;
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
	LinkedList<T> *tmp = new LinkedList<T>;

	tmp-> m_data = pos-> m_data;
	tmp-> m_next = pos-> m_next;
	pos-> m_data = x;
	pos-> m_next = tmp;
}


template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if (this != &rhs)
	{
		clear();
		LinkedList<T> *p = this;
		const LinkedList<T> *q = &rhs;

		while (q -> m_next != NULL)  
		{
			p -> m_data = q -> m_data;
			p -> m_next = new LinkedList<T>;
			p = p -> m_next;
			q = q -> m_next; 
		}
	}

	return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	LinkedList<T> *p = this;
	const LinkedList<T> *q = &rhs;

	while (q -> m_next != NULL)    
	{
		p -> m_data = q -> m_data;
		p -> m_next = new LinkedList<T>;
		p = p -> m_next;
		q = q -> m_next; 
	}

}

template <typename T>
int LinkedList<T>::size() const
{
	int counter = 0;
	const LinkedList<T> *p = this;
	
	while(p-> m_next != NULL)
	{
		counter++;
		p = p->m_next; 
	}
	
	return counter;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if (m_next == NULL) 
		return true;
	else 
		return false; 
}


template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
	if (m_next != NULL)
		return this; 
	else
	{
		cout << "!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list";
		cout << endl;

		return NULL;
	}

}


template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
	LinkedList<T> *p = this; 

	if (m_next != NULL) 
	{
		while (p -> m_next != NULL)
		{
			if (p-> m_next -> m_next != NULL)
				p = p-> m_next;
			else 
				return p;
		}
	}

	else 
	{
		cout << "!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list";
		cout << endl;
		return NULL;
	}
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
	int counter = 0;
	LinkedList<T> *p = this; 

	if (i < this -> size() && i >= 0)
	{
		while (p -> m_next != NULL && counter < i) 
		{
			p = p -> m_next;
			counter++;
		}
		return p;
	}
	else 
	{
		cout << "!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index";
		cout << endl;
		return 0;
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	while (m_next != NULL)
	{
		remove(this);
	}
}

template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
	LinkedList<T> *tmp = pos-> m_next;
	pos -> m_data = tmp -> m_data;
	pos -> m_next = tmp -> m_next;
	delete tmp;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
	const LinkedList<T> *p = this;
	const LinkedList<T> *q = &rhs;
	bool equal = true;

	while (q -> m_next != NULL && p -> m_next != NULL && equal != false)
	{
		if (q -> m_data != p -> m_data)
		{
			equal = false;
		}
		else
		{
			q = q -> m_next;
			p = p -> m_next;
		}
	}

	if ((q -> m_next == NULL && p -> m_next != NULL) || 
		((q -> m_next != NULL && p -> m_next == NULL)))
	{
		equal = false;
	}
		
	return equal;
}

template <typename T>
void LinkedList<T>::reverse()
{
	LinkedList<T> *p = this;
	LinkedList<T> *q;

	while (p -> m_next != NULL)  
	{
		q = getLastPtr();
		insert(q -> m_data, p); 
		remove(q);
		p = p -> m_next;
	}
}

template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
	LinkedList<T> *p = this; 
	bool found = false;

	while (p -> m_next != NULL && found == false)
	{
		if (p-> m_data == x)
			found = true;
		else 
			p = p -> m_next;
	}

	if (found == true)
		return p;
	else
		return NULL;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
	const LinkedList<T> *p = &xlist;

	while (p -> m_next != NULL) 
	{	
		insert(p -> m_data, getLastPtr()->m_next);
		p = p -> m_next;
	}	
}

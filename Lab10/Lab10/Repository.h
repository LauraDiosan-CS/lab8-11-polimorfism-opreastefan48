#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class Repository{
protected:
	vector<T> elem;
public:
	Repository();
	void add(T&);
	int find_elem(T&);
	void update(T&, T&);
	void remove(int);
	int size();
	vector<T> getAll();
};

template<class T>
inline Repository<T>::Repository()
{
}

template<class T>
inline void Repository<T>::add(T &e)
{
	elem.push_back(e);
}

template<class T>
inline int Repository<T>::find_elem(T & e)
{
	auto it=std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}

template<class T>
inline void Repository<T>::update(T & vechi, T & nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline void Repository<T>::remove(int id)
{
	int i = 0, gasit = 0;
	while (gasit == 0 && i < this->size()) {
		if (elem[i].getID() == id)
			gasit = 1;
		i++;
	}

	typename vector<T>::iterator it;
	it = find(elem.begin(), elem.end(), elem[i - 1]);
	if (gasit)
		elem.erase(it);
}

template<class T>
inline int Repository<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> Repository<T>::getAll()
{
	return elem;
}

#pragma once
#include "Repository.h"
template <class T> class RepositoryInMemory :
	public Repository<T>
{
public:
	RepositoryInMemory() :Repository<T>() {};
	~RepositoryInMemory() {};
};


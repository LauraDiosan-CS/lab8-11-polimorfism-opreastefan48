#pragma once
template <class T> class RepositoryFileTXT:public RepositoryFile<T>
{
public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char*);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileTXT();
};

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT()
{
}

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(const char * fName):RepositoryFile<T>(fName)
{
}

template<class T>
inline void RepositoryFileTXT<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		T ob(line, ' ');
		Repository<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepositoryFileTXT<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	for (T crt : Repository<T>::elem) {
		f << crt.toStringDelimiter(' ') << endl;
	}
}

template<class T>
inline RepositoryFileTXT<T>::~RepositoryFileTXT()
{
}

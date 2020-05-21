#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "Medicament.h"
#include "User.h"

class MedicineService
{
private:
	Repository<Medicament>* repoMed;
	Repository<User>* repoUser;

public:
	MedicineService();

	MedicineService(Repository<Medicament>* repoMed, Repository<User>* repoUser);
	MedicineService(Repository<Medicament>* repoMed);

	void add(Medicament &m);
	void update(Medicament &m1, Medicament &m2);
	void remove(int);
	bool login(string, string);
	vector<Medicament> search(string);

	vector<Medicament> getAll();

	~MedicineService();
};


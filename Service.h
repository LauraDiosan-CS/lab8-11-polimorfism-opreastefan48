#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "Medicament.h"

class MedicineService
{
private:
	Repository<Medicament>* repoMed;

public:
	MedicineService();

	MedicineService(Repository<Medicament>* repomed);

	void add(Medicament &m);
	void update(Medicament &m1, Medicament &m2);
	void remove(int);
	vector<Medicament> search(string);

	vector<Medicament> getAll();

	~MedicineService();
};


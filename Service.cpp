#include "Service.h"



MedicineService::MedicineService()
{
}

MedicineService::MedicineService(Repository<Medicament>* repomed)
{
	this->repoMed = repomed;

}


void MedicineService::add(Medicament &m)
{
	repoMed->add(m);
}

void MedicineService::update(Medicament &m1,Medicament &m2)
{
	repoMed->update(m1, m2);
}
void MedicineService::remove(int id)
{
	repoMed->remove(id);
}

vector<Medicament> MedicineService::search(string s)
{
	vector<Medicament> res;
	for (Medicament med : repoMed->getAll())
		if (med.getNume().find(s) != string::npos)
			res.push_back(med);
	return res;
}


vector<Medicament> MedicineService::getAll()
{
	return repoMed->getAll();
}

MedicineService::~MedicineService()
{
}

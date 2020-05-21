#include "Service.h"
#include "User.h"



MedicineService::MedicineService()
{
}

MedicineService::MedicineService(Repository<Medicament>* repomed, Repository<User>* repoUseri)
{
	this->repoMed = repomed;
	this->repoUser = repoUseri;
	User u1("Ana", "123");
	User u2("Ion", "1234");
	repoUser->add(u1);
	repoUser->add(u2);
}

MedicineService::MedicineService(Repository<Medicament>* repoMed)
{
}


bool MedicineService::login(string u, string p)
{
	User usr(u, p);

	return repoUser->find_elem(usr) != -1;
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

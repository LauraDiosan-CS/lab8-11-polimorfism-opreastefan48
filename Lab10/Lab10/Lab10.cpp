#include <iostream>
#include "TestsService.h"
#include "Tests.h"
#include "Medicament.h"
#include "Repository.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryInMemory.h"
#include "Service.h"
#include "UI.h"

int main()
{
    teste();
    testeService();

	Repository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>("Medicament.csv");
	((RepositoryFile<Medicament>*)repoMed)->loadFromFile();
	
	Repository<User>* repoUser = new RepositoryInMemory<User>();


	MedicineService s(repoMed, repoUser);
	UI ui(s);
	ui.showMenu();
    return 0;
}

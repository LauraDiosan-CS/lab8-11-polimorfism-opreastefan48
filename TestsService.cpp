#pragma once
#include "TestsService.h"
#include <assert.h>
#include "RepositoryInMemory.h"
#include "Service.h"

void testeService(){
	Repository<Medicament>* repoMed = new RepositoryFileTXT<Medicament>;

	MedicineService * service = new MedicineService{ repoMed };

	Medicament m1 = Medicament(100, "parasinus", false, 10, "p1");
	Medicament m2 = Medicament(200, "ketonal", false, 90, "p2");
	Medicament m3 = Medicament(300, "antibiotic", true, 70, "p3");

	service->add(m1);
	service->add(m2);
	assert(service->getAll().size() == 2);
	assert(service->getAll()[0] == m1);
	assert(service->getAll()[1] ==m2);
	service->add(m3);
	assert(service->getAll()[2] == m3);

	assert(service->search("ic").size() == 1);
	assert(service->search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service->update(m1, m1_new);

	assert(service->search("al").size() == 2);
	assert(service->search("al")[0] == m1_new);
	assert(service->search("al")[1] == m2);
	service->remove(200);
	assert(service->search("al").size() == 1);
	assert(service->search("al")[0] == m1_new);
}

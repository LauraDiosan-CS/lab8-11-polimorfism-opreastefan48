#pragma once
#include <string>
#include "Service.h"
#include "User.h"
using namespace std;

class UI
{
private:
	MedicineService serv;
	User u;
	void AddMed();
	void UpdateMed();
	void RemoveMed();
	void Continue(int &gata);
	int login();

public:
	UI();
	UI(MedicineService&);
	void showMenu();
	~UI();
};


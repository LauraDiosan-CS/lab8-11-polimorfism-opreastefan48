#include "UI.h"
#include <iostream>
#include "Service.h"
using namespace std;



int UI::login()
{
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Dati user: ";
	cin >> user;
	cout << endl << "Parola:";
	cin >> pass;
	return serv.login(user, pass);
}





void UI::AddMed()
{
	int ID,nr_stoc;
	string nume,producator;
	bool reteta;
	char x;
	cout << "Dati ID-ul Medicamentului:";
	cin >> ID;

	cout << "Dati Numele Medicamentului:";
	cin >> nume;

	cout << "Necesita Reteta? (da/nu): "; \

		cin >> x;
	if (x == 'da' or x == 'Da' or x == 'DA' or x == 'dA')
		reteta = 1;
	else
		if (x == 'nu' or x == 'Nu' or x == 'NU' or x == 'nU')
			reteta = 0;

	cout << "Dati Numarul de Stoc:";
	cin >> nr_stoc;

	cout << "Dati Producatorul Medicamentului:";
	cin >> producator;

	

	Medicament m = Medicament(ID,nume,reteta,nr_stoc,producator);
	serv.add(m);
	cout << "Medicamentul a fost adaugat cu succes." << endl;
}

void UI::UpdateMed()
{



	//serv.update(m1, m2);
}

void UI::RemoveMed()
{
	//serv.remove(id)
}

void UI::Continue(int &gata)
{
	cout << "1. Delogare si inchidere program. ";
	cout << "2. Schimbare User: "; \
	int x;
	cin >> x;
	if (x == 1)
		gata = 1;
	else
		if (login())
			x = login();

}





UI::UI()
{
}


UI::UI(MedicineService& ss)
{
	serv = ss;
}

void UI::showMenu()
{
	int gata = 0;
	int rez = login();
	if (rez != -1) {
		while (!gata) {
			cout << "1. Adaugare Medicament: " << endl;
			cout << "2. Editare Medicament: " << endl;
			cout << "3. Stergere Medicament: " << endl;
			cout << "0. Logout" << endl;
			int opt;
			cout << "Dati optiunea: " << endl;
			cin >> opt;
			switch (opt) {
			case 1: {AddMed(); break; }
			case 2: {UpdateMed(); break; }
			case 3: {RemoveMed(); break; }
			case 0: {Continue(gata); break;}
			}

		}
	}
	else cout << "Autentificare esuata!" << endl;
}

UI::~UI()
{
}

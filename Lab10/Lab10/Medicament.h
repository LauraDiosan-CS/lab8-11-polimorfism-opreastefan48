#pragma once
#include <iostream>
#include <string>
using namespace std;

class Medicament {
private:
	string nume;
	string producator;
	int id,nr_stoc;
	bool reteta;
public:
	Medicament();
	Medicament(int ,string , bool, int, string );
	Medicament(string, char);


	void setReteta(bool);
	void setNume(string);
	void setProducator(string);
	void setID(int);
	void setNr_Stoc(int);

	string getProducator();
	string getNume();
	int getID();
	int getNr_Stoc();
	bool getReteta();
	string toString();
	string toStringDelimiter(char);
	bool operator==(const Medicament&);
	bool operator!=(const Medicament&);
	
	~Medicament();
};


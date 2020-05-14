#include "Medicament.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Medicament::Medicament()
{
}

Medicament::Medicament(int ID, string num, bool ret, int nr, string prod)
{
	id = ID;
	nume= num;
	reteta = ret;
	nr_stoc = nr;
	producator = prod;
}

Medicament::Medicament(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	id = stoi(tokens[0]);
	nume = tokens[1];
	reteta = stoi(tokens[2]);
	nr_stoc = stoi(tokens[3]);
	producator = tokens[4];
}
int Medicament::getID()
{
	return id;
}
std::string Medicament::getNume()
{
	return nume;
}

bool Medicament::getReteta()
{
	return reteta;
}

int Medicament::getNr_Stoc()
{
	return nr_stoc;
}

string Medicament::getProducator()
{
	return producator;
}

void Medicament::setID(int ID)
{
	id = ID;
}
void Medicament::setNume(string nume)
{
	nume = nume;
}

void Medicament::setReteta(bool ret)
{
	reteta = ret;
}

void Medicament::setNr_Stoc(int nr)
{
	nr_stoc = nr;
}

void Medicament::setProducator(std::string prod)
{
	producator = prod;
}
bool Medicament::operator==(const Medicament& m)
{
	return (id == m.id && nume == m.nume && reteta == m.reteta && nr_stoc == m.nr_stoc && producator == m.producator);
}

bool Medicament::operator!=(const Medicament& m)
{
	return (id != m.id || nume != m.nume || reteta != m.reteta || nr_stoc != m.nr_stoc || producator != m.producator);
}


std::string Medicament::toString()
{
	return to_string(id) + " " + nume + " " + to_string(reteta) + " " + to_string(nr_stoc) + " " + producator;
}
std::string Medicament::toStringDelimiter(char delim)
{
	return to_string(id) + delim + nume + delim + to_string(reteta) + delim + to_string(nr_stoc) + delim + producator;
}
Medicament::~Medicament()
{
}
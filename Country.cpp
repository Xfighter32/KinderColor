#include "Country.h"

Country::Country(string pId, string pName) 
{
	this->id = pId;
	this->name = pName;
}

void Country::addNeighbor(Country * pNeighbor)
{
	this->neighbors[pNeighbor->getId()] = pNeighbor;
	pNeighbor->addNeighborAux(this);
}

void Country::addNeighborAux(Country * pNeighbor)
{
	this->neighbors[pNeighbor->getId()] = pNeighbor;
}

void Country::setColor(string pColor)
{
	this->color = pColor;
}

int Country::getConections()
{
	return conections;
}

void Country::setConections()
{
	this->conections = this->neighbors.size();
}

void Country::setConections(int pConections)
{
	this->conections = pConections;
}

vector<string> Country::getRestrictedColors()
{
	return this->restrictedColors;
}

void Country::addColorRestriction(string pColorCode)
{
	this->restrictedColors.push_back(pColorCode);
}

string Country::getColor()
{
	return this->color;
}

unordered_map<string, Country*> Country::getNeighbors()
{
	return this->neighbors;
}

string Country::getName()
{
	return this->name;
}

string Country::getId()
{
	return id;
}

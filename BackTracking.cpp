#include "BackTracking.h"

BackTracking::BackTracking(Observer* pObserver)
{
	this->fileName = "WorldBackTracking.svg";
	this->observer = pObserver;
}

void BackTracking::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	colorPallete = pColorPallete;
	std::vector<Country*>::iterator firstVectorElement = pCountries.begin();
	bruteForce(pCountries, firstVectorElement);
	cout << "End";
}

void BackTracking::bruteForce(vector<Country*> pVector, std::vector<Country*>::iterator pFirstCountry/*Pasar los colores */) {
	std::vector<Country*>::iterator currentIterator = pVector.begin();
	if (currentIterator != pVector.end())
	{
		Country* currentCountry = *currentIterator;
		for (const auto& color : colorPallete)
		{
			if (!endOfAlgorithm) {
				tryToPaint(currentCountry, color);
				if (currentCountry->isColored())
				{
					bruteForce(vector<Country*>(next(currentIterator), pVector.end()), pFirstCountry);
				}
			}
		}
		if (!currentCountry->isColored() && triggeredBackTracking == NULL) {
			triggeredBackTracking = currentCountry;
		}
		if (*pVector.begin() == *pFirstCountry && triggeredBackTracking != NULL) {
			cout << triggeredBackTracking->getId();
			cout << "Llega al primero";
			Country* current2 = *pFirstCountry;
			cout << current2->getId();
			pVector.erase(std::remove(pVector.begin(), pVector.end(), triggeredBackTracking));
			cout << pVector.size();
			triggeredBackTracking = NULL;
			bruteForce(pVector, pFirstCountry);
		}
	}
	else
		endOfAlgorithm = true;
}

void BackTracking::tryToPaint(Country* pCountry, string color)//Podia ser un metodo que tuviera el country, pero solo va a ser usado aca
{
	bool paint = true;
	for (auto pair : pCountry->getNeighborsHash()) {
		if (pair.second->getColor() == color) {
			paint = false;
			break;
		}
	}
	if (paint)
		pCountry->setColor(color);
	else 
		pCountry->unPaint();
}
//No hay una buena distribucion de colores
//El algoritmo dura demasiado o falla con 4 colores, seguramente al aumento de pruebas del ciclo
//Puede que se necesite una poda mas significativa
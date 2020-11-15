#pragma once

#include "Includes.h"
#include "Parser.h"
#include "Strategy.h"

class Map {
private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	int colorAmount;
	string pallete[3] = { "FF4533","47FF33","F6FF33" };
	//Painter painter;
	Strategy currentStrategy;
	int alreadyPainted;
public:
	Map();
	Map(string pStrategy, int pColorAmount);

	void setStrategy(string pStrategy);
	void setColorAmount(int pColorAmount);
	void rotatePallete();
	vector<Country *> prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy
	void paint();
};
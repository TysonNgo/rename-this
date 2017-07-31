#include "ComboColour.h"

ComboColour::ComboColour(int r, int g, int b){
	this->setRed(r);
	this->setGreen(g);
	this->setBlue(b);
};

void ComboColour::setColour(int &rgb, int rgbValue){
	int value;
	if (rgbValue > 255){
		value = 255;
	} else if (rgbValue < 0){
		value = 0;
	} else{
		value = rgbValue;
	}
	rgb = value;
}

int ComboColour::getRed() const{
	return this->r;
}

int ComboColour::getGreen() const{
	return this->g;
}

int ComboColour::getBlue() const{
	return this->b;
}

void ComboColour::setRed(int r){
	this->setColour(this->r, r);
}

void ComboColour::setGreen(int g){
	this->setColour(this->g, g);
}

void ComboColour::setBlue(int b){
	this->setColour(this->b, b);
}

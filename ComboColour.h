#ifndef COMBOCOLOUR_H
#define COMBOCOLOUR_H

class ComboColour{
private:
	int r;
	int g;
	int b;

	void setColour(int &rgb, int rgbValue);
public:
	ComboColour();
	ComboColour(int r, int g, int b);
	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	void setRed(int r);
	void setGreen(int g);
	void setBlue(int g);
};

#endif
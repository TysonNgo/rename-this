#ifndef SPINNER_H
#define SPINNER_H
#include "HitObject.h"

class Spinner : public HitObject {
private:
	int endTime;
public:
	Spinner();
	Spinner(int x, int y, int time, int type, int hitSound, int endTime);
	Spinner(int time, int type, int hitSound, int endTime);
	int getEndTime() const;

	void setPoint(int x, int y);
	void setX(int x);
	void setY(int y);
	void setTime(int begin, int end);
	void setEndTime(int time);
};

#endif

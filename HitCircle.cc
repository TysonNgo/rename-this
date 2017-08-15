#include "HitCircle.h"

HitCircle::HitCircle() :
	HitCircle::HitCircle(0, 0, 0, 1, 0)
{};

HitCircle::HitCircle(int x, int y, int time, int type, int hitSound):
	HitObject(x, y, time, type, hitSound)
{};

int HitCircle::getEndTime() const{
	return this->time;
}

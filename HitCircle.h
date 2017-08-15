#ifndef HITCIRCLE_H
#define HITCIRCLE_H
#include "HitObject.h"

class HitCircle : public HitObject {
public:
	HitCircle();
	HitCircle(int x, int y, int time, int type, int hitSound);
	int getEndTime() const;
};

#endif

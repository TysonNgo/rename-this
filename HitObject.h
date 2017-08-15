#ifndef HITOBJECT_H
#define HITOBJECT_H

#include "Addition.h"

// hit circle syntax
// x,y,time,type,hitSound,addition
// 164,260,2434,1,0,0:0:0:0:

// slider syntax
// x,y,time,type,hitSound,
// sliderType|curvePoints,repeat,pixelLength,
// edgeHitsounds,edgeAdditions,addition
// 424,96,66,2,0,B|50:120|0:10|0:10,1,130,2|0,0:0|0:0,0:0:0:0:

// x,y,time,type,hitSound,endTime,addition
// 256,192,730,8,8,3983

struct Point{
	int x;
	int y;
	friend Point operator+(const Point& p1, const Point& p2){
		return Point{(int)(p1.x + p2.x),(int)( p1.y + p2.y)};
	}
	friend Point operator*(const Point& p1, const Point& p2){
		return Point{(int)(p1.x * p2.x),(int)( p1.y * p2.y)};
	}
	friend Point operator*(const Point& pt, const double& i){
		return Point{(int)(pt.x*i),(int)(pt.y*i)};
	}
	friend Point operator*(const double& i, const Point& pt){
		return Point{(int)(pt.x*i),(int)(pt.y*i)};
	}
};

class HitObject {
protected:
	Point pt;
	int time;
	int type;
	int hitSound;
public:
	Addition additions;

	HitObject(int x, int y, int time, int type, int hitSound);

	Point getPoint() const;
	int getX() const;
	int getY() const;
	int getTime() const;
	int getType() const;
	int getHitSound() const;

	// virtual because spinner points should not change
	virtual void setPoint(int x, int y);
	virtual void setX(int x);
	virtual void setY(int y);
	void setTime(int time);
	void setHitSound(int hitSound);

	virtual int getEndTime() const = 0;
};

#endif

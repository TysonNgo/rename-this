#include "HitObject.h"

HitObject::HitObject(int x, int y, int time, int type, int hitSound):
	pt{x,y},
	time{time},
	type{type},
	hitSound{hitSound}
{};

Point HitObject::getPoint() const{
	return this->pt;
}

int HitObject::getX() const{
	return this->pt.x;
}

int HitObject::getY() const{
	return this->pt.y;
}

int HitObject::getTime() const{
	return this->time;
}

int HitObject::getType() const{
	return this->type;
}

int HitObject::getHitSound() const{
	return this->hitSound;
}

void HitObject::setPoint(int x, int y){
	this->pt.x = x;
	this->pt.y = y;
}

void HitObject::setX(int x){
	this->pt.x = x;
}

void HitObject::setY(int y){
	this->pt.y = y;
}

void HitObject::setTime(int time){
	this->time = time;
}

void HitObject::setHitSound(int hitSound){
	this->hitSound = hitSound;
}

#include "Spinner.h"

#define ORIGIN_X 256
#define ORIGIN_Y 192

Spinner::Spinner():
	Spinner::Spinner(0, 8, 0, 0)
{};

Spinner::Spinner(int x, int y, int time, int type, int hitSound, int endTime):
	Spinner::Spinner(time, type, hitSound, endTime)
{};

Spinner::Spinner(int time, int type, int hitSound, int endTime):
	HitObject(ORIGIN_X, ORIGIN_Y, time, type, hitSound),
	endTime{endTime}
{};

void Spinner::setPoint(int x, int y){
	Spinner::setX(x);
	Spinner::setY(y);
}

void Spinner::setX(int x){
	this->pt.x = (this->pt.x != ORIGIN_X) ? ORIGIN_X : this->pt.x;
}

void Spinner::setY(int y){
	this->pt.y = (this->pt.y != ORIGIN_Y) ? ORIGIN_Y : this->pt.y;
}

void Spinner::setTime(int begin, int end){
	this->time = begin;
	this->endTime = end;
}

void Spinner::setEndTime(int time){
	this->endTime = time;
}

int Spinner::getEndTime() const{
	return this->endTime;
}
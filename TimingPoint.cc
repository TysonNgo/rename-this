#include "TimingPoint.h"

using namespace std;

TimingPoint::TimingPoint(string tp):
	meter{4},
	sampleType{1},
	sampleSet{1},
	volume{100},
	inherited{1}
{
	if (tp.length() <= 1){return;}
	string line;
	stringstream ss{tp};

	int i = 0;
	int vol;

	while (getline(ss, line, ',')){
		switch(i){
			case 0: this->offset = stol(line); break;
			case 1: this->mspb = stod(line); break;
			case 2: this->meter = stoi(line); break;
			case 3: this->sampleType = stoi(line); break;
			case 4: this->sampleSet = stoi(line); break;
			case 5: 
				vol = stoi(line);
				if (vol >=0 && vol<=100){
					this->volume = vol; 
				}
				break;
			case 6: this->inherited = stoi(line); break;
			case 7: this->kiai = stoi(line); break;
			default: break;
		}
		i++;
	}
};

TimingPoint::TimingPoint(
		int offset, double mspb, int meter,
		int sampleType, int sampleSet,
		int volume, bool inherited, bool kiai):
	offset{offset},
	mspb{mspb},
	meter{meter},
	sampleType{sampleType},
	sampleSet{sampleSet},
	volume{volume},
	inherited{inherited},
	kiai{kiai}
{};

int TimingPoint::getOffset() const{
	return this->offset;
}

double TimingPoint::getMspb() const{
	return this->mspb;
}

int TimingPoint::getMeter() const{
	return this->meter;
}

int TimingPoint::getSampleType() const{
	return this->sampleType;
}

int TimingPoint::getSampleSet() const{
	return this->sampleSet;
}

int TimingPoint::getVolume() const{
	return this->volume;
}

bool TimingPoint::getInherited() const{
	return this->inherited;
}

bool TimingPoint::getKiai() const{
	return this->kiai;
}

void TimingPoint::setOffset(int offset){
	this->offset = offset;
}

void TimingPoint::setMspb(double mspb){
	this->mspb = mspb;
}

void TimingPoint::setMeter(int meter){
	this->meter = meter;
}

void TimingPoint::setSampleType(int sampleType){
	this->sampleType = sampleType;
}

void TimingPoint::setSampleSet(int sampleSet){
	this->sampleSet = sampleSet;
}

void TimingPoint::setVolume(int volume){
	this->volume = volume;
}

void TimingPoint::setInherited(bool inherited){
	this->inherited = inherited;
}

void TimingPoint::setKiai(bool kiai){
	this->kiai = kiai;
}

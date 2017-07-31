#ifndef TIMINGPOINT_H
#define TIMINGPOINT_H

#include <string>
#include <sstream>
#include <iostream>

class TimingPoint {
private:
	int offset;
	double mspb;
	int meter;
	int sampleType;
	int sampleSet;
	int volume; // 0-100
	bool inherited;
	bool kiai;
public:
	TimingPoint();
	TimingPoint(std::string tp);
	TimingPoint(
		int offset,
		double mspb,
		int meter,
		int sampleType,
		int sampleSet,
		int volume,
		bool inherited,
		bool kiai
	);
	int getOffset() const;
	double getMspb() const;
	int getMeter() const;
	int getSampleType() const;
	int getSampleSet() const;
	int getVolume() const;
	bool getInherited() const;
	bool getKiai() const;

	void setOffset(int offset);
	void setMspb(double mspb);
	void setMeter(int meter);
	void setSampleType(int sampleType);
	void setSampleSet(int sampleSet);
	void setVolume(int volume);
	void setInherited(bool inherited);
	void setKiai(bool kiai);
};

#endif

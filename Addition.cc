#include "Addition.h"

using namespace std;

Addition::Addition():
	Addition::Addition(0,0,0,0,"")
{};

Addition::Addition(
	int sampleSet
):
	Addition::Addition(sampleSet, 0, 0, 0, "")
{};

Addition::Addition(
	int sampleSet, int additions
):
	Addition::Addition(sampleSet, additions, 0, 0, "")
{};

Addition::Addition(
	int sampleSet, int additions, int customIndex
):
	Addition::Addition(sampleSet, additions, customIndex, 0, "")
{};

Addition::Addition(
	int sampleSet, int additions,
	int customIndex, int sampleVolume
):
	Addition::Addition(
		sampleSet, additions,
		customIndex, sampleVolume, ""
	)
{};

Addition::Addition(
	int sampleSet, int additions,
	int customIndex, int sampleVolume,
	string filename
):
	sampleSet{sampleSet},
	additions{additions},
	customIndex{customIndex},
	sampleVolume{sampleVolume},
	filename{filename}
{};

int Addition::getSampleSet() const{
	return this->sampleSet;
}

int Addition::getAdditions() const{
	return this->additions;
}

int Addition::getCustomIndex() const{
	return this->customIndex;
}

int Addition::getSampleVolume() const{
	return this->sampleVolume;
}

string Addition::getFilename() const{
	return this->filename;
}

void Addition::setSampleSet(int sampleSet){
	this->sampleSet = sampleSet;
}

void Addition::setAdditions(int additions){
	this->additions = additions;
}

void Addition::setCustomIndex(int customIndex){
	this->customIndex = customIndex;
}

void Addition::setSampleVolume(int sampleVolume){
	this->sampleVolume = sampleVolume;
}

void Addition::setFilename(string filename){
	this->filename = filename;
}

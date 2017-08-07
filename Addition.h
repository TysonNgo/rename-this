#ifndef ADDITION_H
#define ADDITION_H

#include <string>

// addition (sampleSet:additions:customIndex:sampleVolume:filename)

class Addition{
private:
	int sampleSet;
	int additions;
	int customIndex;
	int sampleVolume;
	std::string filename;
public:
	Addition();
	Addition(int sampleSet);
	Addition(int sampleSet, int additions);
	Addition(
		int sampleSet, int additions, int customIndex
	);
	Addition(
		int sampleSet, int additions,
		int customIndex, int sampleVolume
	);
	Addition(
		int sampleSet, int additions,
		int customIndex, int sampleVolume,
		std::string filename
	);
	int getSampleSet() const;
	int getAdditions() const;
	int getCustomIndex() const;
	int getSampleVolume() const;
	std::string getFilename() const;

	void setSampleSet(int sampleSet);
	void setAdditions(int additions);
	void setCustomIndex(int customIndex);
	void setSampleVolume(int sampleVolume);
	void setFilename(std::string filename);
};

#endif
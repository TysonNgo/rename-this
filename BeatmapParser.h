#ifndef BEATMAPPARSER_H
#define BEATMAPPARSER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include "Beatmap.h"

class Beatmap;

namespace BeatmapParser{
	void parseBeatmap(Beatmap* beatmap, std::ifstream &beatmapFile);
}

#endif
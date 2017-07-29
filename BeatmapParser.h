#ifndef BEATMAPPARSER_H
#define BEATMAPPARSER_H

#include <iostream>
#include "Beatmap.h"

class Beatmap;

namespace BeatmapVersions{
	void parseBeatmap(Beatmap* b);
}

#endif
#ifndef BEATMAP_H
#define BEATMAP_H

#include <fstream>
#include <string>
#include <vector>

#include "HitObject.h"
#include "TimingPoint.h"

class Beatmap {
    private:
        float ar, cs, od, hp;
        std::vector<HitObject> hitObjects;
        std::vector<TimingPoint> timingPoints;
    public:
        Beatmap(std::string b);
        Beatmap(std::ifstream &b);
};

#endif

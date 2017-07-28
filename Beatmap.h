#ifndef BEATMAP_H
#define BEATMAP_H

#include "BeatmapVersions.h"

#include <array>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

//#include "HitObject.h"
//#include "TimingPoint.h"

class Beatmap {
    private:
        // osu file format that will be saved is v14
        int osuFileFormat;

        // General
        std::string audioFilename;
        int audioLeadIn;
        int previewTime;
        int countdown;
        std::string sampleSet;
        float stackLeniency;
        int mode;
        int letterboxInBreaks;
        int widescreenStoryboard;

        // Editor
        std::vector<int> bookmarks;
        float distanceSpacing;
        int beatDivisor;
        int gridSize;
        int timelineZoom;

        // Metadata
        std::string title;
        std::string titleUnicode;
        std::string artist;
        std::string artistUnicode;
        std::string creator;
        std::string version;
        std::string source;
        std::string tags;
        std::string beatmapID;
        std::string beatmapsetID;

        // Difficulty
        float approachRate;
        float circleSize;
        float overallDifficulty;
        float HPDrainRate;
        float sliderMultiplier;
        float sliderTickRate;
        
        // Events
        // this is storyboard stuff
        // besides break periods, I am not entirely sure
        // what goes here at the moment

//        std::vector<TimingPoint> timingPoints;

        // Colours
        std::vector<std::array<int,3>> colours;

//        std::vector<HitObject> hitObjects;
    public:
        Beatmap(std::string b);
        Beatmap(std::ifstream &b);
        
        int getOsuFileFormat();
        std::string getAudioFilename();
        int getAudioLeadIn();
        int getPreviewTime();
        int getCountdown();
        std::string getSampleSet();
        float getStackLeniency();
        int getMode();
        int getLetterboxInBreaks();
        int getWidescreenStoryboard();
        std::vector<int> getBookmarks();
        float getDistanceSpacing();
        int getBeatDivisor();
        int getGridSize();
        int getTimelineZoom();
        std::string getTitle();
        std::string getTitleUnicode();
        std::string getArtist();
        std::string getArtistUnicode();
        std::string getCreator();
        std::string getVersion();
        std::string getSource();
        std::string getTags();
        std::string getBeatmapID();
        std::string getBeatmapsetID();
        float getApproachRate();
        float getCircleSize();
        float getOverallDifficulty();
        float getHPDrainRate();
        float getSliderMultiplier();
        float getSliderTickRate();
//        std::vector<TimingPoint> getTimingPoints();
        std::vector<std::array<int,3>> getColours();
//        std::vector<HitObject> getHitObjects();

        void setOsuFileFormat(int osuFileFormat);
        void setAudioFilename(std::string audioFilename);
        void setAudioLeadIn(int audioLeadIn);
        void setPreviewTime(int previewTime);
        void setCountdown(int countdown);
        void setSampleSet(std::string sampleSet);
        void setStackLeniency(float stackLeniency);
        void setMode(int mode);
        void setLetterboxInBreaks(int letterboxInBreaks);
        void setWidescreenStoryboard(int widescreenStoryboard);
        void setBookmarks(std::vector<int> bookmarks);
        void setDistanceSpacing(float distanceSpacing);
        void setBeatDivisor(int beatDivisor);
        void setGridSize(int gridSize);
        void setTimelineZoom(int timelineZoom);
        void setTitle(std::string title);
        void setTitleUnicode(std::string titleUnicode);
        void setArtist(std::string artist);
        void setArtistUnicode(std::string artistUnicode);
        void setCreator(std::string creator);
        void setVersion(std::string version);
        void setSource(std::string source);
        void setTags(std::string tags);
        void setBeatmapID(std::string beatmapID);
        void setBeatmapsetID(std::string beatmapsetID);
        void setApproachRate(float approachRate);
        void setCircleSize(float circleSize);
        void setOverallDifficulty(float overallDifficulty);
        void setHPDrainRate(float HPDrainRate);
        void setSliderMultiplier(float sliderMultiplier);
        void setSliderTickRate(float sliderTickRate);
//        void setTimingPoints(std::vector<TimingPoint> timingPoints);
        void setColours(std::vector<std::array<int,3>> colours);
//        void setHitObjects(std::vector<HitObject> hitObjects);

        void saveBeatmap();
};

#endif

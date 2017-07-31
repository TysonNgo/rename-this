#ifndef BEATMAP_H
#define BEATMAP_H

#include "BeatmapParser.h"
#include "ComboColour.h"

#include <fstream>
#include <string>
#include <vector>

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
        std::vector<ComboColour> comboColours;

//        std::vector<HitObject> hitObjects;
    public:
        Beatmap(std::string b);
        Beatmap(std::ifstream &b);
        
        int getOsuFileFormat() const;
        std::string getAudioFilename() const;
        int getAudioLeadIn() const;
        int getPreviewTime() const;
        int getCountdown() const;
        std::string getSampleSet() const;
        float getStackLeniency() const;
        int getMode() const;
        int getLetterboxInBreaks() const;
        int getWidescreenStoryboard() const;
        std::vector<int> getBookmarks() const;
        float getDistanceSpacing() const;
        int getBeatDivisor() const;
        int getGridSize() const;
        int getTimelineZoom() const;
        std::string getTitle() const;
        std::string getTitleUnicode() const;
        std::string getArtist() const;
        std::string getArtistUnicode() const;
        std::string getCreator() const;
        std::string getVersion() const;
        std::string getSource() const;
        std::string getTags() const;
        std::string getBeatmapID() const;
        std::string getBeatmapSetID() const;
        float getApproachRate() const;
        float getCircleSize() const;
        float getOverallDifficulty() const;
        float getHPDrainRate() const;
        float getSliderMultiplier() const;
        float getSliderTickRate() const;
//        std::vector<TimingPoint> getTimingPoints() const;
        std::vector<ComboColour> getComboColours() const;
//        std::vector<HitObject> getHitObjects() const;

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
//        void setHitObjects(std::vector<HitObject> hitObjects);

        void addComboColour(int r, int g, int b);
        void saveBeatmap();
};

#endif

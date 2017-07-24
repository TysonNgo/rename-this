#include "Beatmap.h"

using namespace std;

#include <iostream>

#define currentVersion 14;

Beatmap::Beatmap(string b){

};

Beatmap::Beatmap(ifstream &b){
    string line;
    smatch result;

    // first line of a .osu file contains the version
    getline(b,line);

    this->osuFileFormat = (
        regex_search(line, result,regex{"v(\\d+)"})
    ) ? stoi(result[1]) : currentVersion;

    while (getline(b, line)){
        switch (this->osuFileFormat){
            // I have found that there exists only v3-14
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:

        }
    }
};

int Beatmap::getOsuFileFormat(){
    return 1;
}
string Beatmap::getAudioFilename(){
    return "";
}
int Beatmap::getAudioLeadIn(){
    return 1;
}
int Beatmap::getPreviewTime(){
    return 1;
}
int Beatmap::getCountdown(){
    return 1;
}
string Beatmap::getSampleSet(){
    return "";
}
float Beatmap::getStackLeniency(){
    return 1.0;
}
int Beatmap::getMode(){
    return 1;
}
int Beatmap::getLetterboxInBreaks(){
    return 1;
}
int Beatmap::getWidescreenStoryboard(){
    return 1;
}
vector<int> Beatmap::getBookmarks(){

}
float Beatmap::getDistanceSpacing(){
    return 1.0;
}
int Beatmap::getBeatDivisor(){
    return 1;
}
int Beatmap::getGridSize(){
    return 1;
}
int Beatmap::getTimelineZoom(){
    return 1;
}
string Beatmap::getTitle(){
    return "";
}
string Beatmap::getTitleUnicode(){
    return "";
}
string Beatmap::getArtist(){
    return "";
}
string Beatmap::getArtistUnicode(){
    return "";
}
string Beatmap::getCreator(){
    return "";
}
string Beatmap::getVersion(){
    return "";
}
string Beatmap::getSource(){
    return "";
}
string Beatmap::getTags(){
    return "";
}
string Beatmap::getBeatmapID(){
    return "";
}
string Beatmap::getBeatmapsetID(){
    return "";
}
float Beatmap::getApproachRate(){
    return 1.0;
}
float Beatmap::getCircleSize(){
    return 1.0;
}
float Beatmap::getOverallDifficulty(){
    return 1.0;
}
float Beatmap::getHPDrainRate(){
    return 1.0;
}
float Beatmap::getSliderMultiplier(){
    return 1.0;
}
float Beatmap::getSliderTickRate(){
    return 1.0;
}
//vector<TimingPoint> Beatmap::getTimingPoints(){}
vector<array<int,3>> Beatmap::getColours(){

}
//vector<HitObject> Beatmap::getHitObjects(){}

void Beatmap::setOsuFileFormat(int osuFileFormat){

}
void Beatmap::setAudioFilename(string audioFilename){

}
void Beatmap::setAudioLeadIn(int audioLeadIn){

}
void Beatmap::setPreviewTime(int previewTime){

}
void Beatmap::setCountdown(int countdown){

}
void Beatmap::setSampleSet(string sampleSet){

}
void Beatmap::setStackLeniency(float stackLeniency){

}
void Beatmap::setMode(int mode){

}
void Beatmap::setLetterboxInBreaks(int letterboxInBreaks){

}
void Beatmap::setWidescreenStoryboard(int widescreenStoryboard){

}
void Beatmap::setBookmarks(vector<int> bookmarks){

}
void Beatmap::setDistanceSpacing(float distanceSpacing){

}
void Beatmap::setBeatDivisor(int beatDivisor){

}
void Beatmap::setGridSize(int gridSize){

}
void Beatmap::setTimelineZoom(int timelineZoom){

}
void Beatmap::setTitle(string title){

}
void Beatmap::setTitleUnicode(string titleUnicode){

}
void Beatmap::setArtist(string artist){

}
void Beatmap::setArtistUnicode(string artistUnicode){

}
void Beatmap::setCreator(string creator){

}
void Beatmap::setVersion(string version){

}
void Beatmap::setSource(string source){

}
void Beatmap::setTags(string tags){

}
void Beatmap::setBeatmapID(string beatmapID){

}
void Beatmap::setBeatmapsetID(string beatmapsetID){

}
void Beatmap::setApproachRate(float approachRate){

}
void Beatmap::setCircleSize(float circleSize){

}
void Beatmap::setOverallDifficulty(float overallDifficulty){

}
void Beatmap::setHPDrainRate(float hPDrainRate){

}
void Beatmap::setSliderMultiplier(float sliderMultiplier){

}
void Beatmap::setSliderTickRate(float sliderTickRate){

}
//void Beatmap::setTimingPoints(vector<TimingPoint> timingPoints){}
void Beatmap::setColours(vector<array<int,3>> colours){

}
//void Beatmap::setHitObjects(vector<HitObject> hitObjects){}

void Beatmap::saveBeatmap(){

}

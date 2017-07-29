#include "Beatmap.h"
#include "BeatmapVersions.h"

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

    BeatmapParser::parseBeatmap(this);
};

int Beatmap::getOsuFileFormat(){
    return this->osuFileFormat;
}
string Beatmap::getAudioFilename(){
    return this->audioFilename;
}
int Beatmap::getAudioLeadIn(){
    return this->audioLeadIn;
}
int Beatmap::getPreviewTime(){
    return this->previewTime;
}
int Beatmap::getCountdown(){
    return this->countdown;
}
string Beatmap::getSampleSet(){
    return this->sampleSet;
}
float Beatmap::getStackLeniency(){
    return this->stackLeniency;
}
int Beatmap::getMode(){
    return this->mode;
}
int Beatmap::getLetterboxInBreaks(){
    return this->letterboxInBreaks;
}
int Beatmap::getWidescreenStoryboard(){
    return this->widescreenStoryboard;
}
vector<int> Beatmap::getBookmarks(){
    return bookmarks;
}
float Beatmap::getDistanceSpacing(){
    return this->distanceSpacing;
}
int Beatmap::getBeatDivisor(){
    return this->beatDivisor;
}
int Beatmap::getGridSize(){
    return this->gridSize;
}
int Beatmap::getTimelineZoom(){
    return this->timelineZoom;
}
string Beatmap::getTitle(){
    return this->title;
}
string Beatmap::getTitleUnicode(){
    return this->titleUnicode;
}
string Beatmap::getArtist(){
    return this->artist;
}
string Beatmap::getArtistUnicode(){
    return this->artistUnicode;
}
string Beatmap::getCreator(){
    return this->creator;
}
string Beatmap::getVersion(){
    return this->version;
}
string Beatmap::getSource(){
    return this->source;
}
string Beatmap::getTags(){
    return this->tags;
}
string Beatmap::getBeatmapID(){
    return this->beatmapID;
}
string Beatmap::getBeatmapsetID(){
    return this->beatmapsetID;
}
float Beatmap::getApproachRate(){
    return this->approachRate;
}
float Beatmap::getCircleSize(){
    return this->circleSize;
}
float Beatmap::getOverallDifficulty(){
    return this->overallDifficulty;
}
float Beatmap::getHPDrainRate(){
    return this->HPDrainRate;
}
float Beatmap::getSliderMultiplier(){
    return this->sliderMultiplier;
}
float Beatmap::getSliderTickRate(){
    return this->sliderTickRate;
}
//vector<TimingPoint> Beatmap::getTimingPoints(){}
vector<array<int,3>> Beatmap::getColours(){
    return this->colours;
}
//vector<HitObject> Beatmap::getHitObjects(){}

void Beatmap::setOsuFileFormat(int osuFileFormat){
    this->osuFileFormat = osuFileFormat;
}
void Beatmap::setAudioFilename(string audioFilename){
    this->audioFilename = audioFilename;
}
void Beatmap::setAudioLeadIn(int audioLeadIn){
    this->audioLeadIn = audioLeadIn;
}
void Beatmap::setPreviewTime(int previewTime){
    this->previewTime = previewTime;
}
void Beatmap::setCountdown(int countdown){
    this->countdown = countdown;
}
void Beatmap::setSampleSet(string sampleSet){
    this->sampleSet = sampleSet;
}
void Beatmap::setStackLeniency(float stackLeniency){
    this->stackLeniency = stackLeniency;
}
void Beatmap::setMode(int mode){
    this->mode = mode;
}
void Beatmap::setLetterboxInBreaks(int letterboxInBreaks){
    this->letterboxInBreaks = letterboxInBreaks;
}
void Beatmap::setWidescreenStoryboard(int widescreenStoryboard){
    this->widescreenStoryboard = widescreenStoryboard;
}
void Beatmap::setBookmarks(vector<int> bookmarks){

}
void Beatmap::setDistanceSpacing(float distanceSpacing){
    this->distanceSpacing = distanceSpacing;
}
void Beatmap::setBeatDivisor(int beatDivisor){
    this->beatDivisor = beatDivisor;
}
void Beatmap::setGridSize(int gridSize){
    this->gridSize = gridSize;
}
void Beatmap::setTimelineZoom(int timelineZoom){
    this->timelineZoom = timelineZoom;
}
void Beatmap::setTitle(string title){
    this->title = title;
}
void Beatmap::setTitleUnicode(string titleUnicode){
    this->titleUnicode = titleUnicode;
}
void Beatmap::setArtist(string artist){
    this->artist = artist;
}
void Beatmap::setArtistUnicode(string artistUnicode){
    this->artistUnicode = artistUnicode;
}
void Beatmap::setCreator(string creator){
    this->creator = creator;
}
void Beatmap::setVersion(string version){
    this->version = version;
}
void Beatmap::setSource(string source){
    this->source = source;
}
void Beatmap::setTags(string tags){
    this->tags = tags;
}
void Beatmap::setBeatmapID(string beatmapID){
    this->beatmapID = beatmapID;
}
void Beatmap::setBeatmapsetID(string beatmapsetID){
    this->beatmapsetID = beatmapsetID;
}
void Beatmap::setApproachRate(float approachRate){
    this->approachRate = approachRate;
}
void Beatmap::setCircleSize(float circleSize){
    this->circleSize = circleSize;
}
void Beatmap::setOverallDifficulty(float overallDifficulty){
    this->overallDifficulty = overallDifficulty;
}
void Beatmap::setHPDrainRate(float HPDrainRate){
    this->HPDrainRate = HPDrainRate;
}
void Beatmap::setSliderMultiplier(float sliderMultiplier){
    this->sliderMultiplier = sliderMultiplier;
}
void Beatmap::setSliderTickRate(float sliderTickRate){
    this->sliderTickRate = sliderTickRate;
}
//void Beatmap::setTimingPoints(vector<TimingPoint> timingPoints){}
void Beatmap::setColours(vector<array<int,3>> colours){

}
//void Beatmap::setHitObjects(vector<HitObject> hitObjects){}

void Beatmap::saveBeatmap(){

}

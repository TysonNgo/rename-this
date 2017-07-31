#include "Beatmap.h"

using namespace std;

#include <iostream>

Beatmap::Beatmap(string b){

};

Beatmap::Beatmap(ifstream &b){
    BeatmapParser::parseBeatmap(this, b);
};

int Beatmap::getOsuFileFormat() const{
    return this->osuFileFormat;
}

string Beatmap::getAudioFilename() const{
    return this->audioFilename;
}

int Beatmap::getAudioLeadIn() const{
    return this->audioLeadIn;
}

int Beatmap::getPreviewTime() const{
    return this->previewTime;
}

int Beatmap::getCountdown() const{
    return this->countdown;
}

string Beatmap::getSampleSet() const{
    return this->sampleSet;
}

float Beatmap::getStackLeniency() const{
    return this->stackLeniency;
}

int Beatmap::getMode() const{
    return this->mode;
}

int Beatmap::getLetterboxInBreaks() const{
    return this->letterboxInBreaks;
}

int Beatmap::getWidescreenStoryboard() const{
    return this->widescreenStoryboard;
}

vector<int> Beatmap::getBookmarks() const{
    return bookmarks;
}

float Beatmap::getDistanceSpacing() const{
    return this->distanceSpacing;
}

int Beatmap::getBeatDivisor() const{
    return this->beatDivisor;
}

int Beatmap::getGridSize() const{
    return this->gridSize;
}

int Beatmap::getTimelineZoom() const{
    return this->timelineZoom;
}

string Beatmap::getTitle() const{
    return this->title;
}

string Beatmap::getTitleUnicode() const{
    return this->titleUnicode;
}

string Beatmap::getArtist() const{
    return this->artist;
}

string Beatmap::getArtistUnicode() const{
    return this->artistUnicode;
}

string Beatmap::getCreator() const{
    return this->creator;
}

string Beatmap::getVersion() const{
    return this->version;
}

string Beatmap::getSource() const{
    return this->source;
}

string Beatmap::getTags() const{
    return this->tags;
}

string Beatmap::getBeatmapID() const{
    return this->beatmapID;
}

string Beatmap::getBeatmapSetID() const{
    return this->beatmapsetID;
}

float Beatmap::getApproachRate() const{
    return this->approachRate;
}

float Beatmap::getCircleSize() const{
    return this->circleSize;
}

float Beatmap::getOverallDifficulty() const{
    return this->overallDifficulty;
}

float Beatmap::getHPDrainRate() const{
    return this->HPDrainRate;
}

float Beatmap::getSliderMultiplier() const{
    return this->sliderMultiplier;
}

float Beatmap::getSliderTickRate() const{
    return this->sliderTickRate;
}

//vector<TimingPoint> Beatmap::getTimingPoints(){}
map<int, ComboColour> Beatmap::getComboColours() const{
    return this->comboColours;
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

void Beatmap::setComboColour(int comboNumber, int r, int g, int b){
    this->comboColours[comboNumber] = ComboColour{r, g, b};
}

//void Beatmap::setHitObjects(vector<HitObject> hitObjects){}

void Beatmap::saveBeatmap(){

}

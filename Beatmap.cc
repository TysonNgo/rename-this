#include "Beatmap.h"

using namespace std;

#include <iostream>

Beatmap::Beatmap(string b){

};

Beatmap::Beatmap(ifstream &b){
    string line;
    while (getline(b, line)){
        cout << line << endl;
    }
};

int Beatmap::getOsuFileFormat(){

}
string Beatmap::getAudioFilename(){

}
int Beatmap::getAudioLeadIn(){

}
int Beatmap::getPreviewTime(){

}
int Beatmap::getCountdown(){

}
string Beatmap::getSampleSet(){

}
float Beatmap::getStackLeniency(){

}
int Beatmap::getMode(){

}
int Beatmap::getLetterboxInBreaks(){

}
int Beatmap::getWidescreenStoryboard(){

}
vector<int> Beatmap::getBookmarks(){

}
float Beatmap::getDistanceSpacing(){

}
int Beatmap::getBeatDivisor(){

}
int Beatmap::getGridSize(){

}
int Beatmap::getTimelineZoom(){

}
string Beatmap::getTitle(){

}
string Beatmap::getTitleUnicode(){

}
string Beatmap::getArtist(){

}
string Beatmap::getArtistUnicode(){

}
string Beatmap::getCreator(){

}
string Beatmap::getVersion(){

}
string Beatmap::getSource(){

}
string Beatmap::getTags(){

}
string Beatmap::getBeatmapID(){

}
string Beatmap::getBeatmapsetID(){

}
float Beatmap::getApproachRate(){

}
float Beatmap::getCircleSize(){

}
float Beatmap::getOverallDifficulty(){

}
float Beatmap::getHPDrainRate(){

}
float Beatmap::getSliderMultiplier(){

}
float Beatmap::getSliderTickRate(){

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

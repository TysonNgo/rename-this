#include "BeatmapParser.h"

#define latestVersion 14

using namespace std;

/*
switch (beatmap->getOsuFileFormat()){
		case 14:
		case 13:
		case 12:
		case 11:
		case 10:
		case 9:
		case 8:
		case 7:
		case 6:
		case 5:
		case 4:
		case 3:
		default:
			
	}
*/

void parseGeneral(Beatmap* beatmap, ifstream &beatmapFile){

}

void parseEditor(Beatmap* beatmap, ifstream &beatmapFile){

}

void parseMetadata(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    int fileFormat = beatmap->getOsuFileFormat();

    // v3 v4
    regex title = regex{"Title:\\s*(.*)\\s*"};
    regex artist = regex{"Artist:\\s*(.*)\\s*"};
    regex creator = regex{"Creator:\\s*(.*)\\s*"};
    regex version = regex{"Version:\\s*(.*)\\s*"};

    // v5-9
    regex source = regex{"Source:\\s*(.*)\\s*"};
    regex tags = regex{"Tags:\\s*(.*)\\s*"};

    // v10-14
    regex titleUnicode = regex{"TitleUnicode:\\s*(.*)\\s*"};
    regex artistUnicode = regex{"ArtistUnicode:\\s*(.*)\\s*"};
    regex beatmapID = regex{"BeatmapID:\\s*(.*)\\s*"};
    regex beatmapSetID = regex{"BeatmapSetID:\\s*(.*)\\s*"};

    while (getline(beatmapFile, line)){
		switch (fileFormat){
			case 14: case 13: case 12: case 11: case 10:
				if (regex_search(line, result, titleUnicode)) {beatmap->setTitleUnicode(result[1]);}
				else if (regex_search(line, result, artistUnicode)) {beatmap->setArtistUnicode(result[1]);}
				else if (regex_search(line, result, beatmapID)) {beatmap->setBeatmapID(result[1]);}
				else if (regex_search(line, result, beatmapSetID)) {beatmap->setBeatmapsetID(result[1]);}
			case 9: case 8: case 7: case 6: case 5:
				if (regex_search(line, result, source)) {beatmap->setSource(result[1]);}
				else if (regex_search(line, result, tags)) {beatmap->setTags(result[1]);}
			case 4: case 3: default:
				if (regex_search(line, result, title)) {beatmap->setTitle(result[1]);}
				else if (regex_search(line, result, artist)) {beatmap->setArtist(result[1]);}
				else if (regex_search(line, result, creator)) {beatmap->setCreator(result[1]);}
				else if (regex_search(line, result, version)) {beatmap->setVersion(result[1]);}
		}
	}
}

void parseDifficulty(Beatmap* beatmap, ifstream &beatmapFile){

}

void parseEvents(Beatmap* beatmap, ifstream &beatmapFile){

}

void parseTimingPoints(Beatmap* beatmap, ifstream &beatmapFile){

}

void parseColours(Beatmap* beatmap, ifstream &beatmapFile){

}

void parseHitObjects(Beatmap* beatmap, ifstream &beatmapFile){

}

namespace BeatmapParser{
	void parseBeatmap(Beatmap* beatmap, ifstream &beatmapFile){
	    string line;
	    smatch result;

	    // first line of a .osu file contains the version
	    getline(beatmapFile, line);

	    int version = (
	        regex_search(line, result, regex{"v(\\d+)"})
	    ) ? stoi(result[1]) : latestVersion;

	    // beatmap will export to version 14, so if a new
	    // file format is released, then the program will
	    // not break
	    version = min(version, latestVersion);

	    beatmap->setOsuFileFormat(version);

	    // section headers in the beatmap file
	    regex general = regex{"\\[General\\]"};
	    regex editor = regex{"\\[Editor\\]"};
	    regex metadata = regex{"\\[Metadata\\]"};
	    regex difficulty = regex{"\\[Difficulty\\]"};
	    regex events = regex{"\\[Events\\]"};
	    regex timingPoints = regex{"\\[TimingPoints\\]"};
	    regex colours = regex{"\\[Colours\\]"};
	    regex hitObjects = regex{"\\[HitObjects\\]"};

	    while (getline(beatmapFile, line)){
	    	if (regex_search(line, general)) {parseGeneral(beatmap, beatmapFile);}
	    	else if (regex_search(line, editor)) {parseEditor(beatmap, beatmapFile);}
	    	else if (regex_search(line, metadata)) {parseMetadata(beatmap, beatmapFile);}
	    	else if (regex_search(line, difficulty)) {parseDifficulty(beatmap, beatmapFile);}
	    	else if (regex_search(line, events)) {parseEvents(beatmap, beatmapFile);}
	    	else if (regex_search(line, timingPoints)) {parseTimingPoints(beatmap, beatmapFile);}
	    	else if (regex_search(line, colours)) {parseColours(beatmap, beatmapFile);}
	    	else if (regex_search(line, hitObjects)) {parseHitObjects(beatmap, beatmapFile);}
	    }
	}
}
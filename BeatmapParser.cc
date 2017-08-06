#include "BeatmapParser.h"

#define latestVersion 14
#define reAttr(attr) (regex{attr ":\\s*(.*)\\s*"})

using namespace std;

/*
	implement parseEvents
	implement parseHitObjects
*/

vector<int> getBookmarks(string bookmarks){
	// bookmarks is a list of comma separated integers
	// ie. 123, 2315, 5000, 6313
	string bookmark = bookmarks;
	stringstream ss{bookmark};
	vector<int> result;

	while (getline(ss, bookmark, ',')){
		result.push_back(stoi(bookmark));
	}

	return result;
}

void parseGeneral(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();

    // v3-5 the bookmarks are included in [General] header
    regex editorBookmarks = reAttr("EditorBookmarks");

	regex audioFilename = reAttr("AudioFilename");
	regex audioLeadIn = reAttr("AudioLeadIn");
	regex previewTime = reAttr("PreviewTime");
	regex countdown = reAttr("Countdown");
	regex sampleSet = reAttr("SampleSet");
	regex stackLeniency = reAttr("StackLeniency");
	regex mode = reAttr("Mode");
	regex letterboxInBreaks = reAttr("LetterboxInBreaks");

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

		switch (fileFormat){
			case 5: case 4: case 3: default:
				if (regex_search(line, result, editorBookmarks)){
					beatmap->setBookmarks(getBookmarks(result[1]));
				}
			case 14: case 13: case 12: case 11:
			case 10: case 9: case 8: case 7: case 6:
				if (regex_search(line, result, audioFilename)){
					beatmap->setAudioFilename(result[1]);
				} else if (regex_search(line, result, audioLeadIn)){
					beatmap->setAudioLeadIn(stoi(result[1]));
				} else if (regex_search(line, result, previewTime)){
					beatmap->setPreviewTime(stoi(result[1]));
				} else if (regex_search(line, result, countdown)){
					beatmap->setCountdown(stoi(result[1]));
				} else if (regex_search(line, result, sampleSet)){
					beatmap->setSampleSet(result[1]);
				} else if (regex_search(line, result, stackLeniency)){
					beatmap->setStackLeniency(stof(result[1]));
				} else if (regex_search(line, result, mode)){
					beatmap->setMode(stoi(result[1]));
				} else if (regex_search(line, result, letterboxInBreaks)){
					beatmap->setLetterboxInBreaks(stoi(result[1]));
				}
		}
	}
}

void parseEditor(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();

    // the [Editor] header exists from v6-14
    regex bookmarks = reAttr("Bookmarks");
	regex distanceSpacing = reAttr("DistanceSpacing");
	regex beatDivisor = reAttr("BeatDivisor");
	regex gridSize = reAttr("GridSize");

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

		switch (fileFormat){
			case 5: case 4: case 3: default:
				break;
			case 14: case 13: case 12: case 11:
			case 10: case 9: case 8: case 7: case 6:
				if (regex_search(line, result, bookmarks)) {
					beatmap->setBookmarks(getBookmarks(result[1]));
				} else if (regex_search(line, result, distanceSpacing)) {
					beatmap->setDistanceSpacing(stof(result[1]));
				} else if (regex_search(line, result, beatDivisor)) {
					beatmap->setBeatDivisor(stoi(result[1]));
				} else if (regex_search(line, result, gridSize)) {
					beatmap->setGridSize(stoi(result[1]));
				}
		}
	}
}

void parseMetadata(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();

    // v3-14
    regex title = reAttr("Title");
    regex artist = reAttr("Artist");
    regex creator = reAttr("Creator");
    regex version = reAttr("Version");

    // v5-14
    regex source = reAttr("Source");
    regex tags = reAttr("Tags");

    // v10-14
    regex titleUnicode = reAttr("TitleUnicode");
    regex artistUnicode = reAttr("ArtistUnicode");
    regex beatmapID = reAttr("BeatmapID");
    regex beatmapSetID = reAttr("BeatmapSetID");

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

		switch (fileFormat){
			case 14: case 13: case 12: case 11: case 10:
				if (regex_search(line, result, titleUnicode)) {
					beatmap->setTitleUnicode(result[1]);
				} else if (regex_search(line, result, artistUnicode)) {
					beatmap->setArtistUnicode(result[1]);
				} else if (regex_search(line, result, beatmapID)) {
					beatmap->setBeatmapID(result[1]);
				} else if (regex_search(line, result, beatmapSetID)) {
					beatmap->setBeatmapsetID(result[1]);
				}
			case 9: case 8: case 7: case 6: case 5:
				if (regex_search(line, result, source)) {
					beatmap->setSource(result[1]);
				} else if (regex_search(line, result, tags)) {
					beatmap->setTags(result[1]);
				}
			case 4: case 3: default:
				if (regex_search(line, result, title)) {
					beatmap->setTitle(result[1]);
				} else if (regex_search(line, result, artist)) {
					beatmap->setArtist(result[1]);
				} else if (regex_search(line, result, creator)) {
					beatmap->setCreator(result[1]);
				} else if (regex_search(line, result, version)) {
					beatmap->setVersion(result[1]);
				}
		}
	}

	if (fileFormat < 10){
		beatmap->setTitleUnicode(beatmap->getTitle());
		beatmap->setArtistUnicode(beatmap->getArtist());
	}
}

void parseDifficulty(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();

    // v8-14
	regex ar = reAttr("ApproachRate");

	// v3-14
	regex cs = reAttr("CircleSize");
	regex od = reAttr("OverallDifficulty");
	regex hp = reAttr("HPDrainRate");
	regex sliderMultiplier = reAttr("SliderMultiplier");
	regex sliderTickRate = reAttr("SliderTickRate");
	
	while (getline(beatmapFile, line)){
		next = beatmapFile.peek(); if (next == '['){break;}
		switch (fileFormat){
			case 14: case 13: case 12: case 11:
			case 10: case 9: case 8:
				if (regex_search(line, result, ar)){
					beatmap->setApproachRate(stof(result[1]));
				}
			case 7: case 6: case 5: case 4: case 3: default:
				if (regex_search(line, result, cs)){
					beatmap->setCircleSize(stof(result[1]));
				} else if (regex_search(line, result, od)){
					beatmap->setOverallDifficulty(stof(result[1]));
				} else if (regex_search(line, result, hp)){
					beatmap->setHPDrainRate(stof(result[1]));
				} else if (regex_search(line, result, sliderMultiplier)){
					beatmap->setSliderMultiplier(stof(result[1]));
				} else if (regex_search(line, result, sliderTickRate)){
					beatmap->setSliderTickRate(stof(result[1]));
				}
		}
	}

	if (fileFormat < 8){
		beatmap->setApproachRate(beatmap->getOverallDifficulty());
	}
}

void parseEvents(Beatmap* beatmap, ifstream &beatmapFile){
	/*
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

		switch (fileFormat){
			case 14: case 13: case 12: case 11:
			case 10: case 9: case 8: case 7: case 6:
			case 5: case 4: case 3: default: break;
		}
	}*/
}

void parseTimingPoints(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

    	TimingPoint tp{line};
    	beatmap->insertTimingPoint(tp);
	}
}

void parseColours(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();
    int comboNumber;
    int r, g, b;

    // v3 and v4 do not appear to have combo colours
    regex combo = regex{
    	"Combo(\\d+)\\s*:\\s*"
    	"(\\s*\\d+\\s*),"
    	"(\\s*\\d+\\s*),"
    	"(\\s*\\d+\\s*)"
    	"\\s*"
    };

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

		switch (fileFormat){
			case 14: case 13: case 12: case 11:
			case 10: case 9: case 8: case 7: case 6:
			case 5: case 4: case 3: default:
			if (regex_search(line, result, combo)){
				comboNumber = stoi(result[1]);
				r = stoi(result[2]);
				g = stoi(result[3]);
				b = stoi(result[4]);
				beatmap->setComboColour(comboNumber, r, g, b);
			}
		}
	}
}

void parseHitObjects(Beatmap* beatmap, ifstream &beatmapFile){
	string line;
    smatch result;
    char next;
    int fileFormat = beatmap->getOsuFileFormat();

    while (getline(beatmapFile, line)){
    	next = beatmapFile.peek(); if (next == '['){break;}

		switch (fileFormat){
			case 14: case 13: case 12: case 11:
			case 10: case 9: case 8: case 7: case 6:
			case 5: case 4: case 3: default: break;
		}
	}
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
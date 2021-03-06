#pragma once
#include "ofMain.h"
#include "Events.h"
#include "ofxImGui.h"

class ChannelInfo {
public:
	ChannelInfo();
	ChannelInfo(int i, const string& name, float hue);

	enum Scale {
		CHROMATIC = 0, MAJOR, MINOR, PENTATONIC
	} scale;

	enum Key {
		C = 0, D_FLAT, D, E_FLAT, E, F,
		G_FLAT, G, A_FLAT, A, B_FLAT, B
	} key;

	int octave;
	
	static std::vector<vector<int>> scaleStep;

	unsigned char chIndex;
	unsigned char chNumInDAW;
	string name;
	float hue;

	array<bool, 4> isActive;
	array<ImVec4, 4> colors;
	ImVec4 colorHeader;

	void drawGui();
	unsigned char translateMidi(int midi) const;
	
	// random seeds
	bool isRandomLoop = false;
	int randomChordNum = 1;
	float randomNotesNum = 0.1;
	int velocityRange = 10;

};
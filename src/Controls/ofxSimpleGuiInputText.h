#pragma once

#include "ofxSimpleGuiControl.h"

class ofxSimpleGuiInputText : public ofxSimpleGuiControl {

public:

	std::string*	value;

	ofxSimpleGuiInputText(string name, string &value , string defaultValue);
	void setup();
	void loadFromXML(ofxXmlSettings &XML);
	void saveToXML(ofxXmlSettings &XML);
	void setValue(string s);
	std::string getValue();
	//void onPress(int x, int y, int button);
	//void onRelease(int x, int y, int button);
	void onKeyPress(int key);
	void onKeyRelease(int key);
	void draw(float x, float y);

};

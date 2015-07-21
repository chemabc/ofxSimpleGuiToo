#pragma once

#include "ofxSimpleGuiControl.h"

class ofxSimpleGuiInputString : public ofxSimpleGuiControl {

public:

	std::string*	value;
	bool			beToggle;
	bool			beenPressed;

	ofxSimpleGuiInputString(string name, string &variable , string defaultValue);
	void setup();
	void loadFromXML(ofxXmlSettings &XML);
	void saveToXML(ofxXmlSettings &XML);
	void setValue(string b);
	void toggle();
	void setToggleMode(bool b);
	void onPress(int x, int y, int button);
	void onRelease(int x, int y, int button);
	void draw(float x, float y);
	std::string getValue();
};

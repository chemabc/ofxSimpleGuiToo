#pragma once

#include "ofxSimpleGuiControl.h"


class ofxSimpleGuiSlider4d : public ofxSimpleGuiControl {
public:
	ofRectangle		*value;
	ofRectangle rect, min, max;

	ofxSimpleGuiSlider4d(string name, ofRectangle& value, float xmin, float xmax, float ymin, float ymax, float wmin, float wmax, float hmin, float hmax);
	void setup();
#ifndef OFXMSAGUI_DONT_USE_XML
	void loadFromXML(ofxXmlSettings &XML);
	void saveToXML(ofxXmlSettings &XML);
#endif
	void setValue(float x, float y, float w, float h);
	void setMin(float x, float y, float w, float h);
	void setMax(float x, float y, float w, float h);
	void onPress(int x, int y, int button);
	void onDragOver(int x, int y, int button);
	void onDragOutside(int x, int y, int button);
	void onRelease();
	void update();
	void draw(float x, float y);
};

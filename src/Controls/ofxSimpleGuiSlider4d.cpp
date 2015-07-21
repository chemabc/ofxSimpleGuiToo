
#include "ofxSimpleGuiSlider4d.h"


ofxSimpleGuiSlider4d::ofxSimpleGuiSlider4d(string name, ofRectangle& value, float xmin, float xmax, float ymin, float ymax, float wmin, float wmax, float hmin, float hmax) : ofxSimpleGuiControl(name) {
	min.set(xmin, ymin, wmin, hmin);
	max.set(xmax, ymax, wmax, hmax);
	this->value = &value;
	controlType = "Slider4D";
	setup();
}

void ofxSimpleGuiSlider4d::setup() {
	setSize(config->slider2DSize.x, config->slider2DSize.y + config->slider2DTextHeight);
	rect.x = ofMap((*value).x, min.x, max.x, x, x+width);
	rect.y = ofMap((*value).y, min.y, max.y, y, y+height-config->slider2DTextHeight);
	rect.width = ofMap((*value).width, min.width, max.width, x, x+width);
	rect.height = ofMap((*value).height, min.height, max.height, y, y+height-config->slider2DTextHeight);
}

#ifndef OFXMSAGUI_DONT_USE_XML
void ofxSimpleGuiSlider4d::loadFromXML(ofxXmlSettings &XML) {
	value->set(XML.getValue(controlType + "_" + key + ":valueX", 0.0f), XML.getValue(controlType + "_" + key + ":valueY", 0.0f), XML.getValue(controlType + "_" + key + ":valueW", 0.0f), XML.getValue(controlType + "_" + key + ":valueH", 0.0f));
}


void ofxSimpleGuiSlider4d::saveToXML(ofxXmlSettings &XML) {
	XML.addTag(controlType + "_" + key);
	XML.pushTag(controlType + "_" + key);
	XML.addValue("name", name);
	XML.addValue("valueX", value->x);
	XML.addValue("valueY", value->y);
	XML.addValue("valueW", value->width);
	XML.addValue("valueH", value->height);
	XML.popTag();
}
#endif

void ofxSimpleGuiSlider4d::setValue(float x, float y, float w, float h) {
	(*value).x = x;
	(*value).y = y;
	(*value).width = w;
	(*value).height = h;
}

void ofxSimpleGuiSlider4d::setMin(float x, float y, float w, float h) {
	min.x = x;
	min.y = y;
	min.width = w;
	min.height = h;
}

void ofxSimpleGuiSlider4d::setMax(float x, float y, float w, float h) {
	max.x = x;
	max.y = y;
	max.width = w;
	max.height = h;
}

void ofxSimpleGuiSlider4d::onPress(int x, int y, int button) {
	lock = true;
	if(button == 0){
            rect.x = x;
            rect.y = y;
	}
	if(button == 2){
        rect.width = x;
        rect.height = y;
	}
}

void ofxSimpleGuiSlider4d::onDragOver(int x, int y, int button) {
	if(lock) {
		if(button == 0){
            rect.x = x;
            rect.y = y;
        }
        if(button == 2){
            rect.width = x;
            rect.height = y;
        }
	}
}

void ofxSimpleGuiSlider4d::onDragOutside(int x, int y, int button) {
	if(lock) {
		if(button == 0){
            rect.x = x;
            rect.y = y;
        }
        if(button == 2){
            rect.width = x;
            rect.height = y;
        }
	}
}

void ofxSimpleGuiSlider4d::onRelease() {
	lock = false;
}

void ofxSimpleGuiSlider4d::update() {
	if(rect.x > x + width)				rect.x = x + width;
	else if(rect.x < x)				rect.x = x;

	if(rect.y > y+height - config->slider2DTextHeight)			rect.y = y + height - config->slider2DTextHeight;
	else if(rect.y < y)				rect.y = y;

	if(rect.width > x + width)				rect.width = x + width;
	else if(rect.width < x)				rect.width = x;

	if(rect.height > y+height - config->slider2DTextHeight)			rect.height = y + height - config->slider2DTextHeight;
	else if(rect.height < y)				rect.height = y;


	if(lock){
		(*value).x = ofMap(rect.x, x, x+width, min.x, max.x);
		(*value).y = ofMap(rect.y, y, y+height-config->slider2DTextHeight, min.y, max.y);
		(*value).width = ofMap(rect.width, x, x+width, min.width, max.width);
		(*value).height = ofMap(rect.height, y, y+height-config->slider2DTextHeight, min.height, max.height);

	}
}

void ofxSimpleGuiSlider4d::draw(float x, float y) {
	setPosition(x, y);
	ofPoint	rectv;
	rectv.x = ofMap((*value).x, min.x, max.x, x, x+width);
	rectv.y = ofMap((*value).y, min.y, max.y, y, y+height-config->slider2DTextHeight);
	ofPoint	rectv2;
	rectv2.x = ofMap((*value).width, min.width, max.width, x, x+width);
	rectv2.y = ofMap((*value).height, min.height, max.height, y, y+height-config->slider2DTextHeight);

	ofEnableAlphaBlending();
	glPushMatrix();
        glTranslatef(x, y, 0);

        ofFill();
        //setFullColor();
        ofColor(0, 100, 0, 150);
        ofRect(0, 0, width, height - config->slider2DTextHeight);

        ofFill();
        //setTextBGColor();
        ofColor(0, 100, 0, 150);
        ofRect(0, height-config->slider2DTextHeight, width, config->slider2DTextHeight);

        setTextColor();
        ofDrawBitmapString(name+"\nx:"+ofToString(value->x, 2)+"\ny:"+ofToString(value->y, 2) + "\nw:"+ofToString(value->width, 2)+"\nh:"+ofToString(value->height, 2), 3, height+15-config->slider2DTextHeight);

        //setTextColor();
        ofSetColor(255,0,0,150); //W & h
        ofCircle(rectv.x-x, rectv.y-y, 2);
        ofSetColor(255,255,0);
        ofCircle(rectv2.x-x, rectv2.y-y, 2);


        //setTextColor();
        ofSetLineWidth(1);
        ofSetColor(255,0,0,150); //W & h
        ofLine(rectv.x-x, 0, rectv.x-x, height-config->slider2DTextHeight);
        ofLine(0, rectv.y-y,width, rectv.y-y);
        ofSetColor(255,255,0,255); //W & h
        ofLine(rectv2.x-x, 0, rectv2.x-x, height-config->slider2DTextHeight);
        ofLine(0, rectv2.y-y,width, rectv2.y-y);


	glPopMatrix();
	ofDisableAlphaBlending();

}

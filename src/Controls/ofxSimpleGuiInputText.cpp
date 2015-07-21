#pragma once


#include "ofxSimpleGuiInputText.h"

#include "ofxSimpleGuiControl.h"

ofxSimpleGuiInputText::ofxSimpleGuiInputText(string name, string &value, string defaultValue) : ofxSimpleGuiControl(name) {
    this->value	= &value;
    setValue(defaultValue);

    controlType = "InputString";

    if(height == 0) height = config->titleHeight;
    if(hasTitle == false) height/=2;
    setSize(config->gridSize.x - config->padding.x, height);
    setup();
}

void ofxSimpleGuiInputText::setup() {

}

void ofxSimpleGuiInputText::loadFromXML(ofxXmlSettings &XML) {
    setValue((string)XML.getValue(controlType + "_" + key + ":value", ""));
}

void ofxSimpleGuiInputText::saveToXML(ofxXmlSettings &XML) {
    //if(!value) return;
    XML.addTag(controlType + "_" + key);
    XML.pushTag(controlType + "_" + key);
    XML.addValue("name", name);
    XML.addValue("value", getValue());
    XML.popTag();
}


std::string ofxSimpleGuiInputText::getValue() {
    return (*value);
}

void ofxSimpleGuiInputText::setValue(string s) {
    (*value) = s;
}

/*void ofxSimpleGuiInputText::onPress(int x, int y, int button) {
    //if(!value) return;
    //beenPressed = true;
    //if(beToggle) (*value) = !(*value);
    //else (*value) = true;
}

void ofxSimpleGuiInputText::onRelease(int x, int y, int button) {
    //if(!value) return;
    //if(!beToggle) (*value) = false;
}*/

void ofxSimpleGuiInputText::onKeyPress(int key) {
    // we check whether the key pressed is backspace or not
    if(key != 8) {
        // if it is not we add the key value
        *value = *value+ofToString((char) key);
    }else{
        //we delete a character
        *value = (*value).substr(0, (*value).length()-1);
    }
}

void ofxSimpleGuiInputText::onKeyRelease(int key) {

}

void ofxSimpleGuiInputText::draw(float x, float y) {
    setPosition(x, y);

	glPushMatrix();
	glTranslatef(x, y, 0);

	ofEnableAlphaBlending();
	ofFill();

	setTextBGColor();
	ofRect(0, 0, width, height);

	ofSetHexColor(config->fullColor);
    ofRect(0, 15, width, 16);

	setTextColor();
	ofDrawBitmapString(name+":", 3, 12);

	ofSetColor(0);
	ofDrawBitmapString("\n" + ofToString(*value), 3, 15);

	glPopMatrix();
}

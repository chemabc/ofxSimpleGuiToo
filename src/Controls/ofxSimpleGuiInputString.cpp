#pragma once


#include "ofxSimpleGuiInputString.h"

#include "ofxSimpleGuiControl.h"

ofxSimpleGuiInputString::ofxSimpleGuiInputString(string name, string &variable, string defaultValue) : ofxSimpleGuiControl(name) {
    beToggle	= false;
    beenPressed = false;
    this->value	= &variable;
    setValue(defaultValue);
    controlType = "Input";
    if(height == 0) height = config->titleHeight;
    if(hasTitle == false) height/=2;
    setSize(config->gridSize.x - config->padding.x, height);
    setup();
}

void ofxSimpleGuiInputString::setup() {
}

void ofxSimpleGuiInputString::loadFromXML(ofxXmlSettings &XML) {
    //if(!value) return;
    setValue((string)XML.getValue(controlType + "_" + key + ":value", ""));
}

void ofxSimpleGuiInputString::saveToXML(ofxXmlSettings &XML) {
    //if(!value) return;
    XML.addTag(controlType + "_" + key);
    XML.pushTag(controlType + "_" + key);
    XML.addValue("name", name);
    XML.addValue("value", getValue());
    XML.popTag();
}


std::string ofxSimpleGuiInputString::getValue() {
    if(!(value)) return 0;
    //std::cout << "Valor de value:"<<(*value)<<std::endl;
    return (*value);
}
void ofxSimpleGuiInputString::setValue(string b) {
    (*value) = b;

}
void ofxSimpleGuiInputString::toggle() {
}

void ofxSimpleGuiInputString::setToggleMode(bool b) {
}

void ofxSimpleGuiInputString::onPress(int x, int y, int button) {
}

void ofxSimpleGuiInputString::onRelease(int x, int y, int button) {
}

void ofxSimpleGuiInputString::draw(float x, float y) {
        //setPos(x, y);
        ofRectangle::setPosition(x,y);


        if(hasTitle == false) return;

        glPushMatrix();
        glTranslatef(x, y, 0);

        ofEnableAlphaBlending();
        //rectangle
        ofFill();
        ofSetHexColor(config->fullActiveColor);
        ofRect(0, 0, width, height);

        //Text
        setTextColor();
        ofDrawBitmapString(name+":", 3, 13);
        ofSetColor(ofColor::aquamarine);
        if((*value)==""){
            ofDrawBitmapString("EMPTY STRING IN XML!!", 3, 28);
        }
        else ofDrawBitmapString((*value), 3, 28);

        ofDisableAlphaBlending();
        glPopMatrix();
}

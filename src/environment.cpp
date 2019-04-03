#include "environment.h"

Environment::Environment(){
}

void Environment::setup(int w, int h){
    width = w;
    height = h;
}

void Environment::update(){

}

void Environment::draw(){
    ofColor bgColor(50,50,50);
    ofSetColor(bgColor);
    ofFill();
    ofDrawRectangle(0,0,width,height);
}

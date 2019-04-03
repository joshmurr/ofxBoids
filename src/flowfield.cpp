#include "flowfield.h"

Flowfield::Flowfield(){
    //Default Constructor
}

void Flowfield::setup(){
    field.clear();
    resolution = 25;
    rows = ofGetHeight()/resolution;
    cols = ofGetWidth()/resolution;
    brightness.set(0,255);

    float xoffSeed = ofRandomf();
    float yoffSeed = ofRandomf();

    std::cout << "X: " << xoffSeed << " Y: " << yoffSeed << endl;

    float xoff = xoffSeed;
    for(int col=0; col<cols; col++){
        float yoff = yoffSeed;
        for(int row=0; row<rows; row++){
            ofVec2f currentFlowVec;
            float theta = ofMap(ofNoise(xoff,yoff),-1,1,0,TWO_PI);
            //brightness.set(ofMap((random_x+random_y)/2,-1,1,0,255),255);
            currentFlowVec.set(cos(theta),sin(theta));
            field.push_back(currentFlowVec);
            yoff += 0.01;
        }
        xoff += 0.01;
    }
}

void Flowfield::update(){

}

ofVec2f Flowfield::lookup(ofVec2f &lookup){
    int column = int(ofClamp(lookup.x/resolution, 0, cols-1));
    int row = int(ofClamp(lookup.y/resolution, 0, rows-1));
    return field[column*rows+row];
}

void Flowfield::draw(){
    ofSetColor(ofColor::gray);
    for(int col=0; col<cols; col++){
        for(int row=0; row<rows; row++){
            ofVec2f horizontal(1,0);
            float angle = horizontal.angle(field[col*rows+row]); 
            ofPushMatrix();
                ofTranslate((col*resolution)+resolution, (row*resolution)+resolution);
                ofRotateDeg(angle);
                ofSetColor(brightness);
                ofDrawLine(0,0,resolution, 0);
                ofDrawLine(resolution,0,resolution-10, 10);
                ofDrawLine(resolution,0,resolution-10, -10);
            ofPopMatrix();
        }
    }
}

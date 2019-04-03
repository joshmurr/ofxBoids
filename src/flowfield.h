#ifndef _FLOWFIELD
#define _FLOWFIELD

#include "ofMain.h"

class Flowfield {
    public:
        void setup();
        void update();
        void draw();


        ofVec2f lookup(ofVec2f &lookup);


        Flowfield();

    private:
        int rows;
        int cols;
        int resolution;
        ofColor brightness;
        vector<ofVec2f> field;

};
#endif

#ifndef _BOID
#define _BOID

#include "ofMain.h"

class Boid {
    public:
        void setup(float x, float y, ofColor c, float ms);
        void update();
        void applyforce(ofVec2f force);
        void seek(ofVec2f target);
        void flee(ofVec2f target);
        void arriveCircleJitter(ofVec2f target, float radius, bool draw=false)
        ofVec2f makeCircleJitter(ofVec2f){
        void arrive(ofVec2f target);
        void draw();

        ofColor thisColor;

        ofVec2f location;
        ofVec2f velocity;
        ofVec2f acceleration;
        ofVec2f _mouseloc;

        float size;
        float maxforce;
        float maxspeed;
        float angle;
        float mathspi = 3.14159265358979323846;

        

        Boid();

    private:
};
#endif

#ifndef _BOID
#define _BOID

#define PI 3.14159265358979323846

#include "ofMain.h"
#include "flowfield.h"

class Boid {
    public:
        void setup(float x, float y, ofColor c, float ms);
        void update();
        void wrap();
        void bounce();
        void applyforce(ofVec2f force);
        void seek(ofVec2f target);
        void flee(ofVec2f target);
        void arriveCircleJitter(ofVec2f target, int radius=25);
        void arrive(ofVec2f target);
        void follow(Flowfield &flow);
        void draw(bool debug=false);

        ofColor thisColor;

        ofVec2f location;
        ofVec2f velocity;
        ofVec2f acceleration;
        ofVec2f _mouseloc;
        ofVec2f jitter;
        ofVec2f newJitter;
        ofVec2f target;
        ofVec2f desired;

        float size;
        float maxforce;
        float maxspeed;
        float angle;
        int rad=25;

        

        Boid();

    private:
};
#endif

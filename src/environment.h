#ifndef _ENVIRONMENT
#define _ENVIRONMENT

#include "ofMain.h"

class Environment {
    public:
        void setup(int w, int h);
        void update();
        void draw();

        int width;
        int height;

        Environment();

    private:

};
#endif

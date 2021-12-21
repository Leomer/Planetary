#ifndef NEW_PLANET_H
#define NEW_PLANET_H

#include"Circle.h"

class NewPlanet : public Circle{
    private:
        float orbitRadius;
        bool orientation;
        float arcPosition = 0;
        int circunference;

    public:
        NewPlanet();
        NewPlanet(float, float, int, bool);
        float getOrbitRadius();
        void translation();
        void setArcPosition();
        void area(float, float);
        ~NewPlanet();
};

#endif
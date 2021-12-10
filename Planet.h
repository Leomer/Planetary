#ifndef PLANET_H
#define PLANET_H

class Planet{
    private:
        float Radius = 0.0f;
        float planetRadiusX = 0.0f;
        float planetRadiusY = 0.0f;
        float orbRadius = 0;
        float posYOrb = 0.0f;
        float posXOrb = 0.0f;
        int steps = 0;
        float arcPosition = 0;
        bool orientation = false;
    public:
        Planet(float, float, int, bool);
        float getPlanetRadiusX();
        float getPlanetRadiusY();
        void circunferencia(int, int);
        void Orbit(int, int);
        float getOrbitPosX();
        float getOrbitPosY();
        void translation();
        bool getSpin();
        void setArcPosition();
        float getRadius();
        void area(float, float);
};

#endif
#include"Planet.h"
#include<math.h>
#include<iostream>

Planet::Planet(float orbR, float planetR, int s, bool spin){
    orbRadius = orbR;
    Radius = planetR;
    steps = s;
    orientation = spin;
}
void Planet::circunferencia(int i, int j){
    double angle = 2 * 3.1416 * i/j;
    planetRadiusX = cos(angle) * Radius;
    planetRadiusY = sin(angle) * Radius;
}
void Planet::Orbit(int i, int j){
    double angle = 2 * 3.1416 * i/j;
    posYOrb = cos(angle)*orbRadius;
    posXOrb = sin(angle)*orbRadius;
}
void Planet::translation(){
    double angle = 2 * 3.1416 * arcPosition / steps;
    posXOrb = cos(angle) * orbRadius;
    posYOrb = sin(angle) * orbRadius;
}
float Planet::getPlanetRadiusX(){
    return planetRadiusX;
}
float Planet::getPlanetRadiusY(){
    return planetRadiusY;
}
float Planet::getOrbitPosX(){
    return posXOrb;
}
float Planet::getOrbitPosY(){
    return posYOrb;
}
bool Planet::getSpin(){
    return orientation;
}
void Planet::setArcPosition(){
    if(orientation){
        arcPosition += 0.1;
        if(arcPosition>steps)
            arcPosition -= steps;
    }else{
        arcPosition -= 0.1;
        if(arcPosition<0)
            arcPosition +=steps;
    }
}
float Planet::getRadius(){
    return Radius;
}
void Planet::area(float x, float y){
    float maxHeight = posYOrb + Radius;
    float minHeight = posYOrb - Radius;
    float maxWeight = posXOrb + Radius;
    float minWeight = posXOrb - Radius;
    if(x>=minWeight && x<=maxWeight && y >=minHeight && y <= maxHeight){
        orientation = !orientation;
    }
}

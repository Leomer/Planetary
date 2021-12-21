#include"NewPlanet.h"
#include<iostream>
#include<math.h>

NewPlanet::NewPlanet(){}
NewPlanet::NewPlanet(float radius, float orbit, int circunference, bool orientation):Circle(){
    this->radius=radius;
    this->orientation=orientation;
    this->circunference=circunference;
    this->orbitRadius=orbit;
}
float NewPlanet::getOrbitRadius(){
    return orbitRadius;
}
void NewPlanet::translation(){
    double angle = 2 * 3.1416 * arcPosition / circunference;
    posX = cos(angle) * orbitRadius;
    posY = sin(angle) * orbitRadius;
}
void NewPlanet::setArcPosition(){
    if(orientation){
        arcPosition += 0.1f;
        if(arcPosition>circunference)
            arcPosition-=circunference;
    }else{
        arcPosition -= 0.1f;
        if(arcPosition<0)
            arcPosition+=circunference;
    }
}
void NewPlanet::area(float x, float y){
    float maxHeight = posY + radius;
    float minHeight = posY - radius;
    float maxWeight = posX + radius;
    float minWeight = posX - radius;
    if(x>=minWeight && x<=maxWeight && y >=minHeight && y <= maxHeight){
        orientation = !orientation;
    }
}
NewPlanet::~NewPlanet(){}

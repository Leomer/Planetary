#include"Circle.h"
#include<math.h>

Circle::Circle(){}
void Circle::coordinates(int i, int j, float r){
    float angle = 2 * 3.1416 * i/j;
    this->posX = cos(angle) * r;
    this->posY = sin(angle) * r;
}
float Circle::getPosX(){
    return posX;
}
float Circle::getPosY(){
    return posY;
}
float Circle::getRadius(){
    return radius;
}
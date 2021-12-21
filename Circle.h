#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
    protected:
        float radius = 0.0f;
        float posX = 0.0f;
        float posY = 0.0f;
    public:
        Circle();
        void coordinates(int, int, float);
        float getRadius();
        float getPosX();
        float getPosY();
};

#endif
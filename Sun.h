#ifndef SUN_H
#define SUN_H

#include"Circle.h"

class Sun : public Circle{
    private:
        float color = 0.0f;
    public:
        Sun(float);
};

#endif
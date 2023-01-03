#pragma once
#include "Circle.h"
#include "Hit.h"
#include "Vec2.h"

namespace MathLib
{
    class Rect
    {
    public:
        Rect(Vec2 pos, Vec2 extends);
        Rect(float xPos, float yPos, float hWidth, float hHeight);
        
        ~Rect();

        Vec2 Position;
        Vec2 Extends = Vec2(.5f,.5f);

        Vec2 GetMin();
        Vec2 GetMax();
        Vec2 GetSize();

        bool IsPointInside(Vec2 point);

        Hit Intersects(Vec2 point);
        Hit Intersects(Rect other);
        Hit Intersects(Circle other);


        
        
    }; 
}


#pragma once
#include "Hit.h"
#include "Vec2.h"

namespace MathLib
{
    class Circle
    {
    public:

        Circle(Vec2 pos, float radius);
        ~Circle();

        Vec2 Position = Vec2();
        float Radius = 1.0f;

        Hit Intersects(Vec2 point);
        Hit Intersects(Circle circle);
    };
}

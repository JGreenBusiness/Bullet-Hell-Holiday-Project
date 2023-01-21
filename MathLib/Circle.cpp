#include "Circle.h"

MathLib::Circle::Circle(Vec2 pos, float radius)
{
    Position = pos;
    Radius = radius;
}

MathLib::Circle::~Circle()
{
}

MathLib::Hit* MathLib::Circle::Intersects(Vec2 point)
{
    float distance = Vec2::Distance(Position, point);
    if (distance > Radius)
        return nullptr;

    Vec2 closestPoint = Vec2::Add(Position , Vec2::PostScale(Vec2::Normalise(Vec2::Subtract(point , Position)),Radius));
    Vec2 delta  = Vec2::Subtract(closestPoint , point);

    Hit* hit =  new Hit();
    hit->pos = closestPoint;
    hit->delta = delta;
    hit->normal = Vec2::Normalise(hit->delta);

    return hit;
}

MathLib::Hit MathLib::Circle::Intersects(Circle circle)
{
    float distance = Vec2::Distance(Position, circle.Position);
    if (distance >= Radius + circle.Radius)
        return Hit();

    Vec2 vec = Vec2::Normalise(Vec2::Subtract(circle.Position, Position));
    Vec2 closestPoint = Vec2::Add(Position , (Vec2::PostScale(vec , Radius)));
    float overlapLength = (Radius + circle.Radius) - distance;
    Vec2 delta = Vec2::PostScale(vec , overlapLength);

    Hit hit = Hit();
    hit.pos = closestPoint;
    hit.delta = delta;
    hit.normal = vec;

    return hit;
}

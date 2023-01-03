#include "Rect.h"

#include <complex>

MathLib::Rect::Rect(Vec2 pos, Vec2 extends)
{
    Position.x = pos.x;
    Position.y = pos.y;
    Extends.x = extends.x;
    Extends.y = extends.y;
}

MathLib::Rect::Rect(float xPos, float yPos, float hWidth, float hHeight)
{
    Position.x = xPos;
    Position.y = yPos;
    Extends.x = hWidth;
    Extends.y = hHeight;
}

MathLib::Rect::~Rect()
{
}

MathLib::Vec2 MathLib::Rect::GetMin()
{
    return Vec2::Subtract(Position , Extends);
}

MathLib::Vec2 MathLib::Rect::GetMax()
{
    return Vec2::Add(Position,Extends);
}

MathLib::Vec2 MathLib::Rect::GetSize()
{
    return Vec2::PostScale(Extends,2);
}

bool MathLib::Rect::IsPointInside(Vec2 point)
{
    Vec2 min = GetMin();
    Vec2 max = GetMax();
    return point.x > min.x && point.x < max.x &&
           point.y > min.y && point.y < max.y;
}

MathLib::Hit MathLib::Rect::Intersects(Vec2 point)
{
    Hit hit = Hit();
    
    if (!IsPointInside(point))
        return hit;


    Vec2 vec = Vec2::Subtract(point , Position);
    Vec2 overlap = Vec2::Subtract(Extends,  Vec2(std::abs(vec.x),std::abs(vec.y)));

    if (overlap.x < overlap.y)
    {
        float xDir = vec.x < 0 ? -1 : 1;
        hit.delta.x = overlap.x * xDir;
        hit.normal.x = xDir;
        hit.pos.x = Position.x + (Extends.x * xDir);
        hit.pos.y = point.y;
    }
    else
    {
        float yDir = vec.y < 0 ? -1 : 1;
        hit.delta.y = overlap.y * yDir;
        hit.normal.y = yDir;
        hit.pos.y = Position.y + (Extends.y * yDir);
        hit.pos.x = point.x;
    }

    return hit;
}

MathLib::Hit MathLib::Rect::Intersects(Rect other)
{
    Vec2 vec = Vec2::Subtract(other.Position , Position);
    Vec2 overlap = Vec2::Subtract((Vec2::Add(other.Extends , Extends)) , Vec2(std::abs(vec.x), std::abs(vec.y)));

    Hit hit = Hit();
    
    if (overlap.x <= 0 || overlap.y <= 0)
    {
        return hit;
    }

    if (overlap.x < overlap.y)
    {
        float sx = vec.x < 0 ? -1 : 1;
        hit.delta.x = overlap.x * sx;
        hit.normal.x = sx;
        hit.pos.x = Position.x + (Extends.x * sx);
        hit.pos.y = other.Position.y;
    }
    else
    {
        float sy = vec.y < 0 ? -1 : 1;
        hit.delta.y = overlap.y * sy;
        hit.normal.y = sy;
        hit.pos.x = other.Position.x;
        hit.pos.y = Position.y + (Extends.y * sy);
    }

    return hit;
}

MathLib::Hit MathLib::Rect::Intersects(Circle other)
{
    Vec2 vec = Vec2::Subtract(other.Position , Position);
    Vec2 overlap = Vec2::Subtract((Vec2::Add(Vec2(other.Radius, other.Radius) , Extends)) , Vec2(std::abs(vec.x), std::abs(vec.y)));


    Hit hit =  Hit();

    if (overlap.x <= 0 || overlap.y <= 0)
    {
        return hit;
    }


    if (overlap.x < overlap.y)
    {
        float sx = vec.x < 0 ? -1 : 1;
        hit.delta.x = overlap.x * sx;
        hit.normal.x = sx;
        hit.pos.x = Position.x + (Extends.x * sx);
        hit.pos.y = other.Position.y;
    }
    else
    {
        float sy = vec.y < 0 ? -1 : 1;
        hit.delta.y = overlap.y * sy;
        hit.normal.y = sy;
        hit.pos.x = other.Position.x;
        hit.pos.y = Position.y + (Extends.y * sy);
    }

    return hit;
}

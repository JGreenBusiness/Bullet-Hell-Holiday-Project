#include "Vec2.h"
#include <complex>

namespace MathLib
{
    double Vec2::Add(double a, double b)
    {
        return a + b;
    }

    Vec2 Vec2::Add(Vec2 _lhs, Vec2 _rhs)
    {
        return *new Vec2(
            _lhs.x + _rhs.x,
            _lhs.y + _rhs.y);
    }

    Vec2 Vec2::Subtract(Vec2 _lhs, Vec2 _rhs)
    {
        return Vec2(
            _lhs.x - _rhs.x,
            _lhs.y - _rhs.y);
    }

    bool Vec2::Equal(Vec2 _lhs, Vec2 _rhs)
    {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
    }

    Vec2 Vec2::PreScale(float _lhs, Vec2 _rhs)
    {
        return Vec2(
            _lhs * _rhs.x,
            _lhs * _rhs.y);
    }

    Vec2 Vec2::PostScale(Vec2 _lhs, float _rhs)
    {
        return  Vec2(
            _lhs.x * _rhs,
            _lhs.y * _rhs);
    }

    Vec2 Vec2::Scale(Vec2 _lhs, Vec2 _rhs)
    {
        return Vec2(
            _lhs.x * _rhs.x,
            _lhs.y * _rhs.y);
    }

    float Vec2::Length()
    {
        return std::sqrt(x * x + y * y);
    }

    float Vec2::Distance(Vec2 _vector1, Vec2 _vector2)
    {
        return Vec2::Subtract(_vector1, _vector2).Length();
    }

    void Vec2::Normalise()
    {
        float length = Length();
        x /= length;
        y /= length;
    }

    Vec2 Vec2::Normalise(Vec2 _vec)
    {
        float len = _vec.Length();
        return Vec2(_vec.x / len, _vec.y / len);
    }

    float Vec2::Dot(Vec2 _rhs)
    {
        return (x * _rhs.x) + (y * _rhs.y);
    }

    float Vec2::Dot(Vec2 _lhs, Vec2 _rhs)
    {
        return (_lhs.x * _rhs.x) + (_lhs.y * _rhs.y);
    }

    Vec2 Vec2::CreateRotationVector(float _radians)
    {

        return Vec2(std::cos(_radians), std::sin(_radians));
    }

    float Vec2::Rotation()
    {
        return std::atan2(y, x);
    }

    void Vec2::Rotate(float _amount)
    {
        float x_rotated = x * std::cos(_amount) - y * std::cos(_amount);
        float y_rotated = x * std::sin(_amount) + y * std::sin(_amount);

        x = x_rotated;
        y = y_rotated;
    }

    void Vec2::RotateAround(Vec2 _pivotPoint, float _amount)
    {
        x -= _pivotPoint.x;
        y -= _pivotPoint.y;

        Rotate(_amount);

        x += _pivotPoint.x;
        y += _pivotPoint.y;
    }
}

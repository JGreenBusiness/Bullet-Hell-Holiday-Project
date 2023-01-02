#include "Vec3.h"

#include <complex>

namespace MathLib
{
    Vec3::Vec3()
    {
    }

    Vec3::Vec3(float _x, float _y, float _z)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    Vec3 Vec3::Add(Vec3 _lhs, Vec3 _rhs)
    {
        return Vec3(
                _lhs.x + _rhs.x,
                _lhs.y + _rhs.y,
                _lhs.z + _rhs.z);
    }

    Vec3 Vec3::Subtract(Vec3 _lhs, Vec3 _rhs)
    {
        return Vec3(
                _lhs.x - _rhs.x,
                _lhs.y - _rhs.y,
                _lhs.z - _rhs.z);
    }

    bool Vec3::Equals(Vec3 _lhs, Vec3 _rhs)
    {
        return _lhs.x == _rhs.x &&
                    _lhs.y == _rhs.y &&
                    _lhs.z == _rhs.z;
    }

    // Vec3 Vec3::operator+(Vec3 _lhs, Vec3 _rhs)
    // {
    //     return Add(_lhs, _rhs);
    // }
    //
    // Vec3 Vec3::operator-(Vec3 _lhs, Vec3 _rhs)
    // {
    //     return Subtract(_lhs,_rhs);
    // }
    //
    // bool Vec3::operator==(Vec3 _lhs, Vec3 _rhs)
    // {
    //     return Equals(_lhs, _rhs);
    // }
    //
    // bool Vec3::operator!=(Vec3 _lhs, Vec3 _rhs)
    // {
    //     return !Equals(_lhs, _rhs);
    // }

    Vec3 Vec3::PreScale(float _lhs, Vec3 _rhs)
    {
        return Vec3(
                _lhs * _rhs.x,
                _lhs * _rhs.y,
                _lhs * _rhs.z);
    }

    Vec3 Vec3::Multiply(Vec3 _lhs, Vec3 _rhs)
    {
        return Vec3(
                _lhs.x * _rhs.x,
                _lhs.y * _rhs.y,
                _lhs.z * _rhs.z);
    }

    Vec3 Vec3::PostScale(Vec3 _lhs, float _rhs)
    {
        return Vec3(
                _lhs.x * _rhs,
                _lhs.y * _rhs,
                _lhs.z * _rhs);
    }

    // Vec3 Vec3::operator*(float _lhs, Vec3 _rhs)
    // {
    //     return PreScale(_lhs,_rhs);
    // }
    //
    // Vec3 Vec3::operator*(Vec3 _lhs, Vec3 _rhs)
    // {
    //     return Multiply(_lhs,_rhs);
    // }
    //
    // Vec3 Vec3::operator*(Vec3 _lhs, float _rhs)
    // {
    //     return PostScale(_lhs,_rhs);
    // }

    float Vec3::Length()
    {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }

    float Vec3::Distance(Vec3 _vector1, Vec3 _vector2)
    {
        return (Subtract(_vector1,_vector2)).Length();
    }

    void Vec3::Normalise()
    {
        float length = Length();
        x /= length;
        y /= length;
        z /= length; 
    }

    Vec3 Vec3::Normalise(Vec3 _vec)
    {
        float len = _vec.Length();
        return  Vec3(_vec.x /= len,
                        _vec.y /= len,
                        _vec.z /= len);
    }

    float Vec3::Dot(Vec3 _rhs)
    {
        return (x * _rhs.x) + (y * _rhs.y) + (z * _rhs.z);
    }

    float Vec3::Dot(Vec3 _lhs, Vec3 _rhs)
    {
        return (_lhs.x * _rhs.x) + (_lhs.y * _rhs.y) + (_lhs.z * _rhs.z);
    }

    Vec3 Vec3::Cross(Vec3 _rhs)
    {
        return Vec3(
             (y * _rhs.z) - (z * _rhs.y),
             (z * _rhs.x) - (x * _rhs.z),
             (x * _rhs.y) - (y * _rhs.x)
             );
    }
}

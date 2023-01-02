#include "Mat3.h"

#include <complex>

namespace MathLib
{
    Mat3::Mat3()
    {
        m1 = 1; m2 = 0; m3 = 0;
        m4 = 0; m5 = 1; m6 = 0;
        m7 = 0; m8 = 0; m9 = 1;
    }

    Mat3::Mat3(float _m1, float _m4, float _m7, float _m2, float _m5, float _m8, float _m3, float _m6, float _m9)
    {
        this->m1 = _m1; this->m2 = _m2; this->m3 = _m3;
        this->m4 = _m4; this->m5 = _m5; this->m6 = _m6;
        this->m7 = _m7; this->m8 = _m8; this->m9 = _m9;
    }

    Mat3 Mat3::CreateTranslation(float _tx, float _ty)
    {
        return Mat3(
                1, 0, _tx,
                0, 1, _ty,
                0, 0, 1
             );
    }

    Mat3 Mat3::CreateXRotation(float _rot)
    {
        float cos = std::cos(_rot);
        float sin = std::sin(_rot);

        return Mat3(
         // xa  ya  za
            1,  0,  0,      // x
            0,  cos,-sin,   // y
            0,  sin, cos    // z
        );
    }

    Mat3 Mat3::CreateYRotation(float _rot)
    {
        float cos = std::cos(_rot);
        float sin = std::sin(_rot);
        
        return Mat3(
             //   xa    ya  za
                 cos,   0,  sin,  // x
                 0,     1,  0,    // y
                -sin,   0,  cos   // z
            );
    }

    Mat3 Mat3::CreateZRotation(float _rot)
    {
        float cos = std::cos(_rot);
        float sin = std::sin(_rot);

        return Mat3(
         cos, -sin, 0,
         sin, cos, 0,
         0, 0, 1
      );
    }

    void Mat3::SetRotationX(float _xRot)
    {
        float yLen = std::sqrt(m4 * m4 + m5 * m5 + m6 * m6);
        float zLen = std::sqrt(m7 * m7 + m8 * m8 + m9 * m9);

        float cos = std::cos(_xRot);
        float sin = std::sin(_xRot);

        m5 = cos * yLen; m8 = -sin * zLen;
        m6 = sin * yLen; m9 = cos * zLen;
    }

    void Mat3::SetRotationY(float _yRot)
    {
        float zLen = std::sqrt(m7 * m7 + m8 * m8 + m9 * m9);
        float xLen = std::sqrt(m1 * m1 + m2 * m2 + m3 * m3);


        float cos = std::cos(_yRot);
        float sin = std::sin(_yRot);


        m1 = cos * xLen; m7 = sin * zLen;
        m3 = -sin * xLen; m9 = cos * zLen;
    }

    void Mat3::SetRotationZ(float _zRot)
    {
        float xLen = std::sqrt(m1 * m1 + m2 * m2 + m3 * m3);
        float yLen = std::sqrt(m4 * m4 + m5 * m5 + m6 * m6);


        float cos = std::cos(_zRot);
        float sin = std::sin(_zRot);


        m1 = cos * xLen; m4 = -sin * yLen;
        m2 = sin * xLen; m5 = cos * yLen;
    }

    float Mat3::GetRotationX()
    {
        return std::atan2(m2, m1);
    }

    float Mat3::GetRotationY()
    {
        return std::atan2(-m4, m5);
    }

    float Mat3::GetRotationZ()
    {
        return std::atan2(m7, m9);
    }

    Vec2 Mat3::GetTranslation()
    {
        return Vec2(m7, m8);
    }

    void Mat3::SetTranslation(Vec2 _translation)
    {
        m7 = _translation.x;
        m8 = _translation.y;
    }

    void Mat3::SetTranslation(float _tx, float _ty)
    {
        m7 += _tx;
        m8 += _ty;
    }

    Mat3 Mat3::CreateScale(float _sx, float _sy)
    {
        return Mat3(
                _sx, 0, 0,
                0, _sy, 0,
                0, 0, 1
             );
    }

    Mat3 Mat3::CreateZScale(float _sx, float _sy, float _sz)
    {
        return Mat3(
                _sx, 0, 0,
                0, _sy, 0,
                0, 0, _sz
             );
    }

    Vec2 Mat3::GetScale()
    {
        float xALength = (float)(std::sqrt((m1 * m1) + (m2 * m2) + (m3 * m3)));
        float yALength = (float)(std::sqrt((m4 * m4) + (m5 * m5) + (m6 * m6)));
        return Vec2(xALength,yALength);
    }

    void Mat3::SetScale(float _sx, float _sy)
    {
        float xALength = (float)(std::sqrt(m1 * m1 + m2 * m2 + m3 * m3));
        float yALength = (float)(std::sqrt(m4 * m4 + m5 * m5 + m6 * m6));


        if (xALength > 0 && yALength > 0)
        {
            m1 /= xALength;
            m2 /= xALength;
            m3 /= xALength;

            m4 /= yALength;
            m5 /= yALength;
            m6 /= yALength;
        }

        m1 *= _sx;
        m2 *= _sx;
        m3 *= _sx;
               
        m4 *= _sy;
        m5 *= _sy;
        m6 *= _sy;
    }

    void Mat3::SetScale(Vec2 _scale)
    {
        float xALength = (float)(std::sqrt(m1 * m1 + m2 * m2 + m3 * m3));
        float yALength = (float)(std::sqrt(m4 * m4 + m5 * m5 + m6 * m6));


        if (xALength > 0 && yALength > 0)
        {
            m1 /= xALength;
            m2 /= xALength;
            m3 /= xALength;

            m4 /= yALength;
            m5 /= yALength;
            m6 /= yALength;
        }

        m1 *= _scale.x;
        m2 *= _scale.x;
        m3 *= _scale.x;
               
        m4 *= _scale.y;
        m5 *= _scale.y;
        m6 *= _scale.y;
    }

    void Mat3::SetScale(float _sx, float _sy, float _sz)
    {
        float xALength = (float)(std::sqrt(m1 * m1 + m2 * m2 + m3 * m3));
        float yALength = (float)(std::sqrt(m4 * m4 + m5 * m5 + m6 * m6));
        float zALength = (float)(std::sqrt(m7 * m7 + m8 * m8 + m9 * m9));


        if (xALength > 0 && yALength > 0 && zALength > 0)
        {
            m1 /= xALength;
            m2 /= xALength;
            m3 /= xALength;

            m4 /= yALength;
            m5 /= yALength;
            m6 /= yALength;

            m7 /= zALength;
            m8 /= zALength;
            m9 /= zALength;
        }

        m1 *= _sx;
        m2 *= _sx;
        m3 *= _sx;

        m4 *= _sy;
        m5 *= _sy;
        m6 *= _sy;

        m7 *= _sz;
        m8 *= _sz;
        m9 *= _sz;
    }

    Mat3 Mat3::Multiply(Mat3 _lhs, Mat3 _rhs)
    {
        Mat3 result = Mat3();

        result.m1 = (_lhs.m1 * _rhs.m1) +
                    (_lhs.m2 * _rhs.m4) +
                    (_lhs.m3 * _rhs.m7);

        result.m2 = (_lhs.m1 * _rhs.m2) +
                    (_lhs.m2 * _rhs.m5) +
                    (_lhs.m3 * _rhs.m8);

        result.m3 = (_lhs.m1 * _rhs.m3) +
                    (_lhs.m2 * _rhs.m6) +
                    (_lhs.m3 * _rhs.m9);

        result.m4 = (_lhs.m4 * _rhs.m1) +     
                    (_lhs.m5 * _rhs.m4) +
                    (_lhs.m6 * _rhs.m7);

        result.m5 = (_lhs.m4 * _rhs.m2) +
                    (_lhs.m5 * _rhs.m5) +
                    (_lhs.m6 * _rhs.m8);

        result.m6 = (_lhs.m4 * _rhs.m3) +
                    (_lhs.m5 * _rhs.m6) +
                    (_lhs.m6 * _rhs.m9);

        result.m7 = (_lhs.m7 * _rhs.m1) +
                    (_lhs.m8 * _rhs.m4) +
                    (_lhs.m9 * _rhs.m7);

        result.m8 = (_lhs.m7 * _rhs.m2) +
                    (_lhs.m8 * _rhs.m5) +
                    (_lhs.m9 * _rhs.m8);

        result.m9 = (_lhs.m7 * _rhs.m3) +
                    (_lhs.m8 * _rhs.m6) +
                    (_lhs.m9 * _rhs.m9);

        return result; 
    }

    Vec3 Mat3::MultiplyV3(Vec3 _lhs, Mat3 _rhs)
    {
        return Vec3(
                _lhs.x * _rhs.m1 + _lhs.y * _rhs.m4 + _lhs.z * _rhs.m7,
                _lhs.x * _rhs.m2 + _lhs.y * _rhs.m5 + _lhs.z * _rhs.m8,
                _lhs.x * _rhs.m3 + _lhs.y * _rhs.m6 + _lhs.z * _rhs.m9
            );
    }
    Vec3 Mat3::MultiplyV3(Mat3 _lhs, Vec3 _rhs)
    {
        return Vec3(
                (_lhs.m1 * _rhs.x) + (_lhs.m2 * _rhs.y) + (_lhs.m3 * _rhs.z),
                (_lhs.m4 * _rhs.x) + (_lhs.m5 * _rhs.y) + (_lhs.m6 * _rhs.z), 
                (_lhs.m7 * _rhs.x) + (_lhs.m8 * _rhs.y) + (_lhs.m9 * _rhs.z) 
            );
    }

    // Mat3 Mat3::operator*(Mat3 _lhs, Mat3 _rhs)
    // {
    //     return Multiply(_lhs, _rhs);
    // }

    Vec2 Mat3::TransformPoint(Vec2 point)
    {
        float x = (point.x * m1) + (point.y * m4) + m7;
        float y = (point.x * m2) + (point.y * m5) + m8;

        return Vec2(x, y);
    }

    Vec2 Mat3::TransformVector(Vec2 _vec)
    {
        float x = (_vec.x * m1) + (_vec.y * m4) + (m7 * 0);
        float y = (_vec.x * m2) + (_vec.y * m5) + (m8 * 0);

        return Vec2(x, y);
    }
}

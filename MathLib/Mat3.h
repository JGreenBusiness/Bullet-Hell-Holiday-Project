#pragma once
#include "Vec2.h"
#include "Vec3.h"

namespace MathLib
{
    struct Mat3
    {
    public:
        float    m1, m2, m3,// is actually Column 1
                 m4, m5, m6,// is actually Column 2
                 m7, m8, m9;// is actually Column 3
        // in memory layout they looks like rows.

        Mat3();
        Mat3(float _m1, float _m4, float _m7, float _m2, float _m5, float _m8, float _m3, float _m6, float _m9);

        static Mat3 CreateTranslation(float _tx, float _ty);
        
        static Mat3 CreateXRotation(float _rot);
        static Mat3 CreateYRotation(float _rot);
        static Mat3 CreateZRotation(float _rot);

        void SetRotationX(float _xRot);
        void SetRotationY(float _yRot);
        void SetRotationZ(float _zRot);

        float GetRotationX();
        float GetRotationY();
        float GetRotationZ();

        Vec2 GetTranslation();
        void SetTranslation(Vec2 _translation);
        void SetTranslation(float _tx, float _ty);

        static Mat3 CreateScale(float _sx, float _sy);
        static Mat3 CreateZScale(float _sx, float _sy, float _sz);
        Vec2 GetScale();
        void SetScale(float _sx, float _sy);
        void SetScale(Vec2 _scale);
        void SetScale(float _sx, float _sy, float _sz);

        static Mat3 Multiply(Mat3 _lhs, Mat3 _rhs);
        static Vec3 MultiplyV3(Vec3 _lhs, Mat3 _rhs);
        static Vec3 MultiplyV3(Mat3 _lhs, Vec3 _rhs);
        // Mat3 operator *(Mat3 _lhs, Mat3 _rhs);
        
        Vec2 TransformPoint(Vec2 _point);
        Vec2 TransformVector(Vec2 _vec);
        
    protected:
    private:
        
    };
}

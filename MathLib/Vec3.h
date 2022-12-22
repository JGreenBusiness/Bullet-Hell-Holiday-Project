#pragma once

namespace MathLib
{
    struct Vec3
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;

        Vec3();

        Vec3(float _x,float _y,float _z);

        static Vec3 Add(Vec3 _lhs, Vec3 _rhs);
        static Vec3 Subtract(Vec3 _lhs, Vec3 _rhs);
        static bool Equals(Vec3 _lhs, Vec3 _rhs);
        
        Vec3 operator +(Vec3 _lhs, Vec3 _rhs);
        Vec3 operator -(Vec3 _lhs, Vec3 _rhs);
        bool operator ==(Vec3 _lhs, Vec3 _rhs);
        bool operator !=(Vec3 _lhs, Vec3 _rhs);

        static Vec3 PreScale(float _lhs, Vec3 _rhs);
        static Vec3 Multiply(Vec3 _lhs, Vec3 _rhs);
        static Vec3 PostScale(Vec3 _lhs, float _rhs);
        Vec3 operator *(float _lhs, Vec3 _rhs);
        Vec3 operator *(Vec3 _lhs, Vec3 _rhs);
        Vec3 operator *(Vec3 _lhs, float _rhs);

        float Length();
        static float Distance(Vec3 _vector1, Vec3 _vector2);

        void Normalise();
        static Vec3 Normalise(Vec3 _vec);

        float Dot(Vec3 _rhs);
        static float Dot(Vec3 _lhs, Vec3 _rhs);

        Vec3 Cross(Vec3 _rhs);
    protected:
    private:
    };
}

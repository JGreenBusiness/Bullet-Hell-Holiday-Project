#pragma once


namespace MathLib
{
    struct Vec2
    {
    public:
        float x = 0.0f;
        float y = 0.0f;

        Vec2() = default;

        Vec2(float _x, float _y)
        {
            this->x = _x;
            this->y = _y;
        }

        static double Add(double a, double b);
        static Vec2 Add(Vec2 _lhs, Vec2 _rhs);
        static Vec2 Subtract(Vec2 _lhs, Vec2 _rhs);
        static bool Equal(Vec2 _lhs, Vec2 _rhs);
        
        // Vec2 operator +(Vec2 _lhs, Vec2 _rhs);
        // Vec2 operator - (Vec2 _lhs, Vec2 _rhs);
        // bool operator == (Vec2 _lhs, Vec2 _rhs);
        // bool operator !=(Vec2 _lhs, Vec2 _rhs);

        static Vec2 PreScale(float _lhs, Vec2 _rhs);
        static Vec2 PostScale(Vec2 _lhs, float _rhs);
        static Vec2 Scale(Vec2 _lhs, Vec2 _rhs);

        // Vec2 operator * (float _lhs, Vec2 _rhs);
        // Vec2 operator *(Vec2 _lhs, Vec2 _rhs);
        // Vec2 operator * (Vec2 _lhs, float _rhs);

        float Length();
        static float Distance(Vec2 _vector1, Vec2 _vector2);

        void Normalise();
        static Vec2 Normalise(Vec2 _vec);

        float Dot(Vec2 _rhs);
        static float Dot(Vec2 _lhs, Vec2 _rhs);

        static Vec2 CreateRotationVector(float _radians);
        float Rotation();
        void Rotate(float _amount);
        void RotateAround(Vec2 _pivotPoint, float _amount);

    protected:
    private:
    };

}
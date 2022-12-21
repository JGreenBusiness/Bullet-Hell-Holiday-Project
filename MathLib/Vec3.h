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

        Vec3(float x,float y,float z);

        static Vec3 Add(Vec3 lhs, Vec3 rhs);
        static Vec3 Add(Vec3 lhs, Vec3 rhs);
    protected:
    private:
    };
}

//
//  GlueMath.hpp
//  LinearAlgebra
//
//  Created by Alexander Fomenko on 12/11/2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#ifndef GlueMath_hpp
#define GlueMath_hpp

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using std::vector;

struct Vector3
{
    float X;
    float Y;
    float Z;
    
    Vector3();
    Vector3(float X, float Y, float Z);
    ~Vector3(){}
    Vector3 operator*(Vector3 otherVector);
    Vector3 operator-(Vector3 otherVector);
    static Vector3 normal(Vector3 vector);
    float module();
    //new methods
    void operator+=(Vector3 otherVector);
    Vector3 operator+(Vector3 otherVector);
    void operator-=(Vector3 otherVector);
    Vector3 operator*(float otherFloat);
    Vector3 operator/(float otherFloat);
};

struct Operators
{
    static void transp(vector<vector<float>>&matrix);
};

#endif /* GlueMath_hpp */

//
//  GlueMath.cpp
//  LinearAlgebra
//
//  Created by Alexander Fomenko on 12/11/2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#include "GlueMath.hpp"

Vector3::Vector3()
{
    X = 0.f;
    Y = 0.f;
    Z = 0.f;
}

Vector3::Vector3(float X, float Y, float Z)
{
    this->X = X;
    this->Y = Y;
    this->Z = Z;
}

Vector3 Vector3::operator*(Vector3 otherVector)
{
    Vector3 result;
    
    result.X = this->Y * otherVector.Z - this->Z * otherVector.Y;
    result.Y = this->Z * otherVector.X - this->X * otherVector.Z;
    result.Z = this->X * otherVector.Y - this->Y * otherVector.X;
    
    return result;
}

float Vector3::module()
{
    return sqrt(powl(X, 2.f) + powl(Y, 2.f) + powl(Z, 2.f));
}

Vector3 Vector3::operator-(Vector3 otherVector)
{
    Vector3 result;
    
    result.X = this->X - otherVector.X;
    result.Y = this->Y - otherVector.Y;
    result.Z = this->Z - otherVector.Z;
    
    return result;
}

Vector3 Vector3::normal(Vector3 vector)
{
    float vectLength = sqrt(powf(vector.X, 2.f) + powf(vector.Y, 2.f) + powf(vector.Z, 2.f));
    Vector3 normal;
    
    normal.X = vector.X / vectLength;
    normal.Y = vector.Y / vectLength;
    normal.Z = vector.Z / vectLength;
    
    return normal;
}

void Vector3::operator+=(Vector3 otherVector)
{
    this->X += otherVector.X;
    this->Y += otherVector.Y;
    this->Z += otherVector.Z;
}
Vector3 Vector3::operator+(Vector3 otherVector)
{
    Vector3 result;
    
    result.X = this->X + otherVector.X;
    result.Y = this->Y + otherVector.Y;
    result.Z = this->Z + otherVector.Z;
    
    return result;
}
void Vector3::operator-=(Vector3 otherVector)
{
    this->X -= otherVector.X;
    this->Y -= otherVector.Y;
    this->Z -= otherVector.Z;
}

Vector3 Vector3::operator*(float otherFloat)
{
    Vector3 result;
    
    result.X = this->X * otherFloat;
    result.Y = this->Y * otherFloat;
    result.Z = this->Z * otherFloat;
    
    return result;
}
Vector3 Vector3::operator/(float otherFloat)
{
    Vector3 result;
    
    result.X = this->X / otherFloat;
    result.Y = this->Y / otherFloat;
    result.Z = this->Z / otherFloat;
    
    return result;
}

void Operators::transp(vector<vector<float>>&matrix)
{
    vector<vector<float>>transpMatr = matrix;
    
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            transpMatr[row][col] = matrix[col][row];
        }
    }
    
    matrix = transpMatr;
}


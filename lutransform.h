#ifndef LUTRANSFORM_H
#define LUTRANSFORM_H

#include <QVector>
#include "gluekitmath.h"

class LUTransform
{
public:
    LUTransform();

    static QVector<float> CalculateSolution(Matrix matrix, QVector<float> vector);
};

#endif // LUTRANSFORM_H

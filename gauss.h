#ifndef GAUSS_H
#define GAUSS_H

#include "gluekitmath.h"
#include <QVector>

class Gauss
{
public:
    Gauss();

    static QVector<float> CalculateSolution(Matrix matrix, QVector<float> vector);

private:

};

#endif // GAUSS_H

#ifndef SWEEP_H
#define SWEEP_H

#include "gluekitmath.h"
#include <QVector>

class Sweep
{
public:
    Sweep();

    static QVector<float> CalculateSolution(Matrix matrix, QVector<float> vector);
};

#endif // SWEEP_H

#include "sweep.h"

Sweep::Sweep()
{

}

QVector<float> Sweep::CalculateSolution(Matrix matrix, QVector<float> vector)
{
    int height = matrix.height();

    QVector<float> a(height - 1);
    QVector<float> b(height - 1);
    QVector<float> c(height);
    QVector<float> f = vector;

    for (int i = 0; i < height; i++)
    {
        if (i != height - 1)
        {
            a[i] = matrix[i + 1][i];
            b[i] = matrix[i][i + 1];
        }

        c[i] = matrix[i][i];
    }

    QVector<float> alpha(a.size());
    QVector<float> beta(c.size());
    QVector<float> gamma(c.size());

    alpha[0] = -b[0] / c[0];
    beta[0] = f[0] / c[0];

    int size = c.size();

    for (int i = 1; i < size; i++)
    {
        gamma[i] = c[i] + a[i - 1] * alpha[i - 1];

        if (i != size - 1)
        {
            alpha[i] = -b[i] / gamma[i];
        }

        beta[i] = (-a[i - 1] * beta[i - 1] + f[i]) / gamma[i];
    }

    QVector<float> solution(size);

    solution[size - 1] = beta[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        solution[i] = alpha[i] * solution[ i + 1] + beta[i];
    }

    return solution;
}

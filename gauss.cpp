#include "gauss.h"

Gauss::Gauss()
{

}

QVector<float> Gauss::CalculateSolution(Matrix matrix, QVector<float> vector)
{
    Matrix fullMatrix = matrix;
    fullMatrix.addCol(vector);
    int limit = 1;

    QVector<QVector<float>> triangMatrix = Matrix::fromMatrix(fullMatrix);

    for (int col = 0; col < fullMatrix.width() - 1; col++)
    {
        fullMatrix.setMatrix(triangMatrix);
        triangMatrix.clear();

        for (int row = fullMatrix.height() - 1; row >= limit; row--)
        {
            float topElement = fullMatrix[row - 1][col];
            float botElement = -fullMatrix[row][col];

            Matrix topRow = Matrix(fullMatrix[row - 1]) * botElement;
            Matrix botRow = Matrix(fullMatrix[row]) * topElement;
            Matrix resRow = topRow + botRow;

            triangMatrix.push_front(Matrix::fromMatrix(resRow)[0]);
        }

        for (int cnt = limit - 1; cnt >= 0; cnt--)
        {
            triangMatrix.push_front(fullMatrix[cnt]);
        }

        limit++;
    }

    QVector<float> solution;
    int height = fullMatrix.height();
    int width = fullMatrix.width();

    solution.resize(height);
    solution[height - 1] = fullMatrix[height - 1][width - 1] / fullMatrix[height - 1][width - 2];

    for (int i = height - 2; i >= 0; i--)
    {
        float sum = 0.f;

        for (int j = i + 1; j < height; j++)
        {
            sum += fullMatrix[i][j] * solution[j];
        }

        solution[i] = (fullMatrix[i][width - 1] - sum) / fullMatrix[i][i];
    }

    return solution;
}

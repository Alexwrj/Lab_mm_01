#include "lutransform.h"

LUTransform::LUTransform()
{

}

QVector<float> LUTransform::CalculateSolution(Matrix matrix, QVector<float> vector)
{
    Matrix fullMatrix = matrix;
    fullMatrix.addCol(vector);
    int limit = 1;

    QVector<QVector<float>> vectMatrixU = Matrix::fromMatrix(fullMatrix);

    //create U matrix
    for (int col = 0; col < fullMatrix.width() - 1; col++)
    {
        fullMatrix.setMatrix(vectMatrixU);
        vectMatrixU.clear();

        for (int row = fullMatrix.height() - 1; row >= limit; row--)
        {
            float topElement = fullMatrix[row - 1][col];
            float botElement = -fullMatrix[row][col];

            Matrix topRow = Matrix(fullMatrix[row - 1]) * botElement;
            Matrix botRow = Matrix(fullMatrix[row]) * topElement;

            Matrix resRow = topRow + botRow;

            vectMatrixU.push_front(Matrix::fromMatrix(resRow)[0]);
        }

        for (int cnt = limit - 1; cnt >= 0; cnt--)
        {
            vectMatrixU.push_front(fullMatrix[cnt]);
        }

        limit++;
    }

    Matrix matrixU = Matrix(vectMatrixU);

    for (int i = 0; i < matrixU.height(); i++)
    {
        float centroid = matrixU[i][i];
        for (int j = 0; j < matrixU[i].size(); j++)
        {
            matrixU[i][j] /= centroid;
        }
    }

    Matrix tmp(matrixU.height(), matrixU.width() - 1);

    for (int i = 0; i < matrixU.height(); i++)
    {
        for (int j = 0; j < matrixU.width() - 1; j++)
        {
            tmp[i][j] = matrixU[i][j];
        }
    }

    matrixU = tmp;

    int height = matrix.height();
    int width = matrix.width();

    Matrix matrixL = Matrix(height, width);

    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            matrixL[i][j] = 0.f;
        }
    }

    for (int i = 0; i < height; i++)
    {
        matrixL[i][0] = matrix[i][0];
    }

    for (int i = 1; i < height; i++)
    {
        matrixL[i][0] = matrix[i][0];

        for (int j = 1; j < height; j++)
        {
            float sum = 0.f;
            for (int k = 0; k < j; k++)
            {
                sum += matrixL[i][k] * matrixU[k][j];
            }

            matrixL[i][j] = matrix[i][j] - sum;
        }
    }

    Matrix check = matrixL * matrixU;
    QVector<float> y;
    y.resize(height);

    y[0] = vector[0] / matrixL[0][0];

    for (int i = 1; i < height; i++)
    {
        float sum = 0.f;

        for (int j = 0; j < i; j++)
        {
            sum += matrixL[i][j] * y[j];
        }

        y[i] = (vector[i] - sum) / matrixL[i][i];
    }

    QVector<float> solution;
    solution.resize(width);

    solution[width - 1] = y[width - 1];

    for (int i = width - 2; i >= 0; i--)
    {
        float sum = 0.f;

        for (int j = i + 1; j < width; j++)
        {
            sum += matrixU[i][j] * solution[j];
        }

        solution[i] = y[i] - sum;
    }


    return solution;
}

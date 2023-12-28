#pragma once

struct Matrix
{
    double data[4][4];
    
    //Default error value: -1.69420
    Matrix()
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                data[i][j] = -69420;
    }
};

namespace DH
{
    Matrix CreateMatrix(double d, double theta_input, double r, double alpha_input);
    void printMatrix(Matrix input);
    Matrix multiplyMatrices(const Matrix& first, const Matrix& second);
    Matrix calculateFinal(const Matrix& nr1, const Matrix& nr2, const Matrix& nr3, const Matrix& nr4, const Matrix& nr5, const Matrix& nr6);
}
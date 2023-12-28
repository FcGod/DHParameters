#pragma once

struct Matrix
{
    double data[4][4];
   
    //Init 0
    Matrix()
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                data[i][j] = 0;
    }

    //* overload
    Matrix operator*(const Matrix& second) const
    {
        Matrix result;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    result.data[i][j] += data[i][k] * second.data[k][j];
                }
            }

        }
        return result;
    }

};

namespace DH
{
    Matrix CreateMatrix(double d, double theta_input, double r, double alpha_input);
    void printMatrix(Matrix input);
    Matrix calculateFinal(const Matrix& nr1, const Matrix& nr2, const Matrix& nr3, const Matrix& nr4, const Matrix& nr5, const Matrix& nr6);
    Matrix fill();
}

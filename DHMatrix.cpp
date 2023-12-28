#include "DHMatrix.h"
#include <cmath>
#include <iostream>

namespace DH
{
    Matrix CreateMatrix(double d, double theta_input, double r, double alpha_input)
    {
        Matrix transformMatrix;
        constexpr double pi{ 3.14159265358979323846 };
        constexpr double tolerance{ 1e-10 };

        //Convert to radians, as sin() and cos() need.
        double theta = theta_input * pi / 180.0;
        double alpha = alpha_input * pi / 180.0;
        
        //Floating point error at 10e-17. 
        //Using ternary to convert 10e-17 to 0.0
        //Abs in case negative answers for false 0.0                                        === MATRIX VALUES ===
        transformMatrix.data[0][0] = (std::abs(cos(theta))                < tolerance)      ? 0.0 : cos(theta);
        transformMatrix.data[0][1] = (std::abs(-sin(theta) * cos(alpha))  < tolerance)      ? 0.0 : -sin(theta) * cos(alpha);
        transformMatrix.data[0][2] = (std::abs(sin(theta) * sin(alpha))   < tolerance)      ? 0.0 : sin(theta) * sin(alpha);
        transformMatrix.data[0][3] = (std::abs(cos(theta))                < tolerance)      ? 0.0 : r * cos(theta);

        transformMatrix.data[1][0] = (std::abs(sin(theta))                < tolerance)      ? 0.0 : sin(theta);
        transformMatrix.data[1][1] = (std::abs(cos(theta) * cos(alpha))   < tolerance)      ? 0.0 : cos(theta) * cos(alpha);
        transformMatrix.data[1][2] = (std::abs(-cos(theta) * sin(alpha))  < tolerance)      ? 0.0 : -cos(theta) * sin(alpha);
        transformMatrix.data[1][3] = (std::abs(sin(theta))                < tolerance)      ? 0.0 : r * sin(theta);

        transformMatrix.data[2][0] =                                                        0;
        transformMatrix.data[2][1] = (std::abs(sin(alpha))                < tolerance)      ? 0.0 : sin(alpha);
        transformMatrix.data[2][2] = (std::abs(cos(alpha))                < tolerance)      ? 0.0 : cos(alpha);
        transformMatrix.data[2][3] =                                                        d;

        transformMatrix.data[3][0] =                                                        0;
        transformMatrix.data[3][1] =                                                        0;
        transformMatrix.data[3][2] =                                                        0;
        transformMatrix.data[3][3] =                                                        1;

        return transformMatrix;
    }

    void printMatrix(Matrix input)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                std::cout << input.data[i][j] << " | ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    double randomnr()
    {
        return rand() % 10 + 1;
    }

    Matrix fill()
    {
        Matrix temp;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                temp.data[i][j] = randomnr();

        return temp;
    }

    Matrix calculateFinal(const Matrix& T1, const Matrix& T2, const Matrix& T3, const Matrix& T4, const Matrix& T5, const Matrix& T6)
    {
        Matrix result;
       
        result = ((((T1 * T2) * T3) * T4) * T5) * T6;
        printMatrix(result);


        return result;
    }


}

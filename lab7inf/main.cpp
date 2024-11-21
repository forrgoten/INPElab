#include <iostream>
#include <array>
#include <stdexcept>

using namespace std;

array<double, 4> gauss(array<array<double, 5>, 4> matrix)
{
    for (int i = 0; i < 4; ++i)
    {
        double maxElement = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < 4; ++k)
        {
            if (abs(matrix[k][i]) > maxElement)
            {
                maxElement = abs(matrix[k][i]);
                maxRow = k;
            }
        }
        for (int k = i; k < 5; ++k)
        {
            swap(matrix[maxRow][k], matrix[i][k]);
        }
        for (int k = i + 1; k < 4; ++k)
        {
            double coeff = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < 5; ++j)
            {
                if (i == j)
                {
                    matrix[k][j] = 0;
                } else
                {
                    matrix[k][j] += coeff * matrix[i][j];
                }
            }
        }
    }
    array<double, 4> solution;
    for (int i = 3; i >= 0; --i)
    {
        solution[i] = matrix[i][4] / matrix[i][i];
        for (int j = i + 1; j < 4; ++j)
        {
            solution[i] -= (matrix[i][j] / matrix[i][i]) * solution[j];
        }
    }
    return solution;
}

int main()
{
    array<array<double, 5>, 4> matrix;
    cout << "Enter matrix row by row" << endl;
    cin >> matrix[0][0] >> matrix[0][1] >> matrix[0][2] >> matrix[0][3] >> matrix[0][4];
    cin >> matrix[1][0] >> matrix[1][1] >> matrix[1][2] >> matrix[1][3] >> matrix[1][4];
    cin >> matrix[2][0] >> matrix[2][1] >> matrix[2][2] >> matrix[2][3] >> matrix[2][4];
    cin >> matrix[3][0] >> matrix[3][1] >> matrix[3][2] >> matrix[3][3] >> matrix[3][4];
    array<double, 4> y = gauss(matrix);
    array<double, 4> x = {1, 1, 2, -3};
    double answr = y[0] * x[0] + y[1] * x[1] + y[2] * x[2] + y[3] * x[3];
    cout << answr << endl;
    return 0;
}
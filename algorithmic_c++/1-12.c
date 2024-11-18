#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAT_SIZE 3

double input_a[MAT_SIZE][MAT_SIZE + 1] = {{1, -5, 1, 7},
                                          {10, 0, 20, 6},
                                          {5, 0, -1, 4}};
double input_b[MAT_SIZE][MAT_SIZE + 1] = {{1, 1, -1, 1},
                                          {1, 1, 4, 2},
                                          {2, -1, 2, 3}};
double input_c[MAT_SIZE][MAT_SIZE + 1] = {{2, -3, 2, 5},
                                          {-4, 2, -6, 14},
                                          {2, 2, 4, 8}};
double input_d[MAT_SIZE][MAT_SIZE + 1] = {{0, 1, 1, 6},
                                          {1, -2, -1, 4},
                                          {1, -1, 1, 5}};

void standard_g(double (*input)[MAT_SIZE + 1])
{
    double input_copy[MAT_SIZE][MAT_SIZE + 1];

    for (int n = 0; n < MAT_SIZE; n++)
        for (int m = 0; m < MAT_SIZE + 1; m++)
            input_copy[n][m] = input[n][m];

    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int l = i + 1; l < MAT_SIZE; l++)
        {
            double m = input_copy[l][i] / input_copy[i][i];
            for (int k = 0; k < MAT_SIZE + 1; k++)
                input_copy[l][k] = input_copy[l][k] - m * input_copy[i][k];
        }
    }

    for (int i = MAT_SIZE - 1; i > -1; i--)
    {
        double sub_val = 0.0;
        for (int l = i + 1; l < MAT_SIZE; l++)
            sub_val += input_copy[i][l] * input_copy[l][MAT_SIZE];

        input_copy[i][MAT_SIZE] = (input_copy[i][MAT_SIZE] - sub_val) / input_copy[i][i];
    }

    for (int i = 0; i < MAT_SIZE; i++)
        printf("%f ", input_copy[i][MAT_SIZE]);
    printf("\n");
}

int main(void)
{
    double(*input_list[4])[MAT_SIZE + 1] = {input_a, input_b, input_c, input_d};
    for (int i = 0; i < 4; i++)
    {
        standard_g(input_list[i]);
    }

    return 0;
}
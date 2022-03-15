/*
** EPITECH PROJECT, 2021
** B-MAT_203hotline
** File description:
** test_computations
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Hotline.hpp"

double getBinomialCoef(double, double);
long double factorial(int);

Test(compute, getBinomialCoef)
{
    cr_assert_eq(6, getBinomialCoef(4, 2));
}

Test(compute, factorial)
{
    cr_assert_eq(120, factorial(5));
}

Test(compute, binomial_distributions)
{
    const int calls = 3500;
    const int hours = 8;
    double prob = (double)(180) / (double)(hours * 60 * 60);
    double res = 0.0;
    double bin[] = {0.000, 0.000, 0.000, 0.000, 0.000,
                    0.000, 0.000, 0.000, 0.000, 0.001,
                    0.002, 0.004, 0.008, 0.013, 0.021,
                    0.030, 0.041, 0.053, 0.065, 0.075,
                    0.082, 0.085, 0.085, 0.081, 0.074,
                    0.064, 0.054, 0.044, 0.034, 0.026,
                    0.019, 0.013, 0.009, 0.006, 0.004,
                    0.002, 0.001, 0.000, 0.000, 0.000,
                    0.000, 0.000, 0.000, 0.000, 0.000,
                    0.000, 0.000, 0.000, 0.000, 0.000,
                    0.000};
    
    for (int k = 0; k != 51; k++) {
        res = getBinomialCoef(calls, k) * std::pow(prob, k) * std::pow((1 - prob), calls - k);
        cr_assert_float_eq(bin[k], res, 0.001);
    }
}

Test(compute, poisson_distribution)
{
    const int calls = 3500;
    const int hours = 8;
    double prob = (double)(180) / (double)(hours * 60 * 60);
    double res = 0.0;
    double exp = calls * prob;
    double poi[] = {0.000, 0.000, 0.000, 0.000, 0.000,
                    0.000, 0.000, 0.000, 0.000, 0.001,
                    0.002, 0.004, 0.008, 0.013, 0.021,
                    0.030, 0.042, 0.053, 0.065, 0.075,
                    0.082, 0.085, 0.085, 0.081, 0.073,
                    0.064, 0.054, 0.044, 0.034, 0.026,
                    0.019, 0.013, 0.009, 0.006, 0.004,
                    0.002, 0.001, 0.000, 0.000, 0.000,
                    0.000, 0.000, 0.000, 0.000, 0.000,
                    0.000, 0.000, 0.000, 0.000, 0.000,
                    0.000};

    for (int k = 0; k != 51; k++) {
        res = (std::exp(-exp) * std::pow(exp, k)) / factorial(k);
        cr_assert_float_eq(poi[k], res, 0.001);
    }
}
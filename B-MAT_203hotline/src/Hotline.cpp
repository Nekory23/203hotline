/*
** EPITECH PROJECT, 2021
** 203hotline
** File description:
** Hotline
*/

#include <time.h>
#include "Error.hpp"
#include "Hotline.hpp"

hotline::Hotline::Hotline(int const ac, char const **av)
{
    if (ac > 3 || ac < 2)
        throw Error(std::cerr, "Invalid number of arguments, retry with -h.");
    for (int i = 1; i != ac; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] >= '0' && av[i][j] <= '9')
                continue;
            else
                throw Error(std::cerr, "The argurments must be numbers, retry with -h.");
    if (ac == 3 && atoi(av[1]) < atoi(av[2]))
        throw Error(std::cerr, "Binomial coefficient: The first argument must be greater than the second argument.");
    if (ac == 3) {
        _n = atoi(av[1]);
        _k = atoi(av[2]);
    } else {
        _d = atoi(av[1]);
    }
}

unsigned __int128 hotline::Hotline::getCoef(int n, int k) const
{
    if (k == 0)
        return 1;
    return (n * getCoef(n-1, k-1) / k);
}

std::string hotline::Hotline::int128ToString(unsigned __int128 fac) const
{
    std::string res;
    std::string cpy;

    for (; fac > 0; fac /= 10)
        cpy += fac % 10 + '0';
    for (int i = cpy.length() - 1; i >= 0; i--)
        res += cpy[i];
    return res;
}

void hotline::Hotline::binomialCoef() const
{
    std::cout << _k << "-combinations of a set of size " << _n << ":" << std::endl;
    std::cout << int128ToString(getCoef(_n, _k)) << std::endl;
}

long double factorial(int nbr)
{
    long double res = nbr;

    if (nbr == 0)
        return 1;
    for (int i = 1; i != nbr; i++)
        res *= i;
    return res;
}

double getBinomialCoef(double n, double k)
{
    if (k == 0)
        return 1;
    return (n * getBinomialCoef(n-1, k-1) / k);
}

void hotline::Hotline::compute() const
{
    const int hours = 8;
    const int calls = 3500;
    double res = 0;
    double overload = 0;
    double prob = (double)(_d) / (double)(hours * 60 * 60);
    double exp = calls * prob;
    clock_t execTime;

    execTime = clock();
    std::cout << "Binomial distribution:" << std::endl;
    for (int k = 0; k != 51; k++) {
        if ((k != 0) && (k % 5 == 0))
            std::cout << std::endl;
        else if ((k != 0))
            std::cout << "\t";
        res = getBinomialCoef(calls, k) * std::pow(prob, k) * std::pow((1 - prob), calls - k);
        std::cout << k << " -> " << std::fixed << std::setprecision(3) << res;
        if (k <= 25)
            overload += res;
    }
    std::cout << std::endl;
    overload = (1 - overload) * 100;
    std::cout << "Overload: " << std::fixed << std::setprecision(1) << overload << "%" << std::endl;
    std::cout << "Computation time: " << std::fixed << std::setprecision(2) << ((float)execTime)/CLOCKS_PER_SEC * 1000 << " ms\n" << std::endl;
    
    overload = 0;
    execTime = clock();
    std::cout << "Poisson distribution:" << std::endl;
    for (int k = 0; k != 51; k++) {
        if ((k != 0) && (k % 5 == 0))
            std::cout << std::endl;
        else if ((k != 0))
            std::cout << "\t";
        res = (std::exp(-exp) * std::pow(exp, k)) / factorial(k);
        std::cout << k << " -> " << std::fixed << std::setprecision(3) << res;
        if (k <= 25)
            overload += res;
    }
    overload = (1 - overload) * 100;
    std::cout << std::endl;
    std::cout << "Overload: " << std::fixed << std::setprecision(1) << overload << "%" << std::endl;
    std::cout << "Computation time: " << std::fixed << std::setprecision(2) << ((float)execTime)/CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}
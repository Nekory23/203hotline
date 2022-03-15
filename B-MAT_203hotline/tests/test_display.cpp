/*
** EPITECH PROJECT, 2021
** B-MAT_203hotline
** File description:
** test_display
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <string>
#include "Hotline.hpp"
#include "Error.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display, binomial_coef, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[3] = {"\0", "4", "2"};

    hotline::Hotline htl(ac, av);
    htl.binomialCoef();
    cr_assert_stdout_eq_str("2-combinations of a set of size 4:\n6\n");
}

//Test(display, distribution, .init=redirect_all_stdout)
//{
//    const int ac = 3;
//    const char *av[3] = {"\0", "180"};
//    std::string line;
//    std::string display[] = {"Binomial distribution:",
//                             "0 -> 0.000      1 -> 0.000      2 -> 0.000      3 -> 0.000      4 -> 0.000",
//                             "5 -> 0.000      6 -> 0.000      7 -> 0.000      8 -> 0.000      9 -> 0.001",
//                             "10 -> 0.002     11 -> 0.004     12 -> 0.008     13 -> 0.013     14 -> 0.021",
//                             "15 -> 0.030     16 -> 0.041     17 -> 0.053     18 -> 0.065     19 -> 0.075",
//                             "20 -> 0.082     21 -> 0.085     22 -> 0.085     23 -> 0.081     24 -> 0.074",
//                             "25 -> 0.064     26 -> 0.054     27 -> 0.044     28 -> 0.034     29 -> 0.026",
//                             "30 -> 0.019     31 -> 0.013     32 -> 0.009     33 -> 0.006     34 -> 0.004",
//                             "35 -> 0.002     36 -> 0.001     37 -> 0.001     38 -> 0.000     39 -> 0.000",
//                             "40 -> 0.000     41 -> 0.000     42 -> 0.000     43 -> 0.000     44 -> 0.000",
//                             "45 -> 0.000     46 -> 0.000     47 -> 0.000     48 -> 0.000     49 -> 0.000",
//                             "50 -> 0.000",
//                             "Overload: 21.4%",
//                             "",
//                             "Poisson distribution:",
//                             "0 -> 0.000      1 -> 0.000      2 -> 0.000      3 -> 0.000      4 -> 0.000",
//                             "5 -> 0.000      6 -> 0.000      7 -> 0.000      8 -> 0.000      9 -> 0.001",
//                             "10 -> 0.002     11 -> 0.004     12 -> 0.008     13 -> 0.013     14 -> 0.021",
//                             "15 -> 0.030     16 -> 0.042     17 -> 0.053     18 -> 0.065     19 -> 0.075",
//                             "20 -> 0.082     21 -> 0.085     22 -> 0.085     23 -> 0.081     24 -> 0.073",
//                             "25 -> 0.064     26 -> 0.054     27 -> 0.044     28 -> 0.034     29 -> 0.026",
//                             "30 -> 0.019     31 -> 0.013     32 -> 0.009     33 -> 0.006     34 -> 0.004",
//                             "35 -> 0.002     36 -> 0.001     37 -> 0.001     38 -> 0.001     39 -> 0.000",
//                             "40 -> 0.000     41 -> 0.000     42 -> 0.000     43 -> 0.000     44 -> 0.000",
//                             "45 -> 0.000     46 -> 0.000     47 -> 0.000     48 -> 0.000     49 -> 0.000",
//                             "50 -> 0.000",
//                             "Overload: 21.5%"};
//
//    hotline::Hotline htl(ac, av);
//    htl.compute();
//    for (int i = 0; std::getline(std::cin, line); i++) {
//        if (line.compare(0, std::strlen("Computation"), "Computation") == 0)
//            continue;
//        cr_assert_eq(line, display[i]);
//    }
//}

Test(return_value, exit_0_distribution, .exit_code=0, .init=redirect_all_stdout)
{
    const int ac = 2;
    const char *av[2] = {"\0", "180"};

    start(ac, av);
}

Test(return_value, exit_0_binomial, .exit_code=0, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[3] = {"\0", "4", "2"};

    start(ac, av);
}
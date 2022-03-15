/*
** EPITECH PROJECT, 2021
** 203hotline
** File description:
** Start
*/

#include "Error.hpp"
#include "Hotline.hpp"

int display_help(const char *bin_name)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    " << bin_name << " [n k | d]\n" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "  n    n value for the computation of C(n, k)" << std::endl;
    std::cout << "  k    k value for the computation of C(n, k)" << std::endl;
    std::cout << "  d    average duration of calls (in seconds)" << std::endl;
    return SUCCESS;
}

int start(int const ac, char const **av)
{
    int ret = SUCCESS;
    
    try {
        if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
            return (display_help(av[0]));
        hotline::Hotline htl(ac, av);
        if (ac == 2)
            htl.compute();
        else
            htl.binomialCoef();
    }
    catch (const Error &e) {
        std::cout << "Error(s): " << e.what() << std::endl;
        ret = ERROR;
    }
    catch (...) {}
    return ret;
}
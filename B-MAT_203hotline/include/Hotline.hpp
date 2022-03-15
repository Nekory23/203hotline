/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

/* INCLUDE */
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "IHotline.hpp"

/* NAMESPACE | CLASS */
namespace hotline {
    class Hotline : public IHotline {
        public:
            Hotline(int const ac, char const **av);
            ~Hotline() = default;

            void binomialCoef() const;
            void compute() const;
            unsigned __int128 getCoef(int n, int k) const;
            std::string int128ToString(unsigned __int128 fac) const;
        private:
            int _n;
            int _k;
            int _d;
    };
}

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

/* PROTOTYPE */
int start(int const ac, char const **av);

#endif /* !MAIN_H_ */

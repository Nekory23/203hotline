/*
** EPITECH PROJECT, 2021
** 203hotline
** File description:
** IHotline
*/

#ifndef IHOTLINE_HPP_
#define IHOTLINE_HPP_

namespace hotline {
    class IHotline {
        public:
            ~IHotline() = default;

            virtual void binomialCoef() const = 0;
            virtual void compute() const = 0;
            virtual unsigned __int128 getCoef(int n, int k) const = 0;
            virtual std::string int128ToString(unsigned __int128 fac) const = 0;
        protected:
        private:
    };
}

#endif /* !IHOTLINE_HPP_ */
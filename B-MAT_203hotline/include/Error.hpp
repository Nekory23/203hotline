/*
** EPITECH PROJECT, 2021
** 203hotline
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <string>

class Error : std::exception {
    public:
        Error(std::ostream &os, const std::string &msg) throw();
        virtual ~Error() throw() {};
        const char *what() const throw();

    protected:
    private:
        std::string _msg;
        std::ostream &_os;
};

#endif /* !ERROR_HPP_ */
/*
** EPITECH PROJECT, 2021
** B-MAT_203hotline
** File description:
** test_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Hotline.hpp"
#include "Error.hpp"

Test(error_handling_ex, not_enough_args)
{
    const int ac = 1;
    const char *av[] = {"\0"};

    cr_assert_any_throw(hotline::Hotline htl(ac, av));
}

Test(error_handling_ex, too_many_args)
{
    const int ac = 4;
    const char *av[] = {"\0", "hey", "hey", "hey"};

    cr_assert_any_throw(hotline::Hotline htl(ac, av));
}

Test(error_handling_ex, invalid_args_coef)
{
    const int ac = 3;
    const char *av[] = {"\0", "hey", "89"};
    const char *av2[] = {"\0", "67", "hey"};
    const char *av3[] = {"\0", "hey", "hey"};

    cr_assert_any_throw(hotline::Hotline htl(ac, av));
    cr_assert_any_throw(hotline::Hotline htl(ac, av2));
    cr_assert_any_throw(hotline::Hotline htl(ac, av3));
}

Test(error_handling_ex, invalid_args_distribution)
{
    const int ac = 2;
    const char *av[] = {"\0", "hey"};

    cr_assert_any_throw(hotline::Hotline htl(ac, av));
}

Test(error_handling_ex, second_arg_greater)
{
    const int ac = 3;
    const char *av[] = {"\0", "60", "89"};

    cr_assert_any_throw(hotline::Hotline htl(ac, av));
}
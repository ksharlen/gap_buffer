/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:48:18 by ksharlen          #+#    #+#             */
/*   Updated: 2019/12/03 18:27:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		test_sym(char cmp1, char cmp2, char *test_name, char *str_error)
{
	if (cmp1 != cmp2)
	{
		PRINT_KO_NOTE(test_name, str_error);
		return (KO);
	}
	else
		return (OK);
}

int		test_null_ptr(void *ptr, char *test_name, char *str_error)
{
	if (ptr)
	{
		PRINT_KO_NOTE(test_name, str_error);
		return (KO);
	}
	else
		return (OK);
}

int		test_not_null_ptr(void *ptr, char *test_name, char *str_error)
{
	if (!ptr)
	{
		PRINT_KO_NOTE(test_name, str_error);
		return (KO);
	}
	else
		return (OK);
}

int		test_cmp_ptr(void *ptr1, void *ptr2, char *test_name, char *str_error)
{
	if (!TEST_CMP(ptr1, ptr2))
	{
		PRINT_KO_NOTE(test_name, str_error);
		return (KO);
	}
	else
		return (OK);
}

int		test_not_cmp_ptr(void *ptr1, void *ptr2, char *test_name, char *str_error)
{
	if (TEST_CMP(ptr1, ptr2))
	{
		PRINT_KO_NOTE(test_name, str_error);
		return (KO);
	}
	else
		return (OK);
}

int		test_cmp_int(ssize_t one, ssize_t two, char *test_name, char *str_error)
{
	if (one != two)
	{
		PRINT_KO_NOTE(test_name, str_error);
		return (KO);
	}
	else
		return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_put_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:50:47 by ksharlen          #+#    #+#             */
/*   Updated: 2019/12/24 20:39:12 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

//!Напрямую нигде не вызывается, она не защищена
void	gap_put_to_buf(gapbuf *buf, size_t pos, char sym)
{
	if (buf && BUF && pos < (size_t)SIZE_BUF)
		BUF[pos] = sym;
	//else
	//	ft_printf("error put_sym");
}

void	gap_put_sym_slide(gapbuf *buf, char sym)
{
	//!Может быть дополнительная проверка
	//!тут же будет вызываться gap_move
	if (buf && BUF && BUF_SLIDE < SIZE_BUF)
	{
		gap_put_to_buf(buf, BUF_SLIDE, sym);
		BUF_SLIDE++;
		LEN_STR++;
	}
	//else
	//ft_printf("error");
}

//!Используется для вставки перед курсором
void	put_sym_in_gap_buf(gapbuf *buf, char sym)
{
	//!Нужна проверка на остаток места в буфере
	if (!SIZE_GAP_BUF)
	{
		// printf("empty\n");
		new_gap(buf, DFLT_SIZE_GAP);
	}
	gap_move_to_slide(buf);
	BUF[GAP_START] = sym;
	GAP_START++;
	LEN_STR++;
	SIZE_GAP_BUF--;//!Тут опасно
}

void	put_str_in_gap_buf(gapbuf *buf, char *str)
{
	if (str && *str)
	{
		while (*str)
			put_sym_in_gap_buf(buf, *str++);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_put_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:50:47 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 17:48:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		gap_put_sym_in_str(t_gapbuf *buf, char sym)
{
	gapbuf_move_to_slide(buf);
	BUF[GAP_START++] = sym;
	LEN_STR++;
	if (SIZE_GAP_BUF)
		SIZE_GAP_BUF--;
	if (!SIZE_GAP_BUF)
		get_new_gapbuf(buf, buf->main_size_gap_buf);
	GAP_SLIDE++;
}

static void		gap_put_end_str(t_gapbuf *buf, char sym)
{
	if (GAP_START == (LEN_STR + 1))
	{
		BUF[LEN_STR] = sym;
		++GAP_START;
		++GAP_END;
	}
	else if (GAP_START < (LEN_STR + SIZE_GAP_BUF))
		BUF[LEN_STR + SIZE_GAP_BUF] = sym;
	GAP_SLIDE++;
	LEN_STR++;
}

void			gap_putchar_in_buf(t_gapbuf *buf, char sym)
{
	if ((LEN_STR + SIZE_GAP_BUF) < SIZE_BUF)
	{
		if (GAP_SLIDE == LEN_STR)
			gap_put_end_str(buf, sym);
		else
			gap_put_sym_in_str(buf, sym);
	}
	else
		die_gap("t_gapbuf: overflow buf");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_del_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:39:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 17:16:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	gap_put_char_in_buf(t_gapbuf *buf, char sym)
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

void	del_sym(t_gapbuf *buf, size_t del)
{
	if (del < SIZE_BUF)
	{
		GAP_SLIDE = del;
		gap_move_to_slide(buf);
		BUF[GAP_END +++ 1] = '\0';
		LEN_STR--;
		SIZE_GAP_BUF++;
	}
}

void			gap_del_before_slide(t_gapbuf *buf)
{
	if (LEN_STR)
	{
		if (GAP_SLIDE == LEN_STR)
		{
			BUF[LEN_STR + SIZE_GAP_BUF - 1] = '\0';
			--GAP_SLIDE;
			--LEN_STR;
		}
		else if (GAP_SLIDE)
			del_sym(buf, --GAP_SLIDE);
	}
}

void			gap_del_on_slide(t_gapbuf *buf)
{
	if (LEN_STR)
	{
		if (GAP_SLIDE == LEN_STR)
		{
			BUF[find_sym_pos(buf, GAP_SLIDE)] = '\0';
			--LEN_STR;
		}
		else if (GAP_SLIDE < LEN_STR)
			del_sym(buf, GAP_SLIDE);
	}
}

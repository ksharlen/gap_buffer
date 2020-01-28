/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_del_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:39:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 17:23:58 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		del_sym(t_gapbuf *buf, size_t del)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_move_gapbuf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:23:37 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 18:23:38 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		gap_move_left(t_gapbuf *buf, size_t ind)
{
	if (LEN_STR)
	{
		if ((GAP_END + 1) != ind)
		{
			while (GAP_START != ind)
			{
				BUF[GAP_END] = BUF[GAP_START - 1];
				BUF[GAP_START - 1] = '\0';
				--GAP_START;
				--GAP_END;
			}
		}
	}
}

static void		gap_move_right(t_gapbuf *buf, size_t ind)
{
	if (LEN_STR)
	{
		if (GAP_END + 1 != ind)
		{
			while (GAP_END != (ind - 1))
			{
				BUF[GAP_START] = BUF[GAP_END + 1];
				BUF[GAP_END + 1] = '\0';
				++GAP_START;
				++GAP_END;
			}
		}
	}
}

static void		gap_move(t_gapbuf *buf, size_t ind)
{
	if (BUF)
	{
		if (GAP_START < ind)
			gap_move_right(buf, ind);
		else if (GAP_START > ind)
			gap_move_left(buf, ind);
	}
}

void			gapbuf_move_to_slide(t_gapbuf *buf)
{
	int ind;

	ind = get_sym_ind_at_buf(buf, GAP_SLIDE);
	if (ind)
		if (GAP_END != (size_t)ind - 1 && GAP_SLIDE < LEN_STR)
			gap_move(buf, ind);
	if (ind == -1)
		die_gap("gapbuf_move_to_slide: SLIDE > LEN_STR");
}

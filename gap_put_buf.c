/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_put_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:50:47 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/27 21:47:53 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	put_sym_in_gap_buf(gapbuf *buf, char sym)
{
	if ((LEN_STR + SIZE_GAP_BUF) < SIZE_BUF)
	{
		gap_move_to_slide(buf);
		BUF[GAP_START++] = sym;
		LEN_STR++;
		if (SIZE_GAP_BUF)
			SIZE_GAP_BUF--;
		if (!SIZE_GAP_BUF)
			new_gap(buf, DFLT_SIZE_GAP);
	}
}

void	gap_put_sym_in_str(gapbuf *buf, char sym)
{
	put_sym_in_gap_buf(buf, sym);
	USER_SLIDE++;
}

void	gap_put_end_str(gapbuf *buf, char sym)
{
	size_t	end;

	end = LEN_STR + SIZE_GAP_BUF;
	if (end < SIZE_BUF)
	{
		BUF[end] = sym;
		BUF_SLIDE++;
		USER_SLIDE++;
		LEN_STR++;
	}
	else
		die_gap("gapbuf: overflow buf");
}

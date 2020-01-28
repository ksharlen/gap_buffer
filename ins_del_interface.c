/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_del_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:39:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 15:40:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	gap_put_char_in_buf(gapbuf *buf, char sym)
{
	BUF_SLIDE = USER_SLIDE; //!TESTING

	if ((size_t)BUF_SLIDE == LEN_STR)
		gap_put_end_str(buf, sym);
	else
		gap_put_sym_in_str(buf, sym);
}

void	del_sym(gapbuf *buf, size_t del)
{
	// size_t	ind;
//!нужна проверка на переполнение
	BUF_SLIDE = del;
	gap_move_to_slide(buf);
	BUF[GAP_END +++ 1] = '\0';
	LEN_STR--;
	SIZE_GAP_BUF++;
}

void			gap_del_before_slide(gapbuf *buf)
{
	// int ind;

	if (LEN_STR)
	{
		if (USER_SLIDE == LEN_STR)
		{
			BUF[LEN_STR + SIZE_GAP_BUF - 1] = '\0';
			--USER_SLIDE;
			--LEN_STR;
			// ind = find_sym_pos(buf, USER_SLIDE);
			// BUF[ind] = '\0';
			// --USER_SLIDE;
			// --LEN_STR;
		}
		else if (USER_SLIDE)
			del_sym(buf, --USER_SLIDE);
	}
}

void			gap_del_on_slide(gapbuf *buf)
{
	int ind;

	if (LEN_STR)
	{
		if (USER_SLIDE == LEN_STR)
		{
			ind = find_sym_pos(buf, USER_SLIDE);
			BUF[ind] = '\0';
			--LEN_STR;
		}
		else if (USER_SLIDE < LEN_STR)
		{
			del_sym(buf, USER_SLIDE);
		}
	}
}

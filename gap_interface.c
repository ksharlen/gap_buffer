/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/25 22:47:02 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	gap_put_sym_in_str(gapbuf *buf, char sym)
{
	put_sym_in_gap_buf(buf, sym);
	USER_SLIDE++;
}

void	gap_put_end_str(gapbuf *buf, char sym)
{
	BUF_SLIDE = LEN_STR + SIZE_GAP_BUF;
	if (BUF_SLIDE < SIZE_BUF)
	{
		BUF[BUF_SLIDE] = sym;
		BUF_SLIDE++;
		USER_SLIDE++;
		LEN_STR++;
	}
	else
		die_gap("gapbuf: overflow buf");
}

//?Потестить
char	*gap_get_buf(gapbuf *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = NULL;
	i = 0;
	j = 0;
//!remake for strnew()
	str = (char *)malloc(sizeof(char) * (buf->len_string + 1));
	bzero(str, buf->len_string + 1);
	while (j < (size_t)LEN_STR)
	{
		if (i == (size_t)GAP_START)
			i = GAP_END;
		else if (BUF[i])
			str[j++] = BUF[i];
		++i;
	}
	return (str);
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

//!ПОДУМАТЬ
void	gap_slide_left(gapbuf *buf)
{
	if (buf->user_slide)
		buf->user_slide--;
}

void	gap_put_char_in_buf(gapbuf *buf, char sym)
{
	if ((size_t)BUF_SLIDE == (LEN_STR + SIZE_GAP_BUF))
		gap_put_end_str(buf, sym);
	else
		gap_put_sym_in_str(buf, sym);
}

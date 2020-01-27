/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/27 18:58:40 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

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

void	gap_slide_left(gapbuf *buf)
{
	if (USER_SLIDE)
		--USER_SLIDE;
}

void	gap_slide_right(gapbuf *buf)
{
	if (USER_SLIDE < (LEN_STR))
		++USER_SLIDE;
}

void	gap_buf_init(gapbuf *buf, size_t size_buf, size_t size_gap)
{
	if (BUF)
		BUF = NULL;
	if (size_buf && size_gap)
	{
		if (size_gap > size_buf)
			size_gap = size_buf / 3;
		BUF = (char *)malloc(sizeof(char) * size_buf);
		if (!BUF)
			die_gap("gap_buf_init: malloc_error");
		memset(BUF, 0, sizeof(char) * size_buf);
		SIZE_BUF = size_buf;
		SIZE_GAP_BUF = size_gap;
		buf->main_size_gap_buf = size_gap;
		GAP_START = 0;
		GAP_END = SIZE_GAP_BUF - 1;
		BUF_SLIDE = GAP_END + 1;
		USER_SLIDE = 0;
		LEN_STR = 0;
	}
	else
		die_gap("size_buf || size_gap = 0");
}

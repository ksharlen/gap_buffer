/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 15:29:37 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

//!Переделать под libft
char	*gap_get_buf(gapbuf *buf)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (LEN_STR + 1));
	bzero(str, LEN_STR + 1);
	if (!GAP_START)
		memcpy(str, &BUF[GAP_END + 1], LEN_STR);
	else if (GAP_START == (LEN_STR + 1))
		memcpy(str, BUF, LEN_STR);
	else
		fill_str_skip_gap(buf, str);
	str[LEN_STR] = '\0';
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

//!Переделать под libft
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

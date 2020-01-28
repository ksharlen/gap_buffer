/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 17:49:54 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		fill_str_skip_gap(t_gapbuf *buf, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < LEN_STR)
	{
		if (BUF[j])
		{
			str[i] = BUF[j];
			++i;
		}
		++j;
	}
}

//!Переделать под libft
char			*gap_get_buf(t_gapbuf *buf)
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

void			gap_slide_left(t_gapbuf *buf)
{
	if (GAP_SLIDE)
		--GAP_SLIDE;
}

void	gap_slide_right(t_gapbuf *buf)
{
	if (GAP_SLIDE < (LEN_STR))
		++GAP_SLIDE;
}

//!Переделать под libft
void			gap_init(t_gapbuf *buf, size_t size_buf, size_t size_gap)
{
	if (BUF)
		BUF = NULL;
	if (size_buf && size_gap)
	{
		if (size_gap > size_buf)
			size_gap = size_buf / 3;
		BUF = (char *)malloc(sizeof(char) * size_buf);
		if (!BUF)
			die_gap("gap_init: malloc_error");
		memset(BUF, 0, sizeof(char) * size_buf);
		SIZE_BUF = size_buf;
		SIZE_GAP_BUF = size_gap;
		buf->main_size_gap_buf = size_gap;
		GAP_START = 0;
		GAP_END = SIZE_GAP_BUF - 1;
		GAP_SLIDE = 0;
		LEN_STR = 0;
	}
	else
		die_gap("size_buf || size_gap = 0");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_cpi_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:49:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/27 19:23:11 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

char	*gap_copy_str(gapbuf *buf)
{
	return (gap_get_buf(buf));
}

char	*gap_cut_str(gapbuf *buf)
{
	char	*str;

	str = gap_copy_str(buf);
	memset(BUF, '\0', SIZE_BUF);
	SIZE_GAP_BUF = buf->main_size_gap_buf;
	GAP_START = 0;
	GAP_END = SIZE_GAP_BUF - 1;
	BUF_SLIDE = GAP_END + 1;
	USER_SLIDE = 0;
	LEN_STR = 0;
	return (str);
}

static void		gap_put_str(gapbuf *buf, const char *str)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = strlen(str);
	while (i < len_str)
		gap_put_char_in_buf(buf, str[i++]);
}

void	gap_paste(gapbuf *buf, const char *str)
{
	if (str && *str)
	{
		if (!LEN_STR || USER_SLIDE == LEN_STR) //В пустой вставляем
			gap_put_str(buf, str);
/*
		else //Когда вставляем в текст или в начало
*/
	}
}

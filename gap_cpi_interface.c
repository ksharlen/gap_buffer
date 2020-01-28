/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_cpi_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:49:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 17:28:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

char	*gap_copy_str(t_gapbuf *buf)
{
	return (gap_get_buf(buf));
}

char	*gap_cut_str(t_gapbuf *buf)
{
	char	*str;

	str = gap_copy_str(buf);
	memset(BUF, '\0', SIZE_BUF);
	SIZE_GAP_BUF = buf->main_size_gap_buf;
	GAP_START = 0;
	GAP_END = SIZE_GAP_BUF - 1;
	GAP_SLIDE = 0;
	LEN_STR = 0;
	return (str);
}

static void		gap_put_str(t_gapbuf *buf, const char *str)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = strlen(str);
	while (i < len_str)
		gap_put_char_in_buf(buf, str[i++]);
}

static void		put_str_in_gap(t_gapbuf *buf, const char *str)
{
	size_t	len_str;

	len_str = strlen(str);
	if (len_str > SIZE_GAP_BUF)
	{
		del_gap_buf(buf);
		new_gap(buf, len_str);
	}
	gap_put_str(buf, str);
}

void	gap_paste(t_gapbuf *buf, const char *str)
{
	if (str && *str)
	{
		if (!LEN_STR || GAP_SLIDE == LEN_STR)
			gap_put_str(buf, str);
		else
			put_str_in_gap(buf, str);
	}
}

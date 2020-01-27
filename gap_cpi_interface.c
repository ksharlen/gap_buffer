/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_cpi_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:49:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/27 20:08:20 by ksharlen         ###   ########.fr       */
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

static void		put_str_in_gap(gapbuf *buf, const char *str)
{
	size_t	len_str;
	// int		ind;

	len_str = strlen(str);
	if (len_str > SIZE_GAP_BUF)
	{
		del_gap_buf(buf);
		new_gap(buf, len_str);
		// ind = find_sym_pos(buf, LEN_STR + 1);
		// gap_move(buf, LEN_STR + 1);
		// new_gap(buf, len_str);
		// gap_move_to_slide(buf);
		// BUF_SLIDE = USER_SLIDE;
	}
// printf("\n");
// print_stat_gapbuf(buf);
// exit(EXIT_FAILURE);
	gap_put_str(buf, str);
}

void	gap_paste(gapbuf *buf, const char *str)
{
	if (str && *str)
	{
		if (!LEN_STR || USER_SLIDE == LEN_STR) //В пустой вставляем
			gap_put_str(buf, str);
		else
			put_str_in_gap(buf, str);
	}
}

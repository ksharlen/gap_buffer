/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:18:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/28 17:18:35 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

//?TMP
void	print_buf_int(char *buf, size_t size_buf)
{
	for (size_t i = 0; i < size_buf; ++i)
		printf("buf[%zd] = %d\n", i, buf[i]);
	printf("\n");
}

//?TMP
void	print_buf_char(char *buf, size_t size_buf)
{
	for (size_t i = 0; i < size_buf; ++i)
		printf("buf[%zd] = %c\n", i, buf[i]);
	printf("\n");
}

//?TMP
void	print_stat_t_gapbuf(t_gapbuf *buf)
{
	printf("size_buf: %zd\n", buf->size_buf);
	printf("slide: %zd\n", buf->slide);
	printf("size_gap_buf: %zd\n", buf->size_gap_buf);
	printf("gap_start: %zd\n", buf->gap_start);
	printf("gap_end: %zd\n", buf->gap_end);
	printf("len_string: %zd\n", buf->len_string);
	printf("GAP_SLIDE: %zd\n", buf->slide);
	printf("main_size_gap_buf: %zd\n", buf->main_size_gap_buf);
	// printf("start_string: %d\n", buf->start_string);
}

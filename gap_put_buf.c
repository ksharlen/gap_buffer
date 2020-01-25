/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_put_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:50:47 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/25 22:12:59 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

//!Используется для вставки перед курсором
void	put_sym_in_gap_buf(gapbuf *buf, char sym)
{
	//!Нужна проверка на остаток места в буфере
	if (!SIZE_GAP_BUF)
		new_gap(buf, DFLT_SIZE_GAP);
	gap_move_to_slide(buf);
	BUF[GAP_START++] = sym;
	LEN_STR++;
	SIZE_GAP_BUF--;//!Тут опасно
}

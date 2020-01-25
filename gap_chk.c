/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:50:52 by ksharlen          #+#    #+#             */
/*   Updated: 2019/12/24 16:01:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

bool		no_size_gap_buf(gapbuf *buf)
{
	return ((!SIZE_GAP_BUF || GAP_START == GAP_END) ? true : false);
}

bool		no_gap_before_slide(gapbuf *buf)
{
	return ((GAP_END != BUF_SLIDE - 1) ? true : false);
}

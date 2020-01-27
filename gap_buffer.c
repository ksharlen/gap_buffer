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
void	print_stat_gapbuf(gapbuf *buf)
{
	printf("size_buf: %zd\n", buf->size_buf);
	printf("slide: %zd\n", buf->slide);
	printf("size_gap_buf: %zd\n", buf->size_gap_buf);
	printf("gap_start: %zd\n", buf->gap_start);
	printf("gap_end: %zd\n", buf->gap_end);
	printf("len_string: %zd\n", buf->len_string);
	printf("user_slide: %zd\n", buf->user_slide);
	printf("main_size_gap_buf: %zd\n", buf->main_size_gap_buf);
	// printf("start_string: %d\n", buf->start_string);
}

//!только если буфер закончился вызывается она
//!DONE
void	new_gap(gapbuf *buf, size_t len_new_gap)
{
	if (!len_new_gap)
		len_new_gap = buf->main_size_gap_buf;
	if (len_new_gap >= (SIZE_BUF - LEN_STR))
		len_new_gap = (SIZE_BUF - LEN_STR);
	GAP_START = LEN_STR + 1;//!Проверить правильно ли сделал что добавил + 1
	GAP_END = GAP_START + len_new_gap - 1;
	SIZE_GAP_BUF = len_new_gap;
}

//!DONE
int		find_sym_pos(gapbuf *buf, size_t pos_sym)
{
	size_t	ind;
	size_t	sym;

	if (pos_sym <= LEN_STR)
	{
		ind = 0;
		sym = 0;
		while(ind < (LEN_STR + SIZE_GAP_BUF) && sym != pos_sym)
		{
			if (BUF[ind++] != '\0')
				++sym;
		}
		return (ind);
	}
	return (-1);
}

void	del_gap_buf(gapbuf *buf)
{
	size_t	i;

	i = 0;
	if (SIZE_GAP_BUF && GAP_START < GAP_END && GAP_START < LEN_STR)
	{
		while (GAP_START != (SIZE_GAP_BUF + LEN_STR + 1))
		{
			BUF[GAP_START++] = BUF[++GAP_END];
			BUF[GAP_END] = '\0';
		}
	}
	GAP_START = 0;
	GAP_END = 0;
	SIZE_GAP_BUF = 0;
}

void	fill_str_skip_gap(gapbuf *buf, char *str)
{
// 	size_t	i;
// 	int		ind;

// 	ind = find_sym_pos(buf, LEN_STR);
// // printf("\nind: %zd\n", ind);
// // exit(EXIT_FAILURE);
// 	i = 0;
// 	while (i < (size_t)ind)
// 	{
// 		if (BUF[i])
// 		{
// 			*str = BUF[i];
// 			++str;
// 		}
// 		++i;
// 	}

	size_t	size_str = LEN_STR;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size_str)
	{
		if (BUF[j])
		{
			str[i] = BUF[j];
			++i;
		}
		++j;
	}
}

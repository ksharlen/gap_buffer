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
	// printf("start_string: %d\n", buf->start_string);
}

void	new_gap(gapbuf *buf, size_t len_new_gap)
{
	if (len_new_gap)
	{
		if (len_new_gap >= (SIZE_BUF - LEN_STR))
			len_new_gap = (SIZE_BUF - LEN_STR);
		GAP_START = LEN_STR;
		GAP_END = GAP_START + len_new_gap;
		SIZE_GAP_BUF = len_new_gap;
	}
}

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

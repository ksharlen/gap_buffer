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
	printf("size_buf: %d\n", buf->size_buf);
	printf("slide: %d\n", buf->slide);
	printf("size_gap_buf: %d\n", buf->size_gap_buf);
	printf("gap_start: %d\n", buf->gap_start);
	printf("gap_end: %d\n", buf->gap_end);
	printf("len_string: %zd\n", buf->len_string);
	printf("user_slide: %d\n", buf->user_slide);
	// printf("start_string: %d\n", buf->start_string);
}

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
		GAP_START = 0;
		GAP_END = SIZE_GAP_BUF - 1;
		BUF_SLIDE = GAP_END + 1;
		USER_SLIDE = 0;
		LEN_STR = 0;
	}
	else
		die_gap("size_buf || size_gap = 0");
}

void	new_gap(gapbuf *buf, size_t len_new_gap)
{
	if (len_new_gap)
	{
		if (len_new_gap <= (SIZE_BUF - LEN_STR))
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

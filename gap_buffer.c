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

void	new_gap(t_gapbuf *buf, size_t len_new_gap)
{
	if (!len_new_gap)
		len_new_gap = buf->main_size_gap_buf;
	if (len_new_gap >= (SIZE_BUF - LEN_STR))
		len_new_gap = (SIZE_BUF - LEN_STR);
	GAP_START = LEN_STR + 1;
	GAP_END = GAP_START + len_new_gap - 1;
	SIZE_GAP_BUF = len_new_gap;
}

int		find_sym_pos(t_gapbuf *buf, size_t pos_sym)
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

void	del_gap_buf(t_gapbuf *buf)
{
	if (SIZE_GAP_BUF && GAP_START < LEN_STR)
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

void	fill_str_skip_gap(t_gapbuf *buf, char *str)
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

void	die_gap(const char *s)
{
	write(STDERR_FILENO, s, strlen(s));
	exit(EXIT_FAILURE);
}

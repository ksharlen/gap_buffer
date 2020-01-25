#include "gap_buf.h"

#define TEST

int			main(void)
{
	gapbuf buf;

	gap_buf_init(&buf, 40, 10);

	gap_put_char_in_buf(&buf, 'h');
	gap_put_char_in_buf(&buf, 'e');
	gap_put_char_in_buf(&buf, 'l');
	gap_put_char_in_buf(&buf, 'l');
	gap_put_char_in_buf(&buf, 'o');
	gap_put_char_in_buf(&buf, ' ');
	gap_put_char_in_buf(&buf, 'w');
	gap_put_char_in_buf(&buf, 'o');
	gap_put_char_in_buf(&buf, 'r');
	gap_put_char_in_buf(&buf, 'l');
	gap_put_char_in_buf(&buf, 'd');

	buf.slide = 3;
	gap_put_char_in_buf(&buf, ' ');
	gap_put_char_in_buf(&buf, 'h');
	gap_put_char_in_buf(&buf, 'o');
	gap_put_char_in_buf(&buf, 'w');
	gap_put_char_in_buf(&buf, ' ');

	buf.slide = 0;
	gap_put_char_in_buf(&buf, 'a');
	gap_put_char_in_buf(&buf, 'r');
	gap_put_char_in_buf(&buf, 'e');
	gap_put_char_in_buf(&buf, ' ');

	gap_put_char_in_buf(&buf, 'h');
	gap_put_char_in_buf(&buf, 'a');
	gap_put_char_in_buf(&buf, 't');
	gap_put_char_in_buf(&buf, 'e');

	char	*str;

	str = gap_get_buf(&buf);

	if (!strcmp(str, "are hatehel how lo world"))
		printf("OKK!!!!\n");
	else
		printf("KO!!!!\n");

	printf("str:%s\n", str);

	print_buf_char(buf.buf, buf.size_buf);
	print_stat_gapbuf(&buf);
	return (0);
}

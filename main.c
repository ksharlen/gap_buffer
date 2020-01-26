#include "gap_buf.h"
#include <termio.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>

int			main(void)
{
	gapbuf buf;

	gap_buf_init(&buf, 100, 10);

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

	gap_slide_left(&buf);
	gap_slide_left(&buf);
	gap_slide_left(&buf);

	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');
	gap_put_char_in_buf(&buf, 'd');

	char	*str = gap_get_buf(&buf);


	print_buf_char(buf.buf, buf.size_buf);
	print_stat_gapbuf(&buf);
	printf("str: %s\n", str);
	return (0);
}

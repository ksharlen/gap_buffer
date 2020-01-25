#include "test.h"

gapbuf *test_init(size_t len_buf, size_t len_gap)
{
	gapbuf *buf;

	buf = (gapbuf *)malloc(sizeof(gapbuf));
	if (!buf)
		die_gap("test_init: malloc_error");
	gap_buf_init(buf, len_buf, len_gap);
	return (buf);
}

int		main(void)
{
	test_move();
	test_put_buf();
	test_chk();
	// test_gapbufer();
	return (0);
}

#include "test.h"

t_gapbuf *test_init(size_t len_buf, size_t len_gap)
{
	t_gapbuf *buf;

	buf = (t_gapbuf *)malloc(sizeof(t_gapbuf));
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
	// test_t_gapbufer();
	return (0);
}

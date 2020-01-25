#include "test.h"

static int		test_put_to_buf(void)
{
	gapbuf *buf;

	buf = test_init(20, 10);
	gap_put_to_buf(buf, buf->slide, 't');
	if (BUF[BUF_SLIDE] == 't')
		return (OK);
	else
		PRINT_KO_NOTE("put_to_buf", "slide != t");
	return (KO);
}

static int		test_null(void)
{
	gapbuf buf;

	buf.buf = NULL;
	gap_put_sym_slide(&buf, 't');
	gap_put_to_buf(&buf, 3, 'e');
	return (OK);
}

int				test_put_buf(void)
{
	PRINT_NAME_BLOCK("GAP_PUT_BUF");
	if (test_put_to_buf() == OK)
		PRINT_OK("put_to_buf");
	if (test_null() == OK)
		PRINT_OK("test_null");
	return (OK);
}

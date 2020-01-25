#include "test.h"

static int		test_move_right(void)
{
	gapbuf *buf;
	char	*test_str = "hello";
	char	*p_test = test_str;

	buf = test_init(30, 10);
	while (*p_test)
		gap_put_sym_slide(buf, *p_test++);
	gap_move(buf, 4);
	if (!memcmp("hell\0\0\0\0\0\0\0\0\0\0o", BUF, 15))
		return (OK);
	else
	{
		PRINT_KO_NOTE("move_right", "BUF != hel0000000000lo");
		return (KO);
	}
}

int		test_empty_buf(void)
{
	gapbuf *buf;
	gapbuf test;

	buf = test_init(20, 10);
	test = *buf;
	gap_move(buf, 4);
	if (memcmp(buf, &test, sizeof(gapbuf)))
	{
		PRINT_KO_NOTE("empty_buf", "memcmp != 0");
		return (KO);
	}
	else
		return (OK);
}

static int		test_ind_bigger_len_str(gapbuf *buf)
{
	char	*test_name = "ind > LEN_STRING";
	gapbuf 	test;

	test = *buf;
	gap_move(&test, test.len_string + 4);
	if (memcmp(buf, &test, sizeof(gapbuf)))
	{
		PRINT_KO_NOTE(test_name, "test_buf != buf");
		return (KO);
	}
	else
		return (OK);
}

static int	test_ind_bigger_size_buf(gapbuf *buf)
{
	gapbuf	test;
	char	*test_name = "ind > SIZE_BUF";

	test = *buf;
	gap_move(&test, SIZE_BUF + LEN_STR);
	if (memcmp(&test, buf, sizeof(gapbuf)))
	{
		PRINT_KO_NOTE(test_name, "test_buf != buf")
		return (KO);
	}
	else
		return (OK);
}

static int	test_buf_null(void)
{
	gapbuf buf;

	buf.buf = NULL;
	gap_move(&buf, 3);
	return (OK);
}

static int		test_move_beg_gap(gapbuf *buf)
{
	gapbuf	test = *buf;
	char	*test_name = "move_gap_beg(pos = 1)";

	gap_move(&test, 5);
	gap_move(&test, 0);
	if (memcmp(&test, buf, sizeof(gapbuf)))
	{
		PRINT_KO_NOTE(test_name, "test_buf != buf");
		return (KO);
	}
	else
		return (OK);
}

int		test_ind(void)
{
	gapbuf *buf;
	char	*test_string = 	"hello world";
	char	*p_test =		 test_string;
	int		ok[4];
	int		ret;

	buf = test_init(40, 10);
	while (*p_test)
		gap_put_sym_slide(buf, *p_test++);
	ok[0] = test_ind_bigger_len_str(buf);
	ok[1] = test_ind_bigger_size_buf(buf);
	ok[2] = test_buf_null();
	ok[3] = test_move_beg_gap(buf);
	ret = (ok[0] == OK && (ok[0] == ok[1] && ok[1] == ok[2] && ok[2] == ok[3]) ? OK : KO);
	return (ret);
}

int		test_move(void)
{
	PRINT_NAME_BLOCK("GAP_MOVE");
	if (test_move_right() == OK)
		PRINT_OK("move_right");
	if (test_empty_buf() == OK)
		PRINT_OK("emtpy_buf");
	if (test_ind() == OK)
		PRINT_OK("test_ind");
	return (OK);
}

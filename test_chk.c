#include "test.h"

static int	test_no_size_gap_buf(void)
{
	t_gapbuf *buf;

	buf = test_init(20, 10);
	SIZE_GAP_BUF = 0;
	if (no_size_gap_buf(buf) != true)
	{
		PRINT_KO_NOTE("no_size_gap_buf", "no_size_gap_buf != true");
		return (KO);
	}
	SIZE_GAP_BUF = 10;
	GAP_START = 2;
	GAP_END = 2;
	if (no_size_gap_buf(buf) != true)
	{
		PRINT_KO_NOTE("no_size_gap_buf", "no_size_gap_buf != true");
		return (KO);
	}
	SIZE_GAP_BUF = 10;
	GAP_START = 4;
	GAP_END = 10;
	if (no_size_gap_buf(buf) != false)
	{
		PRINT_KO_NOTE("no_size_gap_buf", "no_size_gap_buf != false");
		return (KO);
	}
	return (OK);
}

static int	test_no_gap_before_slide(void)
{
	t_gapbuf *buf = test_init(20, 10);

	if (no_gap_before_slide(buf) != false)
	{
		PRINT_KO_NOTE("no_gap_before_slide", "gap_pos != slide");
		return (KO);
	}
	GAP_END = BUF_SLIDE + 1;
	if (no_gap_before_slide(buf) != true)
	{
		PRINT_KO_NOTE("no_gap_before_slide", "gap_pos != slide");
		return (KO);
	}
	return (OK);
}

int		test_chk(void)
{
	PRINT_NAME_BLOCK("CHK_GAP");
	if (test_no_size_gap_buf() == OK)
		PRINT_OK("no_size_gap_buf");
	if (test_no_gap_before_slide() == OK)
		PRINT_OK("no_gap_before_slide");
	return (OK);
}

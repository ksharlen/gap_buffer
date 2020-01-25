#include "gap_buf.h"

static void		gap_move_left(gapbuf *buf, size_t before_sym)
{
	int		ind;

	if (LEN_STR)
	{
		ind = find_sym_pos(buf, before_sym);
		if (GAP_END + 1 != ind && before_sym <= LEN_STR)
		{
			while (GAP_START != ind)
			{
				BUF[GAP_END] = BUF[GAP_START - 1];
				BUF[GAP_START - 1] = '\0';
				--GAP_START;
				--GAP_END;
			}
		}
	}
}

static void		gap_move_right(gapbuf *buf, size_t before_sym)
{
	int		ind;

	if (LEN_STR)
	{
		ind = find_sym_pos(buf, before_sym);
		if (GAP_END + 1 != ind && before_sym <= LEN_STR)
		{
			while (GAP_END != ind - 1)
			{
				BUF[GAP_START] = BUF[GAP_END + 1];
				BUF[GAP_END + 1] = '\0';
				++GAP_START;
				++GAP_END;
			}
		}
	}
}

void	gap_move(gapbuf *buf, size_t before_sym)
{
	if (BUF)
	{
		if ((size_t)GAP_START < before_sym)
			gap_move_right(buf, before_sym);
		else if ((size_t)GAP_START > before_sym)
			gap_move_left(buf, before_sym);
	}
}

void	gap_move_to_slide(gapbuf *buf)
{
	if (GAP_END != BUF_SLIDE - 1)
	{
		gap_move(buf, BUF_SLIDE);
		BUF_SLIDE = GAP_END + 1;
	}
}

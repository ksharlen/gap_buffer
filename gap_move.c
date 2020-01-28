#include "gap_buf.h"

//!DONE
static void		gap_move_left(gapbuf *buf, size_t ind)
{
	if (LEN_STR)
	{
		if ((GAP_END + 1) != ind)
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

//!DONE - работает на ура
static void		gap_move_right(gapbuf *buf, size_t ind)
{
	if (LEN_STR)
	{
		if (GAP_END + 1 != ind)
		{
			while (GAP_END != (ind - 1))
			{
				BUF[GAP_START] = BUF[GAP_END + 1];
				BUF[GAP_END + 1] = '\0';
				++GAP_START;
				++GAP_END;
			}
		}
	}
}

//!DONE
void	gap_move(gapbuf *buf, size_t ind)
{
	if (BUF)
	{
		if ((size_t)GAP_START < (size_t)ind)
			gap_move_right(buf, ind);
		else if ((size_t)GAP_START > (size_t)ind)
			gap_move_left(buf, ind);
	}
}

//!DONE
void	gap_move_to_slide(gapbuf *buf)
{
	int ind;

	ind = find_sym_pos(buf, USER_SLIDE);
	if (ind > 0)
	{
		if (GAP_END != (size_t)ind - 1 && USER_SLIDE < LEN_STR)//!Опасно
			gap_move(buf, ind);
	}
	else
		die_gap("ind == -1");
}

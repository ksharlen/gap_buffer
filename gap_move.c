#include "gap_buf.h"

//!DONE
static void		gap_move_left(gapbuf *buf, size_t before_sym)
{
	int		ind;

	if (LEN_STR)
	{
		ind = find_sym_pos(buf, before_sym);
//!TMP
		// if (ind == -1)
			// die_gap("ind == -1");
//!сделать проверку на ind == -1
		if ((GAP_END + 1) != (size_t)ind && before_sym < LEN_STR)
		{
			while (GAP_START != (size_t)ind)
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
static void		gap_move_right(gapbuf *buf, size_t before_sym)
{
	int		ind;

	if (LEN_STR)
	{
		ind = find_sym_pos(buf, before_sym);
		if (GAP_END + 1 != (size_t)ind && before_sym < LEN_STR)
		{
			while (GAP_END != (size_t)(ind - 1))
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
void	gap_move(gapbuf *buf, size_t before_sym)
{
	int ind;

	if (BUF)
	{
		ind = find_sym_pos(buf, before_sym);
		if ((size_t)GAP_START < (size_t)ind)
			gap_move_right(buf, before_sym);
		else if ((size_t)GAP_START > (size_t)ind)
			gap_move_left(buf, before_sym);
	}
}

//!DONE
void	gap_move_to_slide(gapbuf *buf)
{
	int ind;

	ind = find_sym_pos(buf, BUF_SLIDE);
	if (GAP_END != (size_t)ind - 1) //! Если буфер уже стоит где надо
	{
		gap_move(buf, BUF_SLIDE);
		// BUF_SLIDE = GAP_END + 1;
	}
}

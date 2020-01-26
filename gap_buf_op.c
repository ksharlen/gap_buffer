#include "gap_buf.h"

void	gap_clean(gapbuf *buf)
{
	memset(&BUF[GAP_START], 0, sizeof(char) * buf->size_gap_buf);
}

void	die_gap(const char *s)
{
	write(STDERR_FILENO, s, strlen(s));
	exit(EXIT_FAILURE);
}

void	f_print(char *filename, const char *fmt)
{
	FILE *fp = fopen(filename, "w");

	P_UNUSED(fp);
	P_UNUSED(filename);
	P_UNUSED(fmt);
	// fprintf(fp, fmt);
}

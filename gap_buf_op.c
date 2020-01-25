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

void	gap_write(gapbuf *buf, void *data, size_t len)
{
	memcpy(&BUF[buf->slide], (unsigned char *)data, len);
	buf->slide += len;
}

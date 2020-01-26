#include "gap_buf.h"
#include <termio.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>

#define TEST

void	ftsh_entry_not_canon(struct termios *st_copy)
{
	struct termios	chg_mode;

	if (st_copy)
	{
		tcgetattr(STDIN_FILENO, &chg_mode);
		*st_copy = chg_mode;
		chg_mode.c_lflag &= ~(ICANON | ECHO | ISIG);
		tcsetattr(STDIN_FILENO, TCSANOW, &chg_mode);
	}
}

void	ftsh_entry_canon(struct termios *st_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, st_term);
}

int			getch(void)
{
	ssize_t	nread;
	char	sym;

	nread = read(STDIN_FILENO, &sym, 1);
	if (nread == 1 && sym == '\e')
	{
		nread = read(STDIN_FILENO, &sym, 1);
		if (sym == '[')
			return (1);
	}
	//TODO return (sym);
	return (0);
}



int			main(void)
{
	struct termios	copy;
	gapbuf buf;

ftsh_entry_not_canon(&copy);


	gap_buf_init(&buf, 40, 10);

ftsh_entry_canon(&copy);
	print_buf_char(buf.buf, buf.size_buf);
	print_stat_gapbuf(&buf);
	return (0);
}

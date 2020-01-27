#include "gap_buf.h"
#include <termios.h>
#include <unistd.h>
#include <term.h>

#define TEST

FILE *fp;

enum	key
{
	LEFT_ARROW = 1000,
	RIGHT_ARROW,
	DEL_KEY,
	BKCSPACE_KEY = 127
};

typedef struct	cursor
{
	int x;
	int y;
}				cursor;

void	ftsh_entry_not_canon(struct termios *st_copy)
{
	struct termios	chg_mode;

	if (st_copy)
	{
		tcgetattr(STDIN_FILENO, &chg_mode);
		*st_copy = chg_mode;
		chg_mode.c_lflag &= ~(ICANON | ECHO);
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
		{
// exit(EXIT_FAILURE);
			nread = read(STDIN_FILENO, &sym, 1);
			if (sym == 'C')//RIGHT
				return (RIGHT_ARROW);
			else if (sym == 'D')//LEFT
				return (LEFT_ARROW);
			else if (sym >= '0' && sym <= '9')
			{
				char	digit = sym;

				nread = read(STDIN_FILENO, &sym, 1);
				if (sym == '~')
				{
					if (digit == '3')
						return (DEL_KEY);
				}
			}
		}
	}
	return (sym);
}

void	init_cursor(void)
{
	write(STDOUT_FILENO, "\e[2J", 4);
	write(STDOUT_FILENO, "\e[H", 3);
}

void		input(gapbuf *buf)
{
	int		key;
	char	*str;
	cursor	cr = {1, 0};
	char	buf_w[32] = {0};

	init_cursor();
	do
	{
		key = getch();
		if (key == LEFT_ARROW)
		{
			// write(STDOUT_FILENO, "\e[D", 3);
			if (cr.x)
				cr.x--;
			gap_slide_left(buf);
		}
		else if (key == RIGHT_ARROW)
		{
			cr.x++;
			gap_slide_right(buf);
		}
		else if (key >= 32 && key <= 126)
		{
			cr.x++;
			gap_put_char_in_buf(buf, key);
		}
		else if (key == BKCSPACE_KEY)
		{
// exit(EXIT_FAILURE);
			cr.x--;
			gap_del_before_slide(buf);
		}
			str = gap_get_buf(buf);
			init_cursor();
			write(STDOUT_FILENO, str, strlen(str));
			snprintf(buf_w, sizeof(buf_w), "\x1b[%d;%dH", cr.y, cr.x);
			write(STDOUT_FILENO, buf_w, strlen(buf_w));
	} while (key != '\n');
	printf("\n");
}

int			main(void)
{
	struct termios	copy;
	gapbuf buf;

	gap_buf_init(&buf, 100, 10);
	fp = fopen("output", "w");
ftsh_entry_not_canon(&copy);

	input(&buf);

ftsh_entry_canon(&copy);
	print_buf_char(buf.buf, buf.size_buf);
	print_stat_gapbuf(&buf);
	return (0);
}

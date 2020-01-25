#ifndef GAP_BUF_H
# define GAP_BUF_H

# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define DFLT_SIZE_GAP		10
# define P_UNUSED(var) ((void)var) //!TMP

# define BUF			buf->buf
# define GAP_START		buf->gap_start
# define GAP_END		buf->gap_end
# define SIZE_BUF		buf->size_buf
# define SIZE_GAP_BUF	buf->size_gap_buf
# define BUF_SLIDE		buf->slide //!с включением gap_buf
# define LEN_STR		buf->len_string
# define START_STRING	buf->start_string
# define USER_SLIDE		buf->user_slide //!Без включения buf

enum			e_gap_dir
{
	GAP_LEFT,
	GAP_RIGHT
};

typedef struct gapbufer
{
	char	*buf;
	int		start_string;
	int		size_buf;
	size_t	len_string;
	int		slide;
	int		user_slide;//!tmp
	int		size_gap_buf;
	int 	gap_start;
	int		gap_end;
}				gapbuf;

void			die_gap(const char *s);
void			gap_buf_init(gapbuf *buf, size_t size_buf, size_t size_gap);
void			gap_move(gapbuf *buf, size_t before_sym);//!TMP
void			gap_clean(gapbuf *buf);
int				find_sym_pos(gapbuf *buf, size_t pos_sym);
void			new_gap(gapbuf *buf, size_t len_new_gap);
void			gap_move_to_slide(gapbuf *buf);
void			gap_put_end_str(gapbuf *buf, char sym);
void			gap_put_sym_in_str(gapbuf *buf, char sym);
// void			put_sym_to_buf(gapbuf *buf, char sym);

/*
**INTERFACE
*/
void			gap_put_char_in_buf(gapbuf *buf, char sym);
char			*gap_get_buf(gapbuf *buf);

/*
**PUT_BUF
*/
void			gap_put_to_buf(gapbuf *buf, size_t pos, char sym);
void			gap_put_sym_slide(gapbuf *buf, char sym);
void			put_sym_in_gap_buf(gapbuf *buf, char sym);
void			put_str_in_gap_buf(gapbuf *buf, char *str); //!TMP

/*
**SLIDE
*/
void			move_slide(gapbuf *buf, size_t pos);
void			gap_move_slide(gapbuf *buf, int dir);

/*
**CHK_BUF
*/
bool			no_size_gap_buf(gapbuf *buf);
bool			no_gap_before_slide(gapbuf *buf);

//TMP
void			gap_write(gapbuf *buf, void *data, size_t len);
void			print_buf_int(char *buf, size_t size_buf);
void			print_stat_gapbuf(gapbuf *buf);
void			print_buf_char(char *buf, size_t size_buf);

#endif

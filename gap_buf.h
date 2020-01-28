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
# ifndef P_UNUSED
#  define P_UNUSED(var) ((void)var)
# endif

# define BUF			buf->buf
# define GAP_START		buf->gap_start
# define GAP_END		buf->gap_end
# define SIZE_BUF		buf->size_buf
# define SIZE_GAP_BUF	buf->size_gap_buf
# define LEN_STR		buf->len_string
# define GAP_SLIDE		buf->slide

typedef struct	s_gapbuf
{
	char	*buf;
	size_t	main_size_gap_buf;
	size_t	size_buf;
	size_t	len_string;
	size_t	slide;
	size_t	size_gap_buf;
	size_t 	gap_start;
	size_t	gap_end;
}				t_gapbuf;

/*
**INTERFACE
*/
void			gap_buf_init(t_gapbuf *buf, size_t size_buf, size_t size_gap);
char			*gap_get_buf(t_gapbuf *buf);
void			gap_slide_left(t_gapbuf *buf);
void			gap_slide_right(t_gapbuf *buf);

/*
**INTERFACE_DEL_INS_SYM
*/
void			gap_put_char_in_buf(t_gapbuf *buf, char sym);
void			gap_del_before_slide(t_gapbuf *buf);
void			gap_del_on_slide(t_gapbuf *buf);

/*
**INTERFACE_COPY_PASTE_CUT_STRING
*/
char			*gap_copy_str(t_gapbuf *buf); //!DONE
char			*gap_cut_str(t_gapbuf *buf);	//!DONE
void			gap_paste(t_gapbuf *buf, const char *str);

/*
**PUT_BUF_INTERNAL
*/
void			gap_put_end_str(t_gapbuf *buf, char sym);
void			gap_put_sym_in_str(t_gapbuf *buf, char sym);

/*
**INTERNAL
*/
void			die_gap(const char *s);
int				find_sym_pos(t_gapbuf *buf, size_t pos_sym);
void			gap_move_to_slide(t_gapbuf *buf);
void			gap_move(t_gapbuf *buf, size_t before_sym);
void			del_sym(t_gapbuf *buf, size_t del_pos);
void			new_gap(t_gapbuf *buf, size_t len_new_gap);
void			del_gap_buf(t_gapbuf *buf);
void			fill_str_skip_gap(t_gapbuf *buf, char *str);

//*TMP
void			print_stat_t_gapbuf(t_gapbuf *buf);
void			print_buf_int(char *buf, size_t size_buf);
void			print_buf_char(char *buf, size_t size_buf);
extern FILE *fp;

//TODO: сделать заполнение t_gapbuf когда у нас закончился размер

#endif

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

enum			e_gap_dir
{
	GAP_LEFT,
	GAP_RIGHT
};

typedef struct gapbufer
{
	char	*buf;
	size_t	main_size_gap_buf;
	size_t	size_buf;
	size_t	len_string;
	size_t	slide;
	size_t	size_gap_buf;
	size_t 	gap_start;
	size_t	gap_end;
}				gapbuf;

/*
**INTERFACE
*/
void			gap_buf_init(gapbuf *buf, size_t size_buf, size_t size_gap);
char			*gap_get_buf(gapbuf *buf);
void			gap_slide_left(gapbuf *buf);
void			gap_slide_right(gapbuf *buf);
//?DEV

/*
**INTERFACE_DEL_INS_SYM
*/
void			gap_put_char_in_buf(gapbuf *buf, char sym);
void			gap_del_before_slide(gapbuf *buf);
void			gap_del_on_slide(gapbuf *buf);

/*
**INTERFACE_COPY_PASTE_CUT_STRING
*/
char			*gap_copy_str(gapbuf *buf); //!DONE
char			*gap_cut_str(gapbuf *buf);	//!DONE
void			gap_paste(gapbuf *buf, const char *str);

/*
**PUT_BUF_INTERNAL
*/
void			gap_put_end_str(gapbuf *buf, char sym);
void			gap_put_sym_in_str(gapbuf *buf, char sym);

/*
**INTERNAL
*/
void			die_gap(const char *s);
int				find_sym_pos(gapbuf *buf, size_t pos_sym);
void			gap_move_to_slide(gapbuf *buf);
void			gap_move(gapbuf *buf, size_t before_sym);
void			del_sym(gapbuf *buf, size_t del_pos);
void			new_gap(gapbuf *buf, size_t len_new_gap);
void			del_gap_buf(gapbuf *buf);
void			fill_str_skip_gap(gapbuf *buf, char *str);

//*TMP
void			print_stat_gapbuf(gapbuf *buf);
void			print_buf_int(char *buf, size_t size_buf);
void			print_buf_char(char *buf, size_t size_buf);
void			f_print(char *filename, const char *fmt);
extern FILE *fp;

//TODO: сделать заполнение gapbuf когда у нас закончился размер

#endif

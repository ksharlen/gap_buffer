#ifndef TEST_H
# define TEST_H

# include <string.h>

# include "gap_buf.h"

# ifndef P_UNUSED
#  define P_UNUSED(v)			(void)v
# endif

# define SIZE				40
# define WEIGHT(name)		(int)(SIZE - strlen(name))

# define T_OK					"OK"
# define T_KO					"KO"

# define COLOR_OK			"\x1b[38;2;26;255;5;1m"
# define COLOR_KO			"\x1b[38;2;255;5;5;1m"
# define COLOR_FUNC			"\x1b[38;2;255;243;5;1m"
# define COLOR_NAME_BLOCK	"\x1b[1;4;38;2;0;250;237;1m"

# define COLOR_DFLT	"\e[0m"

# define TEST_SYM	'a'

# define PRINT_OK(name) printf("%s%s:%s%*s%s\n", COLOR_FUNC, name, COLOR_OK, WEIGHT(name), T_OK, COLOR_DFLT)
# define PRINT_KO(name) printf("%s%s:%s%*s%s\n", COLOR_KO, name, COLOR_KO, WEIGHT(name), T_KO, COLOR_DFLT)
# define PRINT_NAME_BLOCK(name)	printf("%s%s%s\n", COLOR_NAME_BLOCK, name, COLOR_DFLT)
# define PRINT_NOTE(str) printf("%s\n", str);
# define PRINT_KO_NOTE(name, str) {PRINT_KO(name); PRINT_NOTE(str)}

/*
**TEST_MACRO
*/
# define TEST_CMP(one, two)	((one) == (two))
# define TEST_CMP_PTR		test_cmp_ptr
# define TEST_NOT_CMP_PTR	test_not_cmp_ptr
# define TEST_NULL			test_null_ptr
# define TEST_NOT_NULL		test_not_null_ptr
# define TEST_CMP_SYM		test_sym
# define TEST_CMP_INT		test_cmp_int

enum test
{
	KO,
	OK
};

/*
**SIMPLE_TEST
*/
int		test_cmp_ptr(void *ptr1, void *ptr2, char *test_name, char *str_error);
int		test_not_cmp_ptr(void *ptr1, void *ptr2, char *test_name, char *str_error);
int		test_sym(char cmp1, char cmp2, char *test_name, char *str_error);
int		test_null_ptr(void *ptr, char *test_name, char *str_error);
int		test_not_null_ptr(void *ptr, char *test_name, char *str_error);
int		test_cmp_int(ssize_t one, ssize_t two, char *test_name, char *str_error);
t_gapbuf *test_init(size_t len_buf, size_t len_gap);


/*
**UTESTS
*/
int		test_move(void);
int		test_put_buf(void);
int		test_chk(void);

#endif

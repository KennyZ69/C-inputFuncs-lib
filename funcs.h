#ifndef FUNCS_H 
#define FUNCS_H 

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * type for strings
 */
typedef char *string;

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent char; if text is not a single char, user is prompted
 * to retry. If line can't be read, returns CHAR_MAX.
 */
char Get_char(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent double as precisely as possible; if text does not represent
 * a double or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns DBL_MAX.
 */
double Get_double(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent float as precisely as possible; if text does not represent
 * a float or if value would cause underflow or overflow, user is prompted
 * to retry. If line can't be read, returns FLT_MAX.
 */
float Get_float(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent int; if text does not represent an int in [-2^31, 2^31 - 1)
 * or would cause underflow or overflow, user is prompted to retry. If line
 * can't be read, returns INT_MAX.
 */
int Get_int(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent long; if text does not represent a long in
 * [-2^63, 2^63 - 1) or would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns LONG_MAX.
 */
long Get_long(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent long long; if text does not represent a long long in
 * [-2^63, 2^63 - 1) or would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns LLONG_MAX.
 */
long long Get_long_long(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns
 * it as a string (char *), sans trailing line ending. Supports
 * CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user
 * inputs only a line ending, returns "", not NULL. Returns NULL
 * upon error or no input whatsoever (i.e., just EOF). Stores string
 * on heap, but library's destructor frees memory on program's exit.
 */
string Get_string(va_list *args, const char *format, ...) __attribute__((format(printf, 2, 3)));
#define Get_string(...) Get_string(NULL, __VA_ARGS__)

#endif

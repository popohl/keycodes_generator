/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <paulohl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:39:50 by pohl              #+#    #+#             */
/*   Updated: 2021/04/19 11:31:32 by ft               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <strings.h>
# include <stdbool.h>

/* Checker */
bool	ft_isalnum(const int c);
bool	ft_isalpha(const int c);
bool	ft_isascii(const int c);
bool	ft_isdigit(const int c);
bool	ft_isprint(const int c);
bool	ft_iswhitespace(const int c);
bool	ft_isnumber(const char *str);

/* Conv */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* Io */
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		get_next_line(int fd, char **line);

/* Math */
int		ft_pow(int base, int power);

/* Mem */
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* Num */
int		ft_intlen(int nbr);

/* Str */
char	*ft_strchr(const char *str, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *needle, size_t len);
char	*ft_strrchr(const char *str, char c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strreplace(char *original, const char *new_value);
char	*ft_strncpy(char *dst, const char *src, int len);
int		ft_strcpy(char *dst, const char *src);

#endif

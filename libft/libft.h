/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:49:06 by edraccan          #+#    #+#             */
/*   Updated: 2025/05/05 14:05:07 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <ctype.h>

/*
** SECTION - MANDATORY
*/

// NOTE - 0 if it's not, 1 if it is
int		ft_isalpha(int c);

int		ft_isdigit(int c);

// NOTE - 0 if it's not, 1 if it is
int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

char	**ft_split(char const *s, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

/* 
** SECTION - PERSONAL
*/

// NOTE - return 1 if it's quotes, 0 if not
int		ft_is_quotes(char c);

// NOTE - return 1 if it's quotes, 0 if not
int		ft_isspace(char c);

// flag1 && flag2 are flags for freeing orig and new (if they are 1)
char	*ft_rejoin(char *orig, char *new, int flag1, int flag2);

char	**ft_dup_matrix(char **matrix);

void	free_matrix(char **m);

int		matrix_len(char **matrix);

char	**ft_rematrix(char **old, char **new);

char	*ft_restr(char *old, char *new);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp_2(const char *s1, const char *s2, size_t n);

long	ft_atol(const char *s);

#endif
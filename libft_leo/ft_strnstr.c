/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:25:31 by edraccan          #+#    #+#             */
/*   Updated: 2024/11/29 10:05:47 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NOTE
** len-- serve a decrementare i numeri di caratteri da controllare nella 
** stringa originale dato che il contatore i aumenta ogni ciclo fatto
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (!little || !little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] \
				&& (i + j) < len)
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/* 
void test_case(const char *big, const char *little, size_t len)
{
	// Risultato della tua funzione
	char *ft_result = ft_strnstr(big, little, len);
	// Risultato della funzione originale
	char *lib_result = strnstr(big, little, len);

	printf("Test con:\n");
	printf("  big: \"%s\"\n", big);
	printf("  little: \"%s\"\n", little);
	printf("  len: %zu\n", len);
	printf("  Tuo risultato: %s\n", ft_result ? ft_result : "NULL");
	printf("  Risultato atteso: %s\n", lib_result ? lib_result : "NULL");

	if ((ft_result && lib_result && ft_result == lib_result) || \
		(!ft_result && !lib_result))
		printf("  ✅ Test passato!\n");
	else
		printf("  ❌ Test fallito!\n");

	printf("\n");
}

int main()
{
	test_case("abcdef", "cde", 4);
	test_case("abcdef", "cde", 3);
	test_case("abc\0def", "def", 7);
	test_case("abc\0def", "c\0d", 7);
	test_case("aaaabaaa", "aaa", 8);
	test_case("aaaabaaa", "b", 8);
	test_case("abcde", "e", 1);
	test_case("abcde", "e", 5);
	test_case("abc", "abcde", 5);
	test_case("abc", "abc", 2);
	test_case("abcabcabc", "abcabc", 9);
	test_case("aabbccdd", "bbcc", 6);
	test_case("aabbccdd", "bbcc", 4);
	test_case("", "a", 1);
	test_case("a", "", 1);
	test_case("", "", 0);
	test_case("a", "", 0);

	return 0;
} */
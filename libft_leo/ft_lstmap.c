/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:41:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 10:51:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define UN_BOTTO 100
#define ONLY_HEAD 0
#define EVERYTHING 1

t_typelist		*free_newlist(t_typelist **lst, \
	void (*del)(void *), int how_much);
static void		ft_lstiter_custom(t_typelist *lst, void *(*f)(void *));

/*
void	ft_toupper_custom1(void	*string)
{
    char	*pointer;

	pointer = (char *)string;
	while ((pointer) && (*pointer))
	{
    	*pointer = ft_toupper(*pointer);
		++pointer;
	}
}

void	*ft_toupper_custom2(void *string)
{
	char	*pointer;

	pointer = (char *)string;
	while ((pointer) && (*pointer))
	{
    	*pointer = ft_toupper(*pointer);
		++pointer;
	}
	return (string);
}

static void	del(void *data)
	{
		if (data)
		{
			data = NULL;
		}
	}

int	main(void)
{
	if ("test")
		{
			char	*data;
			t_typelist	*node;
			t_typelist	*lstmap_node;
			t_typelist	*node_pointer;
			t_typelist	*new_pointer;
			size_t	size_of_list;
			size_t	counter;

			printf("\nBONUS\nI test sono effettuati dando in pasto alla tua \
			 ft_lstmap la funzione ft_touppercustom(vedi inizio file).\n");
			printf("Devi effettuare un controllo manuale. \n");
			printf("\n--PRIMA PROVA: LISTA DI SIZE 20--\n");
			size_of_list = 20;
			counter = 0;
			data = (char *)malloc(UN_BOTTO);
			if (!data)
				return (2);
			ft_strlcpy(data, (const char *)"mega_rayquaza e gabibbo", UN_BOTTO);
			if (counter < size_of_list)
				node = ft_lstnew((void *)data);
			else
				node = NULL;
			if (!node)
			{
				free(data);
				data = NULL;
				return (2);
			}
			node_pointer = node;
			++counter;
			while ((counter < size_of_list) && (node_pointer))
			{
				new_pointer = ft_lstnew((void *)data);
				if (new_pointer)
				{
					ft_lstadd_back(&node_pointer, new_pointer);
				}
				else
				{
					break ;
				}
				++counter;
			}
			ft_lstadd_back(&node_pointer, NULL);
			printf("Contenuto: %s", (char *)node->content);
			printf("\nNext: %p", node->next);
			printf("\nSIZE: %d", ft_lstsize(node));
			printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
			ft_lstiter(node, *ft_toupper_custom1);
			node_pointer = node;
			counter = 1;
			while (node_pointer->next)
			{
				printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			printf("\nLSTITER(To_upper) node n. %ld: %s\n", \
			counter, (char *)node_pointer->content);
			printf("\n---\n");
			lstmap_node = ft_lstmap(node, *ft_toupper_custom2, *del);
			node_pointer = lstmap_node;
			counter = 1;
			while (node_pointer->next)
			{
				printf("\nLSTMAP(To_upper) node n. %ld: %s\n", \
				counter, (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			printf("\nLSTMAP(To_upper) node n. %ld: %s\n", \
			counter, (char *)node_pointer->content);
			ft_lstclear(&node, *del);
			ft_lstclear(&lstmap_node, *del);
			free(data);
			data = NULL;
		}
		if ("test")
		{
			char	*data;
			t_typelist	*node;
			t_typelist	*lstmap_node;
			t_typelist	*node_pointer;
			t_typelist	*new_pointer;
			size_t	size_of_list;
			size_t	counter;

			printf("\n--SECONDA PROVA: LISTA DI SIZE 1--\n");
			size_of_list = 1;
			counter = 0;
			data = (char *)malloc(UN_BOTTO);
			if (!data)
				return (2);
			ft_strlcpy(data, (const char *)"mega_rayquaza e gabibbo", UN_BOTTO);
			if (counter < size_of_list)
				node = ft_lstnew((void *)data);
			else
				node = NULL;
			if (!node)
			{
				free(data);
				data = NULL;
				return (2);
			}
			node_pointer = node;
			++counter;
			while ((counter < size_of_list) && (node_pointer))
			{
				new_pointer = ft_lstnew((void *)data);
				node_pointer = new_pointer;
				++counter;
			}
			ft_lstadd_back(&node_pointer, NULL);
			printf("Contenuto: %s", (char *)node->content);
			printf("\nNext: %p", node->next);
			printf("\nSIZE: %d", ft_lstsize(node));
			printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
			ft_lstiter(node, *ft_toupper_custom1);
			node_pointer = node;
			counter = 1;
			while (node_pointer->next)
			{
				printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
			(char *)node_pointer->content);
			printf("\n---\n");
			lstmap_node = ft_lstmap(node, *ft_toupper_custom2, *del);
			node_pointer = lstmap_node;
			counter = 1;
			while ((node_pointer) && (node_pointer->next))
			{
				printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			if (node_pointer)
				printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
			ft_lstclear(&node, *del);
			ft_lstclear(&lstmap_node, *del);
			free(data);
			data = NULL;
		}
		if ("test")
		{
			char	*data;
			t_typelist	*node;
			t_typelist	*lstmap_node;
			t_typelist	*node_pointer;
			t_typelist	*new_pointer;
			size_t	size_of_list;
			size_t	counter;

			printf("\n--TERZA PROVA: LISTA DI SIZE 0--\n");
			size_of_list = 0;
			counter = 0;
			data = (char *)malloc(UN_BOTTO);
			if (!data)
				return (2);
			ft_strlcpy(data, (const char *)"mega_rayquaza e gabibbo", \
			 UN_BOTTO);
			if (counter < size_of_list)
				node = ft_lstnew((void *)data);
			else
				node = NULL;
			if (!node)
			{
				free(data);
				data = NULL;
			}
			node_pointer = node;
			++counter;
			while ((counter < size_of_list) && (node_pointer))
			{
				new_pointer = ft_lstnew((void *)data);
				if (new_pointer)
				{
					ft_lstadd_back(&node_pointer, new_pointer);
				}
				else
				{
					break ;
				}
				++counter;
			}
			if (node_pointer)
				node_pointer->next = NULL;
			printf("\nSIZE: %d", ft_lstsize(node));
			if (node)
				printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
			ft_lstiter(node, *ft_toupper_custom1);
			node_pointer = node;
			counter = 1;
			while ((node_pointer) && (node_pointer->next))
			{
				printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			if (node_pointer)
				printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
				(char *)node_pointer->content);
			lstmap_node = ft_lstmap(node, *ft_toupper_custom2, *del);
			node_pointer = lstmap_node;
			counter = 1;
			while ((node_pointer) && (node_pointer->next))
			{
				printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			ft_lstclear(&node, *del);
			ft_lstclear(&lstmap_node, *del);
			free(data);
			data = NULL;
		}
		if ("test")
		{
			char	*data;
			t_typelist	*node;
			t_typelist	*lstmap_node;
			t_typelist	*node_pointer;
			t_typelist	*new_pointer;
			size_t	size_of_list;
			size_t	counter;

			printf("\n--QUARTA PROVA: LISTA DI SIZE 40--\n");
			size_of_list = 40;
			counter = 0;
			data = (char *)malloc(UN_BOTTO);
			if (!data)
				return (2);
			ft_strlcpy(data, (const char *)"mega_rayquaza e gabibbo", UN_BOTTO);
			if (counter < size_of_list)
				node = ft_lstnew((void *)data);
			else
				node = NULL;
			if (!node)
			{
				free(data);
				data = NULL;
				return (2);
			}
			node_pointer = node;
			++counter;
			while ((counter < size_of_list) && (node_pointer))
			{
				new_pointer = ft_lstnew((void *)data);
				if (new_pointer)
				{
					ft_lstadd_back(&node_pointer, new_pointer);
				}
				else
				{
					break ;
				}
				++counter;
			}
			ft_lstadd_back(&node_pointer, NULL);
			printf("Contenuto: %s", (char *)node->content);
			printf("\nNext: %p", node->next);
			printf("\nSIZE: %d", ft_lstsize(node));
			printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
			ft_lstiter(node, *ft_toupper_custom1);
			node_pointer = node;
			counter = 1;
			while (node_pointer->next)
			{
				printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, \
			 (char *)node_pointer->content);
			printf("\n---\n");
			lstmap_node = ft_lstmap(node, *ft_toupper_custom2, *del);
			node_pointer = lstmap_node;
			counter = 1;
			while (node_pointer->next)
			{
				printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, \
				 (char *)node_pointer->content);
				node_pointer = node_pointer->next;
				++counter;
			}
			printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, \
			(char *)node_pointer->content);
			ft_lstclear(&node, *del);
			ft_lstclear(&lstmap_node, *del);
			free(data);
			data = NULL;
		}
}
*/

t_typelist	*ft_lstmap(t_typelist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_typelist	*new_lst;
	t_typelist	*new_node;

	if (!lst)
		return (NULL);
	ft_lstiter_custom(lst, *f);
	new_lst = ft_lstnew((void *)lst->content, lst->type);
	if ((!lst) || (!new_lst))
		return (free_newlist(&new_lst, *del, ONLY_HEAD));
	if (lst->next)
	{
		new_node = NULL;
		lst = lst->next;
		while (lst)
		{
			new_node = ft_lstnew((void *)lst->content, lst->type);
			if (!new_node)
				return (free_newlist(&new_lst, *del, EVERYTHING));
			ft_lstadd_back(&new_lst, new_node);
			lst = lst->next;
		}
	}
	ft_lstiter_custom(new_lst, *f);
	return (new_lst);
}

t_typelist	*free_newlist(t_typelist **lst, void (*del)(void *), int how_much)
{
	if (how_much == ONLY_HEAD)
	{
		if (*lst)
			free((*lst));
	}
	else if (how_much == EVERYTHING)
	{
		ft_lstclear(lst, *del);
	}
	(*lst) = NULL;
	return (NULL);
}

static void	ft_lstiter_custom(t_typelist *lst, void *(*f)(void *))
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->content)
				lst->content = f(lst->content);
			if (lst->type)
				lst->type = f(lst->type);
			lst = lst->next;
		}
		if (lst->content)
			lst->content = f(lst->content);
		if (lst->type)
			lst->type = f(lst->type);
	}
}

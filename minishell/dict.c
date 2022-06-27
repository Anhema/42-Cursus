/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:11:20 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/23 22:13:03 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dict	*dict_new(char *key, char *value)
{
	t_dict	*list;

	list = malloc(sizeof(t_dict));
	if (list == NULL)
		return (NULL);
	if (!key)
		list->key = NULL;
	else
		list->key = key;
	if (!value)
		list->value = NULL;
	else
		list->value = value;
	list->next = NULL;
	return (list);
}

t_dict	*dict_add_back(t_dict *lst, t_dict *new)
{
	t_dict	*temp;

	temp = lst;
	if (lst == NULL)
		lst = new;
	else
	{
		while (temp->next)
		{
			if (ft_str_equals(temp->next->key, new->key) == 1)
			{
				temp->next->value = new->value;
				return (lst);
			}
			temp = temp->next;
		}
		temp->next = new;
	}
	return (lst);
}

t_dict	*dict_add_back_repeat(t_dict *lst, t_dict *new)
{
	t_dict	*temp;

	temp = lst;
	if (lst == NULL)
		lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (lst);
}

t_dict	*dict_add_front(t_dict *lst, t_dict *new)
{
	if (lst == NULL)
		lst = new;
	if (lst != NULL && new != NULL)
	{
		new->next = lst;
		lst = new;
	}
	return (lst);
}

t_dict	*del_one(t_dict *dict, char	*key)
{
	t_dict	*temp;
	t_dict	*q;

	temp = dict;
	q = dict->next;
	if (!key || ft_str_equals(key, ""))
		return (dict);
	while (q)
	{
		if (ft_str_equals(q->key, key))
			break ;
		temp = temp->next;
		q = q->next;
	}
	if (!q)
		return (dict);
	del_one_aux(temp, q, key);
	return (dict);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:04:30 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/09 10:16:51 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		if (f(lst->content))
		{
			result->content = ft_lstnew(lst)->content;
			result->next = lst->next;
			result = result->next;
		}
		else
		{
			ft_lstdelone(lst, del);
		}
		lst = lst->next;
	}
	return (result);
}

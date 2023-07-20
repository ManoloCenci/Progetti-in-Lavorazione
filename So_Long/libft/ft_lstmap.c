/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darlan <darlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:46:14 by darlan            #+#    #+#             */
/*   Updated: 2023/05/10 11:41:53 by darlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp_new;

	new = malloc(sizeof(t_list));
	temp_new = new;
	while (lst != 0 && lst->content != 0)
	{
		new->content = malloc(sizeof(lst->content));
		if (new->content == 0)
			return (0);
		new->content = ((*f)(lst->content));
		new->next = malloc(sizeof(t_list));
		if (new->next == 0)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		lst = lst->next;
		if (lst != 0)
			new = new->next;
	}
	free(new->next);
	new->next = 0;
	return (temp_new);
}
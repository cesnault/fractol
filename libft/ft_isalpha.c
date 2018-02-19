/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:09:59 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:09:28 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if ((c < 91 && c > 64) || (c < 123 && c > 96))
		return (1);
	return (0);
}

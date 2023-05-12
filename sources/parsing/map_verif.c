/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/12 11:47:37 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	valid_extension(char *path, char *extension)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(path);
	len2 = ft_strlen(extension);
	if (len1 > len2 && ft_strncmp(&path[len1 - len2], extension, len2) == 0)
		return (1);
	print_error_map(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:43:28 by jduval            #+#    #+#             */
/*   Updated: 2023/05/11 11:01:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

//------ENUM------//

typedef enum e_coord
{
	X,
	Y
}	t_coord;

//------STRUCT------//

typedef struct s_player
{
	int	*pos[2];
	int	*dir[2];
	int	*cam1[2];
	int	fov;
}

#endif

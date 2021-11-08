/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:35 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/08 19:33:47 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

# include <unistd.h>
# include <stdlib.h>

int	get_next_line(int fd, char **line);

#endif

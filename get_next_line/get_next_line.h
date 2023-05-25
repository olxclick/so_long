/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:25:33 by jbranco-          #+#    #+#             */
/*   Updated: 2023/03/03 18:48:38 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strjoin(char *str, const char *str2);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*read_file(int fd, char *backup);
char	*get_myline(char *res);
char	*remove_read(char *backup);

#endif

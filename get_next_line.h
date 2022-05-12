/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:22:22 by clvicent          #+#    #+#             */
/*   Updated: 2022/05/12 17:47:44 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

char	*ft_strdup(char *s);
char	*ft_strjoin(char *s, char *s2);
int		get_index(char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_clear_static(char *stc);
char	*ft_new_line(char *stc, int fd);
char	*ft_read(int fd, char *stc);
char	*ft_pull(char *stc);

#endif
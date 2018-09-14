/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 22:28:50 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/12 05:14:49 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONS_H

# define FT_FUNCTIONS_H

void	ft_strcat(char *dest, char *str);
void	copy_and_verify(char *dest, char *src);
int		ft_strlen(char *str);
int		map_helper(t_list	*first_line, char *buffer);

#endif

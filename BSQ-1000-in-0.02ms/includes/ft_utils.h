/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:54:51 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/05 11:57:55 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

int		min(int	a, int	b, int c);
t_list	*ft_create_elem(int data);
void	ft_list_push_back(t_list **first_line, int data);
void	ft_putstr(char *str);
int		ft_atoi(char *str, int	length);

#endif

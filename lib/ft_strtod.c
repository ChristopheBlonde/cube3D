/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:13:12 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/09 10:57:04 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	get_sign(const char **s, double *sign)
{
	while ((*s)[0] == 32 || (9 <= (*s)[0] && (*s)[0] <= 13))
		(*s)++;
	if ((*s)[0] == '-' || (*s)[0] == '+')
	{
		if ((*s)[0] == '-')
			*sign *= -1;
		(*s)++;
	}
	return ;
}

double	ft_strtod(const char *s)
{
	double	result;
	double	sign;
	int		point;

	result = 0;
	sign = 1;
	point = 0;
	get_sign(&s, &sign);
	while (*s == '.' || ('0' <= *s && *s <= '9'))
	{
		if (*s == '.')
		{
			if (point)
				break ;
			point = 1;
			s++;
			continue ;
		}
		if (point)
			sign /= 10;
		result = result * 10 + (double)(*s - '0');
		s++;
	}
	return (result * sign);
}

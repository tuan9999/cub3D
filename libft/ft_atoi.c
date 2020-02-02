/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:28:19 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/05 16:55:03 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	long	maxval;

	maxval = 9223372036854775807;
	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (result > (maxval / 10))
			return (sign > 0) ? (-1) : (0);
		str++;
	}
	return (result * sign);
}

#include "../includes/philosophers.h"

const char* get_philo_color(int color_index) 
{
   
    if (color_index == 5) return COLOR_ROSE;
    if (color_index == 1) return COLOR_LILAC;
    if (color_index == 2) return COLOR_VIOLET;
    if (color_index == 3) return COLOR_GREEN;
    if (color_index == 4) return COLOR_CYAN;

    return COLOR_RESET; // Sécurité, ne devrait pas arriver
}


int	ft_nbrcount(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	char	*str;
	int		signe;

	i = 0;
	str = (char *)nptr;
	res = 0;
	signe = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (signe * res);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*res;

	neg = 1;
	len = ft_nbrcount(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		neg *= -1;
	while (len > 0)
	{
		res[len - 1] = (neg * (n % 10)) + '0';
		n /= 10;
		len--;
	}
	if (neg == -1)
		res[0] = '-';
	return (res);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	char	*str;

	i = 0;
	str = (char *) src;
	dup = (char *) malloc(sizeof (char) * (ft_strlen(str) + 1));
	if (!dup)
		return (0);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

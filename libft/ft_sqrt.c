int	ft_sqrt(int nb)
{
	int i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 0;
	while (i <= 46341 && i <= nb / 2)
	{
		if (i * i == nb)
			return (i);
		if (i * i > nb)
			return (i - 1);
		i++;
	}
	return (0);
}

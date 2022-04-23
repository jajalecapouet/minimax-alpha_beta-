#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

static int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static int ft_power(int a, int b)
{
	if (b < 0)
		return (0);
	if (b == 0)
		return (1);
	return (a * ft_power(a, b - 1));
}

int	ft_minimax(int *LEAF, int branchf, int depht, int a, int b, int joueur, int *compteur)
{
	int i;
	int value;

	i = 0;
	if (depht == 0)
	{
		return (*LEAF);
		(*compteur)++;
	}
	if (joueur == 1)
	{
		value = -999;
		while (i < branchf)
		{
			value = ft_max(value, ft_minimax(&LEAF[i * ft_power(branchf, depht - 1)], branchf, depht - 1, a, b, 0, compteur));
			(*compteur)++;		
			if (value >= b)
				break;
			a = ft_max(value, a);
			i++;
		}
	}
	if (joueur == 0)
	{
		value = 999;
		while (i < branchf)
		{
			value = ft_min(value, ft_minimax(&LEAF[i * ft_power(branchf, depht - 1)], branchf, depht - 1, a, b, 1, compteur));
			(*compteur)++;
			if (value <= a)
				break;
			b = ft_min(value, b);
			i++;
		}
	}
	return (value);
}

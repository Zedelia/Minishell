/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_arg.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jotrique <jotrique@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 13:12:21 by jotrique     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 13:27:16 by jotrique    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

// prend une chaine en argument, la split selon le set de caracteres donné, avec priorité

/*
** Take a char, split it with the char list taken as second arg, or as third arg if any
** ie : "\"|'" and " " will split by " or ' then by space
*/

static int	ft_str_count(const char *s, char *sep_maj, char *sep_min)
{
	int			i;
	int			cpt;
	char		sep;

	i = 0;
	cpt = 0;
	while (is_in(s[i], sep_min))
		i++;
	while (s[i])
	{
		if (is_in(s[i], sep_maj))
		{
			sep = s[i];
			while (s[i] != sep)
				i++;
			if (s[i] != sep)
				return (-1);
			cpt++;
		}
		if (is_in(s[i], sep_min))
		{
			while (is_in(s[i], sep_min))
				i++;
			if (s[i] != '\0')
				cpt++;
		}
		else
			i++;
	}
	if (i > 0 && cpt == 0 && !is_in(s[i - 1], sep_maj))
		return (1);
	return (cpt == 0 && is_in(s[0], sep_min) ? 0 : 1);
}

static void	emp(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_fill(char **tab, char const *s, int len)
{
	char	*cp;

	if (!(cp = malloc(sizeof(char) * (len + 1))))
	{
		emp(tab);
		return (NULL);
	}
	cp[len] = 0;
	while (len--)
		cp[len] = s[len];
	return (cp);
}

char		**ft_split_arg(char const *s, char *sep_maj, char *sep_min)
{
	int			i;
	int			j;
	int			start;
	int			end;
	char		**tab;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	ft_printf("strcount %d\n", ft_str_count(s, sep_maj, sep_min) + 1);
	if (!(tab = malloc(sizeof(char*) * (ft_str_count(s, sep_maj, sep_min) + 1))))
		return (0);
	while (s[i] && j < ft_str_count(s, sep_maj, sep_min))
	{
		while (is_in(s[i], sep_min))
			i++;
		start = i;
		while (s[i] && !is_in(s[start], sep_maj) && !is_in(s[start], sep_min))
			i++;
		end = i;
		tab[j] = ft_fill(tab, s + start, end - start);
		j++;
	}
	tab[j] = 0;
	return (tab);
}

//! TO KILL
int main(void)
{
	int i = 0;
	char *str = "Bouyah \'\' je m'appelle \' \' '";

	char **s = ft_split_arg(str, "\"\'", " ");

	while(s[i])
	{
		ft_printf("|%d| ~ |%s|\n", i, s[i]);
		i++;
	}
	return (0);
}
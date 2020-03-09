// ft_parse is a function set intended to split a giving char* with strong and weak separator
// the point is to make parsing () "" '' {} [] easy, while allowing to split by space anyway

//TODO replace malloc by wrmalloc and its return -1 by return wrdestroy
//TODO replace generic function by lifbt one (strlen -> ft_strlen and so on)
//TODO replace int by bool when logical

//! WIP, currently too complex

#include <string.h>

// used by next_char_index_weak()
// used to check if the boolean array is empty, meaning no strongseparator is open at the time
static int	is_empty(char *str, int size)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int is_there(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int		next_chr_index_weak(char *str, int i, char *strongsep, char weaksep)
{
	int		*bool_strongsep;
	int		bool_count;
	int		double_strongsep; // the len-- due to case like echo " boop "" ola" = " boop  ola"
	int		sep_index;

	double_strongsep = 0;
	bool_count = strlen(strongsep);
	if (!(bool_strongsep = malloc(sizeof(int) * bool_count)))
		return (-1);
	bzero(bool_strongsep, bool_count);
	i++;
	while (str[i])
	{
		//TODO think about this : when should this case happen and only when
		while (is_there(str[i], strongsep) != -1 && is_in(str[i + 1], strongsep) != -1)
		{
			double_strongsep++;
			i += 2;
		}
		if (sep_index = is_in(str[i], strongsep) != -1)
		{
			bool_strongsep[sep_index] = bool_strongsep[sep_index] == 1 ? 0 : 1;
			i++;
		}
		if (str[i] == weaksep && is_empty(bool_strongsep, bool_count))
			return (i);
		i++;
	}
	return (-1);
}

int	next_chr_index_strong(char *str, int i, char strongsep)
{
	i++;
	while (str[i])
	{
		if (str[i] != strongsep)
			return (i);
		i++;
	}
	return (-1);
}

typedef struct s_elem t_elem;

struct s_elem
{
	int		index;
	char	*content;
	t_elem	*next;
};

char **ft_parse(char *str, char *strong_sep, char *weak_sep)
{
	int		elem_count;
	char	**tab;
	t_elem	**head;


	//malloc le char**
		//choppe nombre d'elements
		//choppe taille de chacun
	//rempli le char**
	//le renvoie

	return (tab);
}

int main(void)
{
	char *example = "    'echo' \" 12 \"\' 12 \'";		// should make a *char[3] = {"echo", " 12  12 ", 0};
	char **res = ft_parse(*example, "\"\'", " ");

	int i = 0;

	while (res[i])
	{
		printf("|%d| ~%s~\n", i, res[i]);
		i++;
	}

	return (0);
}
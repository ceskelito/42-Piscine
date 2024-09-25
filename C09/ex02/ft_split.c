#include <stdlib.h>
#include <stdbool.h>

int     ft_strlen(char *str)
{
		int     i;

		i = 0;
    while (str[i])
				i++;

		return (i);
}

bool is_sep(char *str, char *charset)
{
		bool flag;

		flag = true;
		while(*charset)
		{
				if(*str != *charset)
				{
						flag = false;
						break;
				}
				str++;
				charset++;
		}
		return (flag);
}

int wcount(char *str, char *charset)
{
		int seplen;
		int wcount;
		int i;
		bool word_is_counted;

		word_is_counted = false;
		seplen = ft_strlen(charset);
		wcount = 0;
		
		i = 0;
		while(str[i])
		{
				if(str[i] == charset[0])
				{
						if(is_sep(str + i, charset))
						{
								i += seplen;
								word_is_counted = false;
								continue;
						}
				}

				if (!word_is_counted)
				{
						wcount++;
						word_is_counted = true;
				}
				i++;
		}

		return (wcount);
}

char *fill_word(char *str, char *charset, int *i)
{
		int n;
		char *spl;

		spl = malloc(sizeof(char) * (*i));
		n = 0;
		while(n < (*i))
		{
				spl[n] = str[n];
				n++;
		}
		return (spl);
}

char **ft_split(char *str, char *charset)
{
		char **splitted;
		int i;
		int j;
		int n;

		if(!str || !charset)
				return (NULL);
		
		splitted = malloc(sizeof(char*) * (wcount(str, charset) + 1));
		
		i = 0;
		j = 0;

		while(str[i])	
		{
				if(!is_sep(str + i, charset))
				{
						i++;
						continue;
				}			
				splitted[j] = fill_word(str, charset, &i);
				str += (i + ft_strlen(charset));
				i = 0;
				j++;
		}		
		splitted[j] = fill_word(str, charset, &i);
		return (splitted);
}




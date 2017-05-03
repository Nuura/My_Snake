/*
** my_tab_in_str.c for  in /home/nuura/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Fri Apr 28 01:50:27 2017 SANCHEZ Pierre
** Last update Fri Apr 28 01:50:29 2017 SANCHEZ Pierre
*/
#include <stdlib.h>

int alphanum(char x)
{
  if (((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z'))
      || ((x > '0') && (x <= '9')) || (x == ' '))
    return (1);
  return (0);
}

int size_word(char *str)
{
  int e;
  int wordn;
  int c;

  e = 0;
  wordn = 0;
  c = 1;
  while (str[e] != '\0')
    {
      if (alphanum(str[e]) == 1)
	{
	  if (c == 1)
	    {
	      c = 0;
	      wordn++;
	    }
	}
      else
	c = 1;
      e++;
    }
  return (wordn);
}

int size_char(char *str, int length)
{
  int count;
  int word;
  int c;

  count = 0;
  word = 0;
  c = 0;
  while(str[count] != '\0')
    {
      if ((alphanum(str[count - 1]) == 1) && (alphanum(str[count]) == 0))
	word++;
      if ((alphanum(str[count]) == 1) && (word == length))
	{
	  c++;
	}
      count++;
    }
  return (c);
}

char *strcpy_bis(char *str, char *array, int size)
{
  int x;
  int tab;
  int word;

  x = 0;
  tab = 0;
  word = 0;
  while (str[x] != '\0')
    {
      if ((alphanum(str[x - 1]) == 1) && (alphanum(str[x]) == 0))
	{
	  word++;
	}
      if ((alphanum(str[x]) == 1) && (word == size))
	{
	  array[tab] = str[x];
	  tab++;
	}
      x++;
    }
  return (array);
}

char **my_tab_in_str2(char *str)
{
  char **array;
  int size;
  int wordn;

  size = 0;
  wordn = size_word(str);
  array = malloc(wordn * sizeof(char*));
  while (size < wordn)
    {
      array[size] = malloc(size_char(str, size) * sizeof(char*));
      strcpy_bis(str, array[size],size);
      size++;
    }

  return (array);
}

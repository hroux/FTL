/*
** readline.c for  in /home/hugues/Documents/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Fri Nov 11 09:47:04 2016 ROUX Hugues
** Last update Sat Nov 12 09:29:51 2016 ROUX Hugues
*/

#include "ftl.h"

char		*readLine()
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}

int	my_rand(int val1, int val2)
{
  int	random;

  random = (rand() % val2) + val1;
  return (random);
}

void		my_sleep(int sec1)
{
  time_t	sec;

  sec = time(NULL) + sec1;
  while (time(NULL) != sec);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*parse(char *line)
{
  char	*str;

  str = line;
  while(str != NULL && (*str > 122 || *str < 97))
    str++;
  return (str);
}

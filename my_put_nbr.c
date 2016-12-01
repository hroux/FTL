/*
** my_put_nbr.c for  in /home/hugues/DEVC/Jour05
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 13:57:43 2016 ROUX Hugues
** Last update Sat Nov 12 09:17:29 2016 ROUX Hugues
*/

#include "ftl.h"

void	inc_i(int *i, int n, int result)
{
  int	i_bis;

  i_bis = 1;
  while (result > 9 || result < -9)
    {
      i_bis = i_bis * 10;
      result = n / i_bis;
    }
  *i = i_bis;
}

void	aff_nb(int is_neg, int *result, int *i)
{
  int	result_bis;
  int	i_bis;

  result_bis = *result;
  i_bis = *i;
  if (is_neg == 1)
    my_putchar((result_bis / i_bis) * -1 + 48);
  else
    my_putchar(result_bis / i_bis  + 48);
  result_bis = result_bis - (result_bis / i_bis) * i_bis;
  i_bis = i_bis / 10;
  *result = result_bis;
  *i = i_bis;
}

void	my_put_nbr(int n)
{
  int	i;
  int	result;
  int	is_neg;

  is_neg = 0;
  if (n < 0)
    {
      my_putchar('-');
      is_neg = 1;
    }
  result = n;
  inc_i(&i, n, result);
  while (i > 1)
    aff_nb(is_neg, &result, &i);
  if (is_neg == 1)
    my_putchar((result * -1) % 10 + 48);
  else
    my_putchar(result % 10 + 48);
}

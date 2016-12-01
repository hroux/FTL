/*
** actions.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:19:59 2016 ROUX Hugues
** Last update Sat Nov 12 10:07:41 2016 ROUX Hugues
*/

#include "ftl.h"

void	attack(t_ship *ship, t_ennemy *ennemy)
{
  if (ennemy->alive == 0)
    my_putstr_color("red", "Nous n'allons pas attaquer le vide !\n");
  else
    {
      if (my_strcmp(ship->weapon->system_state, "online") != 0)
	my_putstr_color("red", "Notre armement est HS\n");
      else
	{
	  my_putstr_color("yellow", "Nous avons touché le vaisseau ennemi !\n");
	  ennemy->life = ennemy->life - ship->weapon->damage;
	  sound_explo();
	  if (ennemy->life <= 0)
	    {
	      ennemy_dead(ship, ennemy);
	      my_putstr_color("green", "Le vaisseau a été abatu !\n");
	    }
	}
    }
}

int		get_container(t_ship *ship)
{
  int		rand;
  t_freight	*freight;
  
  freight = malloc(sizeof(t_freight));
  if (freight == NULL)
    return (1);
  rand = my_rand(1, 10);
  if (rand > 7)
    {
      rand = my_rand(1, 10);
      if (rand <= 3)
	freight->item = my_strdup("energy");
      else if (rand <= 6)
	freight->item = my_strdup("attackbonus");
      else if (rand <= 9)
	freight->item = my_strdup("evadebonus");
      else
	freight->item = my_strdup("scrap");
    }
  else
    freight->item = my_strdup("scrap");
  my_putstr(freight->item);
  my_putstr(" récolté\n");
  add_freight_to_container(ship, freight);
  return (0);
}

void		detect(t_ship *ship)
{
  static int	tab[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int		i;

  i = 0;
  if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : ");
      my_putstr_color("red", "Vos outils de navigations sont HS\n");
    }
  else
    {
      if (tab[ship->navigation_tools->sector] == 0)
	{
	  sound_detect();
	  while (i < 10)
	    {
	      if (get_container(ship))
		my_putstr_color("red", "Le conteneur s'est déintégré...\n");
	      i++;
	    }
	  tab[ship->navigation_tools->sector] = 1;
	}
      else
	my_putstr_color("red", "Tout les conteneurs ont déjà été pris\n");
    }
}

void	jump(t_ship *ship, t_ennemy *ennemy)
{
  if (ennemy->alive)
    my_putstr_color("red", "Nous devons faire face au vaisseau rebel\n");
  else if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
    my_putstr_color("red", "Notre réacteur est HS!\n");
  else
    {
      ship->navigation_tools->sector++;
      ship->ftl_drive->energy--;
      sound_jump();
      my_putstr_color("green", "Nous sommes désormais au secteur suivant\n");
      if (ship->navigation_tools->sector < 10)
	new_ennemy(ennemy);
    }
}

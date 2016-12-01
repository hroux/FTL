/*
** container.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 10:57:53 2016 ROUX Hugues
** Last update Sat Nov 12 10:23:46 2016 ROUX Hugues
*/

#include "ftl.h"

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  my_putstr_color("yellow", "ajout du containeur en cours...\n");
  container = malloc(sizeof(t_container));
  if (container == NULL)
    {
      my_putstr_color("red","votre vaisseau a explose lorsque ");
      my_putstr_color("red", "vous avez pose le containeur\n");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr_color("green", "le containeur a ete ajoute avec succes!\n");
  return (1);
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (ship->container->first == NULL)
    {
      ship->container->first = freight;
      freight->prev = NULL;
    }
  else
    {
      freight->prev = ship->container->last;
      ship->container->last->next = freight;
    }
  freight->next = NULL; 
  ship->container->last = freight;
  ship->container->nb_elem++;
}

void		del_freight_from_container(t_ship *ship, t_freight *freight)
{
  if (freight != NULL)
    {
      if (freight->next != NULL)
	freight->next->prev = freight->prev;
      if (freight->prev != NULL)
	freight->prev->next = freight->next;
      if (freight == ship->container->first)
	ship->container->first = freight->next;
      if (freight == ship->container->last)
	ship->container->last = freight->prev;
      free(freight);
      ship->container->nb_elem--;
    }
}

void		get_bonus(t_ship *ship)
{
  t_freight	*freight;
  t_freight	*temp;

  freight = ship->container->first;
  while (freight != NULL)
    {
      if (my_strcmp("attackbonus", freight->item) == 0)
	ship->weapon->damage = ship->weapon->damage + 5;
      if (my_strcmp("evadebonus", freight->item) == 0)
	ship->navigation_tools->evade = ship->navigation_tools->evade + 3;
      if (my_strcmp("energy", freight->item) == 0)
	ship->ftl_drive->energy = ship->ftl_drive->energy + 1;
      temp = freight;
      freight = freight->next;
      del_freight_from_container(ship, temp);
    }
  my_putstr_color("magenta", "Bonus ajoutés à notre vaisseau\n");
  sound_getbonus();
}

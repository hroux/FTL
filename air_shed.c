/*
** air_shed.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:30:28 2016 ROUX Hugues
** Last update Sat Nov 12 09:27:42 2016 ROUX Hugues
*/

#include "ftl.h"

t_ship		*create_ship()
{
  t_ship	*ship;

  my_putstr_color("yellow", "construction du vaisseau en cours...\n");
  ship = malloc(sizeof(t_ship));
  if (ship == NULL)
    {
      my_putstr_color("red", "le vaisseau n'a pas pu etre ");
      my_putstr_color("red","construit par manque de matariaux\n");
      return (NULL);
    }
  ship->hull = 50;
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  ship->navigation_tools = NULL;
  ship->container = NULL;
  my_putstr_color("green", "amelioration du vaisseau termine!\n");
  return (ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*weapon;

  my_putstr_color("yellow", "ajout des armes en cours...\n");
  weapon = malloc(sizeof(t_weapon));
  if (weapon == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose quand");
      my_putstr_color("red", "vous avez tente d'ajouter les armes\n");
      return (0);
    }
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  ship->weapon = weapon;
  my_putstr_color("green", "les armes on ete ajoutes avec succes!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*ftl_drive;

  my_putstr_color("yellow", "ajout du reacteur en cours...\n");
  ftl_drive = malloc(sizeof(t_ftl_drive));
  if (ftl_drive == NULL)
    {
      my_putstr_color("red","votre vaisseau a explose ");
      my_putstr_color("red", "lorsque vous avez pose le reacteur\n");
      return (0);
    }
  ftl_drive->energy = 10;
  ftl_drive->system_state = my_strdup("online");
  ship->ftl_drive = ftl_drive;
  my_putstr_color("green", "le reacteur a ete ajoute avec succes !\n");
  return (1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*navigation_tools;

  my_putstr_color("yellow", "ajout des outils de navigations...\n");
  navigation_tools = malloc(sizeof(t_navigation_tools));
  if (navigation_tools == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous avez");
      my_putstr_color("red", " pose les outils de navigations\n");
      return (0);
    }
  navigation_tools->sector = 0;
  navigation_tools->evade = 25;
  navigation_tools->system_state = my_strdup("online");
  ship->navigation_tools = navigation_tools;
  my_putstr_color("green", "les outils de navigations ont ");
  my_putstr_color("green", "ete ajoutes avec succes\n");
  return (1);
}

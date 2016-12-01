/*
** fnc_main.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 10:03:41 2016 ROUX Hugues
** Last update Sat Nov 12 09:41:49 2016 ROUX Hugues
*/

#include "ftl.h"

static const t_repair_command_menu g_cmd[] =
  {
    {"attack", &attack},
    {"detect", &detect},
    {"jump", &jump},
    {"getbonus", &get_bonus},
    {"help", &help},
    {"system_control", &system_control},
    {"system_repair", &system_repair_action},
    {"stat", &stat},
    {"quit", &quit},
    {NULL, NULL}
  };

t_ship		*init_ship()
{
  t_ship	*ship;
  int		(*f[4])();
  int		i;

  ship = create_ship();
  if (ship == NULL)
    return (NULL);
  f[0] = &add_weapon_to_ship;
  f[1] = &add_ftl_drive_to_ship;
  f[2] = &add_navigation_tools_to_ship;
  f[3] = &add_container_to_ship;
  i = 0;
  while (i < 4)
    {
      if (f[i](ship) == 0)
	return (NULL);
      i++;
    }
  return (ship);
}

void		deinit(t_ship *ship, t_ennemy *ennemy)
{
  t_freight	*freight;
  t_freight	*temp;

  free(ship->weapon->system_state);
  free(ship->weapon);
  free(ship->navigation_tools->system_state);
  free(ship->navigation_tools);
  free(ship->ftl_drive->system_state);
  free(ship->ftl_drive);
  freight = ship->container->first;
  while (freight != NULL)
    {
      temp = freight;
      freight = freight->next;
      free(temp);
    }
  free(ship->container);
  free(ship);
  free(ennemy);
}

int	search_fnc(t_ship *ship, t_ennemy *ennemy, char *line)
{
  int	i;

  i = 0;
  while (g_cmd[i].str != NULL &&
	 (my_strcmp(g_cmd[i].str, parse(line)) != 0))
    i++;
  if (g_cmd[i].str == NULL)
    my_putstr_color("red", "[SYSTEM FAILURE]: commande inconnue\n");
  else
    {
      g_cmd[i].f(ship, ennemy);
      return (0);
    }
  return (1);
}

int	round_ship(t_ship *ship, t_ennemy *ennemy)
{
  char	*line;
  int	bool;
  
  bool = 1;
  if (ship->hull > 0)
    {
      while (bool)
	{
	  my_putstr_color("blue", "[Action]>");
	  line = readLine();
	  if (my_strcmp("", line) == 0 || line == NULL)
	    {
	      my_putstr_color("red", "[GAME OVER] : L'invite de commande ");
	      my_putstr_color("red", " est cassé\n");
	      return (1);
	    }
	  bool = search_fnc(ship, ennemy, line);
	  free(line);
	}
    }
  return (0);
}

int		ftl(SDL_Surface *win)
{
  t_ship	*ship;
  t_ennemy	*ennemy;

  my_putstr_color("clear", "");
  my_putstr_color("magenta", "Bienvenue sur FTL !\nVotre but ? ");
  my_putstr_color("magenta", "Arrivez au secteur 10 !\n");
  my_putstr_color("cyan", "Tapez help pour connaître vos action\n");
  ship = init_ship();
  if (ship == NULL)
    return (0);
  ennemy = init_ennemy();
  if (ennemy == NULL)
    return (0);
  init_sdl(win);
  while (ship->navigation_tools->sector != 10 &&
	 ship->ftl_drive->energy > 0 &&
	 ship->hull > 0)
    {
      if (ennemy->alive)
	attack_ennemy(ship, ennemy, win);
      if (round_ship(ship, ennemy))
	return (1);
    }
  end(ship, ennemy, win);
  return (1);
}

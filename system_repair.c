/*
** system_repair.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 16:37:05 2016 ROUX Hugues
** Last update Sat Nov 12 10:15:18 2016 ROUX Hugues
*/

#include "ftl.h"

int	ftl_drive_system_repair(t_ship *ship)
{
  my_putstr_color("yellow","reparation du reacteur en cours...\n");
  free(ship->ftl_drive->system_state);
  ship->ftl_drive->system_state = my_strdup("online");
  if (ship->ftl_drive->system_state == NULL)
    {
      my_putstr_color("red", "les reparations du reacteur ont echoue\n");
      return (1);
    }
  else
    {
      sound_repair();
      my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
    }
  return (0);
}

int	navigation_tools_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du systeme de ");
  my_putstr_color("yellow", "navigation en cours...\n");
  free(ship->navigation_tools->system_state);
  ship->navigation_tools->system_state = my_strdup("online");
  if (ship->navigation_tools->system_state == NULL)
    {
      my_putstr_color("red", "les reparations des outils de ");
      my_putstr_color("red", "navigations ont echoue\n");
      return (1);
    }
  else
    {
      sound_repair();
      my_putstr_color("green", "reparation termine! ");
      my_putstr_color("green", "systeme de navigation OK!\n");
    }
  return (0);
}

int	weapon_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du systeme d'armement en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if (ship->weapon->system_state == NULL)
    {
      my_putstr_color("red", "les reparations du systeme d'armement ");
      my_putstr_color("red", "ont echoue\n");
      return (1);
    }
  else
    {
      sound_repair();
      my_putstr_color("green","reparation termine! systeme d'armement OK!\n");
    }
  return (0);
}

int	help_repair()
{
  my_putstr_color("cyan", "ftl_drive -> Reparation du reacteur\n");
  my_putstr_color("cyan", "weapon -> Reparation du systeme d'armements\n");
  my_putstr_color("cyan", "navigation_tools -> Reparation des outils ");
  my_putstr_color("cyan", "de navigations\n");
  return (0);
}

static const t_repair_command g_fnc[] =
  {
    {"ftl_drive", &ftl_drive_system_repair},
    {"navigation_tools", &navigation_tools_system_repair},
    {"weapon", &weapon_system_repair},
    {"help", &help_repair},
    {NULL, NULL}
  };

int	system_repair(t_ship *ship)
{
  char	*line;
  int	i;
  
  my_putstr_color("blue", "repair_system~>");
  line = readLine();
  if (line == NULL || my_strcmp("", line) == 0)
    {
      my_putstr_color("red", "[SYSTEM FAILURE]: ");
      my_putstr_color("red", "le lecteur de commande est bloque\n");
      return (1);
    }
  else
    {
      i = 0;
      while (g_fnc[i].str != NULL && (my_strcmp(g_fnc[i].str, line) != 0))
	i++;
      if (g_fnc[i].str == NULL)
	{
	  my_putstr_color("red", "[SYSTEM FAILURE]: commande inconnue\n");
	  return (1);
	}
      else
	return (g_fnc[i].f(ship));
    }
}

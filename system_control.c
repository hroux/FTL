/*
** system_control.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 15:56:43 2016 ROUX Hugues
** Last update Sat Nov 12 09:37:55 2016 ROUX Hugues
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du reacteur en cours...\n");
  if (my_strcmp("online", ship->ftl_drive->system_state) == 0)
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "reacteur hors service!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme de ");
  my_putstr_color("yellow", "navigation en cours...\n");
  if (my_strcmp("online", ship->navigation_tools->system_state) == 0)
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    my_putstr_color("red", "systeme de navigation hors service!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme d'armement en cours...\n");
  if (my_strcmp("online", ship->weapon->system_state) == 0)
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    my_putstr_color("red", "systeme d'armement hors service!\n");
}

void	system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}

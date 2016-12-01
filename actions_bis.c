/*
** actions_bis.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 16:27:21 2016 ROUX Hugues
** Last update Sat Nov 12 09:11:38 2016 ROUX Hugues
*/

#include "ftl.h"

void	system_repair_action(t_ship *ship)
{
  if (system_repair(ship) == 1)
    {
      my_putstr_color("red", "Les reparations ne se sont pas passées comme ");
      my_putstr_color("red", "prévues...\n");
    }
}

void	help()
{
  my_putstr_color("cyan", "Vos commandes :\n");
  my_putstr_color("cyan", "attack\n");
  my_putstr_color("cyan", "detect\n");
  my_putstr_color("cyan", "getbonus\n");
  my_putstr_color("cyan", "jump\n");
  my_putstr_color("cyan", "system_repair\n");
  my_putstr_color("cyan", "system_control\n");
  my_putstr_color("cyan", "stat\n");
  my_putstr_color("cyan", "quit\n");
  my_putstr_color("cyan", "help\n");
}

void	stat(t_ship *ship)
{
  my_putstr("\033[35m[Notre vaiseau]\n Points de vie : ");
  my_put_nbr(ship->hull);
  my_putstr("\n Dommage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("\n Energie du réacteur : ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr("\n Points d'évasion : ");
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("\n Secteur en cours : ");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr("\n Etat armements : ");
  my_putstr(ship->weapon->system_state);
  my_putstr("\n Etat réacteur : ");
  my_putstr(ship->ftl_drive->system_state);
  my_putstr("\n Etat outils de navigations : ");
  my_putstr(ship->navigation_tools->system_state);
  my_putstr("\n Le conteneur contient ");
  my_put_nbr(ship->container->nb_elem);
  my_putstr(" éléments\n\033[0m");
}

void	quit(t_ship *ship)
{
  ship->hull = 0;
}

void	end(t_ship *ship, t_ennemy *ennemy, SDL_Surface *win)
{  
  if (ship->navigation_tools->sector == 10)
    {
	my_putstr_color("green", "Felicatation, vous avez gagne\n");
	anim_victory(win);
    }
  else if (ship->ftl_drive->energy < 0)
    my_putstr_color("red", "[GAME OVER]: Vous n'avez plus d'energie\n");
  else
    {
      my_putstr_color("red", "[GAME OVER] : Votre vaisseau a explose\n");
      add_explo(win);
      add_explo(win);
      add_explo(win);
    }
  deinit(ship, ennemy);
}

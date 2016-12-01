/*
** ennemy.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 11:22:48 2016 ROUX Hugues
** Last update Sat Nov 12 09:24:05 2016 ROUX Hugues
*/

#include "ftl.h"

t_ennemy	*init_ennemy()
{
  t_ennemy	*ennemy;

  ennemy = malloc(sizeof(t_ennemy));
  if (ennemy == NULL)
    {
      my_putstr_color("red", "[ERROR SYSTEM] : Votre vaisseau explose\n");
      return (NULL);
    }
  ennemy->life = 20;
  ennemy->life_base = 20;
  ennemy->alive = 0;
  ennemy->damage = 10;
  return (ennemy);
}

void	new_ennemy(t_ennemy *ennemy)
{
  int	rand;

  rand = my_rand(1, 10);
  if (rand <= 3)
    {
      ennemy->alive = 1;
      my_putstr_color("red", "Un vaisseau ennemi est détecté\n");
    }
}

void	ennemy_dead(t_ship *ship, t_ennemy *ennemy)
{
  int	rand;
  
  ennemy->life_base = ennemy->life_base * 1.5;
  ennemy->damage = ennemy->damage * 1.5;
  ennemy->life = ennemy->life_base;
  ennemy->alive = 0;
  rand = my_rand(1, 2);
  if (rand == 1)
    {
      ship->ftl_drive->energy--;
      my_putstr_color("yellow", "Vous avez perdu un point d'énergie\n");
    }
}

void	touch_ennemy(t_ship *ship, SDL_Surface *win)
{
  int	rand;

  rand = my_rand(1, 15);
  if (rand == 1)
    {
      my_putstr_color("red", "L'ennemi a touché notre armement !\n");
      free(ship->weapon->system_state);
      ship->weapon->system_state = my_strdup("offline");
    }
  if (rand == 2)
    {
      my_putstr_color("red", "L'ennemi a touché notre réacteur !\n");
      free(ship->ftl_drive->system_state);
      ship->ftl_drive->system_state = my_strdup("offline");
    }
  if (rand == 3)
    {
      my_putstr_color("red", "L'ennemi a touché nos ");
      my_putstr_color("red", "outils de navigation !\n");
      free(ship->navigation_tools->system_state);
      ship->navigation_tools->system_state = my_strdup("offline");
    }
  add_explo(win);
}

void	attack_ennemy(t_ship *ship, t_ennemy *ennemy, SDL_Surface *win)
{
  int	rand;

  rand = my_rand(1, 100);
  if (rand <= ship->navigation_tools->evade)
    my_putstr_color("green", "L'ennemi a manqué son tir\n");
  else
    {
      my_putstr_color("red", "L'ennemi nous a touché !\n");
      ship->hull = ship->hull - ennemy->damage;
      touch_ennemy(ship, win);
    }
  my_putstr("\033[35m[Etat du vaisseau ennemi]\n");
  my_putstr("  | Points de vie : ");
  my_put_nbr(ennemy->life);
  my_putstr("\n  | Dommage : ");
  my_put_nbr(ennemy->damage);
  my_putstr("\n\033[0m");
}

/*
** ftl.h for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:25:49 2016 ROUX Hugues
** Last update Sat Nov 12 10:23:07 2016 ROUX Hugues
*/

#ifndef		_FTL_H_
# define	_FTL_H_

#include	<SDL/SDL.h>
#include	<SDL/SDL_mixer.h>
#include	<stdlib.h>
#include	<time.h>
#include	<unistd.h>

typedef struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef struct		s_container
{
  t_freight		*first;
  t_freight		*last;
  int			nb_elem;
}			t_container;

typedef struct		s_ftl_drive
{
  char			*system_state;
  int			energy;
}			t_ftl_drive;

typedef struct		s_weapon
{
  char			*system_state;
  int			damage;
}			t_weapon;

typedef	struct		s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			evade;
}			t_navigation_tools;

typedef struct		s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
}			t_ship;

typedef struct		s_repair_command
{
  char			*str;
  int			(*f)(t_ship *ship);
}			t_repair_command;

typedef struct		s_repair_command_menu
{
  char			*str;
  void			(*f)();
}			t_repair_command_menu;

typedef struct		s_ennemy
{
  int			life;
  int			damage;
  int			life_base;
  int			alive;
}			t_ennemy;

void		my_putchar(const char c);
void		my_putstr(const char *str);
void		my_put_nbr(int n);
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
int		my_strcmp(const char *str1, const char *str2);
void		my_putstr_color(const char *color, const char *str);
char		*readLine();
int		my_rand(int val1, int val2);
void		my_sleep(int sec);
void		attack(t_ship *ship, t_ennemy *ennemy);
void		detect(t_ship *ship);
void		jump(t_ship *ship, t_ennemy *ennemy);
void		get_bonus(t_ship *ship);
void		attack_ennemy(t_ship *ship, t_ennemy *ennemy, SDL_Surface *win);
void		system_control(t_ship *ship);
void		help();
void		system_repair_action(t_ship *ship);
void		stat(t_ship *ship);
void		quit(t_ship *ship);
void		add_freight_to_container(t_ship *ship, t_freight *freight);
void		new_ennemy(t_ennemy *ennemy);
void		ennemy_dead(t_ship *ship, t_ennemy *ennemy);
int		system_repair(t_ship *ship);
t_ship		*create_ship();
int		add_weapon_to_ship(t_ship * ship);
int		add_ftl_drive_to_ship(t_ship * ship);
int		add_navigation_tools_to_ship(t_ship * ship);
int		add_container_to_ship(t_ship *ship);
t_ennemy	*init_ennemy();
void		init_sdl(SDL_Surface *win);
int		ftl(SDL_Surface *win);
char		*parse(char *line);
void		sound_explo();
void		sound_jump();
void		sound_detect();
void		sound_repair();
void		sound_getbonus();
void		add_explo(SDL_Surface *win);
void		anim_victory(SDL_Surface *win);
void		deinit(t_ship *ship, t_ennemy *ennemy);
void		end(t_ship *ship, t_ennemy *ennemy, SDL_Surface *win);

#endif		/*_FTL_H_*/

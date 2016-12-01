/*
** main.c for  in /home/hugues/DEVC/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:39:53 2016 ROUX Hugues
** Last update Sat Nov 12 09:28:30 2016 ROUX Hugues
*/

#include "ftl.h"

int		main()
{
  SDL_Surface	*win;

  srand(time(NULL));
  SDL_Init(SDL_INIT_VIDEO);
  win = SDL_SetVideoMode(600, 260, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("My FTL", NULL);
  ftl(win);
  SDL_Quit();
  return (0);
}

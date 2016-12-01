/*
** fnc_SDL.c for  in /home/hugues/Documents/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Thu Nov 10 16:33:22 2016 ROUX Hugues
** Last update Thu Dec  1 22:36:42 2016 ROUX Hugues
*/

#include "ftl.h"

void		init_sdl(SDL_Surface *win)
{
  SDL_Surface	*back_img;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  back_img = SDL_LoadBMP("images/vaisseau.bmp");
  SDL_BlitSurface(back_img, NULL, win, &pos);
  SDL_Flip(win);
  SDL_FreeSurface(back_img);
}

void		add_explo(SDL_Surface *win)
{
  SDL_Surface	*img;
  SDL_Rect	pos;

  pos.x = my_rand(0, 300);
  pos.y = my_rand(0, 150);
  img = SDL_LoadBMP("images/explosion.bmp");
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0 ,0));
  SDL_BlitSurface(img, NULL, win, &pos);
  SDL_Flip(win);
  sound_explo();
}

void		sound_explo()
{
  Mix_Music	*sound;
  
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr_color("red", Mix_GetError());
      return;
    }
  sound = Mix_LoadMUS("sons/boom.mp3");
  Mix_PlayMusic(sound, 1);
  my_sleep(3);
  Mix_FreeMusic(sound);
}

void		anim_victory(SDL_Surface *win)
{
  SDL_Surface	*img;
  Mix_Music	*sound;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  img = SDL_LoadBMP("images/victory.bmp");
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0 ,0));
  SDL_BlitSurface(img, NULL, win, &pos);
  SDL_Flip(win);
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr_color("red", Mix_GetError());
      return;
    }
  sound = Mix_LoadMUS("sons/victory.mp3");
  Mix_PlayMusic(sound, 1);
  my_sleep(3);
  Mix_FreeMusic(sound);
}

void		sound_jump()
{
  Mix_Music	*sound;
  
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr_color("red", Mix_GetError());
      return;
    }
  sound = Mix_LoadMUS("sons/jump.mp3");
  Mix_PlayMusic(sound, 1);
  my_sleep(3);
  Mix_FreeMusic(sound);
}

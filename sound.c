/*
** sound.c for  in /home/hugues/Documents/my_ftl/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sat Nov 12 10:04:58 2016 ROUX Hugues
** Last update Thu Dec  1 22:41:35 2016 ROUX Hugues
*/

#include "ftl.h"

void		sound_detect()
{
  Mix_Music	*sound;
  
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr_color("red", Mix_GetError());
      return;
    }
  sound = Mix_LoadMUS("sons/detect.mp3");
  Mix_PlayMusic(sound, 1);
  my_sleep(3);
  Mix_FreeMusic(sound);
}

void		sound_repair()
{
  Mix_Music	*sound;
  
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr_color("red", Mix_GetError());
      return;
    }
  sound = Mix_LoadMUS("sons/repair.mp3");
  Mix_PlayMusic(sound, 1);
  my_sleep(5);
  Mix_FreeMusic(sound);
}

void		sound_getbonus()
{
  Mix_Music	*sound;
  
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr_color("red", Mix_GetError());
      return;
    }
  sound = Mix_LoadMUS("sons/getbonus.mp3");
  Mix_PlayMusic(sound, 1);
  my_sleep(1);
  Mix_FreeMusic(sound);
}

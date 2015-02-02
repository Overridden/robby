/*
** aspirateur.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Fri Jun 21 20:50:32 2013 alexandre1 nguyen
** Last update Fri Jun 28 11:08:24 2013 alexandre1 nguyen
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "robby.h"

int		check_boulette(t_mov *mov, int j, int i)
{
  while (mov)
    {
      if (mov->pos[0] == j && mov->pos[1] == i && mov->isset == 1)
	return (1);
      mov = mov->next;
    }
  return (EXIT_SUCCESS);
}

int		boulette_remaining(t_mov *mov)
{
  while (mov)
    {
      if (mov->isset != picked)
	return (1);
      mov = mov->next;
    }
  return (EXIT_SUCCESS);
}

void		print_map(t_mov *mov, t_bot *bot)
{
  int		i;
  int		j;

  ps("______________________\n");
  i = -1;
  while (++i != 20)
    {
      j = -1;
      ps("|");
      while (++j != 20)
	{
	  if (bot->pos_robby[0] == j && bot->pos_robby[1] == i)
	    ps("R");
	  else if (bot->pos_dab[0] == j && bot->pos_dab[1] == i)
	    ps("D");
	  else if (check_boulette(mov, j, i) == 1)
	    ps("o");
	  else
	    ps(" ");
	}
      ps("|\n");
    }
  ps("----------------------\n");
}

int		algorithm(t_mov *mov, t_bot *bot)
{
  while (boulette_remaining(mov))
    {
      if (system("clear") < 0 ||
	  printf("\nAspirateur\n\n") < 0 ||
	  printf("Cycles: %d\n", bot->cycle) < 0)
	return (EXIT_FAILURE);
      print_map(mov, bot);
      if (move_dab(mov, &bot) == EXIT_FAILURE)
	move_dab_to_spawn(&bot);
      move_robby(mov, bot);
      bot->cycle += 1;
      usleep(100000);
    }
  if (system("clear") < 0 ||
      printf("\nAspirateur\n\n") < 0 ||
      printf("Cycles: %d\n", bot->cycle) < 0)
    return (EXIT_FAILURE);
  print_map(mov, bot);
  return (EXIT_SUCCESS);
}

int		aspirateur()
{
  t_mov		*mov;
  t_bot		*bot;

  mov = NULL;
  bot = NULL;
  if (parsing(&mov, &bot))
    return (-1);
  revert_list(&mov);
  algorithm(mov, bot);
  sleep(3);
  free(mov);
  free(bot);
  return (EXIT_SUCCESS);
}

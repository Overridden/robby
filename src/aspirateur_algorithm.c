/*
** aspirateur_algorithm.c for robby in /home/nguye_1//projects/prog_elem_c/robby/src
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Thu Jun 27 23:58:56 2013 alexandre1 nguyen
** Last update Fri Jun 28 00:11:50 2013 alexandre1 nguyen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "robby.h"

void		move_dab_to_spawn(t_bot **bot)
{
  if ((*bot)->pos_dab[0])
    (*bot)->pos_dab[0] +=
      (((*bot)->pos_dab[0] > 0) ? -1 : 1);
  else if ((*bot)->pos_dab[1])
    (*bot)->pos_dab[1] +=
      (((*bot)->pos_dab[1] > 0) ? -1 : 1);
}

int		move_dab(t_mov *mov, t_bot **bot)
{
  while (mov && mov->isset != not_droped)
    mov = mov->next;
  if (mov && ((*bot)->pos_dab[0] != mov->pos[0] ||
	      (*bot)->pos_dab[1] != mov->pos[1]))
    {
      if ((*bot)->pos_dab[0] != mov->pos[0])
	(*bot)->pos_dab[0] +=
	  (((mov->pos[0] - (*bot)->pos_dab[0]) > 0) ? 1 : -1);
      else
	(*bot)->pos_dab[1] +=
	  (((mov->pos[1] - (*bot)->pos_dab[1]) > 0) ? 1 : -1);
    }
  else if (mov)
    {
      mov->isset = droped;
      if (mov->next)
      	move_dab(mov, bot);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		move_diago(int round, t_mov *mov, t_bot *bot)
{
  round += 1;
  if (round == 3)
    {
      round = 0;
      bot->pos_robby[0] +=
	(((mov->pos[0] - bot->pos_robby[0]) > 0) ? 1 : -1);
      bot->pos_robby[1] +=
	(((mov->pos[1] - bot->pos_robby[1]) > 0) ? 1 : -1);
    }
  return (round);
}

int		normal_move(int round, t_mov *mov, t_bot *bot)
{
  round += 1;
  if (round == 2)
    {
      round = 0;
      if (bot->pos_robby[0] != mov->pos[0])
	bot->pos_robby[0] +=
	  (((mov->pos[0] - bot->pos_robby[0]) > 0) ? 1 : -1);
      else
	bot->pos_robby[1] +=
	  (((mov->pos[1] - bot->pos_robby[1]) > 0) ? 1 : -1);
    }
  return (round);
}

int		move_robby(t_mov *mov, t_bot *bot)
{
  static int	round;
  int		dist[2];

  while (mov && mov->isset != droped)
    mov = mov->next;
  if (mov && mov->isset == droped)
    {
      dist[0] = mov->pos[0] - bot->pos_robby[0];
      dist[1] = mov->pos[1] - bot->pos_robby[1];
      if (abs(dist[0]) && abs(dist[1]))
	round = move_diago(round, mov, bot);
      else
	round = normal_move(round, mov, bot);
      if (bot->pos_robby[0] == mov->pos[0] && bot->pos_robby[1] == mov->pos[1])
	mov->isset = picked;
    }
  return (0);
}

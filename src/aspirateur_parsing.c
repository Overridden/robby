/*
** aspirateur_parsing.c for robby in /home/nguye_1//projects/prog_elem_c/robby/src
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Thu Jun 27 23:57:05 2013 alexandre1 nguyen
** Last update Fri Jun 28 11:14:07 2013 alexandre1 nguyen
*/

#include <stdio.h>
#include <stdlib.h>
#include "robby.h"

int		parsing(t_mov **mov, t_bot **bot)
{
  FILE		*fp;
  char		*line;
  size_t	len;
  t_bot		*elem;

  line = NULL;
  len = 0;
  if ((fp = fopen("mouv_dab", "r")) == NULL)
    return (-1);
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  while (getline(&line, &len, fp) != -1)
    if (fill_mov(mov, line) == -1)
      return (-1);
  elem->pos_robby[0] = 10;
  elem->pos_robby[1] = 10;
  elem->pos_dab[0] = 0;
  elem->pos_dab[1] = 0;
  elem->cycle = 0;
  *bot = elem;
  return (0);
}

int		revert_list(t_mov **mov)
{
  t_mov		*tmp1;
  t_mov		*tmp2;

  tmp1 = NULL;
  tmp2 = NULL;
  if (*mov)
    {
      tmp1 = (*mov)->next;
      (*mov)->next = NULL;
      while (tmp1)
	{
	  tmp2 = tmp1->next;
	  tmp1->next = *mov;
	  *mov = tmp1;
	  tmp1 = tmp2;
	}
      return (EXIT_SUCCESS);
    }
  else
    return (-1);
}

int		fill_x(char *line)
{
  int		i;
  int		nb;
  char		nb1[3];

  i = 0;
  while (line[i] != ';' && line[i] && i < 2)
    {
      nb1[i] = line[i];
      i += 1;
    }
  nb1[i] = 0;
  if ((nb = atoi(nb1)) > 20 || nb < 0)
    return (nb_too_high());
  return (nb);
}

int		fill_y(char *line)
{
  int		i;
  int		j;
  int		nb;
  char		nb2[3];

  i = 0;
  j = 0;
  while (line[i] != ';' && line[i])
    i += 1;
  while (line[i] && i < i + 3)
    {
      nb2[j] = line[i + 1];
      i += 1;
      j += 1;
    }
  nb2[j] = 0;
  if ((nb = atoi(nb2)) > 19 || nb < 0)
    return (nb_too_high());
  return (nb);
}

int		fill_mov(t_mov **mov, char *line)
{
  t_mov		*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->next = *mov;
  if ((elem->pos[0] = fill_x(line)) == -1 ||
      (elem->pos[1] = fill_y(line)) == -1)
    return (-1);
  elem->isset = not_droped;
  *mov = elem;
  return (0);
}

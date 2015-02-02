/*
** telephone_dictionnary.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Sat Jun 22 18:52:55 2013 alexandre1 nguyen
** Last update Fri Jun 28 11:15:39 2013 alexandre1 nguyen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "robby.h"

t_dict		*set_dictionnary()
{
  t_dict	*elem;
  int		i;

  i = -1;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (NULL);
  if ((elem->word = malloc(10 * 20)) == NULL)
    return (NULL);
  while (++i != 10)
    if ((elem->word[i] = malloc(20)) == NULL)
      return (NULL);
  elem = set_as_null(elem);
  elem->word[0] = fill_word(elem->word[0], "sonne");
  elem->word[1] = fill_word(elem->word[1], "allo");
  elem->word[2] = fill_word(elem->word[2], "raccroche");
  elem->word[3] = fill_word(elem->word[3], "reponds");
  return (elem);
}

int		sonne()
{
  if (printf("\033[0;33mAttends ...\033[0m\n") < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		allo()
{
  if (printf("\033[0;32mConnection établie.\n\033[0m") < 0)
    return (-1);
  return (1);
}

int		raccroche()
{
  if (printf("\033[0;31mConnection échouée.\n\033[0m") < 0)
    return (-1);
  return (1);
}

int		answer_for_me()
{
  if (printf("\n\033[0;33mBonjour, je suis Robby, un robot assistant.\n") < 0)
    return (-1);
  usleep(1400000);
  if (printf("Dr Morbius est indisponible pour le moment.\n") < 0)
    return (-1);
  usleep(1400000);
  if (printf("Veuillez le recontacter ultérieurement.\n\n"
	     "\033[0;31mFin de l'appel.\n\033[0m") < 0)
    return (-1);
  sleep(3);
  return (1);
}

/*
** error_msg.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Fri Jun 21 20:52:20 2013 alexandre1 nguyen
** Last update Fri Jun 28 13:26:27 2013 alexandre1 nguyen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "robby.h"

int		scanf_error_msg()
{
  if (printf("\nSeuls les chiffres sont acceptés. Fin du programme.\n") < 0)
    return (-1);
  return (-1);
}

int		cmd_not_found()
{
  if (printf("Commande inconnue.\n") < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		nb_too_high()
{
  if (printf("Un ou plusieurs nombres des coordonnées est/sont trop grands "
	     "ou négatifs!\n") < 0)
    return (-1);
  sleep(3);
  return (-1);
}

/*
** cuisine.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Fri Jun 21 20:50:56 2013 alexandre1 nguyen
** Last update Fri Jun 28 10:14:06 2013 alexandre1 nguyen
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "robby.h"

int		cuisine()
{
  if (system("clear") < 0 ||
      printf("\nCuisine\n\nOption tombée en panne!\n") < 0)
    return (EXIT_FAILURE);
  sleep(2);
  return (EXIT_SUCCESS);
}

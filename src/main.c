/*
** main.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Thu Jun 20 16:23:35 2013 alexandre1 nguyen
** Last update Fri Jun 28 10:12:40 2013 alexandre1 nguyen
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "robby.h"

int		shutdown()
{
  if (printf("\nFin du programme.\nRobby vous souhaite une excellente journée.\n"
	     "Au revoir et à bientot!\n") < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		modules(int choice)
{
  int		(*func[4])();

  func[0] = &telephone;
  func[1] = &aspirateur;
  func[2] = &cuisine;
  func[3] = &shutdown;
  if (choice > 0 && choice < 5)
    return (func[choice - 1]());
  else
    return (-1);
}

int		menu()
{
  int		choice;
  int		i;

  choice = 0;
  i = 0;
  while (choice != 4)
    {
      if (i == 0 && ((i = 1) != 0))
	{
	  if (system("clear") < 0 ||
	      printf("Bienvenue dans l'interface de Robby. Tapez 1, 2, 3 ou 4"
		     " pour acceder au module voulu.\n\n"
		     "1 - Telephone\n2 - Aspirateur\n"
		     "3 - Cuisine\n4 - Eteindre Robby\n\n") < 0)
	    return (EXIT_FAILURE);
	}
      if (printf("> ") < 0)
	return (EXIT_FAILURE);
      if (scanf("%d", &choice) <= 0)
	return (scanf_error_msg());
      if (!(i = 0) && modules(choice) == -1)
	if (printf("Cet option n'existe pas!\n") < 0)
	  return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		main()
{
  return (menu());
}

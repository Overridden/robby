/*
** telephone.c for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Fri Jun 21 20:49:55 2013 alexandre1 nguyen
** Last update Fri Jun 28 11:02:29 2013 alexandre1 nguyen
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robby.h"

t_dict		*set_as_null(t_dict *elem)
{
  int		i;

  i = -1;
  while (++i != 10)
    elem->word[i][0] = '\0';
  return (elem);
}

char		*fill_word(char *str1, char *str2)
{
  int		i;

  i = 0;
  while (str2[i] && i < 20)
    {
      str1[i] = str2[i];
      i += 1;
    }
  str1[i] = '\0';
  return (str1);
}

int		telephone_while(char *word, t_dict *dict, int (*func[10])())
{
  int		ret_value;

  while (42)
    {
      if (write(1, "> ", 2) < 0)
	return (EXIT_FAILURE);
      word[0] = 0;
      if ((ret_value = read(0, word, 20)) < 0)
	return (-1);
      word[ret_value - 1] = 0;
      if ((ret_value = check_word(word, dict)) < 0)
	return (ret_value);
      else
	if ((ret_value = func[ret_value]()) == 1)
	  {
	    sleep(2);
	    return (0);
	  }
    }
  return (EXIT_SUCCESS);
}

int		telephone()
{
  char		*word;
  t_dict	*dict;
  int		(*func[10])();
  int		ret_value;
  int		i;

  if (system("clear") < 0 || printf("\nTelephone\n\n") < 0 ||
      printf("Dictionnaire:\nallo, sonne, raccroche, reponds\n\n") < 0)
    return (-1);
  dict = set_dictionnary();
  func[0] = &sonne;
  func[1] = &allo;
  func[2] = &raccroche;
  func[3] = &answer_for_me;
  func[9] = &cmd_not_found;
  if ((word = malloc(20)) == NULL)
    return (-1);
  ret_value = telephone_while(word, dict, func);
  free(word);
  i = -1;
  while (++i != 10)
    free(dict->word[i]);
  free(dict->word);
  free(dict);
  return (ret_value);
}

int		check_word(char *word, t_dict *dict)
{
  int		i;

  i = 0;
  while (dict->word[i][0] != '\0')
    {
      if (!my_strcmp(word, dict->word[i]))
	return (i);
      i += 1;
    }
  return (9);
}

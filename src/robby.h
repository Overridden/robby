/*
** robby.h for robby in /home/nguye_1//projects/prog_elem_c/robby
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Thu Jun 20 16:25:17 2013 alexandre1 nguyen
** Last update Fri Jun 28 13:25:03 2013 alexandre1 nguyen
*/

#ifndef ROBBY_H_
# define ROBBY_H_

enum		boulette_condition
  {
    not_droped = 0,
    droped,
    picked
  };

typedef struct	s_dict
{
  char		**word;
}		t_dict;

typedef struct	s_mov
{
  int		pos[2];
  int		isset;
  struct s_mov	*next;
}		t_mov;

typedef struct	s_bot
{
  char		pos_robby[2];
  char		pos_dab[2];
  int		cycle;
}		t_bot;

/* main.c */
int	main();
int	menu();
int	shutdown();
int	modules(int choice);

/* basic_tools.c */
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
void	ps(char *str);

/* error_msg.c */
int	scanf_error_msg();
int	cmd_not_found();
int	nb_too_high();

/* telephone.c */
t_dict	*set_as_null(t_dict *elem);
char	*fill_word(char *str1, char *str2);
int	telephone();
int	check_word(char *word, t_dict *dict);
int	telephone_while(char *word, t_dict *dict, int (*func[10])());

/* telephone_dictionnary.c */
t_dict	*set_dictionnary();
int	sonne();
int	allo();
int	raccroche();
int	answer_for_me();

/* aspirateur.c */
void	print_map(t_mov *mov, t_bot *bot);
int	aspirateur();
int	algorithm(t_mov *mov, t_bot *bot);
int	check_boulette(t_mov *mov, int j, int i);
int	boulette_remaining(t_mov *mov);

/* aspirateur_parsing.c */
int	parsing(t_mov **mov, t_bot **bot);
int	fill_x(char *line);
int	fill_y(char *line);
int	revert_list(t_mov **mov);
int	fill_mov(t_mov **mov, char *line);

/* aspirateur_algorithm */
void	move_dab_to_spawn(t_bot **bot);
int	move_dab(t_mov *mov, t_bot **bot);
int	move_diago(int round, t_mov *mov, t_bot *bot);
int	normal_move(int round, t_mov *mov, t_bot *bot);
int	move_robby(t_mov *mov, t_bot *bot);

/* cuisine.c */
int	cuisine();

#endif /* ROBBY_H_ */

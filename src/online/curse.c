#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <mysql.h>
#include <my_global.h>
#include <time.h>
#include <termios.h>
#include "mysh.h"

#define modeCANON    0
#define modeNonCANON 1

void	connection();

int		check_account(char *user, char *pass, int i, int flag)
{
  MYSQL		mysql;
  MYSQL_FIELD	*field;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM 42_user");
      result = mysql_store_result(&mysql);
      num_champs = mysql_num_fields(result);
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0 && strcmp(row[2], pass) == 0)
	  {
	    printf("Last connection : %s\n", row[3]);
	    flag = 1;
	  }
      mysql_close(&mysql);
    }
  else
    flag = -1;
  free(result);
  return (flag);
}

char		*return_date()
{
  char		*buffer;
  time_t	timestamp;

  buffer = malloc(256 * sizeof(*buffer));
  memset(buffer, 0, 256);
  timestamp = time(NULL);
  strftime(buffer, 256, "%x %H:%M", localtime(&timestamp));
  return (buffer);
}

void	modify_last(char *user)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      requete = malloc(150 * sizeof(char));
      sprintf(requete, "UPDATE 42_user SET last = '%s' WHERE user = '%s'",
	      return_date(), user);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("\033[36mLast connection modification .. \t\t[OK]\033[00m\n");
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}

int		fetch_history(char *user, int i, int flag, t_online *sys)
{
  MYSQL		mysql;
  MYSQL_FIELD	*field;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM history");
      result = mysql_store_result(&mysql);
      num_champs = mysql_num_fields(result);
      printf("\033[37mFetching history Initialisation\t\t\t[OK]\033[00m\n");
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[2], user) == 0)
	  {
	    printf("\033[33mFetching history command %d\t\t\t[OK]\033[00m\n", i);
	    sys->history[i] = malloc(strlen(row[3]) * sizeof(char));
	    strcpy(sys->history[i], row[3]);
	    flag = 1;
	    i++;
	  }
      sys->history[i] = NULL;
      mysql_close(&mysql);
    }
  else
    flag = -1;
  free(result);
  return (flag);
}

int		fetch_friends(char *user, int i, int flag)
{
  MYSQL		mysql;
  MYSQL_FIELD	*field;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM friends");
      result = mysql_store_result(&mysql);
      num_champs = mysql_num_fields(result);
      printf("\033[37mFetching friends Initialisation\t\t\t[OK]\033[00m\n");
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0)
	  printf("\033[33mFetching friend %s\t\t\t[OK]\033[00m\n", row[2]);
      mysql_close(&mysql);
    }
  else
    printf("\033[31mError server connection\t\t[ERROR]\033[00m\n");
  free(result);
  return (flag);
}

void	modify_active(char *user, char *active)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      requete = malloc(150 * sizeof(char));
      sprintf(requete, "UPDATE 42_user SET active = '%s' WHERE user = '%s'",
	      active, user);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("\033[36mSet %s active .. \t\t\t[OK]\033[00m\n", user);
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}

void	add_cmd_history_mysql(t_shell *shell, char *cmd)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      requete = malloc(150 * sizeof(char));
      sprintf(requete, "INSERT INTO history(id, id_private,\
 user, command, date) VALUES('', '0', '%s', '%s', '00')",
	      shell->online->pseudo, cmd);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("\033[36mHistory saved online .. \t\t\t[OK]\033[00m\n");
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}

void	modify_sys(t_online *sys, char *user)
{
  sys->active = 1;
  sys->is_history = 1;
  sys->is_alias = 1;
  sys->is_prompt = 1;
  sys->pseudo = malloc((strlen(user) + 2) * sizeof(char));
  memset(sys->pseudo, 0, strlen(user) + 1);
  strcpy(sys->pseudo, user);
}

void	check_sql(char *user, char *pass, t_online *sys)
{
  int	res;

  res = check_account(user, pass, 0, 0);
  if (res == -1)
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
  else if (res == 0)
    {
      printf("\033[H\033[2J");
      printf("\033[31mUser and/or password wrong\t\t[ERROR]\033[00m\n");
      connection();
    }
  else
    {
      printf("\033[33mYou are now connected as %s\t\t[OK]\033[00m\n", user);
      modify_sys(sys, user);
      modify_last(user);
      fetch_history(user, 0, 0, sys);
      fetch_friends(user, 0, 0);
      modify_active(user, "1");
    }
}

void	add_user(char *user, char *pass)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      requete = malloc(150 * sizeof(char));
      sprintf(requete, "INSERT INTO 42_user(id, user, pass, last)\
 VALUES('NULL', '%s', '%s', '' )", user, pass);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("\033[H\033[2J");
      printf("\033[33mYour account have been created as\
 %s\t\t[OK]\033[00m\n", user);
      connection();
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}

int	check_user_exist(char *user, int flag)
{
  MYSQL		mysql;
  MYSQL_FIELD	*field;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM 42_user");
      result = mysql_store_result(&mysql);
      num_champs = mysql_num_fields(result);
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0)
	  {
	    printf("\033[H\033[2J");
	    printf("\033[31mAn account\
 with this login already exists\t\t[ERROR]\033[00m\n");
	    flag = 1;
	  }
      mysql_close(&mysql);
    }
  else
    flag = -1;
  free(field);
  free(result);
  return (flag);
}

char			*getpassword()
{
  static struct termios oldt;
  static struct termios newt;
  int			i;
  int			c;
  char			*tmp;

  i = 0;
  tmp = malloc(4096 * sizeof(*tmp));
  memset(tmp, 0, 4096);
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  while ((c = getchar()) != '\n' && c != EOF && i < 4095)
    tmp[i++] = c;
  tmp[i] = '\0';
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return (tmp);
}

char	*clean(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i])
    i++;
  str[i] = 0;
  return (str);
}

void	create_user()
{
  char	user[4096];
  char	*pass;

  memset(user, 0, 4096);
  write(1, "Desired username : ", 20);
  read(0, user, 4096);
  write(1, "Password : ", 12);
  pass = getpassword();
  if (check_user_exist(clean(user), 0) != 1)
    add_user(clean(user), pass);
  else
    create_user();
}

void	connection(t_online *sys)
{
  char	user[4096];
  char	*pass;

  memset(user, 0, 4096);
  printf("If you doesn't have an account, type 'create'\
in \"Username\" input\n\n");
  write(1, "Username : ", 12);
  read(0, user, 4096);
  if (strncmp(user, "create", 6) == 0)
    create_user();
  else
    {
      write(1, "Password : ", 12);
      pass = getpassword();
      printf("\nConnecting %s ...\t\t\t[OK]\n", clean(user));
      check_sql(clean(user), clean(pass), sys);
    }
  free(pass);
}

void	aff_pres()
{
  printf("o----------------o\n");
  printf("|   42SH MODE ?  |\n");
  printf("| 'y' -> Online  |\n");
  printf("| 'n' -> Offline |\n");
  printf("o----------------o\n\n");
}

void	init_struct(t_online *sys)
{
  sys->active = 0;
  sys->is_history = 0;
  sys->is_alias = 0;
  sys->is_prompt = 0;
  sys->history = malloc(4096 * sizeof(char*));
}

t_online	*online_mode()
{
  int		ch;
  int		flag;
  char		buff[4096];
  t_online	*sys;

  sys = malloc(sizeof(*sys));
  init_struct(sys);
  aff_pres();
  flag = 1;
  memset(buff, 0, 4096);
  write(1, "Your choice : ", 15);
  if (read(0, buff, 4096) <= 0)
    printf("Read error\n");
  if (buff[0] == 'y')
    {
      connection(sys);
      return (sys);
    }
  else
    return (sys);
  return (sys);
}

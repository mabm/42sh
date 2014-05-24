#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
  int tube[2];
  char c;
  if(pipe(tube))
    {perror("probleme de creation du tube\n");exit(-1);}

  switch (fork())
    {

    case -1: {perror("probleme de fork \n");exit(-2);}

    case 0:
      {
	close(tube[1]); //le fils n'ecrit pas
	while(read(tube[0],&c,1))
	  printf("le caractere lu est: %c \n\n",c);
	write(1,&c,1);
	exit(0);
      }

    default:
      {
	int cr;
	close(tube[0]); //le pere ne lit pas dans le tube
	while((c=getchar())!=EOF)
	  {
	    if((c<='z')&&(c>='a'))
	      {
		write(tube[1],&c,1); //ecriture dans le tube
	      }
	  }
	close(tube[1]); //fermeture du tube en ecriture
	wait(&cr); //attente de la fin du fils
    }
    }
  exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	system("clear");
	printf(" ##### Trivial TOEIC ####"" \n How many players ? (Min 1 up to 4)\n ");
	int nb_players=0;
	while(nb_players<1||nb_players>4){
		scanf("%d",&nb_players);
	}
	if(nb_players==1){
		printf("Let's train alone !\n");
	}else{
		printf("there are %d players\n",nb_players);
	}
	srand(time(NULL));
	printf ("Lancé de dé : %d\n", rand()%6+1);
	printf ("Lancé de dé : %d\n", rand()%6+1);
	printf ("Lancé de dé : %d\n", rand()%6+1);

	return 0;
}
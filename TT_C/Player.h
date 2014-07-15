//This file (and its .c attached) defines both Player and camembert.
#ifndef  TOTAL_CATEG_NB
#define TOTAL_CATEG_NB 6
#endif
typedef enum type_camembert {
	VOID,
	RED,
	BLUE
	/* categ questions +color

	*/

} type_camembert;


struct Player {
	int * statistics;
	char * name;
	int * completion;
	type_camembert * camembert;
};

struct Player * create_player(char * name);
void free_player(struct Player * player);
void load_player(struct Player * player, char * fichier);// to restart a past game
void display_statistics(struct Player * player);
void display_camembert(struct Player * player);
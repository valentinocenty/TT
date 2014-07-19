typedef enum Square_type {//  maybe redundant with enum type_camembert in Player.c  
	VOID,
	GRAMMAR,
	VOCAB,
	FILL,
	TRANSLATE
	//To complete
}Square_type;

struct Square{
	int x;
	int y;
	Square_type * category;
};

struct Game {
	int nb_players;
	struct Player ** players;
	struct Square * board;
};

struct Game * create_game();
void free_game(struct Game * game);
void add_player_to_game(struct Game * game, struct Player * player);
void init_game(struct Game * game, struct Player ** players, int nb_players,struct Control * control);

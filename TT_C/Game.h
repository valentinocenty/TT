struct Game {
	int nb_players;
	struct Player ** players;
	struct Board * board;
};

struct Game * create_game();
void free_game(struct Game * game);
void add_player_to_game(struct Game * game, struct Player * player);
void init_game(struct Game * game, struct Player ** players, int nb_players,struct Control * control);

struct Player * create_player(char * name){
	struct Player * player = (struct Player *)malloc(sizeof(struct Player));
	player->name=name;
	player->camembert=(type_camembert *)malloc(sizeof(type_camembert)*TOTAL_CATEG_NB);
	for(int i=0;i<TOTAL_CATEG_NB;i++){
		player->camembert[i]=VOID;
	}


	return player;
}

void free_player(struct Player * player){
	free(player);
}

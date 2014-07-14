struct Titre * creer_titre( ALLEGRO_BITMAP * image_selection,ALLEGRO_BITMAP * image_deselection,void * lien){
  struct Titre * titre = (struct Titre * )malloc(sizeof(struct Titre)); 
  titre->image_selection=image_selection;
  titre->image_deselection=image_deselection;
  titre->lien=lien;
  return titre;
}


void detruire_titre(struct Titre * titre){
  free(titre->image_deselection);
  free(titre->image_selection);
  free(titre->lien);
}
 

struct Menu * creer_menu(ALLEGRO_BITMAP * image_fond,struct Titre * titres, float ** position,int nb_titre){
  struct Menu * menu = (struct Menu *)malloc(sizeof(struct Menu));
  menu->image_fond=image_fond;
  menu->titre_selection = 0;
  menu->titres=titres;
  menu->position=position;
  menu->nb_titre=nb_titre;
  return menu;
}

void detruire_menu(struct Menu * menu){
  detruire_titre(menu->titres);
  free(menu->position);
  free(menu->image_fond);
  free(menu);
  menu =NULL;
}

float ** creer_position_collonne(int n,int debut,int fin,int y){
  float ** position = (float **)malloc(sizeof(int*)*n);
  for ( int i = 0 ; i<n;i++){
    position[i] = (float*)malloc(sizeof(int)*2);
    position[i][1]=(float)y;
    position[i][0]=(float)(debut +i*(fin-debut));
  }
  return position;
}

void titre_suivant(struct Menu * menu){
  if(menu->nb_titre>menu->titre_selection+1 && menu->titre_selection>-1){
  menu->titre_selection++;
  }
}

void titre_precedent(struct Menu * menu){
  if (menu->titre_selection>0){
    menu->titre_selection--;
  }
}

void afficher_menu(struct Menu * menu ){
  if(menu!=NULL){
  al_draw_bitmap(menu->image_fond,0,0,0);
  for(int i=0 ;i<(menu->nb_titre);i++){
    if (menu->titre_selection != i ){
      al_draw_bitmap(menu->titres[i].image_deselection,menu->position[i][1],menu->position[i][0],0);
    }
    else {
      al_draw_bitmap(menu->titres[i].image_selection,menu->position[i][1],menu->position[i][0],0);
    }
  }
  }
}

/*int lancer_menu(struct Menu * menu){
  afficher_menu(menu);
  al_flip_display();
  ALLEGRO_EVENT_QUEUE * queue=al_create_event_queue();
  ALLEGRO_EVENT * event;
  while (){
    al_wait_for_event(queue,event);

  }
  return 0;
}
*/

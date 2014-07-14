struct Titre {
  ALLEGRO_BITMAP * image_selection;     //image du titre lorsque il est selectionne
  ALLEGRO_BITMAP * image_deselection;  // image du titre lorsque il n'est pas selectionne
  void (*lien)(void);                          // fonction associe au titre(lancer jeu , aller dans un autre menu etc)
};


struct Menu {
  ALLEGRO_BITMAP * image_fond;     //image de fond
  int titre_selection;             // titre actuellement selectionne , -1 si yen a pas 
  struct Titre * titres;           // tableau des titres du menu
  float ** position;                 // position respective de chaque tableau {[x1,y1],[x2 ...}
  int nb_titre;
};

struct Menu * creer_menu(ALLEGRO_BITMAP * image_fond,struct Titre * titres, float ** position,int nb_titre);
void detruire_menu(struct Menu * menu);


struct Titre * creer_titre( ALLEGRO_BITMAP * image_selection,ALLEGRO_BITMAP * image_deselection,void * lien);
void detruire_titre(struct Titre * titre);

float ** creer_position_collonne(int n,int debut,int fin,int y); // creer un tableau position  qui fait une collonne  de titre en y entre les ascisse debut et fin (attention au chevauchement)

void afficher_menu(struct Menu *);
void titre_suivant(struct Menu *); //selectionne le titre suivant (si il yen a un )
void titre_precedent(struct Menu *); // selectionne le precedent
void lancer_menu(struct Menu * menu); //lance l'app menu

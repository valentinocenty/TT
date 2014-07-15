struct Title {
  ALLEGRO_BITMAP * image_selection;     //image du Title lorsque il est selectionne
  ALLEGRO_BITMAP * image_deselection;  // image du titre lorsque il n'est pas selectionne
  void (*link)(void);                          // fonction associe au titre(lancer jeu , aller dans un autre menu etc)
};

struct Menu {
  ALLEGRO_BITMAP * bg_picture;     //image de fond
  int title_selection;             // titre actuellement selectionne , -1 si yen a pas 
  struct Title * titles;           // tableau des titres du menu
  float ** position;                 // position respective de chaque tableau {[x1,y1],[x2 ...}
  int title_nb;
};

struct Menu * create_menu(ALLEGRO_BITMAP * bg_picture,struct Title * titles, float ** position,int title_nb);
void free_menu(struct Menu * menu);


struct Title * create_titles( ALLEGRO_BITMAP * image_selection,ALLEGRO_BITMAP * image_deselection,void * link);
void free_titre(struct Title * titles);

float ** create_column_position(int n,int start,int end,int y); // creer un tableau position  qui fait une collonne de titre en y entre les ascisse debut et fin (attention au chevauchement)

void display_menu(struct Menu *);
void next_title(struct Menu *); //selectionne le titre suivant (si il yen a un )
void previous_title(struct Menu *); // selectionne le precedent
void launch_menu(struct Menu * menu); //lance l'app menu

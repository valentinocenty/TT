#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct Options * options;
static struct Screen * screen;
static struct Control * control;

#include "Options.h"
#include "Screen.h"
#include "Menu.h"
#include "Control.h"
#include "Player.h"

#include "Options.c"
#include "Screen.c"
#include "Menu.c"
#include "Control.c"
#include "Player.c"

int main(int argc,char ** argv){
if(al_init()<0){ //fonction d'initialisation
    fprintf(stderr,"Error at the initialisation of Allegro");
    return -1;
  }

  if(!al_init_image_addon() ) {
    printf("addon Error");
    return 0;
    }

  options=create_options();
  load_options(options,"Options.txt");
  

  screen=create_screen(options);

  control=create_control(screen);

  ALLEGRO_BITMAP * bg_picture=NULL;
  bg_picture = al_load_bitmap("./Ressources/Pictures/test.png");


  ALLEGRO_BITMAP * image_titre_d=NULL;
  image_titre_d =al_load_bitmap("./Ressources/Pictures/play_d.png");
  ALLEGRO_BITMAP * image_titre_s=NULL;
  image_titre_s=al_load_bitmap("./Ressources/Pictures/play_s.png");
/** DEBUT 
  ALLEGRO_BITMAP * image_credit_d=NULL;
  image_credit_d =al_load_bitmap("./ressource/image/credit_d.png");
  ALLEGRO_BITMAP * image_credit_s=NULL;
  image_credit_s=al_load_bitmap("./ressource/image/credit_s.png");
  ALLEGRO_BITMAP * image_quitter_d=NULL;
  image_quitter_d =al_load_bitmap("./ressource/image/quitter_d.png");
  ALLEGRO_BITMAP * image_quitter_s=NULL;
  image_quitter_s=al_load_bitmap("./ressource/image/quitter_s.png");
*/
  if (!bg_picture || !image_titre_d || !image_titre_s){
    printf("bug image\n");
  }


  struct Title *titles=malloc(sizeof(struct Title)*1);
  struct Menu * menu=create_menu(bg_picture,titles,create_column_position(1,200,300,300),1);
  //struct Control* control=creer_control(ecran);
  /** DEBUT
  void (*p)(void);
  void jouer(){
    partie = creer_partie();
    lancer_jeu(partie);}
  void credits(){
    ALLEGRO_BITMAP * image_credits=NULL;
    image_credits = al_load_bitmap("./ressource/image/credits.png");
    al_draw_bitmap(image_credits,0,0,0);
    al_flip_display();
    al_rest(5.0);
  }
  void quitter(){quitter_jeu(partie);}
  
  
  p=jouer;
  titres[0]=*creer_titre(image_titre_s,image_titre_d,*p);
  p=credits;
  titres[1]=*creer_titre(image_credit_s,image_credit_d,*p);
  p=quitter;
  titres[2]=*creer_titre(image_quitter_s,image_quitter_d,*p);
*/
  void (*p)(void);
  void f(){control_menu(menu,control);}

  titles[0]=*create_title(image_titre_s,image_titre_d,*p);
  if (!menu ){
    printf("bug menu\n");
  }
  // HERE
  display_menu(menu);
  al_flip_display();
  al_rest(1.0);
  al_flush_event_queue(control->event);
  control_menu(menu,control);

  

  return 0 ;
}

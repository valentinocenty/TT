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

#include "Options.h"
#include "Screen.h"

#include "Options.c"
#include "Screen.c"

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
/** DEBUT 
  control=creer_control(ecran);



 // struct Control * control =creer_control(ecran);
  ALLEGRO_BITMAP * image_fond=NULL;
  image_fond = al_load_bitmap("./ressource/image/Background_lugdunum.png");
  ALLEGRO_BITMAP * image_titre_d=NULL;
  image_titre_d =al_load_bitmap("./ressource/image/jouer_d.png");
  ALLEGRO_BITMAP * image_titre_s=NULL;
  image_titre_s=al_load_bitmap("./ressource/image/jouer_s.png");
  ALLEGRO_BITMAP * image_credit_d=NULL;
  image_credit_d =al_load_bitmap("./ressource/image/credit_d.png");
  ALLEGRO_BITMAP * image_credit_s=NULL;
  image_credit_s=al_load_bitmap("./ressource/image/credit_s.png");
  ALLEGRO_BITMAP * image_quitter_d=NULL;
  image_quitter_d =al_load_bitmap("./ressource/image/quitter_d.png");
  ALLEGRO_BITMAP * image_quitter_s=NULL;
  image_quitter_s=al_load_bitmap("./ressource/image/quitter_s.png");

  if (!image_fond || !image_titre_d || !image_titre_s){
    printf("bug image\n");
  }


  struct Titre *titres=malloc(sizeof(struct Titre)*3);
  struct Menu * menu=creer_menu(image_fond,titres,creer_position_collonne(3,200,300,300),3);
  //struct Control* control=creer_control(ecran);
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
  void f(){control_menu(menu,control);}
  
  p=jouer;
  titres[0]=*creer_titre(image_titre_s,image_titre_d,*p);
  p=credits;
  titres[1]=*creer_titre(image_credit_s,image_credit_d,*p);
  p=quitter;
  titres[2]=*creer_titre(image_quitter_s,image_quitter_d,*p);

  if (!menu ){
    printf("bug menu\n");
  }

  afficher_menu(menu);
  al_flip_display();
  al_rest(1.0);
  al_flush_event_queue(control->evenement);
  control_menu(menu,control);

  */

  return 0 ;
}

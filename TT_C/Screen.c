 struct Screen {
  ALLEGRO_DISPLAY * display;
};

struct Screen * create_screen(struct Options * options){

  struct Screen * screen = malloc(sizeof(struct Screen));
 //FULL SCREEN or WINDOWED
  if (options->screen_mode==FULL_SCREEN) {
    al_reset_new_display_options();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
  }
  if (options->screen_mode==WINDOWED) {
    al_reset_new_display_options();
    al_set_new_display_flags(ALLEGRO_WINDOWED);
  }
  //screen resolution
  ALLEGRO_DISPLAY *display = NULL;
  display=al_create_display((options->x_resolution),(options->y_resolution));
  if(!display){
    fprintf(stderr,"Error at display init\n");
    return NULL;
  }  
  screen->display=display;
  return screen;
}




void free_screen(struct Screen * screen){
  al_set_target_bitmap(NULL);
  al_destroy_display(screen->display);
  free(screen);
} 

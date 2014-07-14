/*  ALLEGRO_EVENT_KEY_DOWN * touche_pressee;
  ALLEGRO_EVENT_KEY_UP * touche_relachee;
  ALLEGRO_EVENT_KEY_CHAR * lettre;
  ALLEGRO_EVENT_MOUSE_AXES * souris_bougee;
  ALLEGRO_EVENT_MOUSE_BUTTON_DOWN * souris_pressee;
  ALLEGRO_EVENT_MOUSE_BUTTON_UP * souris_relachee;
  ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY * souris_dans_fenetre;
  ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY * souris_hors_fenetre;
  ALLEGRO_EVENT_DISPLAY_CLOSE * exit;
  ALLEGRO_EVENT_DISPLAY_SWITCH_OUT * out;
  ALLEGRO_EVENT_DISPLAY_SWITCH_IN * in;*/


struct Control * create_control(struct Screen * screen){
  struct Control * control = malloc(sizeof(struct Control));
  control->event=al_create_event_queue();
  if (!control->event){
    fprintf(stderr,"Error at event init !\n");
    free(control);
    return NULL;
  }
   al_install_keyboard();
   al_register_event_source(control->event,al_get_keyboard_event_source());
   al_install_mouse();
   al_register_event_source(control->event,al_get_mouse_event_source());
   al_show_mouse_cursor(ecran->display);
   al_register_event_source(control->event,al_get_display_event_source(ecran->display));
   return control;
}

void free_control(struct Control * control){
  al_uninstall_mouse();
  al_uninstall_keyboard();
  al_destroy_event_queue(control->event);
  free(control);
}

int control_menu(struct Menu * menu,struct Control * control){
  ALLEGRO_EVENT  event ;
  al_wait_for_event(control->event,&event);
  while (event.type!=ALLEGRO_KEY_DOWN){
    switch (event.keyboard.keycode){
    case ALLEGRO_KEY_UP:
      titre_precedent(menu);
      break;
    case ALLEGRO_KEY_DOWN:
      titre_suivant(menu);
      break;
    case ALLEGRO_KEY_ENTER:
      (*(menu->titres[menu->titre_selection].lien))();
      break;
    case ALLEGRO_KEY_ESCAPE:
      return 0;
      break;
    }
    afficher_menu(menu);
    al_flip_display();
    al_rest(0.1);
    al_flush_event_queue(control->event);
    al_wait_for_event(control->event,&event);
  }
}

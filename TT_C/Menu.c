struct Title * create_title( ALLEGRO_BITMAP * image_selection,ALLEGRO_BITMAP * image_deselection,void * link){
  struct Title * title = (struct Title * )malloc(sizeof(struct Title)); 
  title->image_selection=image_selection;
  title->image_deselection=image_deselection;
  title->link=link;
  return title;
}


void free_title(struct Title * title){
  free(title->image_deselection);
  free(title->image_selection);
  free(title->link);
}


struct Menu * create_menu(ALLEGRO_BITMAP * bg_picture,struct Title * titles, float ** position,int title_nb){
  struct Menu * menu = (struct Menu *)malloc(sizeof(struct Menu));
  menu->bg_picture=bg_picture;
  menu->title_selection = 0;
  menu->titles=titles;
  menu->position=position;
  menu->title_nb=title_nb;
  return menu;
}

void free_menu(struct Menu * menu){
  free_title(menu->titles);
  free(menu->position);
  free(menu->bg_picture);
  free(menu);
  menu=NULL;
}

float ** create_column_position(int n,int start,int end,int y){
  float ** position = (float **)malloc(sizeof(int*)*n);
  for ( int i = 0 ; i<n;i++){
    position[i] = (float*)malloc(sizeof(int)*2);
    position[i][1]=(float)y;
    position[i][0]=(float)(start +i*(end-start));
  }
  return position;
}


void display_menu(struct Menu * menu ){
  if(menu!=NULL){
    al_draw_bitmap(menu->bg_picture,0,0,0);
    for(int i=0 ;i<(menu->title_nb);i++){
      if (menu->title_selection != i ){
        al_draw_bitmap(menu->titles[i].image_deselection,menu->position[i][1],menu->position[i][0],0);
      }
      else {
        al_draw_bitmap(menu->titles[i].image_selection,menu->position[i][1],menu->position[i][0],0);
      }
    }
  }
}

void next_title(struct Menu * menu){
  if(menu->title_nb>menu->title_selection+1 && menu->title_selection>-1){
    menu->title_selection++;
  }
}

void previous_title(struct Menu * menu){
  if (menu->title_selection>0){
    menu->title_selection--;
  }
}



/*int launch_menu(struct Menu * menu){
  display_menu(menu);
  al_flip_display();
  ALLEGRO_EVENT_QUEUE * queue=al_create_event_queue();
  ALLEGRO_EVENT * event;
  while (){
    al_wait_for_event(queue,event);

  }
  return 0;
}
*/

#define OPTION_NB 3
#define X_RES_DEFAULT 800
#define Y_RES_DEFAULT 600

enum screen_mode{
  FULL_SCREEN,
  WINDOWED
};

struct Options{
  int x_resolution;
  int y_resolution;
  enum screen_mode screen_mode;
};

struct Options *create_options(){
  struct Options * options =malloc(sizeof(struct Options));
  options->x_resolution=0;
  options->y_resolution=0;
  options->screen_mode=WINDOWED;
  return options;
}

void load_options(struct Options * options,char * file){
  //handle option file
  char * path = malloc(sizeof(char)*40);
  sprintf(path,"./Ressources/Options/%s",file);
  FILE * file_to_open = fopen(path,"r");
  if (file_to_open== NULL){
    options->screen_mode=WINDOWED;
    options->x_resolution=X_RES_DEFAULT;
    options->y_resolution=Y_RES_DEFAULT;
    if (file_to_open == NULL ){
      printf("Error when trying to access to the file %s\n",path);
    }
    free(path);
  }

  //Data getter

  char * string2=malloc(sizeof(char)*20);
  for(int i=0; i<OPTION_NB ;i++){
    char * string =malloc(sizeof(char)*20);
    char l=0;
    l=fgetc(file_to_open);
    int i =0;
    do{
      string[i]=l;
      l=fgetc(file_to_open);
      //printf("%s",l);
      i++;
    } while ( l!='=');
    while (i<19){
      string[i]=0;
      i++;
    }
    //printf("\n");
    fgets(string2,20,file_to_open);
    //printf("%s %s",string,string2);

  //switch et applications des options
    

//printf("%d %d %s",strcmp(string2,"FULL_SCREEN\n"),strcmp(string2,"FENETRE\n"),string2);
    // printf("%d ",strcmp(string,"x_resolution"));
    //printf("%d \n",strcmp(string,"y_resolution"));


    if (strcmp(string,"screen_mode")==0){
      if (strcmp(string2,"FULL_SCREEN\n")==0) {
        options->screen_mode=FULL_SCREEN;
      }
      if (strcmp(string2,"WINDOWED\n")==0){
        options->screen_mode=WINDOWED;
      }
    }
    else if (strcmp(string,"x_resolution")==0){
      options->x_resolution=atoi(string2);
    //printf("%d\n",options->x_resolution);
    }
    else if (strcmp(string,"y_resolution")==0){
      options->y_resolution=atoi(string2);
    //printf("%d\n",options->resolution_y);
    }
    free(string);
  }
  free(string2);
  free(path);
  fclose(file_to_open);
}

void free_options(struct Options * options){
  free(options);
}

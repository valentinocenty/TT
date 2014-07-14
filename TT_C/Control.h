struct Control {
  ALLEGRO_EVENT_QUEUE * event;
};

struct Control * create_control(struct Screen * screen);
void free_control(struct Control * control);
int control_menu(struct Menu * menu,struct Control * control);
	
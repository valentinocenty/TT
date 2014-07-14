Main : Main.o 
	gcc -o Main Main.o -g -std=c99  `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0  allegro_primitives-5.0 allegro_ttf-5.0`

Main.o : Main.c Options.c Screen.c Menu.c Control.c Options.h Screen.h Menu.h Control.h
	gcc -o Main.o -c Main.c -g -std=c99 `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0  allegro_primitives-5.0 allegro_ttf-5.0`

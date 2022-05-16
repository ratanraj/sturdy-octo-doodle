#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

#include "conf.h"
#include "splash.h"
#include "levelselector.h"


int main()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    
    int current_level = 1;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_DISPLAY* disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_FONT* font = al_create_builtin_font();

    ALLEGRO_BITMAP* map = al_load_bitmap("map.png");


    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    float x=0;

    //load_splash_screen(queue);  /* SPLASH SCREEN */

    //current_level = select_level(queue); /* LEVEL SELECTOR */

    printf("LEVEL = %d\n", current_level);/* LOAD LEVEL */
    

    while(1) {
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if ((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)) {
            break;
        }

        if(redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0,0,0));
            if(x>100)x=0;
            al_draw_bitmap(map, 0, 0, 0);
            al_draw_text(font, al_map_rgb(255, 150, 150), ++x, 0, 0, "Hello World!");
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}
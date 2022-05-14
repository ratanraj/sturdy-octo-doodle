#include "splash.h"
#include "conf.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>


void load_splash_screen(ALLEGRO_EVENT_QUEUE* queue) {
    ALLEGRO_FONT* font;/* = al_create_builtin_font();*/
    ALLEGRO_EVENT event;
    bool redraw = true;
    int border_width = 10;

    al_init_font_addon();
    al_init_ttf_addon();
    
    font = al_load_font("Gotham-Book.ttf", 72, 0);
    if(!font) {
        printf("ERROR loading font\n");
        exit(1);
    }
    while(1) {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            break;
        } else if (event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }

        if(redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(50, 50, 50));
            al_draw_rectangle(
                border_width,
                border_width,
                SCREEN_WIDTH-border_width,
                SCREEN_HEIGHT-border_width,
                al_map_rgb(255, 255, 255),
                2.0);
            
            al_draw_text(
                font,
                al_map_rgb(255, 255, 255),
                100,
                100,
                0,
                "Hello World!");


            al_flip_display();

            redraw = false;
        }
    }
}
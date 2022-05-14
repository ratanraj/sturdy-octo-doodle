#include "splash.h"
#include "conf.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>


void load_splash_screen(ALLEGRO_EVENT_QUEUE* queue) {
    ALLEGRO_EVENT event;
    bool redraw = true;

    ALLEGRO_BITMAP* splash_image = al_load_bitmap("splash.png");
    al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);

    while(1) {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            break;
        } else if (event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }

        if(redraw && al_is_event_queue_empty(queue)) {
            al_draw_bitmap(splash_image, 0, 0, 0);
            al_flip_display();

            redraw = false;
        }
    }
}
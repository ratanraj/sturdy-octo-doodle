#include "levelselector.h"
#include <stdio.h>

#include "conf.h"

void draw_level_grid() {
    al_draw_rectangle(
        100,
        100, 
        SCREEN_WIDTH-100, 
        SCREEN_HEIGHT-100,
        al_map_rgb(255, 255, 255),
        5);
}

int select_level(ALLEGRO_EVENT_QUEUE* queue) 
{
    bool redraw = true;
    ALLEGRO_EVENT event;
    printf("LEVEL SELECTOR....\n");
    while(1) {
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            break;
        }

        if(redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0,0,0));
            draw_level_grid();
            al_flip_display();
            redraw = false;
        }
    }
    return 1;
}
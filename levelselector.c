#include "levelselector.h"
#include <stdio.h>

#include "conf.h"
#include "colors.h"

#define LEVEL_BOX_WIDTH 100
#define GRID_LEFT 100
#define GRID_TOP 100

ALLEGRO_FONT *font;

int draw_level_number(int n, int x, int y) {
    char buffer[3];
    int hover = 0;
    float x1 = GRID_LEFT + n*(LEVEL_BOX_WIDTH+2) + 10;
    float y1 = 10 + GRID_TOP;
    float x2 = (GRID_LEFT + n*LEVEL_BOX_WIDTH + 10) + LEVEL_BOX_WIDTH;
    float y2 = 10 + GRID_TOP + LEVEL_BOX_WIDTH;
    ALLEGRO_COLOR letter_col;

    if(x>x1 && x<x2 && y>y1 && y<y2) {
        letter_col = RED;
        hover = n+1;
    } else {
        letter_col = PINK;
        hover = 0;
    }

    sprintf(buffer, "%d", n+1);

    al_draw_rectangle(
        x1, y1, x2, y2,
        al_map_rgb(255, 255, 255),
        1
    );
    al_draw_text(
        font,
        letter_col,
        x1+20,
        y1+10,
        0,
        buffer
    );
    return hover;
}

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
    font = al_load_ttf_font("Gotham-Book.ttf", 72, 0);
    bool redraw = true, clicked = false;
    int i, x, y, selected_level;
    ALLEGRO_EVENT event;
    printf("LEVEL SELECTOR....\n");
    while(1) {
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            clicked = true;
        } else if(event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            x = event.mouse.x;
            y = event.mouse.y;
        }

        if(redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0,0,0));
            draw_level_grid();
            for(i=0;i<5;i++) {
                selected_level = draw_level_number(i, x, y);
                if(clicked && selected_level!=0) {
                    return selected_level;
                }
            }
            al_flip_display();
            redraw = false;
        }
    }
    return 0;
}
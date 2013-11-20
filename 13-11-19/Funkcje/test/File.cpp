//
//  File.cpp
//  funkcje
//
//  Created by Filip Bartuzi on 20.11.2013.
//
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

void rysuj_uklad_wspolrzednych();

int main(int argc, char **argv) {
    al_init();
    al_create_display(800, 800);
    al_clear_to_color(al_map_rgb_f(0, 0, 0));
//    for (int i = 50; i < 400; i+=3) {
//        al_draw_pixel(i, 200+i, al_map_rgb_f(255, 255, 255) );
//    }
    rysuj_uklad_wspolrzednych();
    al_flip_display();
    al_rest(10.0);

    return 0;
}
void rysuj_uklad_wspolrzednych(){
    al_draw_line(400, 0, 400, 800, al_map_rgb_f(255, 255, 255), 1.5); // Y
    al_draw_line(0, 400, 800, 400, al_map_rgb_f(255, 255, 255), 1.5); // X
    al_draw_line(800, 400, 770, 410, al_map_rgb_f(255, 255, 255), 1.5); // GROT X
    al_draw_line(800, 400, 770, 390, al_map_rgb_f(255, 255, 255), 1.5); // GROT X
    al_draw_line(400, 0, 410, 30, al_map_rgb_f(255, 255, 255), 1.5); // GROT Y
    al_draw_line(400, 0, 390, 30, al_map_rgb_f(255, 255, 255), 1.5); // GROT Y
    
}
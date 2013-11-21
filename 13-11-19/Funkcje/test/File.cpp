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
const int grubosc = 1.5;
const int poczatek = 0;
const int dlugosc = 800;
const int szerokosc = 800;
const int srodek = (dlugosc/2 + szerokosc/2)/2;
const int dlugosc_grotu = 20;
const int wysokosc_grotu = 10;
const ALLEGRO_COLOR bialy = al_map_rgb_f(255, 255, 255);
const ALLEGRO_COLOR czarny = al_map_rgb_f(0, 0, 0);

int main(int argc, char **argv) {
    al_init();
    al_create_display(dlugosc, szerokosc);
    al_clear_to_color(czarny);
//    for (int i = 50; i < 400; i+=3) {
//        al_draw_pixel(i, 200+i, al_map_rgb_f(255, 255, 255) );
//    }
    rysuj_uklad_wspolrzednych();
    al_flip_display();
    al_rest(10.0);

    return 0;
}
void rysuj_uklad_wspolrzednych(){

    al_draw_line(srodek, poczatek, srodek, dlugosc, bialy, grubosc); // Y
    al_draw_line(poczatek, srodek, szerokosc, srodek, bialy, grubosc); // X
    al_draw_line(szerokosc, srodek, szerokosc - dlugosc_grotu, srodek+ wysokosc_grotu, bialy, grubosc); // GROT X
    al_draw_line(szerokosc, srodek, szerokosc - dlugosc_grotu, srodek - wysokosc_grotu, bialy, grubosc); // GROT X
    al_draw_line(srodek, poczatek, srodek + wysokosc_grotu, poczatek + dlugosc_grotu, bialy, grubosc); // GROT Y
    al_draw_line(srodek, poczatek, srodek - wysokosc_grotu, poczatek + dlugosc_grotu, bialy, grubosc); // GROT Y
    for (int i = 1; i <= 15; i++) {
        int grubosc_miary,szerokosc_miary, przerwa;
        przerwa = 25;
        if (i%2) {
            grubosc_miary = 1.5;
            szerokosc_miary = 10;
        }
        else {
            grubosc_miary = 1;
            szerokosc_miary = 4;
        }
        al_draw_line(srodek-szerokosc_miary, srodek-i*przerwa, srodek+szerokosc_miary, srodek-i*przerwa, bialy , grubosc_miary); // +Y
        al_draw_line(srodek-szerokosc_miary, srodek+i*przerwa, srodek+szerokosc_miary, srodek+i*przerwa, bialy , grubosc_miary); // -Y
        al_draw_line(srodek+i*przerwa, srodek-szerokosc_miary,srodek+i*przerwa,  srodek+szerokosc_miary, bialy , grubosc_miary); // + X
        al_draw_line(srodek-i*przerwa, srodek-szerokosc_miary,srodek-i*przerwa,  srodek+szerokosc_miary, bialy , grubosc_miary); // - X
    }
    
}
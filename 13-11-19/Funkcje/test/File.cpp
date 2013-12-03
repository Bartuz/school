//
//  File.cpp
//  funkcje
//
//  Created by Filip Bartuzi on 20.11.2013.
//
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>


// ZADEKLARUJ!!!!

const int p = -20;
const int k = 20;

void rysuj_uklad_wspolrzednych();
void rysuj_funkcje(double,double);
void szukaj_min_max(int&, int&);
double f();
const double dokladnosc = 1;
const float grubosc = 1.5;
const int poczatek = 0;
const int dlugosc = 800;
const int szerokosc = 800;
const int srodek = (dlugosc/2 + szerokosc/2)/2;
const int dlugosc_grotu = 20;
const int wysokosc_grotu = 10;
const int przerwa = 25;
const ALLEGRO_COLOR bialy = al_map_rgb_f(255, 255, 255);
const ALLEGRO_COLOR czarny = al_map_rgb_f(0, 0, 0);
const ALLEGRO_COLOR czerwony = al_map_rgb_f(255, 0, 0);
const ALLEGRO_COLOR niebieski = al_map_rgb_f(0, 0, 255);
int main(int argc, char **argv) {
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
//    const ALLEGRO_FONT *arial = al_load_ttf_font("arial.ttf", 12, 0);
    al_create_display(dlugosc, szerokosc);
    al_clear_to_color(czarny);
//    for (int i = 50; i < 400; i+=3) {
//        al_draw_pixel(i, 200+i, al_map_rgb_f(255, 255, 255) );
//    }
//     al_draw_text(arial, bialy, 10, 10, 0, "asda"); // X
    int min, max;
    szukaj_min_max(min, max);
    rysuj_uklad_wspolrzednych();
    rysuj_funkcje(min,max);
    al_flip_display();
    al_rest(10.0);
    return 0;
}
double f(double x){
	return  x;
}
void szukaj_min_max(int &min, int &max){
    min = max = -f(p)+400;
    for (int i = p+dokladnosc; i <= k ; i+=dokladnosc) {
        if (-f(i)+400 < min) {
            min = -f(i)+400;
        } else if (-f(i+400 > max)) {
            max = -f(i)+400;
        }
    }
    std::cout << "max = " << max << " min = " << min << std::endl;
}
void rysuj_funkcje(double min,double max){
    ALLEGRO_COLOR kolor;
    double skala;
    if (abs(max) < abs(min)) {
        max = min;
    }
    skala = 400/max;
    std::cout << skala;
    for (float i = 20; i <= 800; i+=dokladnosc) {
        if (i-400>= p && i-400<= k) {
            kolor = niebieski;
        } else {
            kolor = czerwony;
        }
        al_draw_pixel(i, (-f(i-400)+400) , kolor);
//        al_draw_line(i, -f(i-400)+400, i+1, f(i+1-400), czerwony, .1);
    }
}
void rysuj_uklad_wspolrzednych(){

    al_draw_line(srodek, poczatek, srodek, dlugosc, bialy, grubosc); // Y
    al_draw_line(poczatek, srodek, szerokosc, srodek, bialy, grubosc); // X
    al_draw_line(szerokosc, srodek, szerokosc - dlugosc_grotu, srodek+ wysokosc_grotu, bialy, grubosc); // GROT X
    al_draw_line(szerokosc, srodek, szerokosc - dlugosc_grotu, srodek - wysokosc_grotu, bialy, grubosc); // GROT X
    al_draw_line(srodek, poczatek, srodek + wysokosc_grotu, poczatek + dlugosc_grotu, bialy, grubosc); // GROT Y
    al_draw_line(srodek, poczatek, srodek - wysokosc_grotu, poczatek + dlugosc_grotu, bialy, grubosc); // GROT Y
    for (int i = 1; i <= 15; i++) {
        int grubosc_miary,szerokosc_miary;
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
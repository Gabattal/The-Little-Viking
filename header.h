/// ---FICHIER HEADER --- ///
/// --------------------- ///

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#endif // HEADER_H_INCLUDED


///Directives préproc

#include <allegro.h>
#include <stdio.h>

#define NBANIME 2
#define NBDIR 4

#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

#define NFLECHE 3
#define NPROG 2

#define mapSizeX 13
#define mapSizeY 13


///Structures


///Structure contenant les différents sprites qu'on utilise
typedef struct images
{
    ///Sprites du viking
    BITMAP *viking_walk[NBDIR][NBANIME];
    BITMAP *viking_still[NBDIR];

    BITMAP *viking_walk2[NBDIR][NBANIME];
    BITMAP *viking_still2[NBDIR];

    BITMAP *viking_walk3[NBDIR][NBANIME];
    BITMAP *viking_still3[NBDIR];

    BITMAP *viking_walk4[NBDIR][NBANIME];
    BITMAP *viking_still4[NBDIR];

    BITMAP *viking_walk5[NBDIR][NBANIME];
    BITMAP *viking_still5[NBDIR];

    BITMAP *win;
    BITMAP *win2;
    BITMAP *win3;
    BITMAP *win4;
    BITMAP *win5;

    ///Actions
    BITMAP *fleche[NFLECHE];
    BITMAP *PG[NPROG];
    BITMAP *start;
    BITMAP *destroy;

    /// Images de fond et décor
    BITMAP *decor;
    BITMAP *tree;
    BITMAP *crane;
    BITMAP *hache;
    BITMAP *bush;
    BITMAP *ananas;

    ///Barres d'actions
    BITMAP *main;
    BITMAP *PGT1;
    BITMAP *PGT2;
    BITMAP *PG1;
    BITMAP *PG2;
    BITMAP *JAUNE;
    BITMAP *BLEU;
    BITMAP *ORANGE;
    BITMAP *VERT;
    BITMAP *BLANC;



    BITMAP* levels;
    BITMAP* level1;
    BITMAP* level12;
    BITMAP* level123;
    BITMAP* regles;
    BITMAP* menu;
    BITMAP* pause;
    BITMAP* victory;
    BITMAP* SM;

} t_images;

typedef struct sons
{
    SAMPLE* son1; //.ogg ou wav
    SAMPLE* son2;
    SAMPLE* son3;
    SAMPLE* son4;

} t_sons;

struct viking
{
    int coordPX;
    int coordPY;
    float x;
    float y;
    int dir;

    int turn;
    int read;
    int bouge;
    int bouge_depuis;


    int cptdx;
    int tmpdx;

    int imgcourante;
    int cptimg;
    int tmpimg;

    int win;
    int lose;

    int stop;
    int finish;

} tabDeVikings[5];


///Prototypes

BITMAP * load_bitmap_check(char *nomImage);
void loadMap(char map[mapSizeY][mapSizeX + 2], int level);
void charger_images(t_images *img);
int choix_mode();
void lancer_allegro();
int choix(t_images*img,int* mode,int* progress);

void init_viking(t_images*img);
void draw_sprites(t_images*img,BITMAP*page,char map[mapSizeY][mapSizeX +2], int* beginning, int* score,int* level);

void if_move(char map[mapSizeY][mapSizeX +2]);
void display_if_move(t_images*img,BITMAP*page);
void pause(t_images*img,int*mode,BITMAP*page);
void loadSave(int* progress);
void Save(int* progress);

void lemove_solo(int tabm[12],int tabp1[8],int tabp2[4],int*start,int*endt,int*debm,int*debp1,int*debp2);
void actions_solo(char map[mapSizeY][mapSizeX +2],int*debm,int*debp1,int*debp2,int tabm[12],int tabp1[8],int tabp2[4],int*start,int*endt);
void score_win(t_images*img,char map[mapSizeY][mapSizeX +2],int*score,int*win,t_sons*SON,int tabv1[4],int tabv2[4],int tabv3[4],
               int tabv4[4],int tabv5[4],int*dv1,int*dv2,int*dv3,int*dv4,int*dv5);
void drag_drop_solo(t_images*img,int*drag,BITMAP*page,int* main,int*PG1,int*PG2,int tabm[12],int tabp1[8],int tabp2[4],int*start,int*level);
void reset_solo(int*beginning,int*main,int*PG1,int*PG2,int*start,int*debm,int*debp1,int*debp2,int*score,int tabm[12],int tabp1[8],int tabp2[4],int*drag,int*son);
void bouger_solo(char map[mapSizeY][mapSizeX +2],int*endt,int*debm,int*debp1,int*debp2);
void victory_solo(t_images*img,int*main,int*PG1,int*PG2,int*debm,int*debp1,int*debp2,int*progress,int*mode,int*level,int tabm[12], int tabp1[8], int tabp2[4],t_sons*SON,int*son);



//void continue_move(BITMAP*page,char map[mapSizeY][mapSizeX +2]);


void drag_drop_multi(t_images*img,int*drag,BITMAP*page,int* start,int *level,
                     int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],int tabpg2[4],
                     int* v1,int* v2,int* v3,int* v4,int* v5, int* p1, int *p2);
void reset_multi(int*beginning,int*start,int*v1,int*v2,int*v3,int*v4,int*v5,int*p1,int*p2,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,
                 int*score,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],int tabpg2[4],int*drag,int*son,int*vicm,int*losm,
                 int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10);
void lemove_multi(int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4], int tabpg2[4],
                  int* start,int*endt,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10);
void bouger_multi(char map[mapSizeY][mapSizeX +2],int*endt,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,
                  int*dp1,int*dp2,int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10);
void draw_vikings_multi(t_images*img,BITMAP*page,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int*dv1,int*dv2,int*dv3,int*dv4,int*dv5);
void actions_multi(char map[mapSizeY][mapSizeX +2],int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],
                   int tabpg2[4],int* start,int*endt,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10);
void victory_multi(t_images*img,int*v1,int*v2,int*v3,int*v4,int*v5,int*p1,int*p2,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,
                   int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],int tabpg2[4],t_sons*SON,int*son,int*mode,int*start,int*vicm,int*losm,
                   int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10);
void whowin(BITMAP*page,t_images*img,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*vicm,int*start,int*losm);
void stop();


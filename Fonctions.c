/// --- FICHIER FONCTIONS --- ///
/// ------------------------- ///


#include "header.h"

///Fonctions

///Chargement "sécurisé" d'une image :
/// interrompt le programme avec un message si problème...

BITMAP * load_bitmap_check(char *nomImage)
{
    BITMAP *bmp;
    bmp=load_bitmap(nomImage,NULL);
    if (!bmp)
    {
        allegro_message("pas pu trouver %s",nomImage);
        exit(EXIT_FAILURE);
    }
    return bmp;
}

///Chargement de la map de jeu
void loadMap(char map[mapSizeY][mapSizeX + 2], int level)
{

    FILE* mapFile = NULL;
    char buffer[20];

    sprintf(buffer, "./maps/map_%d.txt", level); ///Cherche le .txt de la map dans le dossier
    mapFile = fopen(buffer, "r"); ///Ouverture si le .txt est trouvé

    if (mapFile != NULL) ///Condition OK : on continue
    {
        printf("Ouverture du fichier '%s'\n", buffer);

        fgetc(mapFile);
        int y;

        for (y = 0; y< mapSizeY; y++) ///Prend en compte tous les caractères contenus dans le .txt et les charges
        {
            fgets(map[y], mapSizeX + 2, mapFile);
        }
        fclose(mapFile);
    }
    else /// Condition pas OK
    {
        printf("Erreur : Impossible d'ouvrir le fichier '%s'\n", buffer);
    }
}

///Permet de charger les sprites de la strucuture définie plus haut
void charger_images(t_images *img)
{
    ///Viking


    img->viking_walk[HAUT][0] = load_bitmap_check("viking/UP/viking0.bmp");
    img->viking_walk[HAUT][1] = load_bitmap_check("viking/UP/viking1.bmp");

    img->viking_walk[BAS][0] = load_bitmap_check("viking/DOWN/viking0.bmp");
    img->viking_walk[BAS][1] = load_bitmap_check("viking/DOWN/viking1.bmp");

    img->viking_walk[DROITE][0] = load_bitmap_check("viking/RIGHT/viking0.bmp");
    img->viking_walk[DROITE][1] = load_bitmap_check("viking/RIGHT/viking1.bmp");

    img->viking_walk[GAUCHE][0] = load_bitmap_check("viking/LEFT/viking0.bmp");
    img->viking_walk[GAUCHE][1] = load_bitmap_check("viking/LEFT/viking1.bmp");

    img->viking_still[0]=load_bitmap_check("viking/STILL/viking0.bmp");
    img->viking_still[1]=load_bitmap_check("viking/STILL/viking1.bmp");
    img->viking_still[2]=load_bitmap_check("viking/STILL/viking2.bmp");
    img->viking_still[3]=load_bitmap_check("viking/STILL/viking3.bmp");

    img->win=load_bitmap_check("viking/WIN/win.bmp");




    img->viking_walk2[HAUT][0] = load_bitmap_check("viking/UP/viking2.bmp");
    img->viking_walk2[HAUT][1] = load_bitmap_check("viking/UP/viking3.bmp");

    img->viking_walk2[BAS][0] = load_bitmap_check("viking/DOWN/viking2.bmp");
    img->viking_walk2[BAS][1] = load_bitmap_check("viking/DOWN/viking3.bmp");

    img->viking_walk2[DROITE][0] = load_bitmap_check("viking/RIGHT/viking2.bmp");
    img->viking_walk2[DROITE][1] = load_bitmap_check("viking/RIGHT/viking3.bmp");

    img->viking_walk2[GAUCHE][0] = load_bitmap_check("viking/LEFT/viking2.bmp");
    img->viking_walk2[GAUCHE][1] = load_bitmap_check("viking/LEFT/viking3.bmp");

    img->viking_still2[0]=load_bitmap_check("viking/STILL/viking4.bmp");
    img->viking_still2[1]=load_bitmap_check("viking/STILL/viking5.bmp");
    img->viking_still2[2]=load_bitmap_check("viking/STILL/viking6.bmp");
    img->viking_still2[3]=load_bitmap_check("viking/STILL/viking7.bmp");

    img->win2=load_bitmap_check("viking/WIN/win1.bmp");




    img->viking_walk3[HAUT][0] = load_bitmap_check("viking/UP/viking4.bmp");
    img->viking_walk3[HAUT][1] = load_bitmap_check("viking/UP/viking5.bmp");

    img->viking_walk3[BAS][0] = load_bitmap_check("viking/DOWN/viking4.bmp");
    img->viking_walk3[BAS][1] = load_bitmap_check("viking/DOWN/viking5.bmp");

    img->viking_walk3[DROITE][0] = load_bitmap_check("viking/RIGHT/viking4.bmp");
    img->viking_walk3[DROITE][1] = load_bitmap_check("viking/RIGHT/viking5.bmp");

    img->viking_walk3[GAUCHE][0] = load_bitmap_check("viking/LEFT/viking4.bmp");
    img->viking_walk3[GAUCHE][1] = load_bitmap_check("viking/LEFT/viking5.bmp");

    img->viking_still3[0]=load_bitmap_check("viking/STILL/viking8.bmp");
    img->viking_still3[1]=load_bitmap_check("viking/STILL/viking9.bmp");
    img->viking_still3[2]=load_bitmap_check("viking/STILL/viking10.bmp");
    img->viking_still3[3]=load_bitmap_check("viking/STILL/viking11.bmp");

    img->win3=load_bitmap_check("viking/WIN/win2.bmp");




    img->viking_walk4[HAUT][0] = load_bitmap_check("viking/UP/viking6.bmp");
    img->viking_walk4[HAUT][1] = load_bitmap_check("viking/UP/viking7.bmp");

    img->viking_walk4[BAS][0] = load_bitmap_check("viking/DOWN/viking6.bmp");
    img->viking_walk4[BAS][1] = load_bitmap_check("viking/DOWN/viking7.bmp");

    img->viking_walk4[DROITE][0] = load_bitmap_check("viking/RIGHT/viking6.bmp");
    img->viking_walk4[DROITE][1] = load_bitmap_check("viking/RIGHT/viking7.bmp");

    img->viking_walk4[GAUCHE][0] = load_bitmap_check("viking/LEFT/viking6.bmp");
    img->viking_walk4[GAUCHE][1] = load_bitmap_check("viking/LEFT/viking7.bmp");

    img->viking_still4[0]=load_bitmap_check("viking/STILL/viking12.bmp");
    img->viking_still4[1]=load_bitmap_check("viking/STILL/viking13.bmp");
    img->viking_still4[2]=load_bitmap_check("viking/STILL/viking14.bmp");
    img->viking_still4[3]=load_bitmap_check("viking/STILL/viking15.bmp");

    img->win4=load_bitmap_check("viking/WIN/win3.bmp");




    img->viking_walk5[HAUT][0] = load_bitmap_check("viking/UP/viking8.bmp");
    img->viking_walk5[HAUT][1] = load_bitmap_check("viking/UP/viking9.bmp");

    img->viking_walk5[BAS][0] = load_bitmap_check("viking/DOWN/viking8.bmp");
    img->viking_walk5[BAS][1] = load_bitmap_check("viking/DOWN/viking9.bmp");

    img->viking_walk5[DROITE][0] = load_bitmap_check("viking/RIGHT/viking8.bmp");
    img->viking_walk5[DROITE][1] = load_bitmap_check("viking/RIGHT/viking9.bmp");

    img->viking_walk5[GAUCHE][0] = load_bitmap_check("viking/LEFT/viking8.bmp");
    img->viking_walk5[GAUCHE][1] = load_bitmap_check("viking/LEFT/viking9.bmp");

    img->viking_still5[0]=load_bitmap_check("viking/STILL/viking16.bmp");
    img->viking_still5[1]=load_bitmap_check("viking/STILL/viking17.bmp");
    img->viking_still5[2]=load_bitmap_check("viking/STILL/viking18.bmp");
    img->viking_still5[3]=load_bitmap_check("viking/STILL/viking19.bmp");

    img->win5=load_bitmap_check("viking/WIN/win4.bmp");

    ///Fleches
    img->fleche[0]=load_bitmap_check("boutons/fleche0.bmp");
    img->fleche[1]=load_bitmap_check("boutons/fleche1.bmp");
    img->fleche[2]=load_bitmap_check("boutons/fleche2.bmp");


    ///Actions
    img->PG[0]=load_bitmap_check("boutons/PG1.bmp");
    img->PG[1]=load_bitmap_check("boutons/PG2.bmp");
    img->destroy=load_bitmap_check("boutons/destroy.bmp");
    img->start=load_bitmap_check("boutons/start.bmp");

    ///Map et décor
    img->decor=load_bitmap_check("decor/Map.bmp");
    img->tree=load_bitmap_check("decor/tree.bmp");
    img->crane=load_bitmap_check("decor/crane.bmp");
    img->hache=load_bitmap_check("decor/hache.bmp");
    img->bush=load_bitmap_check("decor/bush.bmp");
    img->ananas=load_bitmap_check("decor/ananas.bmp");


    ///Barres d'actions
    img->main=load_bitmap_check("decor/main.bmp");
    img->PGT1=load_bitmap_check("decor/PGT1.bmp");
    img->PGT2=load_bitmap_check("decor/PGT2.bmp");
    img->PG1=load_bitmap_check("decor/PG1.bmp");
    img->PG2=load_bitmap_check("decor/PG2.bmp");
    img->JAUNE=load_bitmap_check("decor/bloc_jaune.bmp");
    img->ORANGE=load_bitmap_check("decor/bloc_orange.bmp");
    img->BLEU=load_bitmap_check("decor/bloc_bleu.bmp");
    img->VERT=load_bitmap_check("decor/bloc_vert.bmp");
    img->BLANC=load_bitmap_check("decor/bloc_blanc.bmp");


    img->levels=load_bitmap_check("interface/choix_niveaux.bmp");
    img->regles=load_bitmap_check("interface/regles.bmp");
    img->menu=load_bitmap_check("interface/fond_menu.bmp");
    img->pause=load_bitmap_check("interface/pause.bmp");
    img->victory=load_bitmap_check("interface/victoire.bmp");
    img->level1=load_bitmap_check("interface/choix_niveaux_234lock.bmp");
    img->level12=load_bitmap_check("interface/choix_niveaux_34lock.bmp");
    img->level123=load_bitmap_check("interface/choix_niveaux_4lock.bmp");
    img->SM=load_bitmap_check("interface/solo_multi.bmp");
}

///Affichage du choix du mode
int choix_mode()
{

    ///Permet de cliquer sur le rectangle aux coordonnées ci-dessous et d'effectuer l'action en conséquence
    if (mouse_x>=570 && mouse_x<=914 && mouse_y>=280 && mouse_y<=365 && mouse_b&1 )
    {
        printf("choix_mode 1\n");
        return 1;
    }

    if (mouse_x>=570 && mouse_x<=914 && mouse_y>=410 && mouse_y<=495 && mouse_b&1 )
    {
        printf("choix_mode 2\n");
        return 2;
    }

    if (mouse_x>=570&& mouse_x<=914 && mouse_y>=535 && mouse_y<=620 && mouse_b&1 )
    {
        ///test pour le moment, penser à replace
        printf("choix_mode 3\n");
        return 3;
    }

    return 0;
}

/// Lancer allegro et le mode graphique
void lancer_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);//init sound
    show_mouse(screen);
}

void init_viking(t_images*img)
{
    int k;
    for(k=0; k<5; k++)
    {
        tabDeVikings[k].dir = 1;

        tabDeVikings[k].cptdx=0;
        tabDeVikings[k].tmpdx=1;

        tabDeVikings[k].imgcourante=0;
        tabDeVikings[k].cptimg=0;
        tabDeVikings[k].tmpimg=10;

        tabDeVikings[k].bouge=0;
        tabDeVikings[k].bouge_depuis=0;
    }
}



int choix(t_images*img,int *mode,int*progress)
{
    int ready=0;
    int level =0;
    int change = 0;
    int multi =0;


    ready = 0;
    while(level==0)
    {

        if (!mouse_b&1) /// pour qu il n'y ait pas de multi clicks
        {
            ready = 1;
        }
        if (ready == 1)
        {


            switch (choix_mode())
            {
            case 1:
                printf("choix case 1\n");
                ready = 0;
                while(level==0 && change ==0 && *mode==1 )
                {
                    if(multi==0)
                    {

                        blit(img->SM,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                        if (!mouse_b&1 && ready!=1) /// pour qu il n'y ait pas de multi clicks
                        {
                            printf("set ready\n");
                            ready = 1;
                        }

                        if(mouse_x>=325 && mouse_x<=675 && mouse_y>=230 && mouse_y<=310 && mouse_b&1 && ready==1)
                        {
                            multi =1;
                            printf("choix multi 1\n");
                            ready=0;
                        }
                        if(mouse_x>=325 && mouse_x<=675 && mouse_y>=395 && mouse_y<=475 && mouse_b&1 && ready==1)
                        {
                            multi =2;
                            printf("choix multi 2\n");
                            ready=0;
                        }
                    }
                    if(multi==1)
                    {

                        if (*progress ==1)
                        {
                            blit(img->level1,screen,0,0,0,0,SCREEN_W,SCREEN_H); ///afficher le menu
                        }
                        if (*progress ==2)
                        {
                            blit(img->level12,screen,0,0,0,0,SCREEN_W,SCREEN_H); ///afficher le menu
                        }
                        if (*progress ==3)
                        {
                            blit(img->level123,screen,0,0,0,0,SCREEN_W,SCREEN_H); ///afficher le menu
                        }
                        if (*progress ==4)
                        {
                            blit(img->levels,screen,0,0,0,0,SCREEN_W,SCREEN_H); ///afficher le menu
                        }


                        if (!mouse_b&1 && ready!=1) /// pour qu il n'y ait pas de multi clicks
                        {
                            printf("set ready\n");
                            ready = 1;
                        }

                        if (mouse_b&1 && ready == 1)
                        {
                            printf("choix set level ...\n");
                            if(mouse_x>=362 && mouse_x<=642 && mouse_y>=115 && mouse_y<=185)
                            {
                                printf("choix set level 1\n");
                                level=1;
                            }
                            if(mouse_x>=362 && mouse_x<=642 && mouse_y>=245 && mouse_y<=315 && *progress>1)
                            {
                                printf("choix set level 2\n");
                                level=2;
                            }
                            if(mouse_x>=362 && mouse_x<=642 && mouse_y>=380 && mouse_y<=450 && *progress>2)
                            {
                                printf("choix set level 3\n");
                                level=3;
                            }
                            if(mouse_x>=362 && mouse_x<=642 && mouse_y>=510 && mouse_y<=580 && *progress>3)
                            {
                                printf("choix set level 4\n");
                                level=4;
                            }
                        }
                    }
                    if(multi==2)
                    {
                        level=5;
                    }
                    rest(20);
                }

                break;

            case 2:
                printf("choix case 2\n");
                ready = 0;
                do
                {

                    if (!mouse_b&1) /// pour qu il n'y ait pas de multi clicks
                    {
                        ready = 1;
                    }

                    change = 1;
                    if(mouse_b&1)
                    {

                        blit(img->regles,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                        if(mouse_x>=15 && mouse_x<=185 && mouse_y>=10 && mouse_y<=50  && ready ==1)
                        {
                            blit(img->menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                            change=0;
                        }
                    }
                    rest(20);
                }
                while(change == 1 && *mode==1);
                break;

            case 3:
                printf("choix case 3\n");
                ready = 0;
                exit(0);
                break;
            }
        }

        rest(20);
    }
    printf("Leave choix with level %d\n", level);
    return level;
}

void draw_sprites(t_images*img,BITMAP*page,char map[mapSizeY][mapSizeX +2], int* beginning, int* score,int*level)
{
    int i,j,k;

    for (i=0; i<13; i++)
    {
        for(j=0; j<13; j++)
        {
            if (map[j][i] == '#')
            {
                draw_sprite(page,img->tree,35+(i*46),10+j*38);
            }
            if (map[j][i] == 'c')
            {
                draw_sprite(page,img->crane,35+(i*46),10+j*38);
            }
            if (map[j][i] == 'h')
            {
                draw_sprite(page,img->hache,35+(i*46),10+j*38);
            }
            if (map[j][i] == 'b')
            {
                draw_sprite(page,img->bush,35+(i*46),10+j*38);
            }
            if (map[j][i] == 'a')
            {
                draw_sprite(page,img->ananas,35+(i*46),10+j*38);
            }
            if(*level==5)
            {
                if (map[j][i] == '1' && *beginning !=5)
                {
                    tabDeVikings[0].x=35+(i*46);
                    tabDeVikings[0].y=10+(j*38);
                    tabDeVikings[0].coordPY = j;
                    tabDeVikings[0].coordPX = i;
                    *beginning = *beginning+1;
                }
                if (map[j][i] == '2' && *beginning !=5)
                {
                    tabDeVikings[1].x=35+(i*46);
                    tabDeVikings[1].y=10+(j*38);
                    tabDeVikings[1].coordPY = j;
                    tabDeVikings[1].coordPX = i;
                    *beginning = *beginning+1;
                }
                if (map[j][i] == '3' && *beginning !=5)
                {
                    tabDeVikings[2].x=35+(i*46);
                    tabDeVikings[2].y=10+(j*38);
                    tabDeVikings[2].coordPY = j;
                    tabDeVikings[2].coordPX = i;
                    *beginning = *beginning+1;
                }
                if (map[j][i] == '4' && *beginning !=5)
                {
                    tabDeVikings[3].x=35+(i*46);
                    tabDeVikings[3].y=10+(j*38);
                    tabDeVikings[3].coordPY = j;
                    tabDeVikings[3].coordPX = i;
                    *beginning = *beginning+1;
                }
                if (map[j][i] == '5' && *beginning !=5)
                {
                    tabDeVikings[4].x=35+(i*46);
                    tabDeVikings[4].y=10+(j*38);
                    tabDeVikings[4].coordPY = j;
                    tabDeVikings[4].coordPX = i;
                    *beginning = *beginning+1;
                }
            }
            else
            {
                if (map[j][i] == '1' && *beginning ==0)
                {
                    tabDeVikings[0].x=35+(i*46);
                    tabDeVikings[0].y=10+(j*38);
                    tabDeVikings[0].coordPY = j;
                    tabDeVikings[0].coordPX = i;
                    *beginning = *beginning+1;
                }
            }

        }
    }
    draw_sprite(page,img->start,780,580);

    if(*level ==5)
    {
        draw_sprite(page,img->JAUNE,700,20);
        draw_sprite(page,img->BLEU,700,230);
        draw_sprite(page,img->ORANGE,700,160);
        draw_sprite(page,img->VERT,700,300);
        draw_sprite(page,img->BLANC,700,90);
        draw_sprite(page,img->PG1,700,370);
        draw_sprite(page,img->PG2,700,470);
    }
    else
    {
        draw_sprite(page,img->main,700,20);
        draw_sprite(page,img->PGT1,700,275);
        draw_sprite(page,img->PGT2,700,460);
    }


    for (i=0; i<3; i++)
    {
        draw_sprite(page,img->fleche[i],50+(i*80),600);
    }

    draw_sprite(page,img->destroy,370,600);


    for (i=0; i<2; i++)
    {
        draw_sprite(page,img->PG[i],450+(i*80),600);
    }


    textprintf_ex(page,font,3,6,makecol(0,0,0),-1,"Score : %d ",*score);
    textprintf_ex(page,font,5,6,makecol(0,0,0),-1,"Score : %d ",*score);
    textprintf_ex(page,font,4,5,makecol(0,0,0),-1,"Score : %d ",*score);
    textprintf_ex(page,font,4,7,makecol(0,0,0),-1,"Score : %d ",*score);
    textprintf_ex(page,font,4,6,makecol(255,255,255),-1,"Score : %d ",*score);
}


void lemove_solo(int tabm[12],int tabp1[8],int tabp2[4],int* start,int*endt,int*debm,int*debp1,int*debp2)
{
    int dagain=0;
    if(*start==1)
    {
        if(*endt==1)
        {
            if(*debp1==8)
            {
                *debp1=0;
                *debm=*debm+1;
            }
            if (tabm[*debm]==8)
            {
                tabDeVikings[0].bouge=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].turn=0;
            }
            if (tabm[*debm]==6) ///dir0haut  dir1bas dir2droite   dir3gauche
            {
                if(tabDeVikings[0].dir==0 && dagain==0)
                {
                    tabDeVikings[0].dir=2;
                    dagain=1;
                }
                if(tabDeVikings[0].dir==2 && dagain==0)
                {
                    tabDeVikings[0].dir=1;
                    dagain=1;
                }
                if(tabDeVikings[0].dir==1 && dagain==0)
                {
                    tabDeVikings[0].dir=3;
                    dagain=1;
                }
                if(tabDeVikings[0].dir==3 && dagain==0)
                {
                    tabDeVikings[0].dir=0;
                    dagain=1;
                }

                tabDeVikings[0].turn=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].bouge=1;
            }
            if (tabm[*debm]==2)
            {
                if(tabDeVikings[0].dir==0 && dagain==0)
                {
                    tabDeVikings[0].dir=3;
                    dagain=1;
                }
                if(tabDeVikings[0].dir==3 && dagain==0)
                {
                    tabDeVikings[0].dir=1;
                    dagain=1;
                }
                if(tabDeVikings[0].dir==1 && dagain==0)
                {
                    tabDeVikings[0].dir=2;
                    dagain=1;
                }
                if(tabDeVikings[0].dir==2 && dagain==0)
                {
                    tabDeVikings[0].dir=0;
                    dagain=1;
                }
                tabDeVikings[0].turn=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].bouge=1;
            }
            if (tabm[*debm]==7)
            {
                if (tabp1[*debp1]==8)
                {
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].turn=0;
                }
                if (tabp1[*debp1]==2)
                {
                    if(tabDeVikings[0].dir==0 && dagain==0)
                    {
                        tabDeVikings[0].dir=3;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==3 && dagain==0)
                    {
                        tabDeVikings[0].dir=1;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==1 && dagain==0)
                    {
                        tabDeVikings[0].dir=2;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==2 && dagain==0)
                    {
                        tabDeVikings[0].dir=0;
                        dagain=1;
                    }
                    tabDeVikings[0].turn=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].bouge=1;
                }
                if (tabp1[*debp1]==6)
                {
                    if(tabDeVikings[0].dir==0 && dagain==0)
                    {
                        tabDeVikings[0].dir=2;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==2 && dagain==0)
                    {
                        tabDeVikings[0].dir=1;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==1 && dagain==0)
                    {
                        tabDeVikings[0].dir=3;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==3 && dagain==0)
                    {
                        tabDeVikings[0].dir=0;
                        dagain=1;
                    }

                    tabDeVikings[0].turn=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].bouge=1;
                }
                if (tabp1[*debp1]==0)
                {
                    *debm=*debm+1;
                    *debp1=0;
                }

                if (tabp1[*debp1]==9)
                {
                    if (tabp2[*debp2]==8)
                    {
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].turn=0;
                    }
                    if (tabp2[*debp2]==2)
                    {
                        if(tabDeVikings[0].dir==0 && dagain==0)
                        {
                            tabDeVikings[0].dir=3;
                            dagain=1;
                        }
                        if(tabDeVikings[0].dir==3 && dagain==0)
                        {
                            tabDeVikings[0].dir=1;
                            dagain=1;
                        }
                        if(tabDeVikings[0].dir==1 && dagain==0)
                        {
                            tabDeVikings[0].dir=2;
                            dagain=1;
                        }
                        if(tabDeVikings[0].dir==2 && dagain==0)
                        {
                            tabDeVikings[0].dir=0;
                            dagain=1;
                        }
                        tabDeVikings[0].turn=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].bouge=1;
                    }
                    if (tabp2[*debp2]==6)
                    {
                        if(tabDeVikings[0].dir==0 && dagain==0)
                        {
                            tabDeVikings[0].dir=2;
                            dagain=1;
                        }
                        if(tabDeVikings[0].dir==2 && dagain==0)
                        {
                            tabDeVikings[0].dir=1;
                            dagain=1;
                        }
                        if(tabDeVikings[0].dir==1 && dagain==0)
                        {
                            tabDeVikings[0].dir=3;
                            dagain=1;
                        }
                        if(tabDeVikings[0].dir==3 && dagain==0)
                        {
                            tabDeVikings[0].dir=0;
                            dagain=1;
                        }

                        tabDeVikings[0].turn=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].bouge=1;
                    }
                    if (tabp2[*debp2]==0)
                    {
                        *debp1=*debp1+1;
                        *debp2=0;
                    }
                    if(*debp2==4)
                    {
                        *debp1=*debp1+1;
                        *debp2=0;
                    }

                }
            }
            if (tabm[*debm]==9)
            {
                if (tabp2[*debp2]==8)
                {
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].turn=0;
                }
                if (tabp2[*debp2]==2)
                {
                    if(tabDeVikings[0].dir==0 && dagain==0)
                    {
                        tabDeVikings[0].dir=3;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==3 && dagain==0)
                    {
                        tabDeVikings[0].dir=1;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==1 && dagain==0)
                    {
                        tabDeVikings[0].dir=2;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==2 && dagain==0)
                    {
                        tabDeVikings[0].dir=0;
                        dagain=1;
                    }
                    tabDeVikings[0].turn=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].bouge=1;
                }
                if (tabp2[*debp2]==6)
                {
                    if(tabDeVikings[0].dir==0 && dagain==0)
                    {
                        tabDeVikings[0].dir=2;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==2 && dagain==0)
                    {
                        tabDeVikings[0].dir=1;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==1 && dagain==0)
                    {
                        tabDeVikings[0].dir=3;
                        dagain=1;
                    }
                    if(tabDeVikings[0].dir==3 && dagain==0)
                    {
                        tabDeVikings[0].dir=0;
                        dagain=1;
                    }

                    tabDeVikings[0].turn=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].bouge=1;
                }
                if (tabp2[*debp2]==0)
                {
                    *debm=*debm+1;
                    *debp2=0;
                }
                 if (*debp2==8)
                {
                    *debm=*debm+1;
                    *debp2=0;
                }



            }
        }
    }
}




void lemove_multi(int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4], int tabpg2[4],
                  int* start,int*endt,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,
                  int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10)
{
    int i;
    int dagain=0;
    int dagain1=0;
    int dagain2=0;
    int dagain3=0;
    int dagain4=0;

    for(i=0; i<5; i++)
    {
        if (tabDeVikings[i].finish!=1 && tabDeVikings[i].stop !=1)
        {
            if(*start==1)
            {
                if(*endt==1)
                {
                    switch(i)
                    {
                    case 0:
                        ///V1
                        if (*dv1 <4 && dagain == 0)
                        {
                            if (tabv1[*dv1]==8)
                            {
                                tabDeVikings[0].bouge=1;
                                tabDeVikings[0].read=0;
                                tabDeVikings[0].turn=0;
                            }
                            if (tabv1[*dv1]==6) ///dir0haut  dir1bas dir2droite   dir3gauche
                            {

                                if(tabDeVikings[0].dir==0 && dagain==0)
                                {
                                    tabDeVikings[0].dir=2;
                                    dagain=1;
                                }
                                if(tabDeVikings[0].dir==2 && dagain==0)
                                {
                                    tabDeVikings[0].dir=1;
                                    dagain=1;
                                }
                                if(tabDeVikings[0].dir==1 && dagain==0)
                                {
                                    tabDeVikings[0].dir=3;
                                    dagain=1;
                                }
                                if(tabDeVikings[0].dir==3 && dagain==0)
                                {
                                    tabDeVikings[0].dir=0;
                                    dagain=1;
                                }

                                tabDeVikings[0].turn=1;
                                tabDeVikings[0].read=0;
                                tabDeVikings[0].bouge=1;
                            }
                            if (tabv1[*dv1]==2)
                            {
                                if(tabDeVikings[0].dir==0 && dagain==0)
                                {
                                    tabDeVikings[0].dir=3;
                                    dagain=1;
                                }
                                if(tabDeVikings[0].dir==3 && dagain==0)
                                {
                                    tabDeVikings[0].dir=1;
                                    dagain=1;
                                }
                                if(tabDeVikings[0].dir==1 && dagain==0)
                                {
                                    tabDeVikings[0].dir=2;
                                    dagain=1;
                                }
                                if(tabDeVikings[0].dir==2 && dagain==0)
                                {
                                    tabDeVikings[0].dir=0;
                                    dagain=1;
                                }
                                tabDeVikings[0].turn=1;
                                tabDeVikings[0].read=0;
                                tabDeVikings[0].bouge=1;
                            }
                            if (tabv1[*dv1]==7)
                            {
                                if (tabpg1[*dp1]==8)
                                {
                                    tabDeVikings[0].bouge=1;
                                    tabDeVikings[0].read=5;
                                    tabDeVikings[0].turn=0;
                                }
                                if (tabpg1[*dp1]==2)
                                {
                                    if(tabDeVikings[0].dir==0 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=3;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==3 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=1;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==1 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=2;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==2 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=0;
                                        dagain=1;
                                    }
                                    tabDeVikings[0].turn=1;
                                    tabDeVikings[0].read=5;
                                    tabDeVikings[0].bouge=1;
                                }
                                if (tabpg1[*dp1]==6)
                                {
                                    if(tabDeVikings[0].dir==0 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=2;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==2 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=1;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==1 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=3;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==3 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=0;
                                        dagain=1;
                                    }

                                    tabDeVikings[0].turn=1;
                                    tabDeVikings[0].read=5;
                                    tabDeVikings[0].bouge=1;
                                }
                                if (tabpg1[*dp1]==0)
                                {
                                    *dv1=*dv1+1;
                                    *dp1=0;
                                }

                            }
                            if (tabv1[*dv1]==9)
                            {
                                if (tabpg2[*dp2]==8)
                                {
                                    tabDeVikings[0].bouge=1;
                                    tabDeVikings[0].read=6;
                                    tabDeVikings[0].turn=0;
                                }
                                if (tabpg2[*dp2]==2)
                                {
                                    if(tabDeVikings[0].dir==0 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=3;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==3 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=1;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==1 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=2;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==2 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=0;
                                        dagain=1;
                                    }
                                    tabDeVikings[0].turn=1;
                                    tabDeVikings[0].read=6;
                                    tabDeVikings[0].bouge=1;
                                }
                                if (tabpg2[*dp2]==6)
                                {
                                    if(tabDeVikings[0].dir==0 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=2;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==2 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=1;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==1 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=3;
                                        dagain=1;
                                    }
                                    if(tabDeVikings[0].dir==3 && dagain==0)
                                    {
                                        tabDeVikings[0].dir=0;
                                        dagain=1;
                                    }

                                    tabDeVikings[0].turn=1;
                                    tabDeVikings[0].read=6;
                                    tabDeVikings[0].bouge=1;
                                }
                                if (tabpg2[*dp2]==0)
                                {
                                    *dv1=*dv1+1;
                                    *dp2=0;
                                }
                            }
                        }
                        break;
                    case 1:


                        ///V2
                        if (*dv2 <4 && dagain1==0)
                        {
                            if (tabv2[*dv2]==8)
                            {
                                tabDeVikings[1].bouge=1;
                                tabDeVikings[1].read=1;
                                tabDeVikings[1].turn=0;
                            }
                            if (tabv2[*dv2]==6) ///dir0haut  dir1bas dir2droite   dir3gauche
                            {
                                if(tabDeVikings[1].dir==0 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=2;
                                    dagain1=1;
                                }
                                if(tabDeVikings[1].dir==2 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=1;
                                    dagain1=1;
                                }
                                if(tabDeVikings[1].dir==1 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=3;
                                    dagain1=1;
                                }
                                if(tabDeVikings[1].dir==3 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=0;
                                    dagain1=1;
                                }

                                tabDeVikings[1].turn=1;
                                tabDeVikings[1].read=1;
                                tabDeVikings[1].bouge=1;
                            }
                            if (tabv2[*dv2]==2)
                            {
                                if(tabDeVikings[1].dir==0 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=3;
                                    dagain1=1;
                                }
                                if(tabDeVikings[1].dir==3 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=1;
                                    dagain1=1;
                                }
                                if(tabDeVikings[1].dir==1 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=2;
                                    dagain1=1;
                                }
                                if(tabDeVikings[1].dir==2 && dagain1==0)
                                {
                                    tabDeVikings[1].dir=0;
                                    dagain1=1;
                                }
                                tabDeVikings[1].turn=1;
                                tabDeVikings[1].read=1;
                                tabDeVikings[1].bouge=1;
                            }
                            if (tabv2[*dv2]==7)
                            {
                                if (tabpg1[*dp3]==8)
                                {
                                    tabDeVikings[1].bouge=1;
                                    tabDeVikings[1].read=7;
                                    tabDeVikings[1].turn=0;
                                }
                                if (tabpg1[*dp3]==2)
                                {
                                    if(tabDeVikings[1].dir==0 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=3;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==3 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=1;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==1 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=2;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==2 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=0;
                                        dagain1=1;
                                    }
                                    tabDeVikings[1].turn=1;
                                    tabDeVikings[1].read=7;
                                    tabDeVikings[1].bouge=1;
                                }
                                if (tabpg1[*dp3]==6)
                                {
                                    if(tabDeVikings[1].dir==0 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=2;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==2 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=1;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==1 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=3;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==3 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=0;
                                        dagain1=1;
                                    }

                                    tabDeVikings[1].turn=1;
                                    tabDeVikings[1].read=7;
                                    tabDeVikings[1].bouge=1;
                                }
                                if (tabpg1[*dp3]==0)
                                {
                                    *dv2=*dv2+1;
                                    *dp3=0;
                                }
                            }
                            if (tabv2[*dv2]==9)
                            {
                                if (tabpg2[*dp4]==8)
                                {
                                    tabDeVikings[1].bouge=1;
                                    tabDeVikings[1].read=8;
                                    tabDeVikings[1].turn=0;
                                }
                                if (tabpg2[*dp4]==2)
                                {
                                    if(tabDeVikings[1].dir==0 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=3;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==3 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=1;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==1 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=2;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==2 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=0;
                                        dagain1=1;
                                    }
                                    tabDeVikings[1].turn=1;
                                    tabDeVikings[1].read=8;
                                    tabDeVikings[1].bouge=1;
                                }
                                if (tabpg2[*dp4]==6)
                                {
                                    if(tabDeVikings[1].dir==0 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=2;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==2 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=1;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==1 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=3;
                                        dagain1=1;
                                    }
                                    if(tabDeVikings[1].dir==3 && dagain1==0)
                                    {
                                        tabDeVikings[1].dir=0;
                                        dagain1=1;
                                    }

                                    tabDeVikings[1].turn=1;
                                    tabDeVikings[1].read=8;
                                    tabDeVikings[1].bouge=1;
                                }
                                if (tabpg2[*dp4]==0)
                                {
                                    *dv2=*dv2+1;
                                    *dp4=0;
                                }
                            }
                        }
                        break;
                    case 2:

                        //V3
                        if (*dv3 <4 && dagain2==0)
                        {

                            if (tabv3[*dv3]==8)
                            {
                                tabDeVikings[2].bouge=1;
                                tabDeVikings[2].read=2;
                                tabDeVikings[2].turn=0;
                            }
                            if (tabv3[*dv3]==6) ///dir0haut  dir1bas dir2droite   dir3gauche
                            {

                                if(tabDeVikings[2].dir==0 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=2;
                                    dagain2=1;
                                }
                                if(tabDeVikings[2].dir==2 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=1;
                                    dagain2=1;
                                }
                                if(tabDeVikings[2].dir==1 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=3;
                                    dagain2=1;
                                }
                                if(tabDeVikings[2].dir==3 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=0;
                                    dagain2=1;
                                }

                                tabDeVikings[2].turn=1;
                                tabDeVikings[2].read=2;
                                tabDeVikings[2].bouge=1;
                            }
                            if (tabv3[*dv3]==2)
                            {
                                if(tabDeVikings[2].dir==0 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=3;
                                    dagain2=1;
                                }
                                if(tabDeVikings[2].dir==3 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=1;
                                    dagain2=1;
                                }
                                if(tabDeVikings[2].dir==1 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=2;
                                    dagain2=1;
                                }
                                if(tabDeVikings[2].dir==2 && dagain2==0)
                                {
                                    tabDeVikings[2].dir=0;
                                    dagain2=1;
                                }
                                tabDeVikings[2].turn=1;
                                tabDeVikings[2].read=2;
                                tabDeVikings[2].bouge=1;
                            }
                            if (tabv3[*dv3]==7)
                            {
                                if (tabpg1[*dp5]==8)
                                {
                                    tabDeVikings[2].bouge=1;
                                    tabDeVikings[2].read=9;
                                    tabDeVikings[2].turn=0;
                                }
                                if (tabpg1[*dp5]==2)
                                {
                                    if(tabDeVikings[2].dir==0 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=3;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==3 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=1;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==1 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=2;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==2 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=0;
                                        dagain2=1;
                                    }
                                    tabDeVikings[2].turn=1;
                                    tabDeVikings[2].read=9;
                                    tabDeVikings[2].bouge=1;
                                }
                                if (tabpg1[*dp5]==6)
                                {
                                    if(tabDeVikings[2].dir==0 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=2;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==2 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=1;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==1 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=3;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==3 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=0;
                                        dagain2=1;
                                    }

                                    tabDeVikings[2].turn=1;
                                    tabDeVikings[2].read=9;
                                    tabDeVikings[2].bouge=1;
                                }
                                if (tabpg1[*dp5]==0)
                                {
                                    *dv3=*dv3+1;
                                    *dp5=0;
                                }

                            }
                            if (tabv3[*dv3]==9)
                            {
                                if (tabpg2[*dp6]==8)
                                {
                                    tabDeVikings[2].bouge=1;
                                    tabDeVikings[2].read=10;
                                    tabDeVikings[2].turn=0;
                                }
                                if (tabpg2[*dp6]==2)
                                {
                                    if(tabDeVikings[2].dir==0 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=3;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==3 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=1;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==1 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=2;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==2 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=0;
                                        dagain2=1;
                                    }
                                    tabDeVikings[2].turn=1;
                                    tabDeVikings[2].read=10;
                                    tabDeVikings[2].bouge=1;
                                }
                                if (tabpg2[*dp6]==6)
                                {
                                    if(tabDeVikings[2].dir==0 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=2;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==2 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=1;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==1 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=3;
                                        dagain2=1;
                                    }
                                    if(tabDeVikings[2].dir==3 && dagain2==0)
                                    {
                                        tabDeVikings[2].dir=0;
                                        dagain2=1;
                                    }

                                    tabDeVikings[2].turn=1;
                                    tabDeVikings[2].read=10;
                                    tabDeVikings[2].bouge=1;
                                }
                                if (tabpg2[*dp6]==0)
                                {
                                    *dv3=*dv3+1;
                                    *dp6=0;
                                }
                            }
                        }
                        break;
                    case 3:



                        //V4
                        if (*dv4 <4 && dagain3==0)
                        {

                            if (tabv4[*dv4]==8)
                            {
                                tabDeVikings[3].bouge=1;
                                tabDeVikings[3].read=3;
                                tabDeVikings[3].turn=0;
                            }
                            if (tabv4[*dv4]==6) ///dir0haut  dir1bas dir2droite   dir3gauche
                            {

                                if(tabDeVikings[3].dir==0 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=2;
                                    dagain3=1;
                                }
                                if(tabDeVikings[3].dir==2 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=1;
                                    dagain3=1;
                                }
                                if(tabDeVikings[3].dir==1 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=3;
                                    dagain3=1;
                                }
                                if(tabDeVikings[3].dir==3 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=0;
                                    dagain3=1;
                                }

                                tabDeVikings[3].turn=1;
                                tabDeVikings[3].read=3;
                                tabDeVikings[3].bouge=1;
                            }
                            if (tabv4[*dv4]==2)
                            {
                                if(tabDeVikings[3].dir==0 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=3;
                                    dagain3=1;
                                }
                                if(tabDeVikings[3].dir==3 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=1;
                                    dagain3=1;
                                }
                                if(tabDeVikings[3].dir==1 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=2;
                                    dagain3=1;
                                }
                                if(tabDeVikings[3].dir==2 && dagain3==0)
                                {
                                    tabDeVikings[3].dir=0;
                                    dagain3=1;
                                }
                                tabDeVikings[3].turn=1;
                                tabDeVikings[3].read=3;
                                tabDeVikings[3].bouge=1;
                            }
                            if (tabv4[*dv4]==7)
                            {
                                if (tabpg1[*dp7]==8)
                                {
                                    tabDeVikings[3].bouge=1;
                                    tabDeVikings[3].read=11;
                                    tabDeVikings[3].turn=0;
                                }
                                if (tabpg1[*dp7]==2)
                                {
                                    if(tabDeVikings[3].dir==0 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=3;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==3 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=1;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==1 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=2;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==2 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=0;
                                        dagain3=1;
                                    }
                                    tabDeVikings[3].turn=1;
                                    tabDeVikings[3].read=11;
                                    tabDeVikings[3].bouge=1;
                                }
                                if (tabpg1[*dp7]==6)
                                {
                                    if(tabDeVikings[3].dir==0 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=2;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==2 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=1;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==1 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=3;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==3 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=0;
                                        dagain3=1;
                                    }

                                    tabDeVikings[3].turn=1;
                                    tabDeVikings[3].read=11;
                                    tabDeVikings[3].bouge=1;
                                }
                                if (tabpg1[*dp7]==0)
                                {
                                    printf("coucou");
                                    *dv4=*dv4+1;
                                    *dp7=0;
                                }

                            }
                            if (tabv4[*dv4]==9)
                            {
                                if (tabpg2[*dp8]==8)
                                {
                                    tabDeVikings[3].bouge=1;
                                    tabDeVikings[3].read=12;
                                    tabDeVikings[3].turn=0;
                                }
                                if (tabpg2[*dp8]==2)
                                {
                                    if(tabDeVikings[3].dir==0 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=3;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==3 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=1;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==1 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=2;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==2 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=0;
                                        dagain3=1;
                                    }
                                    tabDeVikings[3].turn=1;
                                    tabDeVikings[3].read=12;
                                    tabDeVikings[3].bouge=1;
                                }
                                if (tabpg2[*dp8]==6)
                                {
                                    if(tabDeVikings[3].dir==0 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=2;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==2 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=1;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==1 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=3;
                                        dagain3=1;
                                    }
                                    if(tabDeVikings[3].dir==3 && dagain3==0)
                                    {
                                        tabDeVikings[3].dir=0;
                                        dagain3=1;
                                    }

                                    tabDeVikings[3].turn=1;
                                    tabDeVikings[3].read=12;
                                    tabDeVikings[3].bouge=1;
                                }
                                if (tabpg2[*dp8]==0)
                                {
                                    *dv4=*dv4+1;
                                    *dp8=0;
                                }
                            }
                        }
                        break;
                    case 4:


                        //V5




                        if (*dv5 <4 && dagain4==0)
                        {

                            if (tabv5[*dv5]==8)
                            {
                                tabDeVikings[4].bouge=1;
                                tabDeVikings[4].read=4;
                                tabDeVikings[4].turn=0;
                            }
                            if (tabv5[*dv5]==6) ///dir0haut  dir1bas dir2droite   dir3gauche
                            {

                                if(tabDeVikings[4].dir==0 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=2;
                                    dagain4=1;
                                }
                                if(tabDeVikings[4].dir==2 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=1;
                                    dagain4=1;
                                }
                                if(tabDeVikings[4].dir==1 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=3;
                                    dagain4=1;
                                }
                                if(tabDeVikings[4].dir==3 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=0;
                                    dagain4=1;
                                }

                                tabDeVikings[4].turn=1;
                                tabDeVikings[4].read=4;
                                tabDeVikings[4].bouge=1;
                            }
                            if (tabv5[*dv5]==2)
                            {
                                if(tabDeVikings[4].dir==0 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=3;
                                    dagain4=1;
                                }
                                if(tabDeVikings[4].dir==3 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=1;
                                    dagain4=1;
                                }
                                if(tabDeVikings[4].dir==1 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=2;
                                    dagain4=1;
                                }
                                if(tabDeVikings[4].dir==2 && dagain4==0)
                                {
                                    tabDeVikings[4].dir=0;
                                    dagain4=1;
                                }
                                tabDeVikings[4].turn=1;
                                tabDeVikings[4].read=4;
                                tabDeVikings[4].bouge=1;
                            }
                            if (tabv5[*dv5]==7)
                            {
                                if (tabpg1[*dp9]==8)
                                {
                                    tabDeVikings[4].bouge=1;
                                    tabDeVikings[4].read=13;
                                    tabDeVikings[4].turn=0;
                                }
                                if (tabpg1[*dp9]==2)
                                {
                                    if(tabDeVikings[4].dir==0 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=3;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==3 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=1;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==1 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=2;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==2 && dagain3==0)
                                    {
                                        tabDeVikings[4].dir=0;
                                        dagain4=1;
                                    }
                                    tabDeVikings[4].turn=1;
                                    tabDeVikings[4].read=13;
                                    tabDeVikings[4].bouge=1;
                                }
                                if (tabpg1[*dp9]==6)
                                {
                                    if(tabDeVikings[4].dir==0 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=2;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==2 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=1;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==1 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=3;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==3 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=0;
                                        dagain4=1;
                                    }

                                    tabDeVikings[4].turn=1;
                                    tabDeVikings[4].read=13;
                                    tabDeVikings[4].bouge=1;
                                }
                                if (tabpg1[*dp9]==0)
                                {
                                    printf("vloup");
                                    *dv5=*dv5+1;
                                    *dp9=0;
                                }
                            }
                            if (tabv5[*dv5]==9)
                            {
                                if (tabpg2[*dp10]==8)
                                {
                                    tabDeVikings[4].bouge=1;
                                    tabDeVikings[4].read=14;
                                    tabDeVikings[4].turn=0;
                                }
                                if (tabpg2[*dp10]==2)
                                {
                                    if(tabDeVikings[4].dir==0 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=3;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==3 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=1;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==1 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=2;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==2 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=0;
                                        dagain4=1;
                                    }
                                    tabDeVikings[4].turn=1;
                                    tabDeVikings[4].read=14;
                                    tabDeVikings[4].bouge=1;
                                }
                                if (tabpg2[*dp10]==6)
                                {
                                    if(tabDeVikings[4].dir==0 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=2;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==2 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=1;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==1 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=3;
                                        dagain4=1;
                                    }
                                    if(tabDeVikings[4].dir==3 && dagain4==0)
                                    {
                                        tabDeVikings[4].dir=0;
                                        dagain4=1;
                                    }

                                    tabDeVikings[4].turn=1;
                                    tabDeVikings[4].read=14;
                                    tabDeVikings[4].bouge=1;
                                }
                                if (tabpg2[*dp10]==0)
                                {
                                    *dv5=*dv5+1;
                                    *dp10=0;
                                }
                            }
                        }
                        break;
                    }
                }

            }
        }
    }
}





void actions_solo(char map[mapSizeY][mapSizeX +2],int*debm,int*debp1,int*debp2,int tabm[12],int tabp1[8],int tabp2[4],int*start,int*endt)
{
    int i,j;

    if(*start==1)
    {
        if(*endt==1)
        {
            if (tabm[*debm]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
            {
                map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                tabDeVikings[0].bouge=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].turn=1;
            }

            if (tabm[*debm]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
            {
                map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                tabDeVikings[0].bouge=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].turn=1;
            }

            if (tabm[*debm]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
            {
                map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                tabDeVikings[0].bouge=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].turn=1;
            }

            if (tabm[*debm] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
            {
                map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                tabDeVikings[0].bouge=1;
                tabDeVikings[0].read=0;
                tabDeVikings[0].turn=1;
            }
            for(i=-1; i<2; i++)
            {
                for(j=-1; j<2; j++)
                {
                    if (tabm[*debm] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                    {
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=0;
                        tabDeVikings[0].turn=1;
                    }
                }
            }

            if(tabm[*debm]==7)
            {
                if (tabp1[*debp1]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
                {
                    map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].turn=1;
                }

                if (tabp1[*debp1]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
                {
                    map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].turn=1;
                }

                if (tabp1[*debp1]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
                {
                    map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].turn=1;
                }

                if (tabp1[*debp1] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
                {
                    map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=1;
                    tabDeVikings[0].turn=1;
                }


                for(i=-1; i<2; i++)
                {
                    for(j=-1; j<2; j++)
                    {
                        if (tabp1[*debp1] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                        {
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=1;
                            tabDeVikings[0].turn=1;
                        }
                    }
                }
                if(tabp1[*debp1]==9)
                {
                    if (tabp2[*debp2]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
                    {
                        map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].turn=1;
                    }

                    if (tabp2[*debp2]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
                    {
                        map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].turn=1;
                    }

                    if (tabp2[*debp2]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
                    {
                        map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].turn=1;
                    }

                    if (tabp2[*debp2] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
                    {
                        map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=2;
                        tabDeVikings[0].turn=1;
                    }

                    for(i=-1; i<2; i++)
                    {
                        for(j=-1; j<2; j++)
                        {
                            if (tabp2[*debp2] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                            {
                                tabDeVikings[0].bouge=1;
                                tabDeVikings[0].read=2;
                                tabDeVikings[0].turn=1;
                            }
                        }
                    }
                }
            }

            if(tabm[*debm]==9)
            {
                if (tabp2[*debp2]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
                {
                    map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].turn=1;
                }

                if (tabp2[*debp2]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
                {
                    map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].turn=1;
                }

                if (tabp2[*debp2]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
                {
                    map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].turn=1;
                }

                if (tabp2[*debp2] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
                {
                    map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                    tabDeVikings[0].bouge=1;
                    tabDeVikings[0].read=2;
                    tabDeVikings[0].turn=1;
                }

                for(i=-1; i<2; i++)
                {
                    for(j=-1; j<2; j++)
                    {
                        if (tabp2[*debp2] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                        {
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=2;
                            tabDeVikings[0].turn=1;
                        }
                    }
                }
            }

        }
    }
}









void actions_multi(char map[mapSizeY][mapSizeX +2],int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],
                   int tabpg2[4],int* start,int*endt,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10)
{
    int i,j,k;

    for(k=0; k<5; k++)
    {

        if(tabDeVikings[k].finish !=1 && tabDeVikings[k].stop !=1)
        {


            if(*start==1)
            {
                if(*endt==1)
                {
                    if (tabv1[*dv1]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
                    {
                        map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=0;
                        tabDeVikings[0].turn=1;
                    }

                    if (tabv1[*dv1]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
                    {
                        map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=0;
                        tabDeVikings[0].turn=1;
                    }

                    if (tabv1[*dv1]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
                    {
                        map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=0;
                        tabDeVikings[0].turn=1;
                    }

                    if (tabv1[*dv1] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
                    {
                        map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                        tabDeVikings[0].bouge=1;
                        tabDeVikings[0].read=0;
                        tabDeVikings[0].turn=1;
                    }
                    for(i=-1; i<2; i++)
                    {
                        for(j=-1; j<2; j++)
                        {
                            if (tabv1[*dv1] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                            {
                                tabDeVikings[0].bouge=1;
                                tabDeVikings[0].read=0;
                                tabDeVikings[0].turn=1;
                            }
                        }
                    }

                    if(tabv1[*dv1]==7)
                    {
                        if (tabpg1[*dp1]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
                        {
                            map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=5;
                            tabDeVikings[0].turn=1;
                        }

                        if (tabpg1[*dp1]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
                        {
                            map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=5;
                            tabDeVikings[0].turn=1;
                        }

                        if (tabpg1[*dp1]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
                        {
                            map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=5;
                            tabDeVikings[0].turn=1;
                        }

                        if (tabpg1[*dp1] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
                        {
                            map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=5;
                            tabDeVikings[0].turn=1;
                        }


                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg1[*dp1] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[0].bouge=1;
                                    tabDeVikings[0].read=5;
                                    tabDeVikings[0].turn=1;
                                }
                            }
                        }
                    }

                    if(tabv1[*dv1]==9)
                    {
                        if (tabpg2[*dp2]==1 && (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 0)
                        {
                            map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=6;
                            tabDeVikings[0].turn=1;
                        }

                        if (tabpg2[*dp2]==1 && (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] == 'b')&& tabDeVikings[0].dir == 1)
                        {
                            map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=6;
                            tabDeVikings[0].turn=1;
                        }

                        if (tabpg2[*dp2]==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] == 'b')&& tabDeVikings[0].dir == 2)
                        {
                            map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=6;
                            tabDeVikings[0].turn=1;
                        }

                        if (tabpg2[*dp2] ==1 && (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] == 'b')&& tabDeVikings[0].dir == 3)
                        {
                            map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] = '.';
                            tabDeVikings[0].bouge=1;
                            tabDeVikings[0].read=6;
                            tabDeVikings[0].turn=1;
                        }

                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg2[*dp2] ==1 && (map[(tabDeVikings[0].coordPY)+i][(tabDeVikings[0].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[0].bouge=1;
                                    tabDeVikings[0].read=6;
                                    tabDeVikings[0].turn=1;
                                }
                            }
                        }
                    }





                    if (tabv2[*dv2]==1 && (map[(tabDeVikings[1].coordPY)-1][tabDeVikings[1].coordPX] == 'b')&& tabDeVikings[1].dir == 0)
                    {
                        map[(tabDeVikings[1].coordPY)-1][tabDeVikings[1].coordPX] = '.';
                        tabDeVikings[1].bouge=1;
                        tabDeVikings[1].read=1;
                        tabDeVikings[1].turn=1;
                    }

                    if (tabv2[*dv2]==1 && (map[(tabDeVikings[1].coordPY)+1][tabDeVikings[1].coordPX] == 'b')&& tabDeVikings[1].dir == 1)
                    {
                        map[(tabDeVikings[1].coordPY)+1][tabDeVikings[1].coordPX] = '.';
                        tabDeVikings[1].bouge=1;
                        tabDeVikings[1].read=1;
                        tabDeVikings[1].turn=1;
                    }

                    if (tabv2[*dv2]==1 && (map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)+1] == 'b')&& tabDeVikings[1].dir == 2)
                    {
                        map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)+1] = '.';
                        tabDeVikings[1].bouge=1;
                        tabDeVikings[1].read=1;
                        tabDeVikings[1].turn=1;
                    }

                    if (tabv2[*dv2] ==1 && (map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)-1] == 'b')&& tabDeVikings[1].dir == 3)
                    {
                        map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)-1] = '.';
                        tabDeVikings[1].bouge=1;
                        tabDeVikings[1].read=1;
                        tabDeVikings[1].turn=1;
                    }
                    for(i=-1; i<2; i++)
                    {
                        for(j=-1; j<2; j++)
                        {
                            if (tabv2[*dv2] ==1 && (map[(tabDeVikings[1].coordPY)+i][(tabDeVikings[1].coordPX)+j] != 'b'))
                            {
                                tabDeVikings[1].bouge=1;
                                tabDeVikings[1].read=1;
                                tabDeVikings[1].turn=1;
                            }
                        }
                    }

                    if(tabv2[*dv2]==7)
                    {
                        if (tabpg1[*dp3]==1 && (map[(tabDeVikings[1].coordPY)-1][tabDeVikings[1].coordPX] == 'b')&& tabDeVikings[1].dir == 0)
                        {
                            map[(tabDeVikings[1].coordPY)-1][tabDeVikings[1].coordPX] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=7;
                            tabDeVikings[1].turn=1;
                        }

                        if (tabpg1[*dp3]==1 && (map[(tabDeVikings[1].coordPY)+1][tabDeVikings[1].coordPX] == 'b')&& tabDeVikings[1].dir == 1)
                        {
                            map[(tabDeVikings[1].coordPY)+1][tabDeVikings[1].coordPX] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=7;
                            tabDeVikings[1].turn=1;
                        }

                        if (tabpg1[*dp3]==1 && (map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)+1] == 'b')&& tabDeVikings[1].dir == 2)
                        {
                            map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)+1] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=7;
                            tabDeVikings[1].turn=1;
                        }

                        if (tabpg1[*dp3] ==1 && (map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)-1] == 'b')&& tabDeVikings[1].dir == 3)
                        {
                            map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)-1] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=7;
                            tabDeVikings[1].turn=1;
                        }


                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg1[*dp3] ==1 && (map[(tabDeVikings[1].coordPY)+i][(tabDeVikings[1].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[1].bouge=1;
                                    tabDeVikings[1].read=7;
                                    tabDeVikings[1].turn=1;
                                }
                            }
                        }
                    }

                    if(tabv2[*dv2]==9)
                    {
                        if (tabpg2[*dp4]==1 && (map[(tabDeVikings[1].coordPY)-1][tabDeVikings[1].coordPX] == 'b')&& tabDeVikings[1].dir == 0)
                        {
                            map[(tabDeVikings[1].coordPY)-1][tabDeVikings[1].coordPX] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=8;
                            tabDeVikings[1].turn=1;
                        }

                        if (tabpg2[*dp4]==1 && (map[(tabDeVikings[1].coordPY)+1][tabDeVikings[1].coordPX] == 'b')&& tabDeVikings[1].dir == 1)
                        {
                            map[(tabDeVikings[1].coordPY)+1][tabDeVikings[1].coordPX] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=8;
                            tabDeVikings[1].turn=1;
                        }

                        if (tabpg2[*dp4]==1 && (map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)+1] == 'b')&& tabDeVikings[1].dir == 2)
                        {
                            map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)+1] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=8;
                            tabDeVikings[1].turn=1;
                        }

                        if (tabpg2[*dp4] ==1 && (map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)-1] == 'b')&& tabDeVikings[1].dir == 3)
                        {
                            map[tabDeVikings[1].coordPY][(tabDeVikings[1].coordPX)-1] = '.';
                            tabDeVikings[1].bouge=1;
                            tabDeVikings[1].read=8;
                            tabDeVikings[1].turn=1;
                        }

                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg2[*dp4] ==1 && (map[(tabDeVikings[1].coordPY)+i][(tabDeVikings[1].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[1].bouge=1;
                                    tabDeVikings[1].read=8;
                                    tabDeVikings[1].turn=1;
                                }
                            }
                        }
                    }







                    if (tabv3[*dv3]==1 && (map[(tabDeVikings[2].coordPY)-1][tabDeVikings[2].coordPX] == 'b')&& tabDeVikings[2].dir == 0)
                    {
                        map[(tabDeVikings[2].coordPY)-1][tabDeVikings[2].coordPX] = '.';
                        tabDeVikings[2].bouge=1;
                        tabDeVikings[2].read=2;
                        tabDeVikings[2].turn=1;
                    }

                    if (tabv3[*dv3]==1 && (map[(tabDeVikings[2].coordPY)+1][tabDeVikings[2].coordPX] == 'b')&& tabDeVikings[2].dir == 1)
                    {
                        map[(tabDeVikings[2].coordPY)+1][tabDeVikings[2].coordPX] = '.';
                        tabDeVikings[2].bouge=1;
                        tabDeVikings[2].read=2;
                        tabDeVikings[2].turn=1;
                    }

                    if (tabv3[*dv3]==1 && (map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)+1] == 'b')&& tabDeVikings[2].dir == 2)
                    {
                        map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)+1] = '.';
                        tabDeVikings[2].bouge=1;
                        tabDeVikings[2].read=2;
                        tabDeVikings[2].turn=1;
                    }

                    if (tabv3[*dv3] ==1 && (map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] == 'b')&& tabDeVikings[2].dir == 3)
                    {
                        map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] = '.';
                        tabDeVikings[2].bouge=1;
                        tabDeVikings[2].read=2;
                        tabDeVikings[2].turn=1;
                    }
                    for(i=-1; i<2; i++)
                    {
                        for(j=-1; j<2; j++)
                        {
                            if (tabv3[*dv3] ==1 && (map[(tabDeVikings[2].coordPY)+i][(tabDeVikings[2].coordPX)+j] != 'b'))
                            {
                                tabDeVikings[2].bouge=1;
                                tabDeVikings[2].read=2;
                                tabDeVikings[2].turn=1;
                            }
                        }
                    }

                    if(tabv3[*dv3]==7)
                    {
                        if (tabpg1[*dp5]==1 && (map[(tabDeVikings[2].coordPY)-1][tabDeVikings[2].coordPX] == 'b')&& tabDeVikings[2].dir == 0)
                        {
                            map[(tabDeVikings[2].coordPY)-1][tabDeVikings[2].coordPX] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=9;
                            tabDeVikings[2].turn=1;
                        }

                        if (tabpg1[*dp5]==1 && (map[(tabDeVikings[2].coordPY)+1][tabDeVikings[2].coordPX] == 'b')&& tabDeVikings[2].dir == 1)
                        {
                            map[(tabDeVikings[2].coordPY)+1][tabDeVikings[2].coordPX] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=9;
                            tabDeVikings[2].turn=1;
                        }

                        if (tabpg1[*dp5]==1 && (map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)+1] == 'b')&& tabDeVikings[2].dir == 2)
                        {
                            map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)+1] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=9;
                            tabDeVikings[2].turn=1;
                        }

                        if (tabpg1[*dp5] ==1 && (map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] == 'b')&& tabDeVikings[2].dir == 3)
                        {
                            map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=9;
                            tabDeVikings[2].turn=1;
                        }


                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg1[*dp5] ==1 && (map[(tabDeVikings[2].coordPY)+i][(tabDeVikings[2].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[2].bouge=1;
                                    tabDeVikings[2].read=9;
                                    tabDeVikings[2].turn=1;
                                }
                            }
                        }
                    }

                    if(tabv3[*dv3]==9)
                    {
                        if (tabpg2[*dp6]==1 && (map[(tabDeVikings[2].coordPY)-1][tabDeVikings[2].coordPX] == 'b')&& tabDeVikings[2].dir == 0)
                        {
                            map[(tabDeVikings[2].coordPY)-1][tabDeVikings[2].coordPX] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=10;
                            tabDeVikings[2].turn=1;
                        }

                        if (tabpg2[*dp6]==1 && (map[(tabDeVikings[2].coordPY)+1][tabDeVikings[2].coordPX] == 'b')&& tabDeVikings[2].dir == 1)
                        {
                            map[(tabDeVikings[2].coordPY)+1][tabDeVikings[2].coordPX] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=10;
                            tabDeVikings[2].turn=1;
                        }

                        if (tabpg2[*dp6]==1 && (map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)+1] == 'b')&& tabDeVikings[2].dir == 2)
                        {
                            map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)+1] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=10;
                            tabDeVikings[2].turn=1;
                        }

                        if (tabpg2[*dp6] ==1 && (map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] == 'b')&& tabDeVikings[2].dir == 3)
                        {
                            map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] = '.';
                            tabDeVikings[2].bouge=1;
                            tabDeVikings[2].read=10;
                            tabDeVikings[2].turn=1;
                        }

                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg2[*dp6] ==1 && (map[(tabDeVikings[2].coordPY)+i][(tabDeVikings[2].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[2].bouge=1;
                                    tabDeVikings[2].read=10;
                                    tabDeVikings[2].turn=1;
                                }
                            }
                        }
                    }




                    if (tabv4[*dv4]==1 && (map[(tabDeVikings[3].coordPY)-1][tabDeVikings[3].coordPX] == 'b')&& tabDeVikings[3].dir == 0)
                    {
                        map[(tabDeVikings[3].coordPY)-1][tabDeVikings[3].coordPX] = '.';
                        tabDeVikings[3].bouge=1;
                        tabDeVikings[3].read=3;
                        tabDeVikings[3].turn=1;
                    }

                    if (tabv4[*dv4]==1 && (map[(tabDeVikings[3].coordPY)+1][tabDeVikings[3].coordPX] == 'b')&& tabDeVikings[3].dir == 1)
                    {
                        map[(tabDeVikings[3].coordPY)+1][tabDeVikings[3].coordPX] = '.';
                        tabDeVikings[3].bouge=1;
                        tabDeVikings[3].read=3;
                        tabDeVikings[3].turn=1;
                    }

                    if (tabv4[*dv4]==1 && (map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)+1] == 'b')&& tabDeVikings[3].dir == 2)
                    {
                        map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)+1] = '.';
                        tabDeVikings[3].bouge=1;
                        tabDeVikings[3].read=3;
                        tabDeVikings[3].turn=1;
                    }

                    if (tabv4[*dv4] ==1 && (map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)-1] == 'b')&& tabDeVikings[3].dir == 3)
                    {
                        map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)-1] = '.';
                        tabDeVikings[3].bouge=1;
                        tabDeVikings[3].read=3;
                        tabDeVikings[3].turn=1;
                    }
                    for(i=-1; i<2; i++)
                    {
                        for(j=-1; j<2; j++)
                        {
                            if (tabv4[*dv4] ==1 && (map[(tabDeVikings[3].coordPY)+i][(tabDeVikings[3].coordPX)+j] != 'b'))
                            {
                                tabDeVikings[3].bouge=1;
                                tabDeVikings[3].read=3;
                                tabDeVikings[3].turn=1;
                            }
                        }
                    }

                    if(tabv4[*dv4]==7)
                    {
                        if (tabpg1[*dp7]==1 && (map[(tabDeVikings[3].coordPY)-1][tabDeVikings[3].coordPX] == 'b')&& tabDeVikings[3].dir == 0)
                        {
                            map[(tabDeVikings[3].coordPY)-1][tabDeVikings[3].coordPX] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=11;
                            tabDeVikings[3].turn=1;
                        }

                        if (tabpg1[*dp7]==1 && (map[(tabDeVikings[3].coordPY)+1][tabDeVikings[3].coordPX] == 'b')&& tabDeVikings[3].dir == 1)
                        {
                            map[(tabDeVikings[3].coordPY)+1][tabDeVikings[3].coordPX] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=11;
                            tabDeVikings[3].turn=1;
                        }

                        if (tabpg1[*dp7]==1 && (map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)+1] == 'b')&& tabDeVikings[3].dir == 2)
                        {
                            map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)+1] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=11;
                            tabDeVikings[3].turn=1;
                        }

                        if (tabpg1[*dp7] ==1 && (map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)-1] == 'b')&& tabDeVikings[3].dir == 3)
                        {
                            map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)-1] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=11;
                            tabDeVikings[3].turn=1;
                        }


                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg1[*dp1] ==1 && (map[(tabDeVikings[3].coordPY)+i][(tabDeVikings[3].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[3].bouge=1;
                                    tabDeVikings[3].read=5;
                                    tabDeVikings[3].turn=1;
                                }
                            }
                        }
                    }

                    if(tabv4[*dv4]==9)
                    {
                        if (tabpg2[*dp8]==1 && (map[(tabDeVikings[3].coordPY)-1][tabDeVikings[3].coordPX] == 'b')&& tabDeVikings[3].dir == 0)
                        {
                            map[(tabDeVikings[3].coordPY)-1][tabDeVikings[3].coordPX] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=12;
                            tabDeVikings[3].turn=1;
                        }

                        if (tabpg2[*dp8]==1 && (map[(tabDeVikings[3].coordPY)+1][tabDeVikings[3].coordPX] == 'b')&& tabDeVikings[3].dir == 1)
                        {
                            map[(tabDeVikings[3].coordPY)+1][tabDeVikings[3].coordPX] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=12;
                            tabDeVikings[3].turn=1;
                        }

                        if (tabpg2[*dp8]==1 && (map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)+1] == 'b')&& tabDeVikings[3].dir == 2)
                        {
                            map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)+1] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=12;
                            tabDeVikings[3].turn=1;
                        }

                        if (tabpg2[*dp8] ==1 && (map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)-1] == 'b')&& tabDeVikings[3].dir == 3)
                        {
                            map[tabDeVikings[3].coordPY][(tabDeVikings[3].coordPX)-1] = '.';
                            tabDeVikings[3].bouge=1;
                            tabDeVikings[3].read=12;
                            tabDeVikings[3].turn=1;
                        }

                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg2[*dp8] ==1 && (map[(tabDeVikings[3].coordPY)+i][(tabDeVikings[3].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[3].bouge=1;
                                    tabDeVikings[3].read=12;
                                    tabDeVikings[3].turn=1;
                                }
                            }
                        }
                    }




                    if (tabv5[*dv5]==1 && (map[(tabDeVikings[4].coordPY)-1][tabDeVikings[4].coordPX] == 'b')&& tabDeVikings[4].dir == 0)
                    {
                        map[(tabDeVikings[4].coordPY)-1][tabDeVikings[4].coordPX] = '.';
                        tabDeVikings[4].bouge=1;
                        tabDeVikings[4].read=4;
                        tabDeVikings[4].turn=1;
                    }

                    if (tabv5[*dv5]==1 && (map[(tabDeVikings[4].coordPY)+1][tabDeVikings[4].coordPX] == 'b')&& tabDeVikings[4].dir == 1)
                    {
                        map[(tabDeVikings[4].coordPY)+1][tabDeVikings[4].coordPX] = '.';
                        tabDeVikings[4].bouge=1;
                        tabDeVikings[4].read=4;
                        tabDeVikings[4].turn=1;
                    }

                    if (tabv5[*dv5]==1 && (map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)+1] == 'b')&& tabDeVikings[4].dir == 2)
                    {
                        map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)+1] = '.';
                        tabDeVikings[4].bouge=1;
                        tabDeVikings[4].read=4;
                        tabDeVikings[4].turn=1;
                    }

                    if (tabv5[*dv5] ==1 && (map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)-1] == 'b')&& tabDeVikings[4].dir == 3)
                    {
                        map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)-1] = '.';
                        tabDeVikings[4].bouge=1;
                        tabDeVikings[4].read=4;
                        tabDeVikings[4].turn=1;
                    }
                    for(i=-1; i<2; i++)
                    {
                        for(j=-1; j<2; j++)
                        {
                            if (tabv5[*dv5] ==1 && (map[(tabDeVikings[4].coordPY)+i][(tabDeVikings[4].coordPX)+j] != 'b'))
                            {
                                tabDeVikings[4].bouge=1;
                                tabDeVikings[4].read=4;
                                tabDeVikings[4].turn=1;
                            }
                        }
                    }

                    if(tabv5[*dv5]==7)
                    {
                        if (tabpg1[*dp9]==1 && (map[(tabDeVikings[4].coordPY)-1][tabDeVikings[4].coordPX] == 'b')&& tabDeVikings[4].dir == 0)
                        {
                            map[(tabDeVikings[4].coordPY)-1][tabDeVikings[4].coordPX] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=13;
                            tabDeVikings[4].turn=1;
                        }

                        if (tabpg1[*dp9]==1 && (map[(tabDeVikings[4].coordPY)+1][tabDeVikings[4].coordPX] == 'b')&& tabDeVikings[4].dir == 1)
                        {
                            map[(tabDeVikings[4].coordPY)+1][tabDeVikings[4].coordPX] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=13;
                            tabDeVikings[4].turn=1;
                        }

                        if (tabpg1[*dp9]==1 && (map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)+1] == 'b')&& tabDeVikings[4].dir == 2)
                        {
                            map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)+1] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=13;
                            tabDeVikings[4].turn=1;
                        }

                        if (tabpg1[*dp9] ==1 && (map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)-1] == 'b')&& tabDeVikings[4].dir == 3)
                        {
                            map[tabDeVikings[2].coordPY][(tabDeVikings[2].coordPX)-1] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=13;
                            tabDeVikings[4].turn=1;
                        }


                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg1[*dp9] ==1 && (map[(tabDeVikings[4].coordPY)+i][(tabDeVikings[4].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[4].bouge=1;
                                    tabDeVikings[4].read=13;
                                    tabDeVikings[4].turn=1;
                                }
                            }
                        }
                    }

                    if(tabv5[*dv5]==9)
                    {
                        if (tabpg2[*dp10]==1 && (map[(tabDeVikings[4].coordPY)-1][tabDeVikings[4].coordPX] == 'b')&& tabDeVikings[4].dir == 0)
                        {
                            map[(tabDeVikings[4].coordPY)-1][tabDeVikings[4].coordPX] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=14;
                            tabDeVikings[4].turn=1;
                        }

                        if (tabpg2[*dp10]==1 && (map[(tabDeVikings[4].coordPY)+1][tabDeVikings[4].coordPX] == 'b')&& tabDeVikings[4].dir == 1)
                        {
                            map[(tabDeVikings[4].coordPY)+1][tabDeVikings[4].coordPX] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=14;
                            tabDeVikings[4].turn=1;
                        }

                        if (tabpg2[*dp10]==1 && (map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)+1] == 'b')&& tabDeVikings[4].dir == 2)
                        {
                            map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)+1] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=14;
                            tabDeVikings[4].turn=1;
                        }

                        if (tabpg2[*dp10] ==1 && (map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)-1] == 'b')&& tabDeVikings[4].dir == 3)
                        {
                            map[tabDeVikings[4].coordPY][(tabDeVikings[4].coordPX)-1] = '.';
                            tabDeVikings[4].bouge=1;
                            tabDeVikings[4].read=14;
                            tabDeVikings[4].turn=1;
                        }

                        for(i=-1; i<2; i++)
                        {
                            for(j=-1; j<2; j++)
                            {
                                if (tabpg2[*dp10] ==1 && (map[(tabDeVikings[4].coordPY)+i][(tabDeVikings[4].coordPX)+j] != 'b'))
                                {
                                    tabDeVikings[4].bouge=1;
                                    tabDeVikings[4].read=14;
                                    tabDeVikings[4].turn=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}




void score_win(t_images*img,char map[mapSizeY][mapSizeX +2],int*score,int*win,t_sons*SON,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int*dv1,int*dv2,int*dv3,int*dv4,int*dv5)
{
    int k;

    for(k=0; k<5; k++)
    {
        if(map[tabDeVikings[k].coordPY][tabDeVikings[k].coordPX] == 'c')
        {
            map[tabDeVikings[k].coordPY][tabDeVikings[k].coordPX]='.';
            *score-=100;
            ///ICI TU JOUES LE SON LINK_HURT
            play_sample(SON->son4,120,120,1000,0);
        }

        if(map[tabDeVikings[k].coordPY][tabDeVikings[k].coordPX] == 'a')
        {
            map[tabDeVikings[k].coordPY][tabDeVikings[k].coordPX] = '.';
            *score+=50;
            ///ICI TU JOUES LE SON CANE_MAGIC
            play_sample(SON->son2,120,120,1000,0);
        }

        if(map[tabDeVikings[k].coordPY][tabDeVikings[k].coordPX] == 'h')
        {
            map[tabDeVikings[k].coordPY][tabDeVikings[k].coordPX]='.';
            *score+=100;
            tabDeVikings[k].win = 1;
            tabDeVikings[k].finish=1;
            tabDeVikings[k].lose=1;
            ///ICI TU JOUES LE SON FAIRY
            play_sample(SON->son1,120,120,1000,0);


        }

    }
}

void if_move(char map[mapSizeY][mapSizeX +2])
{
    int k;

    for(k=0; k<5; k++)
    {
        if(tabDeVikings[k].finish!=1 && tabDeVikings[k].stop !=1)
        {


            switch(tabDeVikings[k].dir)
            {
            case HAUT :
                if(tabDeVikings[k].y>25 && ((map[(tabDeVikings[k].coordPY)-1][tabDeVikings[k].coordPX] != '#')&&(map[(tabDeVikings[k].coordPY)-1][tabDeVikings[k].coordPX] != 'b'))&&(tabDeVikings[k].bouge==1)&&(tabDeVikings[k].turn==0))
                    tabDeVikings[k].y-=1.9;
                break;

            case BAS :
                if(tabDeVikings[k].y<470 && ((map[(tabDeVikings[k].coordPY)+1][tabDeVikings[k].coordPX] != '#')&&(map[(tabDeVikings[k].coordPY)+1][tabDeVikings[k].coordPX] != 'b'))&&(tabDeVikings[k].bouge==1)&&(tabDeVikings[k].turn==0))
                    tabDeVikings[k].y+=1.9;
                break;

            case DROITE :
                if(tabDeVikings[k].x<590 && ((map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)+1] != '#')&&(map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)+1] != 'b'))&&(tabDeVikings[k].bouge==1)&&(tabDeVikings[k].turn==0))
                    tabDeVikings[k].x+=2.30;
                break;

            case GAUCHE :
                if(tabDeVikings[k].x>40 && ((map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)-1] != '#')&&(map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)-1] != 'b'))&&(tabDeVikings[k].bouge==1)&&(tabDeVikings[k].turn==0))
                    tabDeVikings[k].x-=2.30;
                break;
            }
        }
    }
}

void pause(t_images*img,int*mode,BITMAP*page)
{

    blit(img->pause,page,0,0,0,0,SCREEN_W,SCREEN_H);

    if (mouse_x>=405 && mouse_x<=690 && mouse_y>=240 && mouse_y<=310 && mouse_b&1 )
    {
        return *mode = 2;
    }
    if (mouse_x>=405 && mouse_x<=690 && mouse_y>=390 && mouse_y<=460 && mouse_b&1 )
    {
        blit(img->menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        return *mode =1;
    }
    if (mouse_x>=405 && mouse_x<=690 && mouse_y>=540 && mouse_y<=610&& mouse_b&1 )
    {
        exit(0);
    }

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void drag_drop_multi(t_images*img,int*drag,BITMAP*page,int* start,int *level,
                     int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],int tabpg2[4],
                     int* v1,int* v2,int* v3,int* v4,int* v5, int* p1, int *p2)
{
    int i=0;

    if(mouse_x >= 370 && mouse_x <= 420 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton destroy
    {
        *drag =1;
    }

    if(mouse_x >= 50 && mouse_x <= 100 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton fleche haut
    {
        *drag =8;
    }

    if(mouse_x >= 130 && mouse_x <= 180 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton fleche droite
    {
        *drag =6;
    }

    if(mouse_x >= 210 && mouse_x <= 260 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton bas
    {
        *drag =2;
    }

    if(mouse_x >= 290 && mouse_x <= 340 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton gauche
    {
        *drag =4;
    }

    if(mouse_x >= 450 && mouse_x <= 500 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton PG[0]
    {
        *drag =7;
    }

    if(mouse_x >= 530 && mouse_x <= 580 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton PG[1]
    {
        *drag =9;
    }
    if(mouse_x >= 780 && mouse_x <= 880 && mouse_y >=580 && mouse_y <=680 &&mouse_b&1 && *start==0)
    {
        *start=1 ;
    }
    if(*v1 >=0 && *v1<=4)
    {
        for(i=0; i<*v1; i++)
        {
            if( tabv1[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,27);
            }
            if( tabv1[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,27);
            }
            if( tabv1[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,27);
            }
            if( tabv1[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,27);
            }
            if( tabv1[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,27);
            }
            if( tabv1[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,27);
            }
        }
    }
    if(*v2 >=0 && *v2<=4)
    {
        for(i=0; i<*v2; i++)
        {
            if( tabv2[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,97);
            }
            if( tabv2[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,97);
            }
            if( tabv2[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,97);
            }
            if( tabv2[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,97);
            }
            if( tabv2[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,97);
            }
            if( tabv2[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,97);
            }
        }
    }
    if(*v3 >=0 && *v3<=4)
    {
        for(i=0; i<*v3; i++)
        {
            if( tabv3[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,167);
            }
            if( tabv3[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,167);
            }
            if( tabv3[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,167);
            }
            if( tabv3[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,167);
            }
            if( tabv3[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,167);
            }
            if( tabv3[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,167);
            }
        }
    }
    if(*v4 >=0 && *v4<=4)
    {
        for(i=0; i<*v4; i++)
        {
            if( tabv4[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,237);
            }
            if( tabv4[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,237);
            }
            if( tabv4[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,237);
            }
            if( tabv4[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,237);
            }
            if( tabv4[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,237);
            }
            if( tabv4[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,237);
            }
        }
    }
    if(*v5 >=0 && *v5<=4)
    {
        for(i=0; i<*v5; i++)
        {
            if( tabv5[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,307);
            }
            if( tabv5[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,307);
            }
            if( tabv5[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,307);
            }
            if( tabv5[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,307);
            }
            if( tabv5[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,307);
            }
            if( tabv5[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,307);
            }
        }
    }
    if(*p1 >=0 && *p1<=4)
    {
        for(i=0; i<*p1; i++)
        {
            if( tabpg1[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,407);
            }
            if( tabpg1[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,407);
            }
            if( tabpg1[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,407);
            }
            if( tabpg1[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,407);
            }
            if( tabpg1[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,407);
            }
            if( tabpg1[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,407);
            }
        }
    }
    if(*p2 >=0 && *p2<=4)
    {
        for(i=0; i<*p2; i++)
        {
            if( tabpg2[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,507);
            }
            if( tabpg2[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,507);
            }
            if( tabpg2[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,507);
            }
            if( tabpg2[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,507);
            }
            if( tabpg2[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,507);
            }
            if( tabpg2[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,507);
            }
        }
    }
    if (*drag==1)///bouton destroy
    {
        draw_sprite(page,img->destroy,mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=80 &&mouse_b&2 && tabv1[3]==0)
        {
            tabv1[*v1]=1;
            *v1=*v1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=90 && mouse_y <=150 &&mouse_b&2 && tabv2[3]==0)
        {
            tabv2[*v2]=1;
            *v2=*v2+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=165 && mouse_y <=225 &&mouse_b&2 && tabv3[3]==0)
        {
            tabv3[*v3]=1;
            *v3=*v3+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=235 && mouse_y <=295 &&mouse_b&2 && tabv4[3]==0)
        {
            tabv4[*v4]=1;
            *v4=*v4+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=305 && mouse_y <=365 &&mouse_b&2 && tabv5[3]==0)
        {
            tabv5[*v5]=1;
            *v5=*v5+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=375 && mouse_y <=460 &&mouse_b&2 && tabpg1[3]==0)
        {
            tabpg1[*p1]=1;
            *p1=*p1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=470 && mouse_y <=560 &&mouse_b&2 && tabpg2[3]==0)
        {
            tabpg2[*p2]=1;
            *p2=*p2+1 ;
            *drag=0 ;
        }
    }

    if (*drag==8)///fleche haut
    {
        draw_sprite(page,img->fleche[0],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=80 &&mouse_b&2 && tabv1[3]==0)
        {
            tabv1[*v1]=8;
            *v1=*v1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=90 && mouse_y <=150 &&mouse_b&2 && tabv2[3]==0)
        {
            tabv2[*v2]=8;
            *v2=*v2+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=165 && mouse_y <=225 &&mouse_b&2 && tabv3[3]==0)
        {
            tabv3[*v3]=8;
            *v3=*v3+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=235 && mouse_y <=295 &&mouse_b&2 && tabv4[3]==0)
        {
            tabv4[*v4]=8;
            *v4=*v4+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=305 && mouse_y <=365 &&mouse_b&2 && tabv5[3]==0)
        {
            tabv5[*v5]=8;
            *v5=*v5+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=375 && mouse_y <=460 &&mouse_b&2 && tabpg1[3]==0)
        {
            tabpg1[*p1]=8;
            *p1=*p1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=470 && mouse_y <=560 &&mouse_b&2 && tabpg2[3]==0)
        {
            tabpg2[*p2]=8;
            *p2=*p2+1 ;
            *drag=0 ;
        }
    }
    if (*drag==6)///fleche droite
    {
        draw_sprite(page,img->fleche[1],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=80 &&mouse_b&2 && tabv1[3]==0)
        {
            tabv1[*v1]=6;
            *v1=*v1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=90 && mouse_y <=150 &&mouse_b&2 && tabv2[3]==0)
        {
            tabv2[*v2]=6;
            *v2=*v2+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=165 && mouse_y <=225 &&mouse_b&2 && tabv3[3]==0)
        {
            tabv3[*v3]=6;
            *v3=*v3+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=235 && mouse_y <=295 &&mouse_b&2 && tabv4[3]==0)
        {
            tabv4[*v4]=6;
            *v4=*v4+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=305 && mouse_y <=365 &&mouse_b&2 && tabv5[3]==0)
        {
            tabv5[*v5]=6;
            *v5=*v5+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=375 && mouse_y <=460 &&mouse_b&2 && tabpg1[3]==0)
        {
            tabpg1[*p1]=6;
            *p1=*p1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=470 && mouse_y <=560 &&mouse_b&2 && tabpg2[3]==0)
        {
            tabpg2[*p2]=6;
            *p2=*p2+1 ;
            *drag=0 ;
        }
    }
    if (*drag==2)///fleche bas
    {
        draw_sprite(page,img->fleche[2],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=80 &&mouse_b&2 && tabv1[3]==0)
        {
            tabv1[*v1]=2;
            *v1=*v1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=90 && mouse_y <=150 &&mouse_b&2 && tabv2[3]==0)
        {
            tabv2[*v2]=2;
            *v2=*v2+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=165 && mouse_y <=225 &&mouse_b&2 && tabv3[3]==0)
        {
            tabv3[*v3]=2;
            *v3=*v3+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=235 && mouse_y <=295 &&mouse_b&2 && tabv4[3]==0)
        {
            tabv4[*v4]=2;
            *v4=*v4+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=305 && mouse_y <=365 &&mouse_b&2 && tabv5[3]==0)
        {
            tabv5[*v5]=2;
            *v5=*v5+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=375 && mouse_y <=460 &&mouse_b&2 && tabpg1[3]==0)
        {
            tabpg1[*p1]=2;
            *p1=*p1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=470 && mouse_y <=560 &&mouse_b&2 && tabpg2[3]==0)
        {
            tabpg2[*p2]=2;
            *p2=*p2+1 ;
            *drag=0 ;
        }
    }
    if (*drag==7)///fleche bas
    {
        draw_sprite(page,img->PG[0],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=80 &&mouse_b&2 && tabv1[3]==0)
        {
            tabv1[*v1]=7;
            *v1=*v1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=90 && mouse_y <=150 &&mouse_b&2 && tabv2[3]==0)
        {
            tabv2[*v2]=7;
            *v2=*v2+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=165 && mouse_y <=225 &&mouse_b&2 && tabv3[3]==0)
        {
            tabv3[*v3]=7;
            *v3=*v3+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=235 && mouse_y <=295 &&mouse_b&2 && tabv4[3]==0)
        {
            tabv4[*v4]=7;
            *v4=*v4+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=305 && mouse_y <=365 &&mouse_b&2 && tabv5[3]==0)
        {
            tabv5[*v5]=7;
            *v5=*v5+1 ;
            *drag=0 ;
        }
    }
    if (*drag==9)///fleche bas
    {
        draw_sprite(page,img->PG[1],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=80 &&mouse_b&2 && tabv1[3]==0)
        {
            tabv1[*v1]=9;
            *v1=*v1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=90 && mouse_y <=150 &&mouse_b&2 && tabv2[3]==0)
        {
            tabv2[*v2]=9;
            *v2=*v2+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=165 && mouse_y <=225 &&mouse_b&2 && tabv3[3]==0)
        {
            tabv3[*v3]=9;
            *v3=*v3+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=235 && mouse_y <=295 &&mouse_b&2 && tabv4[3]==0)
        {
            tabv4[*v4]=9;
            *v4=*v4+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=305 && mouse_y <=365 &&mouse_b&2 && tabv5[3]==0)
        {
            tabv5[*v5]=9;
            *v5=*v5+1 ;
            *drag=0 ;
        }
    }
}


void drag_drop_solo(t_images*img,int*drag,BITMAP*page,int* main,int*PG1,int*PG2,int tabm[12],int tabp1[8],int tabp2[4],int* start,int *level)
{

    int i=0;

    if(mouse_x >= 370 && mouse_x <= 420 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton destroy
    {
        *drag =1;
    }

    if(mouse_x >= 50 && mouse_x <= 100 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton fleche haut
    {
        *drag =8;
    }

    if(mouse_x >= 130 && mouse_x <= 180 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton fleche droite
    {
        *drag =6;
    }

    if(mouse_x >= 210 && mouse_x <= 260 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton bas
    {
        *drag =2;
    }

    if(mouse_x >= 290 && mouse_x <= 340 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton gauche
    {
        *drag =4;
    }

    if(mouse_x >= 450 && mouse_x <= 500 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton PG[0]
    {
        *drag =7;
    }

    if(mouse_x >= 530 && mouse_x <= 580 && mouse_y >=600 && mouse_y <=650 && mouse_b&1) ///bouton PG[1]
    {
        *drag =9;
    }
    if(mouse_x >= 780 && mouse_x <= 880 && mouse_y >=580 && mouse_y <=680 &&mouse_b&1 && *start==0)
    {
        *start=1 ;
    }
    if(*main >=0 && *main<4)
    {

        for(i=0; i<*main; i++)
        {
            if( tabm[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,70);
            }
            if( tabm[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,70);
            }
            if( tabm[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,70);
            }
            if( tabm[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,70);
            }
            if( tabm[i]==7)
            {
                draw_sprite(page,img->PG[0],710+60*i,70);
            }
            if( tabm[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,70);
            }

        }
    }


    if(*main >=4 && *main<8)
    {
        for(i=0; i<*main; i++)
        {
            if( tabm[i]==1)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->destroy,710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->destroy,470+60*i,130);
                }
            }
            if( tabm[i]==8)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[0],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[0],470+60*i,130);
                }
            }
            if( tabm[i]==6)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[1],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[1],470+60*i,130);
                }
            }
            if( tabm[i]==2)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[2],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[2],470+60*i,130);
                }
            }

            if( tabm[i]==7)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->PG[0],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->PG[0],470+60*i,130);
                }
            }
            if( tabm[i]==9)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->PG[1],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->PG[1],470+60*i,130);
                }
            }
        }
    }


    if(*main >=8 && *main<=12)
    {
        for(i=0; i<*main; i++)
        {
            if( tabm[i]==1)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->destroy,710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->destroy,470+60*i,130);
                }
                if(i>=8 && i<=12)
                {
                    draw_sprite(page,img->destroy,230+60*i,190);
                }
            }
            if( tabm[i]==8)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[0],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[0],470+60*i,130);
                }
                if(i>=8 && i<=12)
                {
                    draw_sprite(page,img->fleche[0],230+60*i,190);
                }
            }
            if( tabm[i]==6)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[1],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[1],470+60*i,130);
                }
                if(i>=8 && i<=12)
                {
                    draw_sprite(page,img->fleche[1],230+60*i,190);
                }
            }
            if( tabm[i]==2)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[2],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[2],470+60*i,130);
                }
                if(i>=8 && i<=12)
                {
                    draw_sprite(page,img->fleche[2],230+60*i,190);
                }
            }

            if( tabm[i]==7)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->PG[0],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->PG[0],470+60*i,130);
                }
                if(i>=8 && i<=12)
                {
                    draw_sprite(page,img->PG[0],230+60*i,190);
                }
            }
            if( tabm[i]==9)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->PG[1],710+60*i,70);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->PG[1],470+60*i,130);
                }
                if(i>=8 && i<=12)
                {
                    draw_sprite(page,img->PG[1],230+60*i,190);
                }
            }
        }

    }
    if(*PG1 >=0 && *PG1<4)
    {

        for(i=0; i<*PG1; i++)
        {
            if( tabp1[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,320);
            }
            if( tabp1[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,320);
            }
            if( tabp1[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,320);
            }
            if( tabp1[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,320);
            }

            if( tabp1[i]==9)
            {
                draw_sprite(page,img->PG[1],710+60*i,320);
            }
        }
    }

    if(*PG1 >=4 && *PG1<=8)
    {
        for(i=0; i<*PG1; i++)
        {
            if( tabp1[i]==1)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->destroy,710+60*i,320);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->destroy,470+60*i,380);
                }
            }
            if( tabp1[i]==8)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[0],710+60*i,320);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[0],470+60*i,380);
                }
            }
            if( tabp1[i]==6)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[1],710+60*i,320);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[1],470+60*i,380);
                }
            }
            if( tabp1[i]==2)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->fleche[2],710+60*i,320);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->fleche[2],470+60*i,380);
                }
            }

            if( tabp1[i]==9)
            {
                if(i>=0 && i<4)
                {
                    draw_sprite(page,img->PG[1],710+60*i,320);
                }
                if(i>=4 && i<8)
                {
                    draw_sprite(page,img->PG[1],470+60*i,380);
                }
            }
        }
    }
    if(*PG2 >=0 && *PG2<=4)
    {

        for(i=0; i<*PG2; i++)
        {
            if( tabp2[i]==1)
            {
                draw_sprite(page,img->destroy,710+60*i,500);
            }
            if( tabp2[i]==8)
            {
                draw_sprite(page,img->fleche[0],710+60*i,500);
            }
            if( tabp2[i]==6)
            {
                draw_sprite(page,img->fleche[1],710+60*i,500);
            }
            if( tabp2[i]==2)
            {
                draw_sprite(page,img->fleche[2],710+60*i,500);
            }

        }
    }


    if (*drag==1)///bouton destroy
    {
        draw_sprite(page,img->destroy,mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=265 &&mouse_b&2 && tabm[11]==0)
        {
            tabm[*main]=1;
            *main=*main+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=280 && mouse_y <=450 &&mouse_b&2 && tabp1[7]==0)
        {
            tabp1[*PG1]=1;
            *PG1=*PG1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=460 && mouse_y <=550 &&mouse_b&2 && tabp2[3]==0)
        {
            tabp2[*PG2]=1;
            *PG2=*PG2+1 ;
            *drag=0 ;
        }
    }

    if (*drag==8)///fleche haut
    {
        draw_sprite(page,img->fleche[0],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=265 &&mouse_b&2 && tabm[11]==0)
        {
            tabm[*main]=8;
            *main=*main+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=280 && mouse_y <=450 &&mouse_b&2 && tabp1[7]==0)
        {
            tabp1[*PG1]=8;
            *PG1=*PG1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=460 && mouse_y <=550 &&mouse_b&2 && tabp2[3]==0)
        {
            tabp2[*PG2]=8;
            *PG2=*PG2+1 ;
            *drag=0 ;
        }
    }
    if (*drag==6)///fleche droite
    {
        draw_sprite(page,img->fleche[1],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=265 &&mouse_b&2 && tabm[11]==0)
        {
            tabm[*main]=6;
            *main=*main+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=280 && mouse_y <=450 &&mouse_b&2 && tabp1[7]==0)
        {
            tabp1[*PG1]=6;
            *PG1=*PG1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=460 && mouse_y <=550 &&mouse_b&2 && tabp2[3]==0)
        {
            tabp2[*PG2]=6;
            *PG2=*PG2+1 ;
            *drag=0 ;
        }
    }
    if (*drag==2)///fleche bas
    {
        draw_sprite(page,img->fleche[2],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=265 &&mouse_b&2 && tabm[11]==0)
        {
            tabm[*main]=2;
            *main=*main+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=280 && mouse_y <=450 &&mouse_b&2 && tabp1[7]==0)
        {
            tabp1[*PG1]=2;
            *PG1=*PG1+1 ;
            *drag=0 ;
        }
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=460 && mouse_y <=550 &&mouse_b&2 && tabp2[3]==0)
        {
            tabp2[*PG2]=2;
            *PG2=*PG2+1 ;
            *drag=0 ;
        }
    }


    if (*drag==7)///PG[0]
    {
        draw_sprite(page,img->PG[0],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=265 &&mouse_b&2 && tabm[11]==0)
        {
            tabm[*main]=7;
            *main=*main+1 ;
            *drag=0 ;
        }
    }

    if (*drag==9)///PG[1]
    {
        draw_sprite(page,img->PG[1],mouse_x-25,mouse_y-25);
        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=20 && mouse_y <=265 &&mouse_b&2 && tabm[11]==0)
        {
            tabm[*main]=9;
            *main=*main+1 ;
            *drag=0 ;
        }

        if(mouse_x >= 700 && mouse_x <= 940 && mouse_y >=280 && mouse_y <=450 &&mouse_b&2 && tabp1[7]==0)
        {
            tabp1[*PG1]=9;
            *PG1=*PG1+1 ;
            *drag=0 ;
        }
    }
}




SAMPLE * load_sample_check(char*nomSon)
{
    t_sons*son;
    son=load_sample(nomSon);
    if (!son)
    {
        printf("Couldn't load sample!");
    }

}

void charger_sons(t_sons* SON)
{
    SON->son1=load_sample_check("cane_Magic.wav");
    SON->son2=load_sample_check("get_Item.wav");
    SON->son3=load_sample_check("victory.wav");
    SON->son4=load_sample_check("Link_hurt.wav");

}

void reset_solo(int*beginning,int*main,int*PG1,int*PG2,int*start,int*debm,int*debp1,int*debp2,int*score,int tabm[12],int tabp1[8],int tabp2[4],int*drag,int*son)
{
    int i;
    *beginning =0;
    tabDeVikings[0].dir=1;
    tabDeVikings[0].win=0;
    tabDeVikings[0].lose=0;
    tabDeVikings[0].bouge=0;
    tabDeVikings[0].finish=0;
    *score =0;
    *main=0;
    *PG1=0;
    *PG2=0;
    *start=0;
    *debm=0;
    *debp1=0;
    *debp2=0;
    *drag=0;
    *son=0;
    for(i=0; i<12; i++)
    {
        tabm[i]=0;
    }
    for(i=0; i<8; i++)
    {
        tabp1[i]=0;
    }
    for(i=0; i<4; i++)
    {
        tabp2[i]=0;
    }
}

void reset_multi(int*beginning,int*start,int*v1,int*v2,int*v3,int*v4,int*v5,int*p1,int*p2,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,
                 int*score,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],int tabpg2[4],int*drag,int*son,int*vicm,int*losm,
                 int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10)
{
    int i;
    *beginning =0;
    for(i=0; i<5; i++)
    {
        tabDeVikings[i].win=0;
        tabDeVikings[i].lose=0;
        tabDeVikings[i].finish=0;
        tabDeVikings[i].stop=0;
        tabDeVikings[i].dir=1;
        tabDeVikings[i].bouge=0;
    }
    *vicm=0;
    *losm=0;
    *score =0;
    *p1=0;
    *p2=0;
    *start=0;
    *v1=0;
    *v2=0;
    *v3=0;
    *v4=0;
    *v5=0;

    *dp1=0;
    *dp2=0;
    *dp3=0;
    *dp4=0;
    *dp5=0;
    *dp6=0;
    *dp7=0;
    *dp8=0;
    *dp9=0;
    *dp10=0;

    *dv1=0;
    *dv2=0;
    *dv3=0;
    *dv4=0;
    *dv5=0;
    *drag=0;
    *son=0;
    for(i=0; i<4 ; i++)
    {
        tabv1[i]=0;
        tabv2[i]=0;
        tabv3[i]=0;
        tabv4[i]=0;
        tabv5[i]=0;
        tabpg1[i]=0;
        tabpg2[i]=0;
    }
}

void bouger_solo(char map[mapSizeY][mapSizeX +2],int*endt,int*debm,int*debp1,int*debp2)
{
    if (tabDeVikings[0].bouge)
    {
        tabDeVikings[0].bouge_depuis=tabDeVikings[0].bouge_depuis+1;
        *endt=0;

        if (tabDeVikings[0].bouge_depuis>=20)
        {
            *endt=1;
            tabDeVikings[0].bouge=0;
            tabDeVikings[0].bouge_depuis=0;

            if(tabDeVikings[0].read==0)
            {
                *debm=*debm+1;
            }
            if(tabDeVikings[0].read==1)
            {
                *debp1=*debp1+1;
            }
            if(tabDeVikings[0].read==2)
            {
                *debp2=*debp2+1;
            }



            if(tabDeVikings[0].turn==0)
            {
                switch(tabDeVikings[0].dir)
                {
                case 0:
                    if((map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX] != '#')&& (map[(tabDeVikings[0].coordPY)-1][tabDeVikings[0].coordPX]!='b'))
                        tabDeVikings[0].coordPY--;
                    break;

                case 1:
                    if((map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX] != '#')&& (map[(tabDeVikings[0].coordPY)+1][tabDeVikings[0].coordPX]!='b'))
                        tabDeVikings[0].coordPY++;
                    break;

                case 2:
                    if((map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1] != '#')&& (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)+1]!='b'))
                        tabDeVikings[0].coordPX ++;
                    break;

                case 3:
                    if((map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1] != '#')&& (map[tabDeVikings[0].coordPY][(tabDeVikings[0].coordPX)-1]!='b'))
                        tabDeVikings[0].coordPX --;
                    break;
                }
            }
            if(tabDeVikings[0].bouge_depuis==20)
            {
                if(tabDeVikings[0].turn==1)
                {
                    tabDeVikings[0].turn=0;
                }
            }
        }
    }
}

void bouger_multi(char map[mapSizeY][mapSizeX +2],int*endt,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,
                  int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10)
{
    int k;
    int dagain =0;
    int dagain2 =0;
    int dagain3 =0;
    int dagain4 =0;
    int dagain5 =0;
    int dagain6 =0;
    int dagain7 =0;
    int dagain8= 0;
    int dagain9=0;
    int dagain10=0;
    int dagain11=0;
    int dagain12=0;
    int dagain13=0;
    int dagain14=0;
    int dagain15=0;



    for(k=0; k<5; k++)
    {
        if(tabDeVikings[k].finish!=1 && tabDeVikings[k].stop !=1)
        {
            if (tabDeVikings[k].bouge)
            {
                tabDeVikings[k].bouge_depuis=tabDeVikings[k].bouge_depuis+1;
                *endt=0;

                if (tabDeVikings[k].bouge_depuis>=20)
                {
                    *endt=1;
                    tabDeVikings[k].bouge=0;
                    tabDeVikings[k].bouge_depuis=0;

                    if(tabDeVikings[k].read==0 && dagain == 0)
                    {
                        *dv1=*dv1+1;
                        dagain = 1;
                    }
                    if(tabDeVikings[k].read==1 && dagain2 == 0)
                    {
                        *dv2=*dv2+1;
                        dagain2 = 1;
                    }
                    if(tabDeVikings[k].read==2 && dagain3 == 0)
                    {
                        *dv3=*dv3+1;
                        dagain3 = 1;
                    }
                    if(tabDeVikings[k].read==3 && dagain4 == 0)
                    {
                        *dv4=*dv4+1;
                        dagain4 = 1;
                    }

                    if(tabDeVikings[k].read==4 && dagain5 == 0)
                    {
                        *dv5=*dv5+1;
                        dagain5 = 1;
                    }

                    if(tabDeVikings[k].read==5 && dagain6 == 0)
                    {
                        *dp1=*dp1+1;
                        dagain6 = 1;
                    }

                    if(tabDeVikings[k].read==6 && dagain7 == 0)
                    {
                        *dp2=*dp2+1;
                        dagain7 = 1;
                    }

                    if(tabDeVikings[k].read==7 && dagain8 == 0)
                    {
                        *dp3=*dp3+1;
                        dagain8 = 1;
                    }

                    if(tabDeVikings[k].read==8 && dagain9 == 0)
                    {
                        *dp4=*dp4+1;
                        dagain9 = 1;
                    }

                    if(tabDeVikings[k].read==9 && dagain10 == 0)
                    {
                        *dp5=*dp5+1;
                        dagain10 = 1;
                    }

                    if(tabDeVikings[k].read==10 && dagain11 == 0)
                    {
                        *dp6=*dp6+1;
                        dagain11 = 1;
                    }

                    if(tabDeVikings[k].read==11 && dagain12 == 0)
                    {
                        *dp7=*dp7+1;
                        dagain12 = 1;
                    }

                    if(tabDeVikings[k].read==12 && dagain13 == 0)
                    {
                        *dp8=*dp8+1;
                        dagain13 = 1;
                    }

                    if(tabDeVikings[k].read==13 && dagain14 == 0)
                    {
                        *dp9=*dp9+1;
                        dagain14 = 1;
                    }

                    if(tabDeVikings[k].read==14 && dagain15 == 0)
                    {
                        *dp10=*dp10+1;
                        dagain15 = 1;
                    }

                    if(*dp9==4)
                    {
                        *dp9=0;
                        *dv5=*dv5+1;
                    }

                    if(*dp3==4)
                    {
                        *dp3=0;
                        *dv2=*dv2+1;
                    }


                    if(tabDeVikings[k].turn==0)
                    {
                        switch(tabDeVikings[k].dir)
                        {
                        case 0:
                            if((map[(tabDeVikings[k].coordPY)-1][tabDeVikings[k].coordPX] != '#')&& (map[(tabDeVikings[k].coordPY)-1][tabDeVikings[k].coordPX]!='b'))
                                tabDeVikings[k].coordPY--;
                            break;

                        case 1:
                            if((map[(tabDeVikings[k].coordPY)+1][tabDeVikings[k].coordPX] != '#')&& (map[(tabDeVikings[k].coordPY)+1][tabDeVikings[k].coordPX]!='b'))
                                tabDeVikings[k].coordPY++;
                            break;

                        case 2:
                            if((map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)+1] != '#')&& (map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)+1]!='b'))
                                tabDeVikings[k].coordPX ++;
                            break;
                        case 3:
                            if((map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)-1] != '#')&& (map[tabDeVikings[k].coordPY][(tabDeVikings[k].coordPX)-1]!='b'))
                                tabDeVikings[k].coordPX --;
                            break;
                        }
                    }
                    if(tabDeVikings[k].bouge_depuis==20)
                    {
                        if(tabDeVikings[k].turn==1)
                        {
                            tabDeVikings[k].turn=0;
                        }
                    }
                }
            }

        }
    }
}



void stop()
{
    int i;

    for(i=0; i<5; i++)
    {
        if(mouse_x >= tabDeVikings[i].x-50 && mouse_x <= tabDeVikings[i].x+50 && mouse_y >=tabDeVikings[i].y-50 && mouse_y <=tabDeVikings[i].y+50 &&mouse_b&2 && tabDeVikings[i].stop==1)
        {
            tabDeVikings[i].stop=0;
        }

        if(mouse_x >= tabDeVikings[i].x-50 && mouse_x <= tabDeVikings[i].x+50 && mouse_y >=tabDeVikings[i].y-50 && mouse_y <=tabDeVikings[i].y+50 &&mouse_b&1 && tabDeVikings[i].stop!=1)
        {
            tabDeVikings[i].stop=1;
        }
    }
}

void victory_solo(t_images*img,int*main,int*PG1,int*PG2,int*debm,int*debp1,int*debp2,int*progress,int*mode,int*level,int tabm[12], int tabp1[8], int tabp2[4],t_sons*SON,int*son)
{
    int ready = 0;
    int i;

    *main=0;
    *PG1=0;
    *PG2=0;
    *debm=0;
    *debp1=0;
    *debp2=0;
    tabDeVikings[0].bouge=0;
    tabDeVikings[0].win=0;
    tabDeVikings[0].lose=0;
    for(i=0; i<12; i++)
    {
        tabm[i]=0;
    }
    for(i=0; i<8; i++)
    {
        tabp1[i]=0;
    }
    for(i=0; i<4; i++)
    {
        tabp2[i]=0;
    }
    if( *level ==1 && *progress ==1)
    {
        *progress = 2;
    }
    else if(*level==2 && *progress ==2)
    {
        *progress = 3;
    }
    else if( *level==3 && *progress ==3)
    {
        *progress = 4;
    }
    tabDeVikings[0].bouge = 0;
    rest(1000);
    while(*mode==2)
    {
        if (!mouse_b&1) /// pour qu'il n'y ait pas de multi clicks
        {
            ready = 1;
        }

        blit(img->victory,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        *son=*son+1;
        if(*son==1)
        {
            play_sample(SON->son3,120,120,1000,0);
            *son=*son+1;
        }
        if (mouse_x>=705 && mouse_x<=985 && mouse_y>=610 && mouse_y<=685 && mouse_b&1 && ready ==1)
        {
            blit(img->menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            *mode = 1;
        }
        rest(20);
    }
}



void victory_multi(t_images*img,int*v1,int*v2,int*v3,int*v4,int*v5,int*p1,int*p2,int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*dp1,int*dp2,
                   int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int tabpg1[4],int tabpg2[4],t_sons*SON,int*son,int*mode,int*start,int*vicm,int*losm,
                   int*dp3,int*dp4,int*dp5,int*dp6,int*dp7,int*dp8,int*dp9,int*dp10)
{
    int ready = 0;
    int i;

    *p1=0;
    *p2=0;
    *v1=0;
    *v2=0;
    *v3=0;
    *v4=0;
    *v5=0;
    *dp1=0;
    *dp2=0;
    *dp3=0;
    *dp4=0;
    *dp5=0;
    *dp6=0;
    *dp7=0;
    *dp8=0;
    *dp9=0;
    *dp10=0;

    *dv1=0;
    *dv2=0;
    *dv3=0;
    *dv4=0;
    *dv5=0;
    *son=0;
    *vicm=0;
    *losm=0;
    for(i=0; i<4 ; i++)
    {
        tabv1[i]=0;
        tabv2[i]=0;
        tabv3[i]=0;
        tabv4[i]=0;
        tabv5[i]=0;
        tabpg1[i]=0;
        tabpg2[i]=0;
    }
    for(i=0; i<5; i++)
    {
        tabDeVikings[i].bouge=0;
        tabDeVikings[i].win=0;
        tabDeVikings[i].lose=0;
    }
    rest(1000);
    while(*mode==2)
    {
        if (!mouse_b&1) /// pour qu'il n'y ait pas de multi clicks
        {
            ready = 1;
        }

        blit(img->victory,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        *son=*son+1;
        if(*son==1)
        {
            play_sample(SON->son3,120,120,1000,0);
            *son=*son+1;
        }
        if (mouse_x>=705 && mouse_x<=985 && mouse_y>=610 && mouse_y<=685 && mouse_b&1 && ready ==1)
        {
            blit(img->menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            *mode = 1;
        }
        rest(20);
    }

}

void whowin(BITMAP*page,t_images*img,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int*dv1,int*dv2,int*dv3,int*dv4,int*dv5,int*vicm,int*start,int*losm)
{
    if(tabv1[*dv1] ==0 && *start ==1 && tabDeVikings[0].lose==0 && tabDeVikings[0].win==0)
    {
        tabDeVikings[0].lose=1;
    }

    if(tabv2[*dv2] ==0 && *start ==1  && tabDeVikings[1].lose==0 && tabDeVikings[1].win==0)
    {
        tabDeVikings[1].lose=1;
    }

    if(tabv3[*dv3] ==0 && *start ==1 && tabDeVikings[2].lose==0 && tabDeVikings[2].win==0)
    {
        tabDeVikings[2].lose=1;
    }

    if(tabv4[*dv4] ==0 && *start ==1 && tabDeVikings[3].lose==0 && tabDeVikings[3].win==0)
    {
        tabDeVikings[3].lose=1;
    }

    if(tabv5[*dv5] ==0 && *start ==1 && tabDeVikings[4].lose==0 && tabDeVikings[4].win==0)
    {
        tabDeVikings[4].lose=1;
    }

    if (tabDeVikings[0].win >3)
    {
        *vicm = 1;
        if (tabDeVikings[1].win >3)
        {
            *vicm = 2;
            if (tabDeVikings[2].win >3)
            {
                *vicm = 3;
                if (tabDeVikings[3].win >3)
                {
                    *vicm = 4;
                    if (tabDeVikings[4].win >3)
                    {
                        *vicm = 5;
                    }
                }
            }
        }
    }


    if (tabDeVikings[0].lose >4)
    {
        *losm = 1;
        if (tabDeVikings[1].lose >4)
        {
            *losm = 2;
            if (tabDeVikings[2].lose >4)
            {
                *losm = 3;
                if (tabDeVikings[3].lose >4)
                {
                    *losm = 4;
                    if (tabDeVikings[4].lose >4)
                    {
                        *losm = 5;
                    }
                }
            }
        }
    }

}


void loadSave(int* progress)
{
    FILE* save = NULL;
    char buffer[20];

    sprintf(buffer, "./maps/save.txt"); ///Cherche le .txt de la map dans le dossier
    save = fopen(buffer, "r");

    if (save != NULL) ///Condition OK : on continue
    {
        printf("Ouverture du fichier '%s'\n", buffer);

        fscanf(save,"%d",progress);
        fclose(save);

        printf("la save est %d\n",*progress);
    }
    else /// Condition pas OK
    {
        printf("Erreur : Impossible d'ouvrir le fichier \n");
    }
}

void Save(int* progress)
{
    FILE* save = NULL;
    char buffer[20];

    sprintf(buffer, "./maps/save.txt"); ///Cherche le .txt de la map dans le dossier
    save = fopen(buffer, "w+");

    if (save != NULL) ///Condition OK : on continue
    {
        printf("Ouverture du fichier '%s'\n", buffer);
        fprintf(save, "%d", *progress);
        fclose(save);
        printf("la save est  %d\n",*progress);
    }
    else /// Condition pas OK
    {
        printf("Erreur : Impossible d'ouvrir le fichier \n");
    }
}
void draw_vikings_multi(t_images*img,BITMAP*page,int tabv1[4],int tabv2[4],int tabv3[4],int tabv4[4],int tabv5[4],int*dv1,int*dv2,int*dv3,int*dv4,int*dv5)
{
    int k;


    if (tabDeVikings[0].win >0)
    {
        draw_sprite(page,img->win,tabDeVikings[0].x,tabDeVikings[0].y);
        tabDeVikings[0].win++;
    }

    if (tabDeVikings[1].win >0)
    {
        draw_sprite(page,img->win2,tabDeVikings[1].x,tabDeVikings[1].y);
        tabDeVikings[1].win++;
    }

    if (tabDeVikings[2].win >0)
    {
        draw_sprite(page,img->win3,tabDeVikings[2].x,tabDeVikings[2].y);
        tabDeVikings[2].win++;

    }

    if (tabDeVikings[3].win >0)
    {
        draw_sprite(page,img->win4,tabDeVikings[3].x,tabDeVikings[3].y);
        tabDeVikings[3].win++;
    }

    if (tabDeVikings[4].win >0)
    {
        draw_sprite(page,img->win5,tabDeVikings[4].x,tabDeVikings[4].y);
        tabDeVikings[4].win++;
    }



    if (tabDeVikings[0].lose >0)
    {
        tabDeVikings[0].lose++;
    }
    if (tabDeVikings[1].lose >0)
    {
        tabDeVikings[1].lose++;
    }
    if (tabDeVikings[2].lose >0)
    {
        tabDeVikings[2].lose++;
    }
    if (tabDeVikings[3].lose >0)
    {
        tabDeVikings[3].lose++;
    }

    if (tabDeVikings[4].lose >0)
    {
        tabDeVikings[4].lose++;
    }




    for(k=0; k<5; k++)
    {
        if(tabDeVikings[k].win==0)
        {

            if (tabDeVikings[k].bouge && tabDeVikings[k].turn ==0)
            {
                /// gestion enchainement des images
                if(k==0)
                {
                    draw_sprite(page,img->viking_walk[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==1)
                {
                    draw_sprite(page,img->viking_walk2[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==2)
                {
                    draw_sprite(page,img->viking_walk3[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==3)
                {
                    draw_sprite(page,img->viking_walk4[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==4)
                {
                    draw_sprite(page,img->viking_walk5[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                tabDeVikings[k].cptimg++;
                if (tabDeVikings[k].cptimg>=tabDeVikings[k].tmpimg)
                {
                    tabDeVikings[k].cptimg=0;
                    tabDeVikings[k].imgcourante++;

                    if (tabDeVikings[k].imgcourante>=2)
                    {
                        tabDeVikings[k].imgcourante=0;
                    }
                }
            }
            else
            {
                if(k==0)
                {
                    draw_sprite(page,img->viking_still[tabDeVikings[k].dir],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==1)
                {
                    draw_sprite(page,img->viking_walk2[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==2)
                {
                    draw_sprite(page,img->viking_walk3[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==3)
                {
                    draw_sprite(page,img->viking_walk4[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

                if(k==4)
                {
                    draw_sprite(page,img->viking_walk5[tabDeVikings[k].dir][tabDeVikings[k].imgcourante],tabDeVikings[k].x,tabDeVikings[k].y);
                }

            }
        }
    }
}

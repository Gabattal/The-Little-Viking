/// --- FICHIER MAIN --- ///
/// -------------------- ///

#include "header.h"

int main()
{
    BITMAP *page;
    t_images*img;

    t_sons *SON;

    SON=(t_sons*)malloc(1*sizeof(t_sons));

    charger_sons(SON);

    char map[mapSizeY][mapSizeX +2] = {{0}};
    int tabm[12] = {{0}};
    int tabp1[8] = {{0}};
    int tabp2[4] = {{0}};

    int tabv1[4]= {{0}};
    int tabv2[4]= {{0}};
    int tabv3[4]= {{0}};
    int tabv4[4]= {{0}};
    int tabv5[4]= {{0}};
    int tabpg1[4]= {{0}};
    int tabpg2[4]= {{0}};

    int endp1=0;
    int losm=0;
    int vicm=0;
    int endp2=0;
    int v1=0;
    int v2=0;
    int v3=0;
    int v4=0;
    int v5=0;
    int p1=0;
    int p2=0;
    int dv1=0;
    int dv2=0;
    int dv3=0;
    int dv4=0;
    int dv5=0;
    int dp1=0;
    int dp2=0;
    int dp3=0;
    int dp4=0;
    int dp5=0;
    int dp6=0;
    int dp7=0;
    int dp8=0;
    int dp9=0;
    int dp10=0;
    int son=0;

    int level = 0;
    int multi = 0;

    // LES INFORMATIONS SUIVANTES VONT ALLER DANS UNE STRUCTURE ACTEUR
    //   ( pour pouvoir gérer plusieurs sprites animés )

    // Données géométriques de l'animation
    int dir;
    int turn=0;
    int bouge;
    int bouge_depuis;
    int beginning =0;
    int score = 0;
    int win = 0;
    int lose=0;
    int mode = 1;
    int ready =0;
    int progress = 1;
    int drag=0;
    int main =0;
    int PG1 =0;
    int PG2 =0;
    int start =0;
    int endt =1;
    int debm=0;
    int debp1=0;
    int debp2=0;
    int read=0;
    int i,k;
    int cptdx, tmpdx;




    // Gestion de l'enchainement des images de la séquence
    // indice de l'image courante
    int imgcourante=0;
    // on passe à l'image suivante une fois tous les tmpimg
    int cptimg=0, tmpimg=4;
    printf("Launching allegro... ");
    lancer_allegro();
    printf("SUCCESS\n");

    printf("Creating buffer... ");
    // CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);


    img = malloc(sizeof(t_images));
    charger_images(img);
    printf("SUCCESS\n");


    printf("Init Viking... ");
    init_viking(img);///initialisation des données du viking
    printf("SUCCESS\n");

    blit(img->menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    loadSave(&progress);

    printf("Choose level...\n");
    level = choix(img,&mode,&progress);

    printf("Load map...\n");
    loadMap(map,level);
    mode = 2;

    printf("Main loop\n");
    // Boucle d'animation (pas d'interaction)
    while (!key[KEY_ESC])
    {
        blit(img->decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        if(mode == 0)
        {
            pause(img,&mode,page);
        }

        if(mode ==1)
        {
            level = choix(img,&mode,&progress);
            loadMap(map,level);

            beginning = 0;
            tabDeVikings[0].dir = 1;
            score = 0;
            win = 0;
            lose=0;
            mode = 2;
            main=0;
            PG1=0;
            PG2=0;
            start=0;
            debm=0;
            debp1=0;
            debp2=0;
        }

        if(mode == 2)
        {
            if (key[KEY_P])
            {
                mode = 0;
            }

            if(key[KEY_R])
            {
                loadMap(map,level);
                reset_solo(&beginning,&main,&PG1,&PG2,&start,&debm,&debp1,&debp2,&score,tabm,tabp1,tabp2,&drag,&son);
                reset_multi(&beginning,&start,&v1,&v2,&v3,&v4,&v5,&p1,&p2,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,
                            &score,tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,&drag,&son,&vicm,&losm,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
            }

            draw_sprites(img,page,map,&beginning,&score,&level);// gestion déplacement du viking / NOM A CHANGER

            if(level!=5)
            {


                drag_drop_solo(img,&drag,page,&main,&PG1,&PG2,tabm,tabp1,tabp2,&start,&level);

                /// Decision de bouger

                lemove_solo(tabm,tabp1,tabp2,&start,&endt,&debm,&debp1,&debp2);
                actions_solo(map,&debm,&debp1,&debp2,tabm,tabp1,tabp2,&start,&endt);


                score_win(img,map,&score,&win,SON,tabv1,tabv2,tabv3,tabv4,tabv5,&dv1,&dv2,&dv3,&dv4,&dv5);

                /// Gestion du mouvement SI on bouge

                if_move(map);

                if (tabDeVikings[0].win >0)
                {
                    draw_sprite(page,img->win,tabDeVikings[0].x,tabDeVikings[0].y);
                    tabDeVikings[0].win++;
                }
                if(tabm[debm] ==0 && start ==1)
                {
                    tabDeVikings[0].lose++;
                }
                else if (tabDeVikings[0].bouge && tabDeVikings[0].turn ==0 && tabDeVikings[0].win==0)
                {
                    /// gestion enchainement des images
                    draw_sprite(page,img->viking_walk[tabDeVikings[0].dir][tabDeVikings[0].imgcourante],tabDeVikings[0].x,tabDeVikings[0].y);
                    /// incrémenter imgcourante une fois sur tmpimg
                    tabDeVikings[0].cptimg++;
                    if (tabDeVikings[0].cptimg>=tabDeVikings[0].tmpimg)
                    {
                        tabDeVikings[0].cptimg=0;
                        tabDeVikings[0].imgcourante++;

                        /// quand l'indice de l'image courante arrive à NIMAGE
                        /// on recommence la séquence à partir de 0
                        if (tabDeVikings[0].imgcourante>=2)
                        {
                            tabDeVikings[0].imgcourante=0;
                        }
                    }
                }
                else if (tabDeVikings[0].win==0)
                {
                    draw_sprite(page,img->viking_still[tabDeVikings[0].dir],tabDeVikings[0].x,tabDeVikings[0].y);
                }

                bouger_solo(map,&endt,&debm,&debp1,&debp2);


            }
            /// Affichage (selon qu'on bouge ou pas)
            if(level == 5)
            {

                drag_drop_multi(img,&drag,page,& start,&level,tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,&v1,&v2,&v3,&v4,&v5,&p1,&p2);
                lemove_multi(tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,&start,&endt,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
                actions_multi(map,tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,&start,&endt,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
                score_win(img,map,&score,&win,SON,tabv1,tabv2,tabv3,tabv4,tabv5,&dv1,&dv2,&dv3,&dv4,&dv5);
                if_move(map);
                draw_vikings_multi(img,page,tabv1,tabv2,tabv3,tabv4,tabv5,&dv1,&dv2,&dv3,&dv4,&dv5);
                bouger_multi(map,&endt,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
                whowin(page,img,tabv1,tabv2,tabv3,tabv4,tabv5,&dv1,&dv2,&dv3,&dv4,&dv5,&vicm,&start,&losm);
                stop();


            }
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(level !=5)
            {


                if(tabDeVikings[0].win==4)
                {
                    victory_solo(img,&main,&PG1,&PG2,&debm,&debp1,&debp2,&progress,&mode,&level,tabm,tabp1,tabp2,SON,&son);
                    Save(&progress);
                    reset_solo(&beginning,&main,&PG1,&PG2,&start,&debm,&debp1,&debp2,&score,tabm,tabp1,tabp2,&drag,&son);
                }


                if(tabDeVikings[0].lose==4 && tabm[debm] ==0 && start ==1)
                {
                    rest(1000);
                    loadMap(map,level);
                    reset_solo(&beginning,&main,&PG1,&PG2,&start,&debm,&debp1,&debp2,&score,tabm,tabp1,tabp2,&drag,&son);
                }
            }



            if(vicm== 5 && level ==5)
            {
                victory_multi(img,&v1,&v2,&v3,&v4,&v5,&p1,&p2,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,
                              tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,SON,&son,&mode,&start,&vicm,&losm,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
                reset_multi(&beginning,&start,&v1,&v2,&v3,&v4,&v5,&p1,&p2,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,
                            &score,tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,&drag,&son,&vicm,&losm,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
            }

            if(losm==5 && level ==5)
            {
                rest(1000);
                loadMap(map,level);
                reset_multi(&beginning,&start,&v1,&v2,&v3,&v4,&v5,&p1,&p2,&dv1,&dv2,&dv3,&dv4,&dv5,&dp1,&dp2,
                            &score,tabv1,tabv2,tabv3,tabv4,tabv5,tabpg1,tabpg2,&drag,&son,&vicm,&losm,&dp3,&dp4,&dp5,&dp6,&dp7,&dp8,&dp9,&dp10);
            }
            /// continuer de bouger ou pas

            // affichage du buffer à l'écran

        }
        rest(20);
    }
    return 0;
}
END_OF_MAIN();


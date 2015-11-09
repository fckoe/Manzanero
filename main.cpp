#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


BITMAP* fondo;
BITMAP* fon;
BITMAP* manzanas;
BITMAP* naranja;
BITMAP* mono;
BITMAP* gameover;
BITMAP* bombas;
PALETTE paleta;

void randomize()
{
    time_t tim;   /* Variable para almacenar la hora actual */
    time(&tim);   /* Obtiene la hora actual */
    srand(tim);   /* Establece semilla de acuerdo a hora */
}

int randomABi(int A, int B)
{
      return((int)((double) rand()/RAND_MAX*(B+1-A)+A));
}


int main ()
{
    int x=470, y=0,i=470,j=450,q=270,w=0,z=670,r=0,cont=0,conv=0,score=0,vidas=3,nivel=1,f,g,h,speed=15,con=10;
    allegro_init();
    install_timer();
    install_keyboard();
    volatile int t;
    /*colocar aqui las imagenes*/
    const char *archivo = "fondo.bmp", *archivo2 = "manzanas.bmp", *archivo3 = "mono.bmp", *archivo4 = "naranja.bmp", *archivo5 = "gameover.bmp", *archivo6 = "bombas.bmp";
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
    /*cargar las imagenes*/
    fondo = load_bitmap(archivo,paleta);
    manzanas = load_bitmap(archivo2,paleta);
    mono = load_bitmap(archivo3,paleta);
    naranja = load_bitmap(archivo4,paleta);
    gameover = load_bitmap(archivo5,paleta);
    bombas = load_bitmap(archivo6,paleta);
    set_palette(paleta);
    
    fon = create_bitmap(800,600);
    
    while (!key[KEY_ESC] && vidas >= 0)
    {
        /*insertar las imagenes aqui*/  
        blit(fondo,screen,0,0,0,0,800,600);
        blit(mono,screen,0,0,i,j,60,90);
        blit(manzanas,screen,0,0,x,y,60,60);
        blit(naranja,screen,0,0,q,w,60,60);
        blit(bombas,screen,0,0,z,r,60,60);
        textprintf(screen,font,90,118,-1,"%d",score);
        textprintf(screen,font,70,193,-1,"%d",vidas);
        textprintf(screen,font,70,256,-1,"%d",nivel);
        textprintf(screen,font,100,309,-1,"%d",cont);
        textprintf(screen,font,100,359,-1,"%d",conv);
        f=randomABi(0,2);
        g=randomABi(0,2);
        h=randomABi(0,2);
        /* velocidad de la caida*/  
        rest(1);
        y=y+speed;   /*manzanas rojas*/
        w=w+speed;   /*manzanas verdes*/
        r=r+speed;
        while(con == 10)
        {
                con=0;
                vidas++;
                nivel++;
        }
        /* bombas */
        /*recoger manzanas rojas*/
        if(x == i && y == j)
        {
               score=score+100;
               con++;
               cont++;
               y=0;
               if( f == 0)
               {
                   x=270;
               }
               else if( f == 1)
                    {
                        x=470;
                    }
                    else
                    {
                        x=670;
                    }
        }
        /* no recoge manzanas*/
        else if(y==600)
        {
               y=0;
               if( g == 0)
               {
                   x=270;
               }
               else if( g == 1)
                    {
                        x=470;
                    }
                    else
                    {
                        x=670;
                    }
        }
        /*recoger manzanas verdes*/
        if(q == i && w == j)
        {
               score=score+150;
               con++;
               conv++;
               w=0;
               if( g == 0)
               {
                   q=270;
               }
               else if( g == 1)
                    {
                        q=470;
                    }
                    else
                    {
                        q=670;
                    }
        }
        /* no recoge manzanas verdes*/
        else if(w==600)
        {
               w=0;
               if( g == 0)
               {
                   q=270;
               }
               else if( g == 1)
                    {
                        q=470;
                    }
                    else
                    {
                        q=670;
                    }
        }
               /*recoger bombas*/
        if(z == i && r == j)
        {
               vidas=vidas-1;
               r=0;
               if( h == 0)
               {
                   z=270;
               }
               else if( h == 1)
                    {
                        z=470;
                    }
                    else
                    {
                        z=670;
                    }
        }
        /* no recoge bombas*/
        else if(r==600)
        {
               r=0;
               if( h == 0)
               {
                   z=270;
               }
               else if( h == 1)
                    {
                        z=470;
                    }
                    else
                    {
                        z=670;
                    }
        }
        /*poner aqui el codigo del juego!!!!*/   

        i=470;        
         if(key[KEY_LEFT])
        {                           
                 i=270;               
        }
         if(key[KEY_RIGHT])
        {     
                 i=670;
        }
       
        vsync();               
    }
    while(!key[KEY_ESC])
    {
           blit(gameover,screen,0,0,400,300,600,600);
    }
    /*quitar las imagens aqui*/
    destroy_bitmap(fondo);
    destroy_bitmap(fon);
    destroy_bitmap(manzanas);
    destroy_bitmap(mono);
    destroy_bitmap(naranja);
    destroy_bitmap(gameover);
    destroy_bitmap(bombas);

    clear_keybuf();
    remove_timer();
    
   
    allegro_exit();
    return EXIT_SUCCESS;
    
}END_OF_MAIN();


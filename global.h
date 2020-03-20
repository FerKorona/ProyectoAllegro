const int PANTALLA_ANCHO = 800;
const int PANTALLA_ALTO  = 600;

BITMAP *buffer;

const int desplazamiento=4;

void pintar_pantalla()
{
    blit(buffer, screen, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
}


void inicia_allegro()
{
 allegro_init();
 install_keyboard();

 set_color_depth(32);
 set_gfx_mode(GFX_AUTODETECT_WINDOWED, PANTALLA_ANCHO, PANTALLA_ALTO, 0, 0);

 buffer = create_bitmap(PANTALLA_ANCHO, PANTALLA_ALTO);
}

class player
{
    BITMAP *prota;
    int x,y;
    int direccion;
    int animacion;

public:
    player();
    void pinta();
    void teclado();
};

player::player()
{
    prota = load_bmp("personaje.bmp", NULL);
    direccion = 0;
    animacion = 0;
    x = 10;
    y = 10;
}

void player::pinta()
{
    masked_blit(prota, buffer, animacion*32, direccion*32, x, y, 32,32);
    }

void player::teclado()
{
    int ax = x;
    int ay = y;

    if (key [KEY_UP])
    {
        y-=desplazamiento;
        direccion = 3;
    }
    if (key [KEY_DOWN])
    {
        y+=desplazamiento;
        direccion = 0;
    }
    if (key [KEY_LEFT])
    {
        x-=desplazamiento;
        direccion = 1;
    }
    if (key [KEY_RIGHT])
    {
        x+=desplazamiento;
        direccion = 2;
    }
    if (ax!= x || ay!=y)
    {
        animacion++;
        if(animacion>2)animacion = 0;
    }

    if(x < 0) x = 0;
    if(x>PANTALLA_ANCHO) x = PANTALLA_ANCHO;
    if(y < 0) y = 0;
    if(y>PANTALLA_ALTO) y = PANTALLA_ALTO;
}

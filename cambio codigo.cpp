#include <allegro.h>
#include "global.h"

int main()
{
 inicia_allegro();

 player jugador;
 bool salir;

 salir = false;

 while ( !salir )
 {
          clear_to_color(buffer, 0xaaaaaa);

          jugador.teclado();

          jugador.pinta();

       pintar_pantalla();

       rest(60);

       if ( key[KEY_ESC] ) salir = true;

    }

 destroy_bitmap(buffer);

 return 0;
}

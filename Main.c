#include <SDL.h>
#include <SDL_ttf.h>
#include "Game.h"


int main(int argc, char* args[]) {
    struct Game game;
    Game_init(&game);  // Inicializa el objeto `game`

    game.initialize(&game);  // Inicializa la ventana y los recursos del juego

    if (game.is_running) {  // Si la inicialización fue exitosa
        game.setup(&game);  // Configura la escena inicial del juego

        // Bucle principal del juego
        while (game.is_running) {
            game.process_input(&game);  // Procesa la entrada del usuario
            game.update(&game);         // Actualiza el estado del juego
            game.render(&game);         // Renderiza la escena
        }
    }

    // Al salir del bucle, guarda el historial de eventos
    game.event_history.save_event_history(&game.event_history, "save.txt");

    game.destroy(&game);  // Destruye los recursos y cierra SDL
    return 0;
}

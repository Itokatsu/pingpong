#ifndef DEF_DRAWENGINE
#define DEF_DRAWENGINE

#include <string>
#include <map>

#include "SDL.h"
#include "GameEngine.h"
#include "GraphicEngine.h"

#include "Paddle.h"
#include "Ball.h"


class DrawEngine {

	public:
		DrawEngine();
		void Init(GraphicEngine* gfx);
		void Cleanup();
		void Load(std::string className, std::string file);
		void DrawPaddle(Paddle* pad, GameEngine* game);
		void DrawBall(Ball* ball, GameEngine* game);

	private:
		std::map<std::string, SDL_Texture*> ressources;
		SDL_Renderer* renderer;

};

#endif
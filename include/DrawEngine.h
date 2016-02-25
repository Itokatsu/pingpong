#ifndef DEF_DRAWENGINE
#define DEF_DRAWENGINE

#include <string>
#include <map>

#include "SDL.h"
#include "GameEngine.h"
#include "GraphicEngine.h"

#include "Match.h"
#include "IField.h"
#include "Player.h"
#include "Paddle.h"
#include "Ball.h"


class DrawEngine {

	public:
		DrawEngine();
		void Init(GraphicEngine* gfx);
		void Cleanup();
		void Load(std::string className, std::string file);
		void DrawMatch(Match* match, GameEngine* game);
		void DrawField(IField* field, GameEngine* game);
		void DrawPlayer(Player* player, GameEngine* game);
		void DrawPaddle(Paddle* pad, GameEngine* game);
		void DrawBall(Ball* ball, GameEngine* game);

	private:
		std::map<std::string, SDL_Texture*> ressources;
		SDL_Renderer* renderer;

};

#endif
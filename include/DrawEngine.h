#ifndef DEF_DRAWENGINE
#define DEF_DRAWENGINE

#include <string>
#include <map>

#include "GameEngine.h"
#include "GraphicEngine.h"

#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Match.h"
#include "IField.h"
#include "Player.h"
#include "Paddle.h"
#include "Ball.h"
#include "Goal.h"

class DrawEngine {

	public:
		DrawEngine();
		void Init(GraphicEngine* gfx);
		void Cleanup();
		void Load(std::string className, std::string file);
		SDL_Texture* LoadImage(std::string imgPath);
		SDL_Texture* LoadText(std::string text, SDL_Color color);

		void DrawMatch(Match* match, GameEngine* game);
		void DrawField(IField* field, GameEngine* game);
		void DrawGoal(Goal* goal, GameEngine* game);
		void DrawPlayer(Player* player, GameEngine* game);
		void DrawPaddle(Paddle* pad, GameEngine* game);
		void DrawBall(Ball* ball, GameEngine* game);

	private:
		std::map<std::string, SDL_Texture*> ressources;
		SDL_Renderer* renderer;
		TTF_Font* font;

};

#endif
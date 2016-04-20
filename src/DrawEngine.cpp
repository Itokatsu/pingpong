#include "DrawEngine.h"
#include <iostream>

DrawEngine::DrawEngine() {

}

void DrawEngine::Init(GraphicEngine* gfx) {
	// bool success = true;
	renderer = gfx->GetRenderer();

	// init SDL_image
	int imgFlags = IMG_INIT_PNG; //Loading PNGs
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		std::cerr << "SDL_image init FAILED : " << IMG_GetError() << std::endl;
		// success = false;
	}

	// init SDL_ttf
	if( TTF_Init() == -1 ) {
		std::cerr << "SDL_ttf init FAILED : " << TTF_GetError() << std::endl;
		// success = false;
	}
	font = TTF_OpenFont( "../media/fonts/meguri-p.ttf", 28 );
	if( font == NULL ) {
		std::cerr << "Failed to open font : " << TTF_GetError() << std::endl;
		// success = false;
	}

	// return success;
}

void DrawEngine::Cleanup() {
	/* //clean map
	for ( auto &texture : ressources) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
	*/

	TTF_CloseFont(font);
	font = NULL;

	TTF_Quit();
	IMG_Quit();
}


SDL_Texture* DrawEngine::LoadImage(std::string imgPath) {

    SDL_Texture* newTexture = NULL;
	SDL_Surface* tempSurface = IMG_Load(imgPath.c_str());
	if( tempSurface == NULL ) {
		std::cerr << "Failed to load " << imgPath << " : " << IMG_GetError() << std::endl;
	} 
	else {
		newTexture = SDL_CreateTextureFromSurface( renderer, tempSurface);
		if( newTexture == NULL ) {
			std::cerr << "Failed to create texture from " << imgPath << " : " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface( tempSurface );
	}

	return newTexture;
}


SDL_Texture* DrawEngine::LoadText(std::string text, SDL_Color color) {

	SDL_Texture* newTexture = NULL;	
	SDL_Surface* tempSurface = TTF_RenderUTF8_Solid( font, text.c_str(), color );
	if( tempSurface == NULL ) {
		std::cerr << "Failed to render text surface : " << TTF_GetError() << std::endl;
	}
	else {
		newTexture = SDL_CreateTextureFromSurface( renderer, tempSurface );
		if( newTexture == NULL ) {
			std::cerr << "Failed to create texture from rendered text : " << SDL_GetError() << std::endl;
		}

		//Get rid of old surface
		SDL_FreeSurface( tempSurface );
    }

	return newTexture;
}

// 		void Load(std::string className, std::string file);



/* =====================
	Drawing Functions
====================== */

void DrawEngine::DrawMatch(Match* match, GameEngine* game)
{
	DrawField(match->GetField(), game);
	for ( auto &player : match->GetPlayers() ) {
		DrawPlayer(player, game);
	}
	DrawBall(match->GetBall(), game);
}

void DrawEngine::DrawField(IField* field, GameEngine* game)
{
	for ( auto &goal : field->GetGoals() ) {
		DrawGoal(goal, game);
	}
}

void DrawEngine::DrawGoal(Goal* goal, GameEngine* game)
{
	SDL_Rect* goalRect = goal->GetCollisionBox();
	// mint 50% opacity
	SDL_SetRenderDrawColor(renderer, 0x98, 0xFF, 0x98, 0x80);
	SDL_RenderFillRect(renderer, goalRect);
}


void DrawEngine::DrawPlayer(Player* player, GameEngine* game)
{
	DrawPaddle(player->GetPaddle(), game);
}

void DrawEngine::DrawPaddle(Paddle* pad, GameEngine* game)
{
	SDL_Rect* padRect = pad->GetCollisionBox();
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, padRect);
}


void DrawEngine::DrawBall(Ball* ball, GameEngine* game)
{
	SDL_Rect* ballRect = ball->GetCollisionBox();
	//yellow degueulasse
	SDL_SetRenderDrawColor(renderer, 0xCC, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, ballRect);	
}

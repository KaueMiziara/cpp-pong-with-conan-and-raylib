#include "score.h"
#include "actors.h"
#include "raylib.h"

#include <string>

namespace Pong {

	void Score::DrawScore(Player player1, Player player2) {
		std::string text = std::to_string(player1.score) +
				   " x " + std::to_string(player2.score);
		
		const char* char_text = text.c_str();
		
		int textX;

		if (IsWindowFullscreen())
			textX = SCREEN_WIDTH/2 - 34;
		else
			textX = SCREEN_WIDTH/2 - 50;
		
		DrawText(char_text, textX, 20, 40, WHITE);
	}

	void Score::UpdateScore(Ball *ball, Player *player1, Player *player2) {
		if (ball->posX > SCREEN_WIDTH - 75) {
			player1->score++;
			ball->BallInitialize(20);
		}
		if (ball->posX < 0) {
			player2->score++;
			ball->BallInitialize(20);
		}
	}
}

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
			textX = screen_width/2 - 34;
		else
			textX = screen_width/2 - 50;
		
		DrawText(char_text, textX, 20, 40, WHITE);
	}

	void Score::UpdateScore(Ball *ball, Player *player1, Player *player2) {
		if (ball->posX > screen_width - 75) {
			player1->score++;
			ball->BallInitialize(20);
		}
		if (ball->posX < 0) {
			player2->score++;
			ball->BallInitialize(20);
		}
	}
}

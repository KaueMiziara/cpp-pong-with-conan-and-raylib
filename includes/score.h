#ifndef SCORE_H
#define SCORE_H

#include "actors.h"
#include "raylib.h"


namespace Pong {

	class Score {
		public:
		void DrawScore(Player player1, Player player2);

		void UpdateScore(Ball *ball, Player *player1, Player *player2);
	};

}

#endif

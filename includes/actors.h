#ifndef ACTORS_H
#define ACTORS_H

#include "raylib.h"

namespace Pong {

	// Globals
	const int screen_width = 810;
	const int screen_height = 540;
	const int BAR_SPEED = 5;
	
	class Player {
		public:
		int posX;
		int posY;
		int width;
		int height;
		int score;

		void PlayerInitialize(int posX, int width);

		void DrawPlayer();

		void MovePlayerArrows();

		void MovePlayerKeys();
	};
	
	
	class Ball {
		public:
		int posX;
		int posY;
		int radius;

		int ballLeft = posX - radius;
		int ballRIght = posX + radius;

		void BallInitialize(int width);

		void DrawBall();

		void CollisionWall();

		void CollisionPlayer(Player player);
	};

}

#endif

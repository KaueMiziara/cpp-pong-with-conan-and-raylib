#include "raylib.h"
#include "actors.h"
#include "score.h"


int main(int argc, char** argv) {
	InitWindow(Pong::SCREEN_WIDTH, Pong::SCREEN_HEIGHT, "Pong test (C++, raylib)");
	SetTargetFPS(30);

	// Players
	Pong::Player player1;
	player1.PlayerInitialize(75, 20);
	player1.score = 0;

	Pong::Player player2;
	player2.PlayerInitialize(Pong::SCREEN_WIDTH - 95, 20);
	player2.score = 0;

	Pong::Ball ball;
	ball.BallInitialize(20);

	Pong::Score score;

	// Game loop
	while (!WindowShouldClose()) {
		if (IsKeyPressed(70)) ToggleFullscreen();

		// Drawings
		ClearBackground(BLACK);
		BeginDrawing();

			score.DrawScore(player1, player2);

			player1.DrawPlayer();
			player1.MovePlayerKeys();

			player2.DrawPlayer();
			player2.MovePlayerArrows();

			ball.DrawBall();
			ball.CollisionWall();
			ball.CollisionPlayer(player1);
			ball.CollisionPlayer(player2);

			score.UpdateScore(&ball, &player1, &player2);

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}

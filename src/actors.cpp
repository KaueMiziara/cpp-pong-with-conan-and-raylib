#include "raylib.h"
#include "actors.h"

namespace Pong {

	int ball_speed_x = 7;
	int ball_speed_y = 5;


	void Player::PlayerInitialize(int posX, int width) {
		this->posX = posX;
		this->posY = SCREEN_HEIGHT/2 - (height/2);
		this->width = width;
		height = 5 * width;
	}

	void Player::DrawPlayer() { DrawRectangle(posX, posY, width, height, WHITE); }

	void Player::MovePlayerArrows() {
		// Up
		if (posY > 0 && IsKeyDown(265)) posY -= BAR_SPEED;
		// Down
		if (posY < (SCREEN_HEIGHT - height) && IsKeyDown(264)) posY+= BAR_SPEED;
	}

	void Player::MovePlayerKeys() {
		// Up
		if (posY > 0 && IsKeyDown(87)) posY -= BAR_SPEED;
		// Down
		if (posY < (SCREEN_HEIGHT - height) && IsKeyDown(83)) posY += BAR_SPEED;
	}
	
	
	void Ball::BallInitialize(int width) {
		posX = SCREEN_WIDTH/2;
		posY = SCREEN_HEIGHT/2;
		radius = width/2;
	}

	void Ball::DrawBall() {
		DrawCircle(posX, posY, radius, WHITE);
		posX += ball_speed_x;
		posY += ball_speed_y;
	}

	void Ball::CollisionWall() {
		// Screen collision
		if (this->posY == 0) ball_speed_y *= -1; 
		if (this->posY > SCREEN_HEIGHT) ball_speed_y *= -1;
	}

	void Ball::CollisionPlayer(Player player) {
		// Left player collision
		if (this->posX <= 95 &&
		   (this->posY == player.posY ||
		   (this->posY <= player.posY + player.height &&
		    this->posY >= player.posY - player.height)))
			ball_speed_x *= -1;

		// Right player collision
		if (this->posX >= SCREEN_WIDTH - 95 &&
		   (this->posY == player.posY ||
		   (this->posY <= player.posY + player.height &&
		    this->posY >= player.posY - player.height)))
			ball_speed_x *= -1;
	}
	
}


#include "raylib.h"
#include "actors.h"

namespace Pong {

	int BALL_SPEED_X = 7;
	int BALL_SPEED_Y = 5;


	void Player::PlayerInitialize(int posX, int width) {
		this->posX = posX;
		this->posY = screen_height/2 - (height/2);
		this->width = width;
		height = 5 * width;
	}

	void Player::DrawPlayer() { DrawRectangle(posX, posY, width, height, WHITE); }

	void Player::MovePlayerArrows() {
		// Up
		if (posY > 0 && IsKeyDown(265)) posY -= BAR_SPEED;
		// Down
		if (posY < (screen_height - height) && IsKeyDown(264)) posY+= BAR_SPEED;
	}

	void Player::MovePlayerKeys() {
		// Up
		if (posY > 0 && IsKeyDown(87)) posY -= BAR_SPEED;
		// Down
		if (posY < (screen_height - height) && IsKeyDown(83)) posY += BAR_SPEED;
	}
	
	
	void Ball::BallInitialize(int width) {
		posX = screen_width/2;
		posY = screen_height/2;
		radius = width/2;
	}

	void Ball::DrawBall() {
		DrawCircle(posX, posY, radius, WHITE);
		posX += BALL_SPEED_X;
		posY += BALL_SPEED_Y;
	}

	void Ball::CollisionWall() {
		// Screen collision
		if (this->posY == 0) BALL_SPEED_Y *= -1; 
		if (this->posY > screen_height) BALL_SPEED_Y *= -1;
	}

	void Ball::CollisionPlayer(Player player) {
		// Left player collision
		if (this->posX <= 95 &&
		   (this->posY == player.posY ||
		   (this->posY <= player.posY + player.height &&
		    this->posY >= player.posY - player.height)))
			BALL_SPEED_X *= -1;

		// Right player collision
		if (this->posX >= screen_width - 95 &&
		   (this->posY == player.posY ||
		   (this->posY <= player.posY + player.height &&
		    this->posY >= player.posY - player.height)))
			BALL_SPEED_X *= -1;
	}
	
}


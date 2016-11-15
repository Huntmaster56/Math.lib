#pragma once
#include "Camera.h"
#include "PlayerShip.h"

class GameState
{

public:
	PlayerShip player;
	Camera camera;
	

	void Play();
	void Update(float deltaTime);
	void Draw();
};
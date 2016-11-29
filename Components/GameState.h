#pragma once
#include "Camera.h"
#include "PlayerShip.h"
#include "Floor.h"


class GameState
{
public:
	PlayerShip player;
	Camera camera;
	Floor floor[2];

	void Play();
	void Update(float deltaTime);
	void Draw();
};
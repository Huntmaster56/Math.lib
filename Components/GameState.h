#pragma once
#include "Camera.h"
#include "PlayerShip.h"
#include "Floor.h"


class GameState
{
public:
	const static int FLOOR_COUNT = 2;

	PlayerShip player;
	Camera camera;
	Floor floor[FLOOR_COUNT];

	void Play();
	void Update(float deltaTime);
	void Draw();
};
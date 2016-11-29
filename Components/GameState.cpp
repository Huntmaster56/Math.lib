#include "GameState.h"
#include "ObjectCollision.h"
#include "Floor.h"
#include <cstdio>
#include <iostream>
void GameState::Play()
{
	player.transform.m_position = vec2{ 600,600 };
	player.transform.m_facing = 0;

	floor[0].transform.m_position = vec2{ 200,200 };
	floor[0].transform.m_position = vec2{ 200,200 };
	floor[0].transform.m_position = vec2{ 200,200 };

	floor[1].transform.m_position = vec2{ 400,400 };
	floor[1].transform.m_position = vec2{ 400,400 };
	floor[1].transform.m_position = vec2{ 400,400 };
}

void GameState::Update(float deltaTime)
{
	system("cls");
	printf(" X: %f , Y: %f", player.transform.m_position.x, player.transform.m_position.y);


	player.Update(deltaTime, *this);
	camera.Update(deltaTime, *this);

	for (int i = 0; i < FLOOR_COUNT; ++i)
		floor[i].Update(deltaTime, *this);  


	for (int i = 0; i < FLOOR_COUNT; ++i)
	{
		FloorCollision(player, floor[i]);
	}

	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(floor[i], floor[j]);
}

void GameState::Draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.Draw(cam);

	for (int i = 0; i < 2; ++i)
		floor[i].Draw(cam);
}
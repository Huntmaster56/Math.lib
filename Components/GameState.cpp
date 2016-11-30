#include "GameState.h"
#include "ObjectCollision.h"
#include "Floor.h"
#include <cstdio>
#include <iostream>
void GameState::Play()
{
	player.transform.m_position = vec2{ 200,500 };
	player.transform.m_facing = 0;

	floor[0].transform.m_position = vec2{ 51,1900 };
	floor[0].transform.m_position = vec2{ 51,1900 };
	floor[0].transform.m_position = vec2{ 51,1900 };

	floor[1].transform.m_position = vec2{ 50,-100 };
	floor[1].transform.m_position = vec2{ 50,-100 };
	floor[1].transform.m_position = vec2{ 50,-100 };
	floor[1].transform.m_facing = 1.57;

	floor[2].transform.m_position = vec2{ 50,-200 };
	floor[2].transform.m_position = vec2{ 50,-200 };
	floor[2].transform.m_position = vec2{ 50,-200 };

	floor[3].transform.m_position = vec2{ 2150,-100 };
	floor[3].transform.m_position = vec2{ 2150,-100 };
	floor[3].transform.m_position = vec2{ 2150,-100 };
	floor[3].transform.m_facing = 1.57;

	spring[0].transform.m_position = vec2{ 100,200 };
	spring[0].transform.m_position = vec2{ 100,200 };
	spring[0].transform.m_position = vec2{ 100,200 };

	spring[1].transform.m_position = vec2{ 200,200 };
	spring[1].transform.m_position = vec2{ 200,200 };
	spring[1].transform.m_position = vec2{ 200,200 };

	spring[2].transform.m_position = vec2{ 300,200 };
	spring[2].transform.m_position = vec2{ 300,200 };
	spring[2].transform.m_position = vec2{ 300,200 };

	spring[3].transform.m_position = vec2{ 400,200 };
	spring[3].transform.m_position = vec2{ 400,200 };
	spring[3].transform.m_position = vec2{ 400,200 };

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

	for (int i = 0; i < SPRING_COUNT; ++i)
		spring[i].Update(deltaTime, *this);

	for (int i = 0; i < SPRING_COUNT; ++i)
	{
		FloorCollision(player, spring[i]);
	}


	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(floor[i], floor[j]);
	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(spring[i], spring[j]);

}

void GameState::Draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.Draw(cam);

	for (int i = 0; i < 4; ++i)
		floor[i].Draw(cam);

	for (int j = 0; j < 4; ++j)
		spring[j].Draw(cam);

}
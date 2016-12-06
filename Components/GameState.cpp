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

	floor[1].transform.m_position = vec2{ 50,-100 };
	floor[1].transform.m_facing = 1.57;

	floor[2].transform.m_position = vec2{ 50,-200 };

	floor[3].transform.m_position = vec2{ 2150,-100 };
	floor[3].transform.m_facing = 1.57;
	

	spring[0] = Spring();
	spring[0].transform.m_position = vec2{ 400,100 };
	spring[0].transform.m_facing = 2.37;

	spring[1] = Spring();
	spring[1].transform.m_position = vec2{ 1700,100 };
	spring[1].transform.m_facing = 0.75;

	spring[2] = Spring();
	spring[2].transform.m_position = vec2{ 200,1550 };
	spring[2].transform.m_facing = 0.75;

	spring[3] = Spring();
	spring[3].transform.m_position = vec2{ 1950,1550 };
	spring[3].transform.m_facing = 2.37;

	spring[4] = Spring();
	spring[4].transform.m_position = vec2{ 840,590 };
	spring[4].transform.m_facing = 2.37;

	spring[5] = Spring();
	spring[5].transform.m_position = vec2{ 1255,595 };
	spring[5].transform.m_facing = 0.75;

	spring[6] = Spring();
	spring[6].transform.m_position = vec2{ 625,1100 };
	spring[6].transform.m_facing = 0.75;

	spring[7] = Spring();
	spring[7].transform.m_position = vec2{ 1475,1100 };
	spring[7].transform.m_facing = 2.37;

	spring[8] = Spring();
	spring[8].transform.m_position = vec2{ 625, 800 };
	spring[8].transform.m_facing = 1.57;

	spring[9] = Spring();
	spring[9].transform.m_position = vec2{ 1475, 800 };
	spring[9].transform.m_facing = 1.57;

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
		SpringCollision(player, spring[i]);
	}


	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(floor[i], floor[j]);
	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision2(spring[i], spring[j]);

}

void GameState::Draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.Draw(cam);

	for (int i = 0; i < 4; ++i)
		floor[i].Draw(cam);

	for (int j = 0; j < 10; ++j)
		spring[j].Draw(cam);

}
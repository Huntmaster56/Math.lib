#include "GameState.h"
#include "ObjectCollision.h"
#include "Floor.h"
void GameState::Play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	floor[0].transform.m_position = vec2{ 200,300 };
	floor[0].transform.m_position = vec2{ 300,300 };
	floor[0].transform.m_position = vec2{ 400,300 };

	floor[1].transform.m_position = vec2{ 500,400 };
	floor[1].transform.m_position = vec2{ 300,200 };
	floor[1].transform.m_position = vec2{ 600,500 };
}

void GameState::Update(float deltaTime)
{
	player.Update(deltaTime, *this);
	camera.Update(deltaTime, *this);

	for (int i = 0; i < 2; ++i)
		floor[i].Update(deltaTime, *this);  

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

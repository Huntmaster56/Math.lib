#include "GameState.h"

void GameState::Play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;
}

void GameState::Update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
}

void GameState::Draw()
{

}

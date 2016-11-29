#pragma once

#include "Floor.h"
#include "PlayerShip.h"


void PlayerAsteroidCollision(PlayerShip &player, Floor &as);

void AsteroidCollision(Floor &as1, Floor &as2);

void FloorCollision(PlayerShip & player, Floor & floor);

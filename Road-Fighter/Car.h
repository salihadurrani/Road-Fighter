#pragma once
#include <SDL.h>
#include "Common.h"

class Car
{
public:
	Car(GraphUnitPack* pgup);
	bool IsPlayer();
	void IsPlayer(bool is);
	void AddToBuff();
	void Move(int x, int y);
	void MoveTo(int x, int y);
	SDL_Point& GetPos();
	void SetTexId(int id);
private:
	SDL_Point m_ptPos;
	bool m_bIsPlayer;
	GraphUnitPack* m_pgup;
	int m_nTexId;
};
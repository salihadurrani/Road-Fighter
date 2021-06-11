#include "pch.h"
#include "Car.h"
#include "Engine.h"

Car::Car(GraphUnitPack* pgup)
{
	m_ptPos = { 2,0 };
	m_bIsPlayer = true;
	m_pgup = pgup;
	m_nTexId = 21;
}

bool Car::IsPlayer()
{
	return m_bIsPlayer;
}

void Car::IsPlayer(bool is)
{
	m_bIsPlayer = is;
}

void Car::AddToBuff()
{
	if (m_bIsPlayer)
	{
		GraphEngine::AddSquareToBuff(m_ptPos.x, m_ptPos.y, m_pgup->vec_pguContent[20], false);
	}
	else
	{
		GraphEngine::AddSquareToBuff(m_ptPos.x, m_ptPos.y,
			m_pgup->vec_pguContent[m_nTexId], false);
	}
}

void Car::Move(int x, int y)
{
	m_ptPos.x += x;
	m_ptPos.y += y;
}

void Car::MoveTo(int x, int y)
{
	m_ptPos = { x,y };
}

SDL_Point& Car::GetPos()
{
	return m_ptPos;
}

void Car::SetTexId(int id)
{
	m_nTexId = id;
}
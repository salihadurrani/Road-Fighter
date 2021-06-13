// Saliha Durrani (2020427)

#pragma once
#include <SDL_ttf.h>
#include "Common.h"

class GraphEngine
{
public:
	static const int SQUARES_X_COUNT = 16;
	static const int SQUARES_Y_COUNT = 14;

	static const int SQUARES_COUNT = SQUARES_X_COUNT * SQUARES_Y_COUNT;

public:
	static bool Init();
	static void Quit();

	static void ChangeWinSize(int times);
	static void ChangeWinTitle(const char* utf8_title);
	static void AddSquareToBuff(int sq_x, int sq_y, GraphUnit* unit, bool bottom = true);
	static void AddSquareToBuff(int sq_index, GraphUnit* unit, bool bottom = true);
	static void AddToBuff(int x, int y, int w, int h, GraphUnit* unit);
	static void PresentBuff();
	static void ClearBuff();
	static GraphUnit* LoadUnitFromFile(const char* filename, bool use_key = false,
									   SDL_Color key = { 0,255,0,255 });
	static GraphUnit* LoadUnitFromMem(void* mem, unsigned int mem_size,
									  bool use_key = false,
									  SDL_Color key = { 0,255,0,255 });
	static GraphUnit* StringToUnit(SDL_Point* size, const char* ansi_cstr);
	static GraphUnitPack*
		LoadSqUnitPackFromFile(const char* filename, bool use_key = false,
							   SDL_Color key = { 0,255,0,255 });
	static GraphUnitPack*
		LoadSqUnitPackFromMem(void* mem, unsigned int mem_size,
							  bool use_key = false,
							  SDL_Color key = { 0,255,0,255 });

	static void FreeUnit(GraphUnit* gu);
	static void FreeUnitPack(GraphUnitPack* gup);

private:
	static SDL_Window* sm_pWin;
	static SDL_Renderer* sm_pRen;
	static int sm_nWinSizeTimes;
	static TTF_Font* sm_pFont;
	struct InBuffGraphUnit
	{
		SDL_Rect* prtDst;
		GraphUnit* pgu;
	};
	static std::vector<InBuffGraphUnit> sm_vec_ibguBuff;

private:
	static SDL_Point __IndexToPoint(int index);
	static int __PointToIndex(int pt_x, int pt_y);
};

// Saliha Durrani (2020427)

#pragma once
#include "Car.h"

class Game
{
public:
	static int Run();
private:
	static GraphUnitPack* sm_pgupTex;
	static unsigned int sm_unScore;
	static bool sm_bIsInRace;
	static std::map<std::string, int> sm_map_strPos_nTexId;
	static std::vector<Car> sm_vec_car;
	static unsigned int sm_unDifficulty;
	static SDL_Event sm_msg;
private:
	static bool __Init();
	static int __StartPage();
	static int __InRace();
	static void __DrawAllCar();
	static void __DrawBackground();
	static void __UpdateBackground();
	static void __GenerateOnRoadCar();
	static void __DeleteOutsideOnRoadCar();
	static void __MoveOnRoadCar();
	static void __ControlPlayerCar();
	static bool __IsThereCollision();
	static Uint32 __CycleCB(Uint32 interval, void* praram);
	static void __FinshedBGMCB();
	static int __EndPage();
	static void __StringToPos(const char* cstr, SDL_Point& ptPos);
	static void __PosToString(std::string& str, SDL_Point ptPos);
	static void __IntToString(std::string& str, int num);
};
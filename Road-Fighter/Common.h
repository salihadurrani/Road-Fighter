// Saliha Durrani (2020427)

#pragma once

struct GraphUnit
{
	SDL_Rect* prtSrc;
	SDL_Texture* pTex;
};

struct GraphUnitPack
{
	std::vector<GraphUnit*> vec_pguContent;
};
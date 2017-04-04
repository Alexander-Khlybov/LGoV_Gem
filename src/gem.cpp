#include "../include/gem.h"

GEMS::GEMS (void){
	g = new size_t[5];
	if (g == NULL)
		throw ("Bad memory allocation.");
	g[0] = 0;
	g[1] = 0;
	g[2] = 0;
	g[3] = 0;
	g[4] = 0;
}

GEMS::GEMS (const GEMS& gems){
	g = new size_t[5]
	if (g == NULL)
		throw ("Bad memory allocation.");
	g[0] = gems.g[0];
	g[1] = gems.g[1];
	g[2] = gems.g[2];
	g[3] = gems.g[3];
	g[4] = gems.g[4];
}

GEMS::~GEMS (void){
	delete[] g;
}

GEMS& GEMS::operator= (const GEMS& gems){
	if (this != &gems){
		delete[] g;
		g = new size_t[5];
		g[0] = gems.g[0];
		g[1] = gems.g[1];
		g[2] = gems.g[2];
		g[3] = gems.g[3];
		g[4] = gems.g[4];
	}
	return *this;
}

void GEMS::createAllStones (void){
	g[1] += g[0] / 3;
	g[2] += g[1] / 3;
	g[3] += g[2] / 3;
	g[4] += g[3] / 3;

	g[0] %= 3;
	g[1] %= 3;
	g[2] %= 3;
	g[3] %= 3;
}

size_t GEMS::setStones (size_t stoneLevel, size_t numberOfStones = 1){
	if (stoneLevel == 0 || stoneLevel > 5)
		return INCORRECT_STONE_LEVEL;
	g[SL(stoneLevel)] += numberOfStones;
	return NO_ERR;
}

size_t GEMS::getNumberOfStones (size_t stoneLevel, size_t& numberOfStones)const{
	if (stoneLevel == 0 || stoneLevel > 5)
		return INCORRECT_STONE_LEVEL;
	numberOfStones = g[SL(stoneLevel)];
	return NO_ERR;
}

size_t GEMS::eraseStone (size_t stoneLevel){
	if (stoneLevel == 0 || stoneLevel > 5)
		return INCORRECT_STONE_LEVEL;
	if (g[SL(stoneLevel)] == 0)
		return STONE_DOES_NOT_EXIST;
	g[SL(stoneLevel)] -= 1;
	return NO_ERR;
}

size_t GEMS::createStone (size_t stoneLevel){
	if (stoneLevel < 2 || stoneLevel > 5)
		return INCORRECT_STONE_LEVEL;
	if (SL(stoneLevel) - 1] / 3 == 0)
		return NOT_ENOUGH_STONES;
	g[SL(stoneLevel)] += 1;
	g[SL(stoneLevel) - 1] -= 3;
	return NO_ERR;
}

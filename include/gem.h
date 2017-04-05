#pragma once

#include "defined_constants.h"

class GEMS {
public:
	GEMS(void);
	GEMS(const GEMS& gems);
	~GEMS(void);

	GEMS& 	operator= (const GEMS& gems);
	size_t	changeData (size_t actionType, size_t stoneLevel = 1, size_t numberOfStones = 1);
	size_t	getData (size_t actionType, size_t& numberOfStones = 1, size_t stoneLevel = 1);
private:
	size_t* g;
protected:
	size_t 	setStones (size_t stoneLevel, size_t numberOfStones);
	size_t 	createStone (size_t stoneLevel);
	size_t 	eraseStone (size_t stoneLevel);
	size_t	createAllStones	(void);
	size_t	eraseAllStones(void);
	size_t	getNumberOfStones (size_t stoneLevel, size_t& numberOfStones)const;
	size_t	getNumberOfAllStones (size_t& numberOfStones)const;
};

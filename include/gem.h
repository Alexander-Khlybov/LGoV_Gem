#pragma once

#define NO_ERR 1
#define INCORRECT_STONE_LEVEL 0
#define STONE_DOES_NOT_EXIST 2
#define NOT_ENOUGH_STONES 6

#define SL(sl) (sl - 1)

class GEMS {
	size_t* g;
public:
	GEMS(void);
	GEMS(const GEMS& gems);
	~GEMS(void);

	GEMS& 	operator= (const GEMS& gems);
	void	createAllStones	(void);
	//every method below returns result from lines 3-6
	size_t 	setStones (size_t stoneLevel, size_t numberOfStones = 1);
	size_t	getNumberOfStones (size_t stoneLevel, size_t& numberOfStones)const;
	size_t 	eraseStone (size_t stoneLevel);
	size_t 	createStone (size_t stoneLevel);
};

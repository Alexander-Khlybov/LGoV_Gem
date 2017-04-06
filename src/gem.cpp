#include "../include/gem.h"

///======================================
/// GEMS
///======================================
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

size_t GEMS::setStones (size_t stoneLevel, size_t numberOfStones){
    if (stoneLevel == 0 || stoneLevel > 5)
        return INCORRECT_STONE_LEVEL;
    g[SL(stoneLevel)] += numberOfStones;
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

size_t GEMS::eraseStone (size_t stoneLevel){
    if (stoneLevel == 0 || stoneLevel > 5)
        return INCORRECT_STONE_LEVEL;
    if (g[SL(stoneLevel)] == 0)
        return STONE_DOES_NOT_EXIST;
    g[SL(stoneLevel)] -= 1;
    return NO_ERR;
}

size_t GEMS::createAllStones (void){
    size_t cost = 0;

    cost += LV2 * (g[0] / 3);
    g[1] += g[0] / 3;
    cost += LV3 * (g[1] / 3);
    g[2] += g[1] / 3;
    cost += LV4 * (g[2] / 3);
    g[3] += g[2] / 3;
    cost += LV5 * (g[3] / 3);
    g[4] += g[3] / 3;

    g[0] %= 3;
    g[1] %= 3;
    g[2] %= 3;
    g[3] %= 3;
    return cost;
}

size_t GEMS::eraseAllStones(void){
    g[0] = 0;
    g[1] = 0;
    g[2] = 0;
    g[3] = 0;
    g[4] = 0;

    return NO_ERR;
}

size_t GEMS::getNumberOfStones (size_t stoneLevel, size_t& numberOfStones)const{
    if (stoneLevel == 0 || stoneLevel > 5)
        return INCORRECT_STONE_LEVEL;
    numberOfStones = g[SL(stoneLevel)];
    return NO_ERR;
}

size_t GEMS::getNumberOfAllStones (size_t& numberOfStones)const{
    numberOfStones = 
        g[0] * CSLV1 +
        g[1] * CSLV2 +
        g[2] * CSLV3 +
        g[3] * CSLV4 +
        g[4] * CSLV5;
    return NO_ERR;
}

size_t  GEMS::changeData (size_t actionType, size_t stoneLevel, size_t numberOfStones){
    switch(actionType){
        case ADD_STONE:
            return setStones(stoneLevel, numberOfStones);
        case CREATE_STONE:
            return createStone(stoneLevel);
        case ERASE_STONE:
            return eraseStone(stoneLevel);
        case FULL_MODIFY:
            return createAllStones();
        case ERASE_ALL_STONES:
            return eraseAllStones();
    }
    return INCORRECT_ACTION_TYPE;
}

size_t  GEMS::getData (size_t actionType, size_t& numberOfStones, size_t stoneLevel)const{
    switch(actionType){
        case NUMBER_OF_STONES_BY_LVL:
            return getNumberOfStones(stoneLevel, numberOfStones);
        case NUMBER_OF_STONES_BY_BASE_LVL:
            return getNumberOfAllStones(numberOfStones);
    }
    return INCORRECT_ACTION_TYPE;
}
/// END SECTION
///======================================

///======================================
/// GEMS_TABLE
///======================================
GEMS_TABLE::GEMS_TABLE(void){
    g = new GEMS[6];
    if (g == NULL)
        throw ("Bad memory allocation.");
}

GEMS_TABLE::GEMS_TABLE(const GEMS_TABLE& gt){
    g = new GEMS[6];
    if (g == NULL)
        throw ("Bad memory allocation.");
    g[0] = gt.g[0];
    g[1] = gt.g[1];
    g[2] = gt.g[2];
    g[3] = gt.g[3];
    g[4] = gt.g[4];
    g[5] = gt.g[5];
}

GEMS_TABLE::~GEMS_TABLE(void){
    delete[] g;
}

size_t GEMS_TABLE::setStones (size_t stoneType, size_t stoneLevel, size_t numberOfStones){
    switch(stoneType){
        case __AMETHYST__:
            return g[0].changeData(ADD_STONE, stoneLevel, numberOfStones);
        case __TOPAZ__:
            return g[1].changeData(ADD_STONE, stoneLevel, numberOfStones);
        case __SAPPHIRE__:
            return g[2].changeData(ADD_STONE, stoneLevel, numberOfStones);
        case __ONYX__:
            return g[3].changeData(ADD_STONE, stoneLevel, numberOfStones);
        case __RUBY__:
            return g[4].changeData(ADD_STONE, stoneLevel, numberOfStones);
        case __DIAMOND__:
            return g[5].changeData(ADD_STONE, stoneLevel, numberOfStones);
    }
    return INCORRECT_STONE_TYPE;
}

size_t GEMS_TABLE::createStone (size_t stoneType, size_t stoneLevel){
    switch(stoneType){
        case __AMETHYST__:
            return g[0].changeData(CREATE_STONE, stoneLevel, numberOfStones);
        case __TOPAZ__:
            return g[1].changeData(CREATE_STONE, stoneLevel, numberOfStones);
        case __SAPPHIRE__:
            return g[2].changeData(CREATE_STONE, stoneLevel, numberOfStones);
        case __ONYX__:
            return g[3].changeData(CREATE_STONE, stoneLevel, numberOfStones);
        case __RUBY__:
            return g[4].changeData(CREATE_STONE, stoneLevel, numberOfStones);
        case __DIAMOND__:
            return g[5].changeData(CREATE_STONE, stoneLevel, numberOfStones);
    }
    return INCORRECT_STONE_TYPE;
}

size_t GEMS_TABLE::eraseStone (size_t stoneType, size_t stoneLevel){
    switch(stoneType){
        case __AMETHYST__:
            return g[0].changeData(ERASE_STONE, stoneLevel, numberOfStones);
        case __TOPAZ__:
            return g[1].changeData(ERASE_STONE, stoneLevel, numberOfStones);
        case __SAPPHIRE__:
            return g[2].changeData(ERASE_STONE, stoneLevel, numberOfStones);
        case __ONYX__:
            return g[3].changeData(ERASE_STONE, stoneLevel, numberOfStones);
        case __RUBY__:
            return g[4].changeData(ERASE_STONE, stoneLevel, numberOfStones);
        case __DIAMOND__:
            return g[5].changeData(ERASE_STONE, stoneLevel, numberOfStones);
    }
    return INCORRECT_STONE_TYPE;
}

size_t GEMS_TABLE::createAllStones (void){
    size_t cost = 
        g[0].changeData(FULL_MODIFY) +
        g[1].changeData(FULL_MODIFY) +
        g[2].changeData(FULL_MODIFY) +
        g[3].changeData(FULL_MODIFY) +
        g[4].changeData(FULL_MODIFY) +
        g[5].changeData(FULL_MODIFY);
    return cost;
}

size_t GEMS_TABLE::eraseAllStones(void){
    g[0].changeData(ERASE_ALL_STONES);
    g[1].changeData(ERASE_ALL_STONES);
    g[2].changeData(ERASE_ALL_STONES);
    g[3].changeData(ERASE_ALL_STONES);
    g[4].changeData(ERASE_ALL_STONES);
    g[5].changeData(ERASE_ALL_STONES);
    return NO_ERR;
}

size_t GEMS_TABLE::getNumberOfStones (size_t stoneType, size_t stoneLevel, size_t& numberOfStones)const{
    switch(stoneType){
        case __AMETHYST__:
            return g[0].getData(NUMBER_OF_STONES_BY_LVL, stoneLevel, numberOfStones);
        case __TOPAZ__:
            return g[1].getData(NUMBER_OF_STONES_BY_LVL, stoneLevel, numberOfStones);
        case __SAPPHIRE__:
            return g[2].getData(NUMBER_OF_STONES_BY_LVL, stoneLevel, numberOfStones);
        case __ONYX__:
            return g[3].getData(NUMBER_OF_STONES_BY_LVL, stoneLevel, numberOfStones);
        case __RUBY__:
            return g[4].getData(NUMBER_OF_STONES_BY_LVL, stoneLevel, numberOfStones);
        case __DIAMOND__:
            return g[5].getData(NUMBER_OF_STONES_BY_LVL, stoneLevel, numberOfStones);
    }
    return INCORRECT_STONE_TYPE;
}

size_t GEMS_TABLE::getNumberOfAllStonesByType (size_t stoneType, size_t& numberOfStones)const{
    switch(stoneType){
        case __AMETHYST__:
            return g[0].getData(NUMBER_OF_STONES_BY_BASE_LVL, numberOfStones);
        case __TOPAZ__:
            return g[1].getData(NUMBER_OF_STONES_BY_BASE_LVL, numberOfStones);
        case __SAPPHIRE__:
            return g[2].getData(NUMBER_OF_STONES_BY_BASE_LVL, numberOfStones);
        case __ONYX__:
            return g[3].getData(NUMBER_OF_STONES_BY_BASE_LVL, numberOfStones);
        case __RUBY__:
            return g[4].getData(NUMBER_OF_STONES_BY_BASE_LVL, numberOfStones);
        case __DIAMOND__:
            return g[5].getData(NUMBER_OF_STONES_BY_BASE_LVL, numberOfStones);
    }
    return INCORRECT_STONE_TYPE;
}

size_t GEMS_TABLE::getNumberOfAllStones (size_t& numberOfStones)const{
    size_t tmp;
    g[0].getData(NUMBER_OF_STONES_BY_BASE_LVL, tmp);
    numberOfStones = tmp;
    g[1].getData(NUMBER_OF_STONES_BY_BASE_LVL, tmp);
    numberOfStones += tmp;
    g[2].getData(NUMBER_OF_STONES_BY_BASE_LVL, tmp);
    numberOfStones += tmp;
    g[4].getData(NUMBER_OF_STONES_BY_BASE_LVL, tmp);
    numberOfStones += tmp;
    g[5].getData(NUMBER_OF_STONES_BY_BASE_LVL, tmp);
    numberOfStones += tmp;
    g[7].getData(NUMBER_OF_STONES_BY_BASE_LVL, tmp);
    numberOfStones += tmp;
    return NO_ERR;
}

GEMS_TABLE& GEMS_TABLE::operator= (const GEMS_TABLE& gt){
    if (this != &gems){
        delete[] g;
        g = new GEMS[6];
        g[0] = gt.g[0];
        g[1] = gt.g[1];
        g[2] = gt.g[2];
        g[3] = gt.g[3];
        g[4] = gt.g[4];
        g[5] = gt.g[5];
    }
    return *this;
}

size_t GEMS_TABLE::changeData (size_t actionType, size_t stoneType, size_t stoneLevel, size_t numberOfStones){
    switch(actionType){
        case ADD_STONE:
            return setStones(stoneType, stoneLevel, numberOfStones);
        case CREATE_STONE:
            return createStone(stoneType, stoneLevel);
        case ERASE_STONE:
            return eraseStone(stoneType, stoneLevel);
        case FULL_MODIFY:
            return createAllStones();
        case ERASE_ALL_STONES:
            return eraseAllStones();
    }
    return INCORRECT_ACTION_TYPE;
}

size_t GEMS_TABLE::getData (size_t actionType, size_t& numberOfStones, size_t stoneType, size_t stoneLevel)const{
    switch(actionType){
        case NUMBER_OF_STONES_BY_LVL:
            return getNumberOfStones(stoneLevel, numberOfStones);
        case NUMBER_OF_STONES_BY_BASE_LVL:
            return getNumberOfAllStonesByType(stoneType, numberOfStones);
        case NUMBER_OF_ALL_STONES_BY_BASE_LVL:
            return getNumberOfAllStones(numberOfStones);
    }
    return INCORRECT_ACTION_TYPE;
}
/// END SECTION
///======================================
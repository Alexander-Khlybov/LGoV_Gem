#pragma once

#include "defined_constants.h"

class GEMS {
public:
    GEMS(void);
    GEMS(const GEMS& gems);
    ~GEMS(void);

    GEMS&   operator= (const GEMS& gems);
    size_t  changeData (size_t actionType, size_t stoneLevel = 1, size_t numberOfStones = 1);
    size_t  getData (size_t actionType, size_t& numberOfStones, size_t stoneLevel = 1)const;
private:
    size_t* g;
protected:
    size_t  setStones (size_t stoneLevel, size_t numberOfStones);
    size_t  createStone (size_t stoneLevel);
    size_t  eraseStone (size_t stoneLevel);
    size_t  createAllStones (void);
    size_t  eraseAllStones(void);
    size_t  getNumberOfStones (size_t stoneLevel, size_t& numberOfStones)const;
    size_t  getNumberOfAllStones (size_t& numberOfStones)const;
};

class GEMS_TABLE {
public:
    GEMS_TABLE(void);
    GEMS_TABLE(const GEMS_TABLE&);
    ~GEMS_TABLE(void);

    GEMS_TABLE& operator= (const GEMS_TABLE&);
    size_t      changeData (size_t actionType, size_t stoneType = __AMETHYST__, 
                            size_t stoneLevel = 1, size_t numberOfStones = 1);
    size_t      getData (   size_t actionType, size_t& numberOfStones, 
                            size_t stoneType = __AMETHYST__, size_t stoneLevel = 1)const;
protected:
    size_t  setStones (size_t stoneType, size_t stoneLevel, size_t numberOfStones);
    size_t  createStone (size_t stoneType, size_t stoneLevel);
    size_t  eraseStone (size_t stoneType, size_t stoneLevel);
    size_t  createAllStones (void);
    size_t  eraseAllStones(void);
    size_t  getNumberOfStones (size_t stoneType, size_t stoneLevel, size_t& numberOfStones)const;
    size_t  getNumberOfAllStonesByType (size_t stoneType, size_t& numberOfStones)const;
    size_t  getNumberOfAllStones (size_t& numberOfStones)const;
private:
    GEMS* g;
};

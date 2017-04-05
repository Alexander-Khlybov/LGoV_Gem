#pragma once

//============== FILE INFO =================
//										  //
//	This header file contains all   	  //
//	the constants and macros 			  //
//	of the program defined by me.		  //
//										  //
//==========================================

///=========================================
///	TYPES OF ERRORS
///=========================================
#define NO_ERR					1
#define INCORRECT_ACTION_TYPE	0
#define INCORRECT_STONE_LEVEL	2
#define STONE_DOES_NOT_EXIST	4
#define NOT_ENOUGH_STONES		6
///	END SECTION
///=========================================

///=========================================
///	ACTIONS TO CHANGE
///=========================================
#define ADD_STONE			7
#define CREATE_STONE		8
#define ERASE_STONE			9
#define FULL_MODIFY			10
#define ERASE_ALL_STONES	11
///	END SECTION
///=========================================

///=========================================
///	ACTIONS TO OBTAIN DATA
///=========================================
#define NUMBER_OF_STONES_BY_TYPE		12
#define NUMBER_OF_STONES_BY_BASE_TYPE	13
/// END SECTION
///=========================================

///=========================================
///	COST OF MAKING A STONE
///=========================================
#define LV2	10
#define LV3	20
#define LV4	35
#define LV5	55
///	END SECTION
///=========================================

///=========================================
///	COST OF STONE
///=========================================
#define CSLV1	1
#define CSLV2	3
#define CSLV3	9
#define CSLV4	27
#define CSLV5	81
///	END SECTION
///=========================================

///=========================================
/// TYPES OF PRECIOUS STONES
///=========================================
#define __AMETHYST__	14
#define __TOPAZ__		15
#define __SAPPHIRE__	16
#define __ONYX__		17
#define __RUBY__		18
#define __DIAMOND__		19
///	END SECTION
///=========================================

#define SL(sl) (sl - 1)

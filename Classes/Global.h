#ifndef  __GLOBAL_H__
#define  __GLOBAL_H__

#include "cocos2d.h"

USING_NS_CC;

const auto SCREEN_WIDTH = 512;							// 屏幕宽度 
const auto SCREEN_HEIGHT = 480;							// 屏幕高度 
const auto SCREEN_CX = SCREEN_WIDTH/2;					// 屏幕宽度的一半 
const auto SCREEN_CY = SCREEN_HEIGHT/2;					// 屏幕高度的一半 
const auto CELL_WIDTH = 16;								// 地图元素的宽 
const auto CELL_HEIGHT = 16;							// 地图元素的高 
const auto MAP_ROW = 26;								// 地图行数 
const auto MAP_COL = 26;								// 地图列数 
const auto MAP_WIDTH = MAP_COL*CELL_WIDTH;				// 地图宽度 
const auto MAP_HEIGHT = MAP_ROW*CELL_HEIGHT;			// 地图高度 
const auto ENEMY_NUM = 20;								// 敌人个数 
const auto LEVEL_NUM = 35;								// 关卡数 
const auto ENEMY_MAX_NUM = 4;							// 敌人种类数 
const auto PLAYER_LIFE = 3;								// 玩家初始生命数 
const auto PLAYER_INIT_LEVEL = 1;						// 玩家坦克初始等级 
const int ENEMY_SCORE[] = { 100, 200, 300, 400 };		// 四种敌人对应的分数 
const auto BONUS_SCORE = 500;							// 道具的分数 
const int ADD_LIFE_SCORE[] = { 20000 };					// 达到多少分会加一条生命（数组顺序由大到小，目前只知道20000分） 

enum Direction    // 方向
{
    UP = 1,        // 上
    RIGHT = 2,        // 右
    DOWN = 3,        // 下
    LEFT = 4,        // 左
};
//
//extern bool g_keyUp;        // 上（W键）
//extern bool g_keyRight;     // 右（D键）
//extern bool g_keyDown;        // 下（S键）
//extern bool g_keyLeft;        // 左（A键）
//extern bool g_keySelect;    // 选择（V键）
//extern bool g_keyStart;        // 开始（B键）
//extern bool g_keyB;            // B按钮（J键）
//extern bool g_keyA;            // A按钮（K键）

/* 通过地图的行列计算出坐标 */
static Vec2 getPos(int row, int col)
{
    Vec2 pos;
    pos.x = col*CELL_WIDTH;
    pos.y = (MAP_ROW - row)*CELL_HEIGHT;
    return pos;
}

#endif

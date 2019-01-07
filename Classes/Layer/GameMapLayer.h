//
//  GameMapLayer.h
//  tankDemo
//
//  Created by Alex on 2018/10/12.
//

#ifndef GameMapLayer_h
#define GameMapLayer_h

#include "cocos2d.h"
#include "Global.h"

enum        // 地图元素类型
{
    LAND,    // 地
    BRICK,    // 砖
    GRID,   // 铁
    GRASS,  // 草
    WATER,  // 水
    ICE,    // 冰
    HOME1,  // 大本营（损坏）其余三角
    HOME2,  // 大本营（损坏）左上角
    HOME3,  // 大本营（完好）其余三角
    HOME4   // 大本营（完好）左上角
};

class GameMapLayer : public cocos2d::LayerColor{
    
public:
    GameMapLayer();
    ~GameMapLayer();
    virtual bool init();
    static GameMapLayer* create();
    
//    bool isCanHit(int row, int col);
    bool isCanWalk(int row, int col);
//    bool isOnIce(Vec2 pos);
    
private:
    int _mapId;
    int _map[MAP_ROW][MAP_COL];
    
    void setupSubLayer();
    void setEdgeBody();
    void addContactListener();
    bool onContactBegin(cocos2d::PhysicsContact& contact);

    void createMapCell(int row, int col, int newType);
    std::string getSpriteName(int type);
//    void setHomeWall(int type);

};


#endif /* GameMapLayer_h */

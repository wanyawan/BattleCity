//
//  MenuScene.h
//  tankDemo
//
//  Created by Alex on 2018/9/17.
//

#ifndef MenuScene_h
#define MenuScene_h

#include "cocos2d.h"

enum Option        // 选项
{
    ONE_PLAYER = 0,        // 一个玩家
    TWO_PLAYERS,    // 两个玩家（未实现该选项功能）
    CONSTRUCTION,    // 建造地图（未实现该选项功能）
    FirstOption = ONE_PLAYER,
    LastOption = CONSTRUCTION
};

class MenuScene : public cocos2d::Scene
{
    
public:
    MenuScene();
    ~MenuScene();
    static MenuScene* create();
    virtual bool init();
    virtual void onEnterTransitionDidFinish();

private :
    virtual void layoutSubLayers();
    /* 移动完毕，显示坦克（箭头） */
    void backgroundMoveOver();
//    /* 设置坦克（箭头）所指选项 */
    void setOption(Option option);

    virtual void update(float delta);
    
    cocos2d::Sprite *_bg;        // 菜单背景
    cocos2d::Sprite *_tank;        // 坦克（箭头）
    bool _bgMoveOver = false;        // 是否移动完毕
    Option _option = ONE_PLAYER;        // 选项
    
};


#endif /* MenuScene_h */

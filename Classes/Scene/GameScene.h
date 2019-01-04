//
//  GameScene.h
//  tankDemo
//
//  Created by Alex on 2018/10/11.
//

#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"
#include "GameMapLayer.h"

class GameScene : public cocos2d::Scene
{
public:
    GameScene();
    ~GameScene();
    static GameScene* create();
    virtual bool init();
    
    virtual void layoutSubviews();
    virtual void onEnterTransitionDidFinish();
    
    GameMapLayer * getMapLayer() { return _mapLayer; };
private:
    GameMapLayer *_mapLayer;
};


#endif /* GameScene_h */

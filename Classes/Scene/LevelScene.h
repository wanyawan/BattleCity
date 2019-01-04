//
//  LevelScene.h
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/9.
//

#ifndef LevelScene_h
#define LevelScene_h

#include "cocos2d.h"

class LevelScene : public cocos2d::Scene
{
public:
    LevelScene();
    ~LevelScene();
    static LevelScene* create();
    virtual bool init();
    
    virtual void layoutSubviews();
    virtual void onEnterTransitionDidFinish();
    
private:
    void update(float dt);
    virtual void updateLevelAndStart();

    int _level = 0;
    float _timeTravel = 0;
    cocos2d::LabelAtlas *_levelLabel;
};

#endif /* LevelScene_h */

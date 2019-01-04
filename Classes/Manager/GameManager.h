//
//  GameManager.h
//  tankDemo
//
//  Created by Alex on 2018/10/11.
//

#ifndef GameManager_h
#define GameManager_h

#include "cocos2d.h"
#include "GameScene.h"

class GameManager : public cocos2d::Ref {
    
public:
    GameManager();
    ~GameManager();
    static GameManager* sharedManager();
    bool init();
    int currentLevel() { return _level; };
    
    void setCurrentGameScene(GameScene *gameScene);
    GameScene* getCurrentGameScene() {return _currentScene;}

//    void currentLevel
    
private:
    int _level = 1;
    GameScene *_currentScene;
};

#endif /* GameManager_h */

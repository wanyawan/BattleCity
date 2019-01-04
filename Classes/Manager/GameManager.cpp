//
//  GameManager.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/11.
//

#include <stdio.h>
#include "GameManager.h"

static GameManager *s_sharedManager = nullptr;

GameManager::GameManager()
{
    
}

GameManager::~GameManager()
{
    
}

GameManager* GameManager::sharedManager() {
    if (!s_sharedManager) {
        s_sharedManager = new (std::nothrow) GameManager();
        CCASSERT(s_sharedManager, "FATAL: Not enough memory");
        s_sharedManager->init();
    }
    return s_sharedManager;
}

bool GameManager::init() {
    return true;
}

void GameManager::setCurrentGameScene(GameScene *gameScene) {
//    _currentScene->re
    _currentScene = gameScene;
}

//
//  SceneManager.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/9/20.
//

#include "SceneManager.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "LevelScene.h"
#include "GameScene.h"
#include "GameManager.h"
USING_NS_CC;

static SceneManager *s_sharedManager = nullptr;

SceneManager::SceneManager() {
    
}

SceneManager::~SceneManager() {
    
}

SceneManager* SceneManager::sharedManager() {
    if (!s_sharedManager) {
        s_sharedManager = new (std::nothrow) SceneManager();
        CCASSERT(s_sharedManager, "FATAL: Not enough memory");
        s_sharedManager->init();
    }
    return s_sharedManager;
}

bool SceneManager::init() {
    return true;
}

void SceneManager::changeScene(SceneType sceneType, TransitionType transitionType) {
    if (sceneType == SceneTypeUnknow || sceneType == _sceneType) {
        return;
    }
    Scene *scene = nullptr;
    _sceneType = sceneType;
    switch (sceneType) {
        case SceneTypeLoading:
            scene = LoadingScene::create();
            break;
        case SceneTypeMenu:
            scene = MenuScene::create();
            break;
        case SceneTypeLevel:
            scene = LevelScene::create();
            break;
        case SceneTypeGame:
            scene = GameScene::create();
            
            GameManager::sharedManager()->setCurrentGameScene( ((GameScene *)scene) );
            break;
        case SceneTypeUnknow:
        default:
            break;
    }
    
    if (!scene) return;
    switch (transitionType) {
        case kTransitionNone:
            
        default:
            break;
    }
    
    if (!scene) return;
    Director::getInstance()->replaceScene(scene);
    _currentScene = scene;
}


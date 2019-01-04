//
//  SceneManager.h
//  tankDemo-mobile
//
//  Created by Alex on 2018/9/20.
//

#ifndef SceneManager_h
#define SceneManager_h

#include "cocos2d.h"
#include "LoadingScene.h"
#include "MenuScene.h"

enum SceneType            // 场景类型
{
    SceneTypeUnknow,
    SceneTypeLoading,        // 加载场景
    SceneTypeMenu,            // 菜单场景
    SceneTypeLevel,        // 关卡过渡场景
    SceneTypeGame            // 游戏场景
//    kGameOverScene        // 游戏结束场景
};

enum TransitionType        // 场景切换效果类型
{
    kTransitionNone,    // 无
//    kTransitionExA,        // 扩展效果A（进入关卡过渡场景的效果）
//    kTransitionExB,        // 扩展效果B（离开关卡过渡场景的效果）
};

class SceneManager : public cocos2d::Ref {
    
public:
    SceneManager();
    ~SceneManager();
    static SceneManager* sharedManager();
    bool init();
    
    void changeScene(SceneType sceneType, TransitionType transitionType=kTransitionNone);
    cocos2d::Scene* getCurrentScene() { return _currentScene; }
private:
    cocos2d::Scene* _currentScene;
    SceneType _sceneType = SceneTypeUnknow;
};

#endif /* SceneManager_h */

//
//  LoadingScene.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/9/17.
//

#include "LoadingScene.h"
#include "SceneManager.h"
#include "Global.h"
#include "Joystick.h"

USING_NS_CC;
using namespace std;

LoadingScene::LoadingScene()
{    
}

LoadingScene::~LoadingScene()
{
}

LoadingScene* LoadingScene::create()
{
    LoadingScene *scene = new (std::nothrow) LoadingScene();
    if (scene && scene->init())
    {
        scene->autorelease();
        return scene;
    } else {
        delete scene;
        scene = nullptr;
        return nullptr;
    }
}

bool LoadingScene::init()
{
    return Scene::init();
}

void LoadingScene::onEnterTransitionDidFinish() {
    vector<string>::iterator it;
//    deque<string>
    vector<string> plists = needLoadPlists();
    for (it = plists.begin(); it != plists.end()  ; ++it) {
        printf("plist %s \n",it->c_str());
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(it->c_str());
    }
    
    vector<string> images = needLoadImages();
    for (it = images.begin(); it != images.end()  ; ++it) {
        printf("image %s \n",it->c_str());
        Director::getInstance()->getTextureCache()->addImageAsync(it->c_str(), std::bind(&LoadingScene::loadResourceCallback, this));
    }
}

vector<string> LoadingScene::needLoadPlists() {
    string plists[] = { "num1.plist", "num2.plist", "player.plist", "enemy.plist", "bonus.plist", "bore.plist", "water.plist", "bomb.plist", "shield.plist" };
    vector<string> vec(begin(plists),end(plists));
    return vec;
}

vector<string> LoadingScene::needLoadImages() {
    string images[] = {"brick.png", "bullet.png", "enemyicon.png", "flag.png", "grass.png", "grid.png", "home1.png", "home2.png", "ice.png", "key1.png", "key2.png",
        "key3.png", "key4.png", "lgameover.png", "menu.png", "p1.png", "pause.png", "playericon.png", "score.png", "sgameover.png", "stage.png"};
    vector<string> vec(begin(images),end(images));
    return vec;
}

void LoadingScene::loadResourceCallback() {
    loadFinishResCount ++;
    vector<string> images = needLoadImages();
    if (loadFinishResCount == images.size()) {
        printf("load finish");
        auto joystick = Joystick::sharedInstance();
        joystick->setOpacity(150);
        Director::getInstance()->setNotificationNode(joystick);
        
        SceneManager::sharedManager()->changeScene(SceneTypeMenu);
    }
}


//
//  LevelScene.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/9.
//

#include "LevelScene.h"
#include "Global.h"
#include "Joystick.h"
#include "SceneManager.h"

USING_NS_CC;
using namespace std;

LevelScene::LevelScene()
{
    
}

LevelScene::~LevelScene()
{
}

LevelScene* LevelScene::create(){
    LevelScene *scene = new (std::nothrow) LevelScene();
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

bool LevelScene::init()
{
    layoutSubviews();
    return Scene::init();
}

void LevelScene::layoutSubviews()
{
    auto layerColor = LayerColor::create(Color4B(126, 126, 126, 255));
    this->addChild(layerColor);
    
    auto stage = Sprite::create("stage.png");
    stage->setPosition(Vec2(234, SCREEN_CY));
    this->addChild(stage);
    
    int currentlevel = 0;
    auto num = __String::createWithFormat("%d", currentlevel)->getCString();
    _levelLabel = LabelAtlas::create(num, "num1.plist");
    _levelLabel->setColor(Color3B::WHITE);
    _levelLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
    _levelLabel->setPosition(Vec2(321, SCREEN_CY));
    this->addChild(_levelLabel);
}

void LevelScene::onEnterTransitionDidFinish()
{
    _timeTravel = 0;
    this->scheduleUpdate();
}

void LevelScene::update(float dt) {
    bool start = KeyStart;
    if (start) {
        updateLevelAndStart();
    }else {
        _timeTravel += dt;
        if (_timeTravel > 0.15) {
            updateLevelAndStart();
        }
    }
}

void LevelScene::updateLevelAndStart() {
//    DataM::getInstance()->setLevelId(_id);
    this->unscheduleUpdate();
    _level++;
    auto num = __String::createWithFormat("%d", _level)->getCString();
    _levelLabel->setString(num);
    SceneManager::sharedManager()->changeScene(SceneTypeGame);
}

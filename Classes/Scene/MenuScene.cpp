//
//  MenuScene.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/9/17.
//

#include "MenuScene.h"
#include "Global.h"
#include "Joystick.h"
#include "SceneManager.h"



#include <sstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

USING_NS_CC;

MenuScene::MenuScene() {
    
}

MenuScene::~MenuScene() {
    
}

MenuScene* MenuScene::create(){
    MenuScene *scene = new (std::nothrow) MenuScene();
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

bool MenuScene::init() {
    layoutSubLayers();
    return Scene::init();
}

void MenuScene::layoutSubLayers() {
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//    Size winSize = Director::getInstance()->getWinSize();
    
    _bg = Sprite::create("menu.png");
    _bg->setAnchorPoint(Vec2(0, 0));
    _bg->setPosition(Vec2(0, -SCREEN_HEIGHT));
    this->addChild(_bg);
    
//    auto score = DataM::getInstance()->getScore();
//    auto strScore = String::createWithFormat("%02d", score)->getCString();
//    auto scoreLabel = LabelAtlas::create(strScore, "num1.plist");
//    scoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
//    scoreLabel->setPosition(Vec2(170, 425));
//    _bg->addChild(scoreLabel);
//
//    auto hightScore = DataM::getInstance()->getHighScore();
//    auto strhightScore = String::createWithFormat("%02d", hightScore)->getCString();
//    auto hightScoreLabel = LabelAtlas::create(strhightScore, "num1.plist");
//    hightScoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
//    hightScoreLabel->setPosition(Vec2(329, 425));
//    _bg->addChild(hightScoreLabel);
    
    this->scheduleUpdate();
}

void MenuScene::onEnterTransitionDidFinish() {
    if (!_bg) {
        return;
    }
    auto action = Sequence::create(
                                   MoveBy::create(5.0f, Vec2(0, SCREEN_HEIGHT)),
                                   CallFunc::create(CC_CALLBACK_0(MenuScene::backgroundMoveOver, this)),
                                   nullptr);
    _bg->runAction(action);
}


void MenuScene::backgroundMoveOver() {
    _tank = Sprite::createWithSpriteFrameName("player1_1_2_1.png");
    this->addChild(_tank);
    this->setOption(ONE_PLAYER);
    _bgMoveOver = true;
    
    Vector<SpriteFrame*> animFrames(2);
    auto cache = SpriteFrameCache::getInstance();
    for (auto i = 1; i < 3; i++)
    {
        auto str = __String::createWithFormat("player1_1_2_%d.png", i)->getCString();
        auto frame = cache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.01f);
    _tank->runAction(RepeatForever::create(Animate::create(animation)));
}

void MenuScene::setOption(Option option)
{
    _option = option;
    auto x = 145.0f;
    auto y = 202.0f - option * 32.0f;
    _tank->setPosition(Vec2(x, y));
}

void MenuScene::update(float fDelta)
{
    if (KeyStart)
    {
        KeyStart = false;
        if (_bgMoveOver)
        {
            switch (_option)
            {
                case ONE_PLAYER:
                    
                    SceneManager::sharedManager()->changeScene(SceneTypeLevel);
//                    this->removeAllChildren();
//                    DataM::getInstance()->init();
//                    SceneM::getInstance()->changeScene(kLevelScene, kTransitionExB);
                    break;
                case TWO_PLAYERS:
                    /* 未实现该选项功能 */
                    break;
                case CONSTRUCTION:
                    /* 未实现该选项功能 */
                    break;
                default:
                    break;
            }
            
        }
        else  // 菜单移动中点击开始按键会直接移动完毕
        {
            _bg->stopAllActions();
            _bg->setPosition(Vec2(0, 0));
            this->backgroundMoveOver();
        }
    }
    if (KeyDirection != DirectionKeyStateNotPressed) {
        if (!_bgMoveOver) {
            KeyDirection = DirectionKeyStateNotPressed;
            return;
        }
        int option = _option;
        if (KeyDirection == DirectionKeyStateUpPressed && Option(option) != FirstOption) {
            option--;
        }else if (KeyDirection == DirectionKeyStateDownPressed && Option(option) != LastOption) {
            option++;
        }
        KeyDirection = DirectionKeyStateNotPressed;
        setOption(Option(option));
    }
}






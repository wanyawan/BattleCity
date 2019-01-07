//
//  GameMapLayer.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/12.
//
#include "GameMapLayer.h"
#include "GameManager.h"
#include <sstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Global.h"

USING_NS_CC;
using namespace std;

GameMapLayer::GameMapLayer() {
    
}

GameMapLayer::~GameMapLayer(){
    
}


GameMapLayer* GameMapLayer::create() {
    GameMapLayer *layer = new (std::nothrow) GameMapLayer();
    if (layer && layer->init())
    {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool GameMapLayer::init(){
    bool result = LayerColor::initWithColor(Color4B(0, 0, 150, 255));
    if (result) {
        _mapId = GameManager::sharedManager()->currentLevel();
        setupSubLayer();
        setEdgeBody();
        addContactListener();
    }
    return result;
}

void GameMapLayer::setupSubLayer() {
    stringstream file1;
    //    auto id = (_id - 1) % LEVEL_NUM + 1; // 最后一关之后，地图从第一关开始
    int id = 1;
    auto name = String::createWithFormat("map%d.txt", id)->getCString();
    auto data = FileUtils::getInstance()->getStringFromFile(name);
    file1.str(data);
    for (auto i = 0; i < MAP_ROW; i++)
    {
        for (auto j = 0; j < MAP_COL; j++)
        {
            file1 >> _map[i][j];
            if(_map[i][j] == BRICK)
            {
                _map[i][j] |= 0xf0;        // 设置该砖块为完整的砖块
            }
            this->createMapCell(i, j, _map[i][j]);
        }
    }
    
//    setContentSize(Size(32 * MAP_COL, 32 * MAP_ROW));
    
    
    //    int index = 1;
    //    string mapName = __String::createWithFormat("map%d.txt", index)->_string;
    //    auto data = FileUtils::getInstance()->getStringFromFile(mapName);
    
//        ifstream ifs;
//        ifs.open(mapName,ios::binary);
    //    int i = 0;
    //    int j = 0;
//        if (ifs.is_open()) {
    //
    //    }
    //
    //    string line;
    //    while (getline(ifs, line)) {
    //        //        line<<l;
    //        printf("line %s",line.c_str());
    //    }
}

void GameMapLayer::setEdgeBody()
{
    float width = 32 * MAP_COL;
    float height = 32 * MAP_ROW;
//    auto size = Size(32 * MAP_COL, 32 * MAP_ROW);
    auto edgeSprite = Node::create();
//    edgeSprite->setContentSize(size);
//    auto body = PhysicsBody::createEdgeBox(size, PHYSICSBODY_MATERIAL_DEFAULT, 4, Vec2::ZERO);
    Vec2 vec[] = {Vec2(0, 0),Vec2(0, height/2),Vec2(width/2, height/2),Vec2(width/2, 0)};
    auto body = PhysicsBody::createEdgePolygon(vec, 4, PhysicsMaterial(1.0, 0, 0), 2);
    body->setDynamic(false);
    body->setCategoryBitmask(0x03);
    body->setContactTestBitmask(0x03);
    body->setCollisionBitmask(0x03);
    body->setGroup(-1);
//    body->setPosition(size.width/2, size.height/2);
    edgeSprite->setPhysicsBody(body);
    this->addChild(edgeSprite);
//
}

void GameMapLayer::addContactListener()
{
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameMapLayer::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool GameMapLayer::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody *bodyA = (PhysicsBody *)contact.getShapeA()->getBody();
    PhysicsBody *bodyB = (PhysicsBody *)contact.getShapeB()->getBody();
    Sprite *spriteA = (Sprite *)bodyA->getNode();
    Sprite *spriteB = (Sprite *)bodyB->getNode();
    if(bodyA->getGroup() < 0 || bodyB->getGroup() < 0)
    {
        if(bodyA->getGroup() >= 0)
        {
            
        } else if (bodyB->getGroup() >= 0)
        {
            
        }
    }else
    {
        
    }
    
//    spriteA
//    int tagA=spriteA->getTag();
//    int tagB=spriteB->getTag();
//    if(tagA==1&&tagB==2||tagA==2&&tagB==1)
//    {
//        spriteA->removeFromParent();
//        spriteB->removeFromParent();
//    }
    return true;
}

void GameMapLayer::createMapCell(int row, int col, int type)
{
    Sprite* cell = NULL;
    int zorder = 1;
    if (type == WATER)
    {
        cell = Sprite::createWithSpriteFrameName("water_01.png");
        cell->setName("water");
        Vector<SpriteFrame*> animFrames(2);
        auto cache = SpriteFrameCache::getInstance();
        for (auto i = 1; i < 3; i++)
        {
            auto name = String::createWithFormat("water_%02d.png", i)->getCString();
            auto frame = cache->getSpriteFrameByName(name);
            animFrames.pushBack(frame);
        }
        auto animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
        cell->runAction(RepeatForever::create(Animate::create(animation)));
    }
    else
    {
        auto name = this->getSpriteName(type);
        if (type == GRASS)
        {
            zorder = 3;        // 草在坦克上方，所以要修改渲染层级
        }
        if (name != "")
        {
            cell = Sprite::create(name);
        }
    }
    if (cell)
    {
        auto tag = row*100 + col;
        cell->setAnchorPoint(Vec2(0.0f, 1.0f));
        cell->setPosition(getPos(row, col));
        
        auto cellBody = PhysicsBody::createBox(cell->getContentSize());
        cellBody->setCategoryBitmask(0x02);
        cellBody->setContactTestBitmask(0x02);
        cellBody->setCollisionBitmask(0x02);
        cellBody->setGroup(0);
        cell->setPhysicsBody(cellBody);
        
        this->addChild(cell, zorder, tag);
    }
}

string GameMapLayer::getSpriteName(int type)
{
    string name;
    switch (type & 0x0f)
    {
        case BRICK:
            name = "brick.png";
            break;
        case GRID:
            name = "grid.png";
            break;
        case GRASS:
            name = "grass.png";
            break;
        case ICE:
            name = "ice.png";
            break;
        case HOME2:
            name = "home2.png";
            break;
        case HOME4:
            name = "home1.png";
            break;
        default:
            break;
    }
    return name;
}

bool GameMapLayer::isCanWalk(int row, int col)
{
    if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_COL)
        return false;
    switch (_map[row][col] & 0x0f)
    {
        case ICE:
        case LAND:
        case GRASS:
            return true;
        default:
            return false;
    }
}

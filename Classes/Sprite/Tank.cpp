//
//  Tank.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/22.
//

#include "Tank.h"
#include "GameManager.h"

Tank::Tank()
{
}

Tank::~Tank()
{
}

bool Tank::init(int type)
{
    bool result = Sprite::init();
    if (result) {
        _type = type;
    }
    return result;
}

//void Tank::setupPhysicsBody()
//{    
//    auto body = PhysicsBody::createBox(this->getContentSize());
//    body->setCategoryBitmask(0x01);
//    body->setContactTestBitmask(0x01);
//    body->setCollisionBitmask(0x01);
//    body->setGroup(0);
//    this->setPhysicsBody(body);
//}

void Tank::setPos(Vec2 pos, Direction direction)
{
    _direction = direction;
    this->setPosition(pos);
    _newPos = pos;
    _step = 0;
}

void Tank::moveUp()
{
//    _newPos.y = _position.y + _speed * 60 * _dt;
    _newPos.y = _position.y + 0.5;
    this->addStep();
}

void Tank::moveDown()
{
    //_newPos.y = _position.y - _speed * 60 * _dt;
    _newPos.y = _position.y - _speed;
    this->addStep();
}

void Tank::moveLeft()
{
    //_newPos.x = _position.x - _speed * 60 * _dt;
    _newPos.x = _position.x - _speed;
    this->addStep();
}

void Tank::moveRight()
{
    //_newPos.x = _position.x + _speed * 60 * _dt;
    _newPos.x = _position.x + _speed;
    this->addStep();
}

void Tank::turnLeft()
{
    if (_direction == UP || _direction == DOWN)
        adjustPosY();
    _direction = LEFT;
}

void Tank::turnRight()
{
    if (_direction == UP || _direction == DOWN)
        adjustPosY();
    _direction = RIGHT;
}

void Tank::turnUp()
{
    if (_direction == RIGHT || _direction == LEFT)
        adjustPosX();
    _direction = UP;
}

void Tank::turnDown()
{
    if (_direction == RIGHT || _direction == LEFT)
        adjustPosX();
    _direction = DOWN;
}

void Tank::adjustPosX()
{
//    auto n = _position.x / CELL_WIDTH;
//    if ((int)(n * 10) % 10 < 4) // 判断坦克坐标接近哪一列
//    {
//        _newPos.x = (int)n * CELL_WIDTH;
//    }
//    else
//    {
//        _newPos.x = (int)(n+1) * CELL_WIDTH;
//    }
//    this->setPositionX(_newPos.x);
}

void Tank::adjustPosY()
{
//    auto n = _position.y / CELL_HEIGHT;
//    if ((int)(n * 10) % 10 < 4) // 判断坦克坐标接近哪一行
//    {
//        _newPos.y = (int)n * CELL_HEIGHT;
//    }
//    else
//    {
//        _newPos.y = (int)(n + 1) * CELL_HEIGHT;
//    }
//    this->setPositionY(_newPos.y);
}

void Tank::addStep()
{
    _step++;
    if (_step >= _stepMax)
    {
        _step = 0;
    }
}

bool Tank::overlapCheck()
{
    return false;
    
//    auto overlap = false;
//    auto &tanks =  GameScene::getTankM()->getAllTanks();
//    for (auto i = 0; i < tanks.size(); i++)
//    {
//        auto tank = tanks.at(i);
//        if (tank == this) continue;
//        auto otherPos = tank->getPosition();
//        /* 坦克前端与另一坦克相交则改变行走方向（如果判断相交就改变方法则会发现两只坦克会一直在转圈） */
//        if (_position.x > otherPos.x - 2 * CELL_WIDTH && _position.x < otherPos.x + 2 * CELL_WIDTH)
//        {
//            if (_direction == UP && _position.y > otherPos.y - 2*CELL_HEIGHT && _position.y < otherPos.y)
//            {
//                overlap = true;
//            }
//            else if (_direction == DOWN && _position.y > otherPos.y && _position.y < otherPos.y + 2 * CELL_HEIGHT)
//            {
//                overlap = true;
//            }
//        }
//        if (_position.y > otherPos.y - 2 * CELL_HEIGHT && _position.y < otherPos.y + 2 * CELL_HEIGHT)
//        {
//            if (_direction == LEFT && _position.x < otherPos.x + 2 * CELL_WIDTH && _position.x > otherPos.x)
//            {
//                overlap = true;
//            }
//            else if (_direction == RIGHT && _position.x < otherPos.x && _position.x > otherPos.x - 2 * CELL_WIDTH)
//            {
//                overlap = true;
//            }
//        }
//    }
//    return overlap;
}

bool Tank::collide(){
    auto collide = false;
    if (collideMap())
    {
        collide = true;
    }
//    if (collideTank())
//    {
//        collide = true;
//    }
    this->setPosition(_newPos);
    return collide;
}

bool Tank::collideMap()
{
    int row, col;
    auto collide = false;
    auto stage = GameManager::sharedManager()->getCurrentGameScene()->getMapLayer();
//    auto stage = GameScene::getStage();
    if (_direction == UP)
    {
        col = (int)(_newPos.x / CELL_WIDTH);
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT) - 1;
        if (row < 0 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row, col - 1))
        {
            _newPos.y = (MAP_ROW - row - 2) * CELL_HEIGHT;
            collide = true;
        }
    }
    else if (_direction == DOWN)
    {
        col = (int)(_newPos.x / CELL_WIDTH);
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT) + 1;
        if (row > MAP_ROW - 1 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row, col - 1))
        {
            _newPos.y = (MAP_ROW - row + 1) * CELL_HEIGHT;
            collide = true;
        }
    }
    else if (_direction == LEFT)
    {
        col = (int)(_newPos.x / CELL_WIDTH) - 1;
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT);
        if (col < 0 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row - 1, col))
        {
            _newPos.x = (col + 2) * CELL_WIDTH;
            collide = true;
        }
    }
    else if (_direction == RIGHT)
    {
        col = (int)(_newPos.x / CELL_WIDTH) + 1;
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT);
        if (col > MAP_COL - 1 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row - 1, col))
        {
            _newPos.x = (col - 1) * CELL_WIDTH;
            collide = true;
        }
    }
    return collide;
}

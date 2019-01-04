//
//  Tank.h
//  tankDemo
//
//  Created by Alex on 2018/10/22.
//

#ifndef Tank_h
#define Tank_h

#include "cocos2d.h"
#include "Global.h"

USING_NS_CC;

class Tank : public Sprite
{
public:
    Tank();
    ~Tank();
    virtual bool init(int type);
    /* 获取坦克类型 */
    int getType(){return _type;}
    /* 被子弹打到 */
//    virtual void hit() = 0;
    
protected:
    /* 初始化位置 */
    void initPos();
    /* 设置位置和方向 */
    void setPos(Vec2 pos, Direction direction);
    /* 向上移动    */
    void moveUp();
    /* 向右移动    */
    void moveRight();
    /* 向下移动    */
    void moveDown();
    /* 向左移动    */
    void moveLeft();
    /* 方向转为向上    */
    void turnUp();
    /* 方向转为向右    */
    void turnRight();
    /* 方向转为向下    */
    void turnDown();
    /* 方向转为向左    */
    void turnLeft();
    /* 由左右移动改为上下移动时，调整x坐标 */
    void adjustPosX();
    /* 由上下移动改为左右移动时，调整y坐标 */
    void adjustPosY();
//    /* 发射子弹 */
//    bool shoot();
    /* 行走动画帧数增加 */
    void addStep();
//    /* 碰撞检测 */
    bool collide();
    /* 与坦克的碰撞检测 */
//    bool collideTank();
//    /* 与地图的碰撞检测 */
    bool collideMap();
    /* 检测是否与其它坦克重叠 */
    bool overlapCheck();
//
//    bool _bomb;                // 是否爆炸
    Vec2 _newPos;            // 移动后的坐标
    int _step;                // 移动时显示哪一帧
    int _stepMax;            // 移动动画总帧数
    float _speed;            // 速度
    int _level;                // 等级
    int _type;                // 类型(0为玩家坦克，1 2 3 4为敌人坦克)
    Direction _direction;    // 方向
//    int _bulletPower;        // 子弹的威力(0不可打破铁，1可打破铁)
//    float _bulletSpeed;        // 子弹的速度
//    int _bulletNumMax;        // 一次能发出多少子弹
//    bool _onIce;            // 是否在冰上
    float _dt;                // 两帧之间的时间间隔
};

#endif /* Tank_h */

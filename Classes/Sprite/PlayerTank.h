//
//  PlayerTank.h
//  tankDemo
//
//  Created by Alex on 2018/10/22.
//

#ifndef PlayerTank_h
#define PlayerTank_h

#include "Tank.h"

class PlayerTank : public Tank
{
public:
    PlayerTank();
    ~PlayerTank();
    static PlayerTank* create(int type);
    bool init(int type);
    /* 初始化位置 */
    void initPos();
//    /* 被子弹打到 */
//    virtual void hit();
//    /* 是否有保护盾 */
//    bool isShield() { return _shield != nullptr; }
//    /* 设置保护盾 */
//    void setShield(float time = 10.0f);
//    /* 获取生命数 */
//    int getLife() { return _life; }
//    /* 获取等级 */
//    int getLevel() { return _level; }
//    /* 增加生命 */
//    void addLife();
//    /* 增加等级 */
//    void addLevel();
//    /* 游戏暂停 */
//    void pauseGame();
//    /* 继续游戏 */
//    void resumeGame();
//    /* 播放行走音效 */
//    void playMoveAudio();
//    /* 停止行走音效 */
//    void stopMoveAudio();
    
private:
    void update(float dt);
//    /* 设置玩家坦克等级 */
//    void setLevel(int level);
//    /* 在冰上打滑 */
//    void trackSlip();
//
//    Sprite* _shield;        // 保护盾
//    float _shootInterval;    // 两次发射子弹的间隔
//    int _life;                // 生命数
    int _inertia;            // 在冰上打滑的步数
//    bool _move;                // 是否行走（包括原地行走），用于 行走效播放判断
//    int _moveAudioId;        // 行走音效id
};

#endif /* PlayerTank_h */

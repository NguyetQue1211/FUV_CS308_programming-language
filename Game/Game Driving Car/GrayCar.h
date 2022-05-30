#pragma once
#include "Actor.h"
class GrayCar : public Actor
{
public:
    GrayCar(class Game* game);
    void UpdateActor(float deltaTime);
    void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
    float GetScrollSpeed() const { return mScrollSpeed; }
private:
    float mScrollSpeed;
};

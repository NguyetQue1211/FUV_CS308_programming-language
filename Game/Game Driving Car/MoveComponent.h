#pragma once
#include "Component.h"

class MoveComponent: public Component
{
public:
    MoveComponent(class Actor* owner, int updateOrder = 10);

    void Update(float deltaTime) override;

    float GetAngularSpeed() const {return mAngularSpeed; }
    float GetVerticalSpeed() const {return mVerticalSpeed; }
    float GetHorizontalSpeed() const {return mHorizontalSpeed; }
    void SetAngularSpeed(float speed) { mAngularSpeed = speed;}
    void SetVerticalSpeed(float speed) { mVerticalSpeed = speed; }
    void SetHorizontalSpeed(float speed) { mHorizontalSpeed = speed; }

private:
    //Controls rotation (radians/second)
    float mAngularSpeed;
    //Controls forward movement (units/second)
    float mVerticalSpeed;
    //Controls horizontal movement (units/second)
    float mHorizontalSpeed;
};

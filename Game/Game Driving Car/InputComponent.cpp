#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
:MoveComponent(owner)
,mForwardKey(0)
,mBackKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
    
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
    // Calculate forward speed for MoveComponent
    float verticalSpeed = 0.0f;
    if (keyState[mForwardKey])
    {
        verticalSpeed += mMaxVerticalSpeed;
        //mMaxForwardSpeed
    }
    if (keyState[mBackKey])
    {
        verticalSpeed -= mMaxVerticalSpeed;
    }
    SetVerticalSpeed(verticalSpeed);

    // Calculate angular speed for MoveComponent
    float angularSpeed = 0.0f;
    if (keyState[mClockwiseKey])
    {
        angularSpeed += mMaxAngularSpeed;
    }
    if (keyState[mCounterClockwiseKey])
    {
        angularSpeed -= mMaxAngularSpeed;
    }
    SetAngularSpeed(angularSpeed);
    
    float horizontalSpeed = 0.0f;
    if (keyState[mRightKey])
    {
        horizontalSpeed += mHorizontalSpeed;
    }
    if (keyState[mLeftKey])
    {
        horizontalSpeed -= mHorizontalSpeed;
    }
    SetHorizontalSpeed(horizontalSpeed);
}

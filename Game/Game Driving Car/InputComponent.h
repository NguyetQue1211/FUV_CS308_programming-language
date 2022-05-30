#pragma once
#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public MoveComponent
{
public:
    // Lower update order to update first
    InputComponent(class Actor* owner);

    void ProcessInput(const uint8_t* keyState) override;
    
    // Getters/setters for private variables
    float GetMaxForward() const { return mMaxVerticalSpeed; }
    float GetMaxAngular() const { return mMaxAngularSpeed; }
    int GetForwardKey() const { return mForwardKey; }
    int GetBackKey() const { return mBackKey; }
    //TEST
    int GetRightKey() const {return mRightKey; }
    int GetLeftKey() const {return mLeftKey; }
    int GetClockwiseKey() const { return mClockwiseKey; }
    int GetCounterClockwiseKey() const { return mCounterClockwiseKey; }

    void SetMaxVerticalSpeed(float speed) { mMaxVerticalSpeed = speed; }
    void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
    //TEST
    void SetMaxHorizontalSpeed(float speed) { mHorizontalSpeed = speed; }
    void SetForwardKey(int key) { mForwardKey = key; }
    void SetBackKey(int key) { mBackKey = key; }
    //TEST
    void SetRightKey(int key) {mRightKey = key; }
    void SetLeftKey(int key) {mLeftKey = key; }
    void SetClockwiseKey(int key) { mClockwiseKey = key; }
    void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }
private:
    // The maximum forward/angular speeds
    float mMaxVerticalSpeed;
    float mMaxAngularSpeed;
    float mHorizontalSpeed;
    // Keys for forward/back movement
    int mForwardKey;
    int mBackKey;
    int mRightKey;
    int mLeftKey;
    // Keys for angular movement
    int mClockwiseKey;
    int mCounterClockwiseKey;
};

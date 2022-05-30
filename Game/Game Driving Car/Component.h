#pragma once
#include <cstdint>

class Component
{
public:
    Component(class Actor* owner, int updateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime);
    // Process input for this component
    virtual void ProcessInput(const uint8_t* keyState) {}
    
    int GetUpdateOrder() const { return mUpdateOrder;}
protected:
    class Actor* mOwner;
    int mUpdateOrder;
};

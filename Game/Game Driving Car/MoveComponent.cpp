#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
:Component(owner, updateOrder)
,mAngularSpeed(0.0f)
,mVerticalSpeed(0.0f)
{
    
}

void MoveComponent::Update(float deltaTime)
{
    if (!Math::NearZero(mAngularSpeed))
    {
        float rot = mOwner->GetRotation();
        rot += mAngularSpeed * deltaTime;
        mOwner->SetRotation(rot);
    }
    
    if (!Math::NearZero(mVerticalSpeed))
    {
        Vector1 pos = mOwner->GetPosition();
        pos += mOwner->GetForward() * mVerticalSpeed * deltaTime;

        mOwner->SetPosition(pos);
    }
    
    if (!Math::NearZero(mHorizontalSpeed))
    {
        Vector1 pos = mOwner->GetPosition();
        pos += mOwner->GetHorizontalMove() * mHorizontalSpeed * deltaTime;

        mOwner->SetPosition(pos);
    }
}

#pragma once
#include <vector>
#include "Math.h"

class Actor {
public:
    enum State
    {
        EActive, EPaused, EDead
    };
    Actor(class Game* game);
    virtual ~Actor();
    
    // Update function called from Game
    void Update(float deltaTime);
    // Updates all the components attached to the acto
    void UpdateComponents(float deltaTime);
    // Any actor-specific update code
    virtual void UpdateActor(float deltaTime);
    //Getter and setters
    
    const Vector1& GetPosition(){return mPosition;}
    void SetPosition(const Vector1& pos) {mPosition = pos;}
    
    float GetScale() const { return mScale; }
    void SetScale(float scale) { mScale = scale; }
    float GetRotation() const { return mRotation; }
    void SetRotation(float rotation) { mRotation = rotation; }
    
    Vector1 GetForward() const { return Vector1(-Math::Sin(mRotation), Math::Cos(mRotation)); }
    
    Vector1 GetHorizontalMove() const {return Vector1(Math::Cos(mRotation), -Math::Sin(mRotation));}
    
    State GetState() const {return mState;}
    void SetState(State state) {mState = state;}
    
    // ProcessInput function called from Game (not overridable)
    void ProcessInput(const uint8_t* keyState);
    // Any actor-specific input code (overridable)
    virtual void ActorInput(const uint8_t* keyState);
    
    class Game* GetGame() { return mGame; }
    
    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);
    
private:
    //Actor's state
    State mState;
    
    //Transform
    Vector1 mPosition;
    float mScale;
    float mRotation;
    
    std::vector<class Component*> mComponents;
    class Game* mGame;
    
};


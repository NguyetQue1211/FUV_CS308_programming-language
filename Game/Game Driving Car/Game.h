#pragma once
#include <SDL.h>
#include "SDL2_mixer/SDL_mixer.h"
#include <unordered_map>
#include <string>
#include <vector>

class Game
{
public:
    Game();
    // Initialize the game
    bool Initialize();
    // Runs the game loop until the game is over
    void RunLoop();
    // Shutdown the game
    void Shutdown();
    
    void AddActor(class Actor* actor);
    void RemoveActor(class Actor* actor);

    void AddSprite(class SpriteComponent* sprite);
    void RemoveSprite(class SpriteComponent* sprite);
    
    SDL_Texture* GetTexture(const std::string& fileName);
    
private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void LoadData();
    void UnloadData();
    void LoadMedia();

    // Window created by SDL
    SDL_Window* mWindow;
    // Renderer for 2D drawing
    SDL_Renderer* mRenderer;
    // Game should continue to run
    bool mIsRunning;
    Uint32 mTicksCount;
    
    // Map of textures loaded
    std::unordered_map<std::string, SDL_Texture*> mTextures;
    
    // All the actors in the game
    std::vector<class Actor*> mActors;
    
    // Any pending actors
    std::vector<class Actor*> mPendingActors;
    
    bool mUpdatingActors;
    
    //The music that will be played
    Mix_Chunk *mMusic = NULL;
    
    // All the sprite components drawn
    std::vector<class SpriteComponent*> mSprites;
    
    class PlayerCar* mPlayerCar;
    class GrayCar* mGrayCar1; 
    class GrayCar* mGrayCar2;
    class GrayCar* mGrayCar3;
    class GrayCar* mGrayCar4;
};


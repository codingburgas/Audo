#pragma once
#include <mutex>
#include <iostream>
#include "world.hpp"
#include "renderobject.hpp"
#include "utils.hpp"
#include <thread>
#include <chrono>
#include <stop_token>
#include <functional>

#define TILE_SIZE 100
#define UPDATE_RATE 20.f

#ifndef AUDO_GAME
#define AUDO_GAME

using namespace sf;

namespace Audo {
    class Game {
    private:

        Game();

        static Game* instance;
        static bool running;
        std::vector<RenderObject*> renderObjects;
        Clock clock;

        Texture waterTexture;
        Texture deepWaterTexture;
        Texture groundTexture;
        Texture goldTexture;
        Texture copperTexture;
        Texture ironTexture;
        Texture stoneTexture;
        Texture darkStoneTexture;
        Texture snowTexture;

        std::unordered_map<World::TileType, Texture> textureMap;

    public:

        Game(Game& other) = delete;

        void operator=(const Game&) = delete;

        [[nodiscard]]
        static Game* GetInstance() noexcept;

        void Run() noexcept;

        void Init() noexcept;

        void Update(std::stop_token sToken);
        
        void Render();

        void HandleInput();

        void SetBounds() noexcept;

        [[nodiscard]]
        World::TileType GetCurrentClicked(Vector2f& mouse) const noexcept;

        int width;
        int height;
        double deltaTime;
        double zoom;

        View camera;

        RenderWindow window;

        static std::mutex mutex;

        World::TileType currentSelected;

        std::vector<std::vector<Audo::World::Tile*>> map;
        Audo::World::Tile* selectedTile;
    };
}

#endif
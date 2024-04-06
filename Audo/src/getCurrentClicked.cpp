#include "../include/game.hpp"
#include "../include/world.hpp"

using TileType = Audo::World::TileType;

void Audo::Game::GetCurrentClicked(Vector2& mouse) {
    std::println("{0}, {1}", mouse.x, mouse.y);
    Vector2 clickedPos = GetScreenToWorld2D(mouse, this->camera) / TILE_SIZE;

    clickedPos.x = std::floor(clickedPos.x);
    clickedPos.y = std::floor(clickedPos.y) + 2;

    clickedPos = Vector2Clamp(clickedPos, { 0,0 }, { MAP_WIDTH, MAP_HEIGHT });

    std::println("{0}, {1}", clickedPos.x, clickedPos.y);
    TileType clickedTile = map[clickedPos.y][clickedPos.x];
    switch (clickedTile) {
        case TileType::GROUND:
            std::println("You clicked on a grass!");
            break;
        case TileType::IRON:
            std::println("You clicked on iron!");
            break;
        case TileType::BRONZE:
            std::println("You clicked on bronze!");
            break;
        case TileType::GOLD:
            std::println("You clicked on gold!");
            break;
        case TileType::WATER:
            std::println("You clicked on water!");
            break;
        case TileType::DEEP_WATER:
            std::println("You clicked on deep water!");
            break;
        case TileType::SNOW:
            std::println("You clicked on snow!");
            break;
    }
}
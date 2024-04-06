#include "../include/game.hpp"
#include "../include/world.hpp"

using TileType = Audo::World::TileType;

void Audo::Game::GetCurrentClicked(Vector2& mouse) {

    Vector2 clickedPos = GetScreenToWorld2D(mouse, this->camera) / TILE_SIZE;
    TileType clickedTile = map[clickedPos.x][clickedPos.y];
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
#pragma once
#include "../game.hpp"
#include "../textures.hpp"
void draw(Audo::Game* instance) {
    BeginDrawing();

    ClearBackground(BLACK);
    
    BeginMode2D(instance->camera);

    Vector2 startPosition = GetScreenToWorld2D({ 0,0 }, instance->camera);
    Vector2 endPosition = GetScreenToWorld2D({ (float)GetScreenWidth(), (float)GetScreenHeight() }, instance->camera);

    startPosition = Vector2Clamp(startPosition, { 0,0 }, { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE });
    endPosition = Vector2Clamp(endPosition, { 0,0 }, { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE });

    for (size_t i = startPosition.y / TILE_SIZE; i < endPosition.y / TILE_SIZE; ++i) {
        for (size_t j = startPosition.x / TILE_SIZE; j < endPosition.x / TILE_SIZE; ++j) {
            if (instance->map[i][j] == Audo::World::TileType::WATER) {
                DrawTexture(*Audo::Textures::Water::LoadWaterTexture(), j * TILE_SIZE, i * TILE_SIZE, BLUE);
            }
            else if (instance->map[i][j] == Audo::World::TileType::DEEP_WATER) {
                DrawTexture(*Audo::Textures::DeepWater::LoadDeepWaterTexture(), j * TILE_SIZE, i * TILE_SIZE, DARKBLUE);
            }
            else if (instance->map[i][j] == Audo::World::TileType::GROUND) {
                DrawTexture(*Audo::Textures::Grass::LoadGrassTexture(), j * TILE_SIZE, i * TILE_SIZE, GREEN);
            }
            else if (instance->map[i][j] == Audo::World::TileType::GOLD) {
                DrawTexture(*Audo::Textures::Gold::LoadGoldTexture(), j * TILE_SIZE, i * TILE_SIZE, YELLOW);
            }
            else if (instance->map[i][j] == Audo::World::TileType::LITHIUM) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 143, 110, 145, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::IRON) {
                DrawTexture(*Audo::Textures::Iron::LoadIronTexture(), j * TILE_SIZE, i * TILE_SIZE, LIGHTGRAY);
            }
            else if (instance->map[i][j] == Audo::World::TileType::STONE) {
                DrawTexture(*Audo::Textures::Stone::LoadStoneTexture(), j * TILE_SIZE, i * TILE_SIZE, GRAY);
            }
            else if (instance->map[i][j] == Audo::World::TileType::COPPER) {
                DrawTexture(*Audo::Textures::Copper::LoadCopperTexture(), j * TILE_SIZE, i * TILE_SIZE, ORANGE);
            }
            else if (instance->map[i][j] == Audo::World::TileType::DARK_STONE) {
                DrawTexture(*Audo::Textures::DarkStone::LoadDarkStoneTexture(), j * TILE_SIZE, i * TILE_SIZE, DARKGRAY);
            }
            else if (instance->map[i][j] == Audo::World::TileType::SNOW) {
                DrawTexture(*Audo::Textures::Snow::LoadSnowTexture(), j * TILE_SIZE, i * TILE_SIZE, WHITE);
            }
        }
    }

    EndMode2D();

    DrawText((std::to_string(1 / GetFrameTime()) + " fps").data(), 10, 30, 20, WHITE);
    EndDrawing();
}
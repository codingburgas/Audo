#pragma once
#include "../game.hpp"

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
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
            }
            else if (instance->map[i][j] == Audo::World::TileType::DEEP_WATER) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, { 0, 100, 200, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::GROUND) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGREEN);
            }
            else if (instance->map[i][j] == Audo::World::TileType::GOLD) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD_COLOR);
            }
            else if (instance->map[i][j] == Audo::World::TileType::LITHIUM) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 143, 110, 145, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::IRON) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 189, 141, 91, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::STONE) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 128, 128, 128, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::COPPER) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 184, 115, 51, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::DARK_STONE) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 64, 64, 64, 255 });
            }
            else if (instance->map[i][j] == Audo::World::TileType::SNOW) {
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 255, 255, 255, 255 });
            }
        }
    }

    EndMode2D();

    DrawText((std::to_string(1 / GetFrameTime()) + " fps").data(), 10, 30, 20, WHITE);
    DrawText((std::to_string(instance->camera.target.y)).data(), 10, 50, 20, WHITE);

    EndDrawing();
}
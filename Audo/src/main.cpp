#include <iostream>
#include "world.hpp"
#include "raylib.h"
#include "window.hpp"
#include "rlgl.h"
#include "raymath.h"
#include "utils.hpp"

#undef GOLD
#define GOLD_COLOR { 255, 203, 0, 255 }
#define TILE_SIZE 24

int main() {

    InitWindow(Window::width, Window::height, "fortnite");

    Camera2D camera = { 0 };
    camera.zoom = 0.25f;

    int counter = 0;

    std::vector<std::vector<World::TileType>> v;
    World::GenerateWorld(v);

    //SetTargetFPS(144);
    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f / camera.zoom);

            camera.target = Vector2Add(camera.target, delta);

            if (camera.target.x - (Window::width / 2) * camera.zoom < 0) camera.target.x = (Window::width / 2) * camera.zoom;
            if (camera.target.x - (Window::width / 2) * camera.zoom > TILE_SIZE * 1024) camera.target.x = (TILE_SIZE * 1024) - camera.target.x - (Window::width / 2) * camera.zoom;
        }
        const float zoomIncrement = 0.01f;

        float wheel = GetMouseWheelMove();
        if (wheel != 0) {

            if (!((camera.zoom < 0.1 && wheel < 0) || (camera.zoom > 0.5 && wheel > 0)))
            {
                // Get the world point that is under the mouse
                Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

                // Set the offset to where the mouse is
                if (wheel > 0)
                    camera.target = Vector2Add(camera.target, utils::abs(camera.target - mouseWorldPos) / (camera.zoom * 100));
                else
                    camera.target = Vector2Subtract(camera.target, utils::abs(camera.target - mouseWorldPos) / ((camera.zoom - zoomIncrement) * 100));
                
                // Zoom increment
                camera.zoom += (wheel * zoomIncrement);

            }
        }


        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);
        counter = 0;

        Vector2 startPosition = GetScreenToWorld2D({ 0,0 }, camera);
        Vector2 endPosition = GetScreenToWorld2D({ (float)GetScreenWidth(), (float)GetScreenHeight() }, camera);

        startPosition = Vector2Clamp(startPosition, { 0,0 }, { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE });
        endPosition = Vector2Clamp(endPosition, { 0,0 }, { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE });

        for (size_t i = startPosition.y / TILE_SIZE; i < endPosition.y / TILE_SIZE; ++i) {
            for (size_t j = startPosition.x / TILE_SIZE; j < endPosition.x / TILE_SIZE; ++j) {
                counter++;
                if (v[i][j] == World::TileType::WATER) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
                }
                else if (v[i][j] == World::TileType::DEEP_WATER) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, { 0, 100, 200, 255 });
                }
                else if (v[i][j] == World::TileType::GROUND) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGREEN);
                }
                else if (v[i][j] == World::TileType::GOLD) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD_COLOR);
                }
                else if (v[i][j] == World::TileType::LITHIUM) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 143, 110, 145, 255 });
                }
                else if (v[i][j] == World::TileType::IRON) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 189, 141, 91, 255 });
                }
                else if (v[i][j] == World::TileType::STONE) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 128, 128, 128, 255 });
                }
                else if (v[i][j] == World::TileType::COPPER) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 184, 115, 51, 255 });
                }
                else if (v[i][j] == World::TileType::DARK_STONE) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 64, 64, 64, 255 });
                }
                else if (v[i][j] == World::TileType::SNOW) {
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 255, 255, 255, 255 });
                }
            }
        }

        EndMode2D();

        DrawText((std::to_string(1 / GetFrameTime()) + " fps").data(), 10, 10, 20, WHITE);
        DrawText(std::to_string(counter).data(), 10, 30, 20, WHITE);
        DrawText((std::to_string(startPosition.x / TILE_SIZE) + ", " + std::to_string(startPosition.y / TILE_SIZE)).data(), 10, 50, 20, WHITE);
        DrawText((std::to_string(endPosition.x / TILE_SIZE) + ", " + std::to_string(endPosition.y / TILE_SIZE)).data(), 10, 70, 20, WHITE);


        EndDrawing();
    }
}
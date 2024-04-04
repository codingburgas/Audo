#include <iostream>
#include "world.hpp"
#include "raylib.h"
#include "window.hpp"
#include "rlgl.h"
#include "raymath.h"
#include <print>
int main() {

    InitWindow(Window::width, Window::height, "fortnite");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

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
        }

        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

            // Set the offset to where the mouse is
            camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

            // Zoom increment
            const float zoomIncrement = 0.01f;

            camera.zoom += (wheel * zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }


        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);
        counter = 0;

        Vector2 startPosition = GetScreenToWorld2D({ 0,0 }, camera);
        Vector2 endPosition = GetScreenToWorld2D({ (float)GetScreenWidth(), (float)GetScreenHeight() }, camera);

        startPosition = Vector2Clamp(startPosition, { 0,0 }, { MAP_WIDTH * 8, MAP_HEIGHT * 8 });
        endPosition = Vector2Clamp(endPosition, { 0,0 }, { MAP_WIDTH * 8, MAP_HEIGHT * 8 });

        for (size_t i = startPosition.y / 8; i < endPosition.y / 8; ++i) {
            for (size_t j = startPosition.x / 8; j < endPosition.x / 8; ++j) {
                counter++;
                if (v[i][j] == World::TileType::WATER) {
                    DrawRectangle(j * 8, i * 8, 8, 8, BLUE);
                }
                else {
                    DrawRectangle(j * 8, i * 8, 8, 8, DARKGREEN);
                }
            }
        }

        EndMode2D();

        DrawText((std::to_string(1 / GetFrameTime()) + " fps").data(), 10, 10, 20, WHITE);
        DrawText(std::to_string(counter).data(), 10, 30, 20, WHITE);
        DrawText((std::to_string(startPosition.x / 8) + ", " + std::to_string(startPosition.y / 8)).data(), 10, 50, 20, WHITE);
        DrawText((std::to_string(endPosition.x / 8) + ", " + std::to_string(endPosition.y / 8)).data(), 10, 70, 20, WHITE);


        EndDrawing();
    }
}
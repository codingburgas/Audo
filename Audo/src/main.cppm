#include <iostream>
#include "world.hpp"
#include "raylib.h"
#include "window.hpp"
#include "rlgl.h"
#include "raymath.h"
#include <print>
int main() {

    InitWindow(Window::width, Window::height, "fortnite");
    std::vector<std::vector<World::TileType>> v;
    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    World::GenerateWorld(v);
    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f / camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }

        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

            camera.offset = GetMousePosition();

            camera.target = mouseWorldPos;

            const float zoomIncrement = 0.075f;

            camera.zoom += (wheel * zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }


        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);
        float cameraWidth = GetMonitorWidth(Window::monitor) / (2 * camera.zoom); 
        float cameraHeight = GetMonitorHeight(Window::monitor) / (2 * camera.zoom); 
        float cameraLeft = camera.offset.x - cameraWidth / 2.0f;
        float cameraRight = camera.offset.x + cameraWidth / 2.0f;
        float cameraTop = camera.offset.y - cameraHeight / 2.0f;
        float cameraBottom = camera.offset.y + cameraHeight / 2.0f;
        std::cout << camera.target.y << " " << camera.target.x << " " << GetMonitorHeight(Window::monitor) << "\n";
        for (size_t i = 0; i < MAP_HEIGHT; i++) {
            for (size_t j = 0; j < MAP_WIDTH; j++) {
                if (i >= cameraTop && i <= cameraBottom && j >= cameraLeft && j <= cameraRight) {
                        if (v[i][j] == World::TileType::WATER) {
                            DrawRectangle(j * 8, i * 8, 8, 8, BLUE);
                        }
                        else {
                            DrawRectangle(j * 8, i * 8, 8, 8, DARKGREEN);
                        }
                    }
                }
            }

            EndMode2D();

            EndDrawing();
        }
    }
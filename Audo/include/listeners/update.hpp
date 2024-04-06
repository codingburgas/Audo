#pragma once
#include "../game.hpp"

void update(Audo::Game* instance) {
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        instance->SetBounds();
    }

    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        instance->GetCurrentClicked(mousePos);
    }


    const float zoomIncrement = 0.1;

    float wheel = GetMouseWheelMove();

    // zoom in/out towards mouse position
    if (wheel != 0) {
        Vector2 mouse = GetMousePosition();
        Vector2 before = GetScreenToWorld2D(mouse, instance->camera);

        instance->camera.zoom += wheel * zoomIncrement;

        if (instance->camera.zoom < 0.11) instance->camera.zoom = 0.11;
        else if (instance->camera.zoom > 0.41) instance->camera.zoom = 0.41;

        Vector2 after = GetScreenToWorld2D(mouse, instance->camera);

        instance->camera.target = Vector2Subtract(instance->camera.target, Vector2Subtract(after, before));
    }
}
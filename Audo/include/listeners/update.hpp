#pragma once
#include "../game.hpp"

void update(Audo::Game* instance) {
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {

        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f / instance->camera.zoom);
        instance->camera.target = Vector2Add(instance->camera.target, delta);



        if (instance->camera.target.x - (instance->width / 2) * instance->camera.zoom < 0) instance->camera.target.x = (instance->width / 2) * instance->camera.zoom;
        if (instance->camera.target.y - (instance->height / 2) * instance->camera.zoom < 0) instance->camera.target.y = (instance->height / 2) * instance->camera.zoom;

        //vector with camera bounds -> works for both x/y
        std::vector<float> cameraBounds = {
         19253.25f, 19104.75f, 18938.273438f, 18765.167969f, 18591.777344f,
         18396.193359f, 18189.298828f, 17976.751853f, 17764.203878f, 17469.074219f,
         17234.947266f, 16931.408203f, 16607.429688f, 16250.011719f, 15873.304688f,
         15479.590820f, 14998.400391f, 14502.624023f, 13959.341797f, 13323.376953f,
         12606.097656f, 11823.172852f, 10893.182617f, 9871.197266f, 8621.201172f,
         7165.808594f, 5383.988770f
        };

        //iterate over the vector
        for (uint8_t i = 0; i < cameraBounds.size(); i++) {

            float zoomLowerBound = 0.36f - i * 0.01f - 0.001f;
            float zoomUpperBound = 0.36f - i * 0.01f + 0.001f;

            if (instance->camera.zoom > zoomLowerBound && instance->camera.zoom < zoomUpperBound) {

                if (instance->camera.target.x > cameraBounds[i]) {
                    instance->camera.target.x = cameraBounds[i];
                    break;
                }

                if (instance->camera.target.y > cameraBounds[i]) {
                    instance->camera.target.y = cameraBounds[i];
                    break;
                }

            }
        }
    }
    const float zoomIncrement = 0.1;

    float wheel = GetMouseWheelMove();

    // zoom in/out towards mouse position
    if (wheel != 0) {
        Vector2 mouse = GetMousePosition();
        Vector2 before = GetScreenToWorld2D(mouse, instance->camera);

        instance->camera.zoom += wheel * zoomIncrement;

        if (instance->camera.zoom < 0.12) instance->camera.zoom = 0.12;
        else if (instance->camera.zoom > 0.75) instance->camera.zoom = 0.75;

        Vector2 after = GetScreenToWorld2D(mouse, instance->camera);

        instance->camera.target = Vector2Subtract(instance->camera.target, Vector2Subtract(after, before));
    }
}
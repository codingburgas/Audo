//#pragma once
//#include "../game.hpp"
//
//void input(Audo::Game* instance) {
//    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
//        instance->mutex.lock();
//        instance->SetBounds();
//        instance->mutex.unlock();
//    }
//
//    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
//        Vector2 mousePos = GetMousePosition();
//        instance->currentSelected = instance->GetCurrentClicked(mousePos);
//        if (instance->currentSelected.has_value()) {
//            if (instance->currentSelected == Audo::World::TileType::GROUND)
//                std::println("negrocito");
//        }
//        else {
//            std::cout << instance->currentSelected.error();
//            abort();
//        }
//    }
//
//
//    const float zoomIncrement = 0.1;
//
//    float wheel = GetMouseWheelMove();
//
//    // zoom in/out towards mouse position
//    instance->mutex.lock();
//    if (wheel != 0) {
//        Vector2 mouse = GetMousePosition();
//        Vector2 before = GetScreenToWorld2D(mouse, instance->camera);
//
//        instance->camera.zoom += wheel * zoomIncrement;
//
//        if (instance->camera.zoom < 0.11) instance->camera.zoom = 0.11;
//        else if (instance->camera.zoom > 0.41) instance->camera.zoom = 0.41;
//
//        Vector2 after = GetScreenToWorld2D(mouse, instance->camera);
//
//        instance->camera.target = Vector2Subtract(instance->camera.target, Vector2Subtract(after, before));
//    }
//    instance->mutex.unlock();
//}
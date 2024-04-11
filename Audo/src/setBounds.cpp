//#include "../include/game.hpp"
//
//void Audo::Game::SetBounds() noexcept {
//    Vector2 delta = GetMouseDelta();
//    delta = Vector2Scale(delta, -1.0f / this->camera.zoom);
//    this->camera.target = Vector2Add(this->camera.target, delta);
//
//
//
//    if (this->camera.target.x - (this->width / 2) * this->camera.zoom < 0) this->camera.target.x = (this->width / 2) * this->camera.zoom;
//    if (this->camera.target.y - (this->height / 2) * this->camera.zoom < 0) this->camera.target.y = (this->height / 2) * this->camera.zoom;
//
//
//    // iterate over the vector
//    for (uint8_t i = 0; i < this->cameraBounds.size(); i++) {
//
//        float zoomLowerBound = 0.36f - i * 0.01f - 0.001f;
//        float zoomUpperBound = 0.36f - i * 0.01f + 0.001f;
//
//        if (this->camera.zoom > zoomLowerBound && this->camera.zoom < zoomUpperBound) {
//            if (this->camera.target.x > this->cameraBounds[i]) {
//                this->camera.target.x = this->cameraBounds[i];
//                break;
//            }
//        }
//    }
//
//    for (uint8_t i = 0; i < this->cameraBoundsY.size(); i++) {
//
//        float zoomLowerBound = 0.41f - i * 0.1f - 0.001f;
//        float zoomUpperBound = 0.41f - i * 0.1f + 0.001f;
//
//        std::cout << "Camera Bounds: " << std::endl;
//        std::cout << zoomLowerBound << " " << zoomUpperBound << std::endl;
//
//        if (this->camera.zoom > zoomLowerBound && this->camera.zoom < zoomUpperBound) {
//            if (this->camera.target.y > this->cameraBoundsY[i]) {
//                this->camera.target.y = this->cameraBoundsY[i];
//                break;
//            }
//        }
//    }
//}
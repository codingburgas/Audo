#include "../include/listeners.hpp"

int main() {
	Audo::Game* game = Audo::Game::GetInstance();

	game->updateEvent.Attach(update);
	game->drawEvent.Attach(draw);

	game->Run();

	// Camera2D camera = { 0 };
	// camera.zoom = 0.36f;

	// int counter = 0;

	// std::vector<std::vector<Audo::World::TileType>> v;
	// Audo::World::GenerateWorld(v);

	// //SetTargetFPS(144);
	// while (!WindowShouldClose()) {

	//     if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
	//         Vector2 delta = GetMouseDelta();
	//         delta = Vector2Scale(delta, -1.0f / camera.zoom);
	//         camera.target = Vector2Add(camera.target, delta);



	//         if (camera.target.x - (Audo::Window::width / 2) * camera.zoom < 0) camera.target.x = (Audo::Window::width / 2) * camera.zoom;
	//         if (camera.target.y - (Audo::Window::height / 2) * camera.zoom < 0) camera.target.y = (Audo::Window::height / 2) * camera.zoom;

	//         std::vector<float> cameraBounds = {
	//          19253.25f, 19104.75f, 18938.273438f, 18765.167969f, 18591.777344f,
	//          18396.193359f, 18189.298828f, 17976.751853f, 17764.203878f, 17469.074219f,
	//          17234.947266f, 16931.408203f, 16607.429688f, 16250.011719f, 15873.304688f,
	//          15479.590820f, 14998.400391f, 14502.624023f, 13959.341797f, 13323.376953f,
	//          12606.097656f, 11823.172852f, 10893.182617f, 9871.197266f, 8621.201172f,
	//          7165.808594f, 5383.988770f
	//         };



	//         for (unsigned int i = 0; i < cameraBounds.size(); i++) {
	//             float zoomLowerBound = 0.36f - i * 0.01f - 0.001f;
	//             float zoomUpperBound = 0.36f - i * 0.01f + 0.001f;
	//             if (camera.zoom > zoomLowerBound && camera.zoom < zoomUpperBound && camera.target.x > cameraBounds[i]) {
	//                 if (camera.target.x > cameraBounds[i]) {
	//                     camera.target.x = cameraBounds[i];
	//                     break;
	//                 }
	//                 if (camera.target.y > cameraBounds[i]) {
	//                     camera.target.y = cameraBounds[i];
	//                     break;
	//                 }
	//             }
	//     }
	//     const float zoomIncrement = 0.1;

	//     float wheel = GetMouseWheelMove();

	//     // zoom in/out towards mouse position
	//     if (wheel != 0) {
	//         Vector2 mouse = GetMousePosition();
			 //Vector2 before = GetScreenToWorld2D(mouse, camera);

			 //camera.zoom += wheel * zoomIncrement;

	//         if (camera.zoom < 0.12) camera.zoom = 0.12;
	//         else if (camera.zoom > 0.75) camera.zoom = 0.75;

			 //Vector2 after = GetScreenToWorld2D(mouse, camera);

			 //camera.target = Vector2Subtract(camera.target, Vector2Subtract(after, before));
	//     }


	//     BeginDrawing();

	//     ClearBackground(BLACK);

	//     BeginMode2D(camera);
	//     counter = 0;

	//     Vector2 startPosition = GetScreenToWorld2D({ 0,0 }, camera);
	//     Vector2 endPosition = GetScreenToWorld2D({ (float)GetScreenWidth(), (float)GetScreenHeight() }, camera);
	//     
	//     startPosition = Vector2Clamp(startPosition, { 0,0 }, { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE });
	//     endPosition = Vector2Clamp(endPosition, { 0,0 }, { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE });

	//     for (size_t i = startPosition.y / TILE_SIZE; i < endPosition.y / TILE_SIZE; ++i) {
	//         for (size_t j = startPosition.x / TILE_SIZE; j < endPosition.x / TILE_SIZE; ++j) {
	//             counter++;
	//             if (v[i][j] == Audo::World::TileType::WATER) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
	//             }
	//             else if (v[i][j] == Audo::World::TileType::DEEP_WATER) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, { 0, 100, 200, 255 });
	//             }
	//             else if (v[i][j] == Audo::World::TileType::GROUND) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGREEN);
	//             }
	//             else if (v[i][j] == Audo::World::TileType::GOLD) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD_COLOR);
	//             }
	//             else if (v[i][j] == Audo::World::TileType::LITHIUM) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 143, 110, 145, 255 });
	//             }
	//             else if (v[i][j] == Audo::World::TileType::IRON) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 189, 141, 91, 255 });
	//             }
	//             else if (v[i][j] == Audo::World::TileType::STONE) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 128, 128, 128, 255 });
	//             }
	//             else if (v[i][j] == Audo::World::TileType::COPPER) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 184, 115, 51, 255 });
	//             }
	//             else if (v[i][j] == Audo::World::TileType::DARK_STONE) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 64, 64, 64, 255 });
	//             }
	//             else if (v[i][j] == Audo::World::TileType::SNOW) {
	//                 DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, Color{ 255, 255, 255, 255 });
	//             }
	//         }
	//     }

	//     EndMode2D();

	//     DrawText((std::to_string(1 / GetFrameTime()) + " fps").data(), 10, 10, 20, WHITE);
	//     DrawText(std::to_string(counter).data(), 10, 30, 20, WHITE);
	//     DrawText((std::to_string(startPosition.x / TILE_SIZE) + ", " + std::to_string(startPosition.y / TILE_SIZE)).data(), 10, 50, 20, WHITE);
	//     DrawText((std::to_string(endPosition.x / TILE_SIZE) + ", " + std::to_string(endPosition.y / TILE_SIZE)).data(), 10, 70, 20, WHITE);


	//     EndDrawing();
	// }
}
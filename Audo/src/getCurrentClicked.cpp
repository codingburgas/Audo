//#include "../include/game.hpp"
//#include "../include/world.hpp"
//
//using TileType = Audo::World::TileType;
//
//std::expected<TileType, AUDO_ERROR> Audo::Game::GetCurrentClicked(Vector2& mouse) const noexcept {
//    Vector2 clickedPos = GetScreenToWorld2D(mouse, this->camera) / TILE_SIZE;
//
//    const std::vector<std::vector<Audo::World::TileType>>::size_type* height = new std::vector<std::vector<Audo::World::TileType>>::size_type(map.size());
//    if (clickedPos.y >= 0 && clickedPos.y < *height) {
//        const std::vector<Audo::World::TileType>& row = this->map[static_cast<size_t>(clickedPos.y)];
//        const std::vector<Audo::World::TileType>::size_type* width = new std::vector<Audo::World::TileType>::size_type(row.size());
//
//        if (clickedPos.x >= 0 && clickedPos.x < *width) {
//            delete height;
//            delete width;
//            return row[static_cast<size_t>(clickedPos.x)];
//        }
//    }
//    delete height;
//    return std::unexpected<AUDO_ERROR>(Audo::Error::OUT_OF_BOUNDS().what());
//}
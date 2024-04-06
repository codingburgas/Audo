#pragma once
#include <mutex>
#include <iostream>
#include "world.hpp"
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "utils.hpp"
#include <print>
#include "event.hpp"
#include <expected>

#undef GOLD
#define GOLD_COLOR { 255, 203, 0, 255 }
#define TILE_SIZE 24

#ifndef AUDO_GAME
	#define AUDO_GAME

	namespace Audo {
		class Game {
		private:

			Game();

			static Game* instance_;
			static std::mutex mutex_;
			static bool running_;


		public:

			Game(Game& other) = delete;

			void operator=(const Game&) = delete;

			[[nodiscard]]
			static Game* GetInstance() noexcept;

			void Run() noexcept;

			void Init() noexcept;

			void Update();

			void DrawUI();

			void Draw();

			void SetBounds() noexcept;

			void GetCurrentClicked(Vector2& mouse);


			Camera2D camera;
			double deltaTime;
			std::vector<std::vector<Audo::World::TileType>> map;
			int monitor;
			int height;
			int width;
			World::TileType currentSelected;

			std::vector<float> cameraBounds;
			std::vector<float> cameraBoundsY;

			Event<void, Game*> updateEvent;
			Event<void, Game*> drawEvent;
		};
	}

#endif
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
#include <thread>
#include <chrono>

#undef GOLD
#define GOLD_COLOR { 255, 203, 0, 255 }
#define TILE_SIZE 24
#define UPDATE_RATE 20.f


#ifndef AUDO_GAME
	#define AUDO_GAME

	namespace Audo {
		class Game {
		private:

			Game();

			static Game* instance_;
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


			int width;
			int height;
			int monitor;
			double deltaTime;

			Camera2D camera;
			
			static std::mutex mutex;

			World::TileType currentSelected;

			std::vector<float> cameraBounds;
			std::vector<float> cameraBoundsY;
			std::vector<std::vector<Audo::World::TileType>> map;

			Event<void, Game*> drawEvent;
			Event<void, Game*> inputEvent;
			Event<void, Game*, float> updateEvent;
		};
	}

#endif
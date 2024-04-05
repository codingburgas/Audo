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

			static Game* GetInstance();

			void Run();

			void Init();

			void Update();

			void DrawUI();

			void Draw();

			Camera2D camera;
			double deltaTime;
			std::vector<std::vector<Audo::World::TileType>> map;
			int monitor;
			int height;
			int width;

			Event<void, Game*> updateEvent;
			Event<void, Game*> drawEvent;
		};
	}

#endif
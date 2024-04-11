#pragma once
#include "raylib.h"
#include <memory>
#include <expected>
namespace Audo {
    namespace Textures {
        class Grass {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadGrassTexture() noexcept {
                static std::shared_ptr<Texture2D> grassTexture;
                if (!grassTexture) {
                    grassTexture = std::make_shared<Texture2D>(LoadTexture("../assets/grass.png"));
                }
                return grassTexture;
            }
        };
        class Water {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadWaterTexture() noexcept {
                static std::shared_ptr<Texture2D> waterTexture;
                if (!waterTexture) {
                    waterTexture = std::make_shared<Texture2D>(LoadTexture("../assets/water.png"));
                }
                return waterTexture;
            }
        };
        class Stone {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadStoneTexture() noexcept {
                static std::shared_ptr<Texture2D> stoneTexture;
                if (!stoneTexture) {
                    stoneTexture = std::make_shared<Texture2D>(LoadTexture("../assets/stone.png"));
                }
                return stoneTexture;
            }
        };
        class Snow {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadSnowTexture() noexcept {
                static std::shared_ptr<Texture2D> snowTexture;
                if (!snowTexture) {
                    snowTexture = std::make_shared<Texture2D>(LoadTexture("../assets/snow.png"));
                }
                return snowTexture;
            }
        };
        class Copper {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadCopperTexture() noexcept {
                static std::shared_ptr<Texture2D> copperTexture;
                if (!copperTexture) {
                    copperTexture = std::make_shared<Texture2D>(LoadTexture("../assets/copper.png"));
                }
                return copperTexture;
            }
        };
        class Gold {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadGoldTexture() noexcept {
                static std::shared_ptr<Texture2D> goldTexture;
                if (!goldTexture) {
                    goldTexture = std::make_shared<Texture2D>(LoadTexture("../assets/gold.png"));
                }
                return goldTexture;
            }
        };
        class DeepWater {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadDeepWaterTexture() noexcept {
                static std::shared_ptr<Texture2D> deepWaterTexture;
                if (!deepWaterTexture) {
                    deepWaterTexture = std::make_shared<Texture2D>(LoadTexture("../assets/deep_water.png"));
                }
                return deepWaterTexture;
            }
        };
        class DarkStone {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadDarkStoneTexture() noexcept {
                static std::shared_ptr<Texture2D> darkStoneTexture;
                if (!darkStoneTexture) {
                    darkStoneTexture = std::make_shared<Texture2D>(LoadTexture("../assets/dark_stone.png"));
                }
                return darkStoneTexture;
            }
        };
        class Iron {
        public:
            [[nodiscard]]
            static inline std::shared_ptr<Texture2D> LoadIronTexture() noexcept {
                static std::shared_ptr<Texture2D> ironTexture;
                if (!ironTexture) {
                    ironTexture = std::make_shared<Texture2D>(LoadTexture("../assets/iron.png"));
                }
                return ironTexture;
            }
        };
    }
}
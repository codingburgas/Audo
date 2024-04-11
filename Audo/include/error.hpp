#include <exception>
#include <string>
#include <memory>

#define AUDO_ERROR const char*

namespace Audo {
    namespace Error {
        class OUT_OF_BOUNDS : public std::exception {
        private:
            std::unique_ptr<AUDO_ERROR> error;
        public:
            OUT_OF_BOUNDS() {
                error = std::make_unique<AUDO_ERROR>("Tile is out of bounds");
            }
            // deleteni se maika ti da eba e
            ~OUT_OF_BOUNDS() {
                AUDO_ERROR* ptr = error.release();
                for (int i = 0; i < 25; i++) {
                    delete ptr;
                }
            }

            [[nodiscard]]
            inline virtual AUDO_ERROR what() const noexcept override {
                return *(this->error);
            }
        };


        class INVALID_TILE : public std::exception {
        private:
            std::unique_ptr<AUDO_ERROR> error;
        public:

            INVALID_TILE() {
                error = std::make_unique<AUDO_ERROR>("Tile is out of bounds");
            }

            ~INVALID_TILE() {
                AUDO_ERROR* ptr = error.release();
                for (int i = 0; i < 25; i++) {
                    delete ptr;
                }
            }


            [[nodiscard]]
            inline virtual AUDO_ERROR what() const noexcept override {
                return *(this->error);
            }
        };

        class TEXTURE_ALREADY_LOADED : public std::exception {
        private:
            std::unique_ptr<AUDO_ERROR> error;
        public:

            TEXTURE_ALREADY_LOADED() {
                error = std::make_unique<AUDO_ERROR>("Texture has been already loaded");
            }

            ~TEXTURE_ALREADY_LOADED() {
                AUDO_ERROR* ptr = error.release();
                for (int i = 0; i < 25; i++) {
                    delete ptr;
                }
            }


            [[nodiscard]]
            inline virtual AUDO_ERROR what() const noexcept override {
                return *(this->error);
            }
        };

    }
}
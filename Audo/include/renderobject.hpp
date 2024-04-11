#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Audo {
	class RenderObject {
	protected:
		Sprite sprite;

	public:
		virtual void init(Texture& texture, Vector2f position);
		virtual void setPosition(Vector2f position);
		virtual void setOrigin(Vector2f origin);
		virtual void draw(RenderWindow& window);
		virtual void setScale(Vector2f scale);
		virtual void move(Vector2f offset);
		virtual Vector2f getPosition();
		Vector2f getSize();
		Sprite getSprite();

		void setTexture(Texture& texture);

		bool shouldDraw{ true };
	};
}
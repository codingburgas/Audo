#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Audo {
	class RenderObject {
	protected:
		Sprite sprite;

	public:
		virtual void Init(Texture& texture, Vector2f position);

		virtual void Draw(RenderWindow& window);

		virtual void Move(Vector2f offset);
		
		// Setters
		virtual void SetScale(Vector2f scale);

		virtual void SetPosition(Vector2f position);

		virtual void SetOrigin(Vector2f origin);

		// Getters
		[[nodiscard]]
		virtual Vector2f GetPosition();

		[[nodiscard]]
		Vector2f GetSize();

		[[nodiscard]]
		Sprite GetSprite();

		void SetTexture(Texture& texture);

		bool shouldDraw{ true };
	};
}
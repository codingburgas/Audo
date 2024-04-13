#include "../include/renderobject.hpp"
using namespace Audo;

void RenderObject::Init(Texture& texture, Vector2f position) {
	this->sprite.setTexture(texture);
	this->sprite.setOrigin(Vector2f((float)(texture.getSize().x) / 2, (float)(texture.getSize().y) / 2));
	this->sprite.setPosition(position);
}

void RenderObject::Move(Vector2f offset) {
	this->sprite.move(offset);
}

void RenderObject::Draw(RenderWindow& window) {
	window.draw(this->sprite);
}

void RenderObject::SetOrigin(Vector2f origin) {
	this->sprite.setOrigin(origin);
}

void RenderObject::SetPosition(Vector2f position) {
	this->sprite.setPosition(position);
}

Vector2f RenderObject::GetPosition() {
	return this->sprite.getPosition();
}

void RenderObject::SetTexture(Texture& texture) {
	this->sprite.setTexture(texture);
}

void RenderObject::SetScale(Vector2f scale) {
	this->sprite.setScale(scale);
}

Vector2f RenderObject::GetSize() {
	return Vector2f(this->sprite.getTexture()->getSize());
}

Sprite RenderObject::GetSprite() {
	return this->sprite;
}
#pragma once
#include "renderobject.hpp"

namespace Audo {
	enum class ItemType {
		GOLD_INGOT,
		COPPER_INGOT,
		IRON_INGOT,
		
		IRON_ORE,
		COPPER_ORE,
		GOLD_ORE,
		STONE
	};

	enum class ItemCategory {
		INGOT,
		ORE,
		MISC,
		ALL
	};

	class Item : public RenderObject {
	public:
		ItemCategory category;
		ItemType type;

		Item(ItemCategory category, ItemType type) : category(category), type(type) {};
	};
}
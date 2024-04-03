#pragma once
#include "raylib.h"

namespace Window {

	int monitor = GetCurrentMonitor();
	int height = GetMonitorHeight(monitor);
	int width = GetMonitorWidth(monitor);

}

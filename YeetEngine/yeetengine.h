#pragma once
#include "c_engine.h"














namespace yeetengine {
	void init(LPDIRECT3DDEVICE9 m_device, HWND m_window);
	double get_deltatime();

	void update();

	void new_frame();
	void draw();
	void end();

	extern c_engine* m_engine;
}
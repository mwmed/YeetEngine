#pragma once
#include "yeet_includes.h"
#include <yeet_rectangle.h>











namespace yeetgame {
	class c_boxcanvas {
	public:
		inline c_boxcanvas() {}


		yeetengine::yeet_rectangle m_rectangle;
		ImU32 m_color = 0xFFFFFFFF;


		void update();
	};
}
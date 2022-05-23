#pragma once
#include "yeet_drawable.h"
#include "c_gameobject.h"




















namespace yeetengine {
	class yeet_rectangle : public yeet_drawable{
	public:
		inline yeet_rectangle(ImVec4 p_rectangle = ImVec4(0, 0, 0, 0), ImU32 col = 0xFFFFFFFF, bool filled = true) : m_rectangle(p_rectangle), m_filled(filled), m_color(col) {}


		ImVec4 m_rectangle;
		ImU32 m_color = 0xFFFFFFFF;
		bool m_filled = false;

		bool is_hovering(POINT p);


	public:
			// Inherited via yeet_drawable
		virtual void draw() override;
	};
}
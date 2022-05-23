#include "pch.h"
#include "yeet_rectangle.h"

bool yeetengine::yeet_rectangle::is_hovering(POINT m_mousepos)
{
    return (m_mousepos.x >= m_rectangle.x) && (m_mousepos.x <= m_rectangle.z) && (m_mousepos.y >= m_rectangle.y) && (m_mousepos.y <= m_rectangle.w);

}

void yeetengine::yeet_rectangle::draw()
{
	auto m_drawlist = ImGui::GetForegroundDrawList();
	if (m_filled)
		m_drawlist->AddRectFilled(ImVec2(m_rectangle.x, m_rectangle.y), ImVec2(m_rectangle.z, m_rectangle.w), m_color);
	else
		m_drawlist->AddRect(ImVec2(m_rectangle.x, m_rectangle.y), ImVec2(m_rectangle.z, m_rectangle.w), m_color);
}


#include "yeetengine.h"
#include "yeet_frametimer.h"



yeetengine::yeet_frametimer m_frametimer;

namespace yeetengine {
	c_engine* m_engine = nullptr;
}
void yeetengine::init(LPDIRECT3DDEVICE9 m_device, HWND m_window)
{
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(m_window);
	ImGui_ImplDX9_Init(m_device);

	m_engine = new c_engine();

	m_engine->on_create();



}

double yeetengine::get_deltatime()
{
	return m_frametimer.get_elapsed_time();
}

void yeetengine::update()
{
	m_frametimer.tick();
}

void yeetengine::new_frame()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	m_engine->m_objectmanager->update();
}

void yeetengine::draw()
{
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void yeetengine::end()
{
	ImGui::EndFrame();

}

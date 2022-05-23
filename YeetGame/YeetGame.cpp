#include <base_window.h>
#include <yeetengine.h>
#include <yeet_rectangle.h>

#include "c_gamemanager.h"
#pragma comment(lib, "yeetengine")

D3DCOLOR clear_color = D3DCOLOR_RGBA(35, 35, 35, 125);

int  main(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
    yeet_framework::base_window* m_window = new yeet_framework::base_window(hInstance, "YeetRoyale", "Yeet_Window");


	if (!m_window->create()) {
		spdlog::error("failed to create window.");
		system("pause");
		return -1;
	}

	auto device = m_window->get_d3dbase()->get_device();

	yeetengine::init(device, m_window->get_window());
	yeetgame::c_gamemanager* m_gamemanager = new yeetgame::c_gamemanager();
	yeetengine::m_engine->m_objectmanager->create_new_gameobject(m_gamemanager);



	bool done = false;

	while (!done) 
	{
		yeetengine::update();
		done = m_window->get_message() == false;
		yeetengine::new_frame();

		yeetengine::end();
		device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_color, 1.0f, 0);
		if (device->BeginScene() >= 0) {

			yeetengine::draw();
			device->EndScene();
		}
		HRESULT result = device->Present(NULL, NULL, NULL, NULL);

	}
	while (!done) {

		yeetengine::update();
		MSG msg;
		while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done)
			break;

		yeetengine::new_frame();

		yeetengine::yeet_rectangle m_rectangle(ImVec4(15,15,15,15));

		m_rectangle.draw();

		yeetengine::end();
		device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_color, 1.0f, 0);
		if (device->BeginScene() >= 0) {

			yeetengine::draw();
			device->EndScene();
		}
		HRESULT result = device->Present(NULL, NULL, NULL, NULL);

	}
}


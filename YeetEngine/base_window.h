#pragma once
#include "base_d3d.h"















namespace yeet_framework {
	class base_window {
	public:
		inline base_window(HINSTANCE d_module, std::string d_windowtext, std::string d_classtext, int w = 1280, int h = 800) : m_windowtext(d_windowtext), m_classtext(d_classtext), m_module(d_module), m_width(w), m_height(h) {}

	public:
		bool create();

		bool get_message();

		HWND get_window();
		base_d3d* get_d3dbase();

	private:
		HWND m_window = 0;
		std::string m_windowtext = "";
		std::string m_classtext = "";

		WNDCLASSEX m_class;
		HINSTANCE m_module = 0;

		int m_width = 1280;
		int m_height = 800;

	private:

		base_d3d* m_d3dbase = nullptr;
	};
}
#pragma once
#include "yeet_includes.h"
















namespace yeetengine {
	class c_gameobject {
	public:
		virtual void on_create() = 0;
		virtual void update() = 0;
		virtual void on_delete() = 0;


		std::uint64_t m_objid = 0;
		std::uint64_t m_index = 0;

		std::string m_objtag = "Root";
	};
}
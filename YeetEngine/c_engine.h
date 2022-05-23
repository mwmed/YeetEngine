#pragma once
#include "c_objectmanager.h"
#include "c_inputmanager.h"




















namespace yeetengine {
	class c_engine {
	public:
		inline c_engine(){}

	public:
		c_inputmanager* m_inputmanager = nullptr;
		c_objectmanager* m_objectmanager = nullptr;
	public:
		void on_create();
	};
}
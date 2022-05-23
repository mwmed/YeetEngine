#pragma once
#include "yeet_includes.h"
#include "c_gameobject.h"










namespace yeetengine {
	class c_inputmanager : public c_gameobject {
	public:
		inline c_inputmanager() 
		{
			m_objid = 1;
			m_objtag = "c_inputmanager";
		}


		POINT get_cs();
	private:
		POINT m_previouscs;
		POINT m_currentcs;

		BYTE kbkeys[256];
		std::map<std::int8_t, bool> down_keys;


	public:
		// Inherited via c_gameobject

		virtual void on_create() override;
		virtual void on_delete() override;
		virtual void update() override;
	};
}
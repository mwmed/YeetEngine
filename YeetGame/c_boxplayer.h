#pragma once
#include "c_boxcanvas.h"
#include <c_inputobject.h>


















namespace yeetgame {
	class c_boxplayer : public yeetengine::c_gameobject, public yeetengine::c_inputobject 
	{
	public:

		inline c_boxplayer()
		{
			m_objtag = "c_boxplayer";
		}

		ImVec2 m_position;
		ImVec2 m_rotation;
		float m_jumpframe = 0;
		float m_downframe = 0;
	private:
		float m_playerjumpspeed = 10000;
		float m_playerwalkspeed = 5000;

		c_boxcanvas m_canvas;

	public:
		// Inherited via c_gameobject
		virtual void on_create() override;
		virtual void update() override;
		virtual void on_delete() override;

		// Inherited via c_inputobject
		virtual void on_key_up(int key) override;
		virtual void on_key_down(int key) override;

	};
}
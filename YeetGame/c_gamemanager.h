#pragma once
#include "c_boxplayer.h"










namespace yeetgame {
	class c_gamemanager : public yeetengine::c_gameobject {
	public:
		inline c_gamemanager()
		{
			m_objid = 100000;
			m_objtag = "c_gamemanager";
		}




		// Inherited via c_gameobject
		virtual void on_create() override;

		virtual void update() override;

		virtual void on_delete() override;
	private:
		std::vector<c_boxplayer*> m_players;

	};
}
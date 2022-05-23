#include "c_gamemanager.h"
#include <yeetengine.h>
void yeetgame::c_gamemanager::on_create()
{
	c_boxplayer* m_player = new c_boxplayer();
	yeetengine::m_engine->m_objectmanager->create_new_inputobject(m_player);
	m_players.push_back(m_player);
}

void yeetgame::c_gamemanager::update()
{
	for (auto m_object : m_players)
		m_object->update();

}

void yeetgame::c_gamemanager::on_delete()
{
}

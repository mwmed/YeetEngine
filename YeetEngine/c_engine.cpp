#include "c_engine.h"

void yeetengine::c_engine::on_create()
{
	m_inputmanager = new c_inputmanager();
	m_objectmanager = new c_objectmanager();


	m_objectmanager->create_new_gameobject(m_inputmanager);
}

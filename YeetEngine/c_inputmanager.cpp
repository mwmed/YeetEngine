#include "c_inputmanager.h"
#include "yeetengine.h"
void yeetengine::c_inputmanager::on_create()
{
}

void yeetengine::c_inputmanager::on_delete()
{
	delete[] kbkeys;
}

void yeetengine::c_inputmanager::update()
{
    if (GetKeyboardState(kbkeys)) {
        for (int i = 0; i < 256; i++) {
            if (kbkeys[i] & 0x80) {
                down_keys[i] = true;

                m_engine->m_objectmanager->broadcast_input(i, true);
            }
            else if (down_keys[i]) {
                down_keys[i] = false;
                m_engine->m_objectmanager->broadcast_input(i, false);
            }
        }
    }
}

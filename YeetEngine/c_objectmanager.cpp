#include "c_objectmanager.h"

void yeetengine::c_objectmanager::update()
{

    for (auto m_object : m_gameobjects)
        if (m_object.second) {
            m_object.second->update();
        }
}

yeetengine::c_gameobject* yeetengine::c_objectmanager::create_new_gameobject(c_gameobject* m_object)
{

    mtx.lock();
    m_object->on_create();
    ++m_lastindex;
   
    m_gameobjects[m_lastindex] = m_object;
    m_gameobjectid[m_object->m_objid].push_back(m_object);
    m_gameobjecttags[m_object->m_objtag].push_back(m_object);

    m_object->m_index = m_lastindex;

    mtx.unlock();
    return m_object;
}

void yeetengine::c_objectmanager::create_new_inputobject(c_inputobject* m_object)
{
    m_inputobjects.push_back(m_object);
}

void yeetengine::c_objectmanager::remove_gameobject(std::uint64_t m_index)
{
    if (m_gameobjects.find(m_index) != m_gameobjects.end()) {

        auto m_object = m_gameobjects.at(m_index);
        
        if (m_object) {
            auto m_tagit = m_gameobjecttags.find(m_object->m_objtag);
            auto m_idit = m_gameobjectid.find(m_object->m_objid);

            if (m_tagit != m_gameobjecttags.end()) {
                auto& m_objectarray = m_gameobjecttags.at(m_object->m_objtag);
                auto m_objarrayit = std::find(m_objectarray.begin(), m_objectarray.end(), m_object);
                if (m_objarrayit != m_objectarray.end()) {
                    m_objectarray.erase(m_objarrayit);
                }
            }
            if (m_idit != m_gameobjectid.end()) {
                auto& m_objectarray = m_gameobjectid.at(m_object->m_objid);
                auto m_objarrayit = std::find(m_objectarray.begin(), m_objectarray.end(), m_object);
                if (m_objarrayit != m_objectarray.end()) {
                    m_objectarray.erase(m_objarrayit);
                }
            }

            delete m_object;
            m_object = nullptr;
        }
    }
}

void yeetengine::c_objectmanager::broadcast_input(int key, bool is_down)
{
    for (auto object : m_inputobjects) {

        if (object) {
            if (is_down)
                object->on_key_down(key);
            else
                object->on_key_up(key);
        }
    }
}

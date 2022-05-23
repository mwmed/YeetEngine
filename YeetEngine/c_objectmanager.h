#pragma once
#include "c_inputobject.h"
#include "c_gameobject.h"


















namespace yeetengine {
	class c_objectmanager {
	public:
		inline c_objectmanager(){}


	public:
		void update();

	public:
		c_gameobject* create_new_gameobject(c_gameobject* m_object);
		void create_new_inputobject(c_inputobject* m_object);
		void remove_gameobject(std::uint64_t m_index);

	public:
		void broadcast_input(int key, bool is_down);

	private:
		std::map<std::uint64_t, c_gameobject*> m_gameobjects;
		std::map<std::uint64_t, std::vector<c_gameobject*>> m_gameobjectid;
		std::map<std::string, std::vector<c_gameobject*>> m_gameobjecttags;


		std::vector<c_inputobject*> m_inputobjects;

	private:
		std::uint64_t m_lastindex = 0;

	private:
		std::mutex mtx;
	};
}
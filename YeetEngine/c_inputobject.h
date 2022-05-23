#pragma once
#include "yeet_includes.h"
















namespace yeetengine {
	class c_inputobject {
	public:
		virtual void on_key_up(int key) = 0;
		virtual void on_key_down(int key) = 0;
	};
}
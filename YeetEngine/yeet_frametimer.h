#pragma once
#include "yeet_includes.h"













namespace yeetengine {
	class yeet_frametimer {
	public:
		inline yeet_frametimer() {}

		void tick();
		float get_elapsed_time();

	private:
		DWORD64 m_counts_per_sec = 0;
		DWORD64 m_prev = 0;
		float m_frame_count = 0;
	};
}
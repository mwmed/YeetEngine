#include "yeet_frametimer.h"

void yeetengine::yeet_frametimer::tick()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_counts_per_sec);

	m_frame_count = 1.0f / (float)m_counts_per_sec;

	QueryPerformanceCounter((LARGE_INTEGER*)&m_prev);
}

float yeetengine::yeet_frametimer::get_elapsed_time()
{
	INT64 current_time = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&current_time);
	return (current_time - m_prev) * m_frame_count;
}

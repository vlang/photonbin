#include "photonwrapper.h"

using namespace std;

int photon_init_default() {
	return photon::init(photon::INIT_EVENT_DEFAULT, photon::INIT_IO_DEFAULT);
}

void* thread_test_function(void* arg) {
	cout << "test";
}

void photon_thread_create(void* (* f)(void*), void* arg) {
	photon::thread_create(f, arg);
}

void photon_sleep_s(int n) {
	photon_std::this_thread::sleep_for(std::chrono::seconds(n));
}

void photon_sleep_ms(int n) {
	photon_std::this_thread::sleep_for(std::chrono::milliseconds(n));
}

void set_photon_thread_stack_allocator(
	void* (*alloc_func)(void*, size_t),
	void (*dealloc_func)(void*, void*, size_t)) {
	photon::set_photon_thread_stack_allocator({alloc_func, nullptr}, {dealloc_func, nullptr});
}

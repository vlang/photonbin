#include "photonwrapper.h"

using namespace std;
// using namespace photon;

int photon_init_default() {
	return photon::init(photon::INIT_EVENT_DEFAULT, photon::INIT_IO_DEFAULT);
}

// WorkPool* new_photon_work_pool(size_t vcpu_num) {
// 	// return new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE, -1);
// 	return new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE);
// }

void init_photon_work_pool(size_t vcpu_num) {
	work_pool = new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE);
}

void* thread_test_function(void* arg) {
	cout << "test";
}

void photon_thread_create(void* (* f)(void*), void* arg) {
	photon::thread_create(f, arg);
}

void photon_thread_create_and_migrate_to_work_pool(void* (* f)(void*), void* arg) {
	// -1 it will choose the next vCPU in pool (round-robin).
	work_pool->thread_migrate(photon::thread_create(f, arg), -1UL);
}

void photon_sleep_s(int n) {
    photon_std::this_thread::sleep_for(std::chrono::seconds(n));
}

void photon_sleep_ms(int n) {
    photon_std::this_thread::sleep_for(std::chrono::milliseconds(n));
}

// void* default_photon_thread_stack_alloc(void* a, size_t size) {
// 	return photon::default_photon_thread_stack_alloc(a, size);
// }

// void default_photon_thread_stack_dealloc(void* a, void* ptr, size_t size) {
// 	photon::default_photon_thread_stack_dealloc(a, ptr,  size);
// }

void set_photon_thread_stack_allocator(
	void* (*alloc_func)(void*, size_t),
	void (*dealloc_func)(void*, void*, size_t)) {
	photon::set_photon_thread_stack_allocator({alloc_func, nullptr}, {dealloc_func, nullptr});
}

int photon_socket(int domain, int type, int protocol) {
	return photon::net::socket(domain, type, protocol);
}
int photon_connect(int fd, const struct sockaddr *addr, socklen_t addrlen, uint64_t timeout) {
	return photon::net::connect(fd, addr, addrlen, timeout);
}
int photon_accept(int fd, struct sockaddr *addr, socklen_t *addrlen, uint64_t timeout) {
	return photon::net::accept(fd, addr, addrlen, timeout);
}
ssize_t photon_send(int fd, const void* buf, size_t len, int flags, uint64_t timeout) {
	return photon::net::send(fd, buf, len, flags, timeout);
}
// ssize_t photon_sendmsg(int fd, const struct msghdr* msg, int flags, uint64_t timeout) {
// 	return photon::net::sendmsg(fd, msg, flags, timeout);
// }
ssize_t photon_recv(int fd, void* buf, size_t count, int flags, uint64_t timeout) {
	return photon::net::recv(fd, buf, count, flags, timeout);
}
// ssize_t photon_recvmsg(int fd, struct msghdr* msg, int flags, uint64_t timeout) {
// 	return photon::net::recvmsg(fd, msg, flags, timeout);
// }

#include "photonwrapper.h"

using namespace std;
// using namespace photon;

/*
class MyWorkPool : public photon::WorkPool {
public:
	using InitFunction = void(*)();

	MyWorkPool(int vcpu_num, int ev_engine = photon::INIT_EVENT_DEFAULT, int io_engine = photon::INIT_IO_NONE, int mode = 0)
	: photon::WorkPool(vcpu_num, ev_engine, io_engine, mode) {

		if (init_fn) {
			init_fn();
		}
	}

	void worker_thread_routine(int ev_engine, int io_engine) {
	// void worker_thread_routine(int ev_engine, int io_engine) {
		std::cout << "## MyWorkerPool::worker_thead_routine";
		// if (init_fn) {
		//     init_fn();
		// }
		// worker_thread_routine(ev_engine, io_engine);

		// photon::WorkPool::main_loop();
		// main_loop();
	}

	// Set the initialization function
	static void set_init_fn(InitFunction f) {
		init_fn = f;
	}

private:
  static InitFunction init_fn;
};

MyWorkPool::InitFunction MyWorkPool::init_fn = nullptr;
*/

void* default_photon_thread_stack_alloc(void* a, size_t size) {
	return photon::default_photon_thread_stack_alloc(a, size);
}

void default_photon_thread_stack_dealloc(void* a, void* ptr, size_t size) {
	photon::default_photon_thread_stack_dealloc(a, ptr,  size);
}

void set_photon_thread_stack_allocator(
	void* (*alloc_func)(void*, size_t),
	void (*dealloc_func)(void*, void*, size_t)) {
	photon::set_photon_thread_stack_allocator({alloc_func, nullptr}, {dealloc_func, nullptr});
}

int photon_init_default() {
	return photon::init(photon::INIT_EVENT_DEFAULT, photon::INIT_IO_DEFAULT);
}

// PhotonWorkPool* new_photon_work_pool(size_t vcpu_num) {
void* new_photon_work_pool(size_t vcpu_num) {
	// return new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE, -1);
	return new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE);
}

// void delete_photon_work_pool(void* work_pool) {
// 	delete (photon::WorkPool*)work_pool;
// }

void delete_photon_work_pool() {
	// cout << "## delete_photon_work_pool called!\n";
	delete work_pool;
}

void init_photon_work_pool(size_t vcpu_num) {
	work_pool = new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE);
	// work_pool = new photon::WorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE, 10);
}

// void init_photon_my_work_pool(size_t vcpu_num, void (* f1)()) {
// 	MyWorkPool::set_init_fn(f1);
// 	MyWorkPool* work_pool = new MyWorkPool(vcpu_num, photon::INIT_EVENT_DEFAULT, photon::INIT_IO_NONE, -1);
// }

void photon_thread_create(void* (* f)(void*), void* arg) {
	photon::thread_create(f, arg);
	// auto th = photon::thread_create(f, arg);
	// photon::thread_enable_join(th);
}

void photon_thread_migrate() {
	// cout << "## MIGRATE CALLED\n";
	work_pool->thread_migrate();
}

// void photon_thread_migrate(void* work_pool) {
// 	cout << "## MIGRATE CALLED\n";
// 	((photon::WorkPool*)work_pool)->thread_migrate();
// }

void photon_thread_create_and_migrate_to_work_pool(void* (* f)(void*), void* arg) {
	// -1 it will choose the next vCPU in pool (round-robin).
	work_pool->thread_migrate(photon::thread_create(f, arg), -1UL);
}

// void photon_thread_create_and_migrate_to_work_pool(void* work_pool, void* (* f)(void*), void* arg) {
// 	photon::WorkPool* wp = ((photon::WorkPool*)work_pool);
// 	wp->thread_migrate(photon::thread_create(f, arg), -1UL);
// 	// wp->thread_migrate();
// }

void photon_sleep_s(int n) {
    photon_std::this_thread::sleep_for(std::chrono::seconds(n));
}

void photon_sleep_ms(int n) {
    photon_std::this_thread::sleep_for(std::chrono::milliseconds(n));
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

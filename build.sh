
# CREATE WRAPPER.O
c++ -c -I/Users/alex/code/3rd/PhotonLibOS/include -std=c++14 -O0 -g -Wl,-search_paths_first -Wl,-headerpad_max_install_names photonwrapper.cpp  -L/Users/alex/code/3rd/PhotonLibOS/build/output  -Wl,-rpath,/Users/alex/code/3rd/PhotonLibOS/build/output ../build/output/libphoton.a /opt/homebrew/lib/libgtest.a /opt/homebrew/lib/libgtest_main.a /opt/homebrew/lib/libgmock.a /opt/homebrew/lib/libgflags.dylib ../build/output/libeasy_weak.a ../build/output/libfstack_weak.a  /opt/homebrew/Cellar/openssl@3/3.0.8/lib/libssl.dylib /opt/homebrew/Cellar/openssl@3/3.0.8/lib/libcrypto.dylib /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd   -lpthread /opt/homebrew/lib/libgsasl.dylib /opt/homebrew/lib/libgtest.a || exit



# CREATE WRAPPER.SO
c++ -shared -o photonwrapper.so photonwrapper.o \
	-L/Users/alex/code/3rd/PhotonLibOS/build/output  \
	../build/output/libphoton.a      \
	/opt/homebrew/Cellar/openssl@3/3.0.8/lib/libssl.dylib \
	/opt/homebrew/Cellar/openssl@3/3.0.8/lib/libcrypto.dylib \
	/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd   -lpthread   || exit


echo ".SO BUILT"

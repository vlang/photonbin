# CREATE WRAPPER.O
c++ -c -I ~/code/3rd/PhotonLibOS/include -std=c++14 -O0 -g -Wl,-search_paths_first -Wl,-headerpad_max_install_names photonwrapper.cpp  -L ~/code/3rd/PhotonLibOS/build/output  ~/code/3rd/PhotonLibOS/build/output/libphoton.a /opt/homebrew/lib/libgtest.a /opt/homebrew/lib/libgtest_main.a /opt/homebrew/lib/libgmock.a /opt/homebrew/lib/libgflags.dylib ~/code/3rd/PhotonLibOS/build/output/libeasy_weak.a ~/code/3rd/PhotonLibOS/build/output/libfstack_weak.a  /opt/homebrew/Cellar/openssl@3/3.1.3/lib/libssl.dylib /opt/homebrew/Cellar/openssl@3/3.1.3/lib/libcrypto.dylib /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd   -lpthread /opt/homebrew/lib/libgsasl.dylib /opt/homebrew/lib/libgtest.a || exit


echo ".O BUILT"

# CREATE WRAPPER.SO
c++ -shared -o photonwrapper.so photonwrapper.o \
	-L ~/code/3rd/PhotonLibOS/build/output  \
	~/code/3rd/PhotonLibOS/build/output/libphoton.a      \
	/opt/homebrew/Cellar/openssl@3/3.1.3/lib/libssl.dylib \
	/opt/homebrew/Cellar/openssl@3/3.1.3/lib/libcrypto.dylib \
	/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd   -lpthread  


echo ".SO BUILT"


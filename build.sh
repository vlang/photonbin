PHOTON_REPO_PATH=~/code/3rd/PhotonLibOS
OPEN_SSL_PATH=/opt/homebrew/Cellar/openssl@3/3.1.3

# CREATE WRAPPER.O
c++ -c -I $PHOTON_REPO_PATH/include -std=c++14 -O0 -g -Wl,-search_paths_first -Wl,-headerpad_max_install_names photonwrapper.cpp  \
	-L $PHOTON_REPO_PATH/build/output \
	$PHOTON_REPO_PATH/build/output/libphoton.a \
	/opt/homebrew/lib/libgtest.a \
	/opt/homebrew/lib/libgtest_main.a \
	/opt/homebrew/lib/libgmock.a \
	/opt/homebrew/lib/libgflags.dylib \
	$PHOTON_REPO_PATH/build/output/libeasy_weak.a \
	$PHOTON_REPO_PATH/build/output/libfstack_weak.a  \
	$OPEN_SSL_PATH/lib/libssl.dylib \
	$OPEN_SSL_PATH/lib/libcrypto.dylib \
	/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd \
	-lpthread /opt/homebrew/lib/libgsasl.dylib /opt/homebrew/lib/libgtest.a || exit


echo ".O BUILT"

# CREATE WRAPPER.SO
c++ -shared -o photonwrapper.so photonwrapper.o \
	-L $PHOTON_REPO_PATH/build/output  \
	$PHOTON_REPO_PATH/build/output/libphoton.a      \
	$OPEN_SSL_PATH/lib/libssl.dylib \
	$OPEN_SSL_PATH/lib/libcrypto.dylib \
	/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd   -lpthread  


echo ".SO BUILT"


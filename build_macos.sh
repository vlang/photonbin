PHOTON_REPO_PATH=~/dev/src/cpp/PhotonLibOS
OPEN_SSL_PATH=/opt/homebrew/Cellar/openssl@3/3.2.0_1

# CREATE WRAPPER.O
c++ -c -I $PHOTON_REPO_PATH/include -std=c++14 -O0 -g -Wl,-search_paths_first -Wl,-headerpad_max_install_names photonwrapper.cpp 


echo ".O BUILT"

# CREATE WRAPPER.SO
c++ -shared -o photonwrapper.so photonwrapper.o \
	-L $PHOTON_REPO_PATH/output  \
	$PHOTON_REPO_PATH/output/libphoton.a      \
	$OPEN_SSL_PATH/lib/libssl.dylib \
	$OPEN_SSL_PATH/lib/libcrypto.dylib \
	/Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libcurl.tbd -lpthread


echo ".SO BUILT"


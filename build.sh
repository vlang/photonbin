PHOTON_REPO_PATH=~/code/3rd/PhotonLibOS
OPEN_SSL_PATH=/opt/homebrew/Cellar/openssl@3/3.1.3

# CREATE WRAPPER.O
c++ -c -I $PHOTON_REPO_PATH/include -std=c++14 -O0 -g -Wl,-search_paths_first -Wl,-headerpad_max_install_names photonwrapper.cpp 


echo ".O BUILT"

# CREATE WRAPPER.SO
c++ -shared -o photonwrapper.so photonwrapper.o \
	-L $PHOTON_REPO_PATH/build/output  \
	$PHOTON_REPO_PATH/build/output/libphoton.a      \
	$OPEN_SSL_PATH/lib/libssl.dylib \
	$OPEN_SSL_PATH/lib/libcrypto.dylib \
	/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurl.tbd   -lpthread  


echo ".SO BUILT"


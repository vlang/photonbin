PHOTON_REPO_PATH=~/dev/src/cpp/PhotonLibOS

# CREATE WRAPPER.O
c++ -fPIC -c -I $PHOTON_REPO_PATH/include -std=c++14 -O0 -g -Wl,-search_paths_first -Wl,-headerpad_max_install_names photonwrapper.cpp 


echo ".O BUILT"

# CREATE WRAPPER.SO
c++ -shared -o photonwrapper.so photonwrapper.o \
	-L $PHOTON_REPO_PATH/output  \
	$PHOTON_REPO_PATH/output/libphoton.a      \
	-laio -lssl -lcrypto -lcurl  -lpthread  


echo ".SO BUILT"


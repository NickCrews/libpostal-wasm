DATA_DIR=$(pwd)/.libpostal_data
git clone https://github.com/openvenues/libpostal
cd libpostal
./bootstrap.sh
# Per emscripten docs, we need to use emconfigure and emmake instead of configure and make
# to build the lib to wasm
# https://emscripten.org/docs/compiling/Building-Projects.html?highlight=link#integrating-with-a-build-system
emconfigure ./configure --datadir="${DATA_DIR}" --disable-sse2 MODEL=senzing
emmake make -j10
sudo make install
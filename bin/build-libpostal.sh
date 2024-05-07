DATA_DIR=$(pwd)/.libpostal_data
git clone https://github.com/openvenues/libpostal
cd libpostal
./bootstrap.sh
# Per emscripten docs, we need to use emconfigure and emmake instead of configure and make
# to build the lib to wasm
# https://emscripten.org/docs/compiling/Building-Projects.html?highlight=link#integrating-with-a-build-system
# the LT_MULTI_MODULE=1 flag is there to avoid a `-force_load` error:
# https://github.com/emscripten-core/emscripten/issues/11764#issuecomment-679456112
LT_MULTI_MODULE=1 emconfigure ./configure --datadir="${DATA_DIR}" --disable-sse2 MODEL=senzing
emmake make -j10
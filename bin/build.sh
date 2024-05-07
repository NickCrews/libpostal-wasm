# Run the emcc command in a docker container
# Suggestion from https://emscripten.org/docs/getting_started/downloads.html#using-the-docker-image
emcc_docker() {
    docker run --rm -v $(pwd):/src -u $(id -u):$(id -g) emscripten/emsdk emcc "$@"
}

emcc -O3 -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' \
    libpostal.c \
    /usr/local/lib/libpostal.a
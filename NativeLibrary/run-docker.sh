docker run --rm -v $(pwd):/src -u $(id -u):$(id -g) \
  emscripten/emsdk:2.0.23 bash build.sh

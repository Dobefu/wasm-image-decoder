.PHONY: clean build-dev build

default: clean build

clean:
	rm -f main.js main.wasm

build-dev:
	emcc -o main.js main.c utils.c -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" -s "EXPORTED_FUNCTIONS=['_malloc', '_free']" -s TOTAL_STACK=512mb -O0 -s ASSERTIONS -gsource-map

build:
	emcc -o main.js main.c utils.c -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" -s "EXPORTED_FUNCTIONS=['_malloc', '_free']" -s TOTAL_STACK=512mb -O3

EXECUTABLE_NAME="ray_tracing_demo"
BUILD_DIR="./build"

COLOR_CLEAR  := $(shell tput -Txterm sgr0)
COLOR_RED    := $(shell tput -Txterm setaf 1)
COLOR_GREEN  := $(shell tput -Txterm setaf 2)
COLOR_YELLOW := $(shell tput -Txterm setaf 3)

all: clean config build run

clean:
	@echo "Cleaning ${BUILD_DIR}"
	@rm -rf ${BUILD_DIR}

config:
	@echo "Configuration"
	@mkdir ${BUILD_DIR} && cd ${BUILD_DIR} && cmake ..

build: config
	@echo "Starting build"
	@cd ${BUILD_DIR} && make

run: config build
	@echo "\n${COLOR_GREEN}--------   Running ray_tracing_demo --------${COLOR_CLEAR}\n"
	@./${BUILD_DIR}/${EXECUTABLE_NAME}

clang_format:
	@find -iname *.h -o -iname *.cpp | xargs clang-format -i

valgrind: clean config build
	@valgrind --leak-check=yes ${BUILD_DIR}/${EXECUTABLE_NAME}

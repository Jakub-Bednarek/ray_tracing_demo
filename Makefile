SHELL := /bin/bash
EXECUTABLE_NAME="ray_tracing_demo"
export BUILD_DIR="./build"

ROOT_DIR 	 := $(shell pwd)
COLOR_CLEAR  := $(shell tput -Txterm sgr0)
COLOR_RED    := $(shell tput -Txterm setaf 1)
COLOR_GREEN  := $(shell tput -Txterm setaf 2)
COLOR_YELLOW := $(shell tput -Txterm setaf 3)

all: config build run

clean:
	@echo "Cleaning ${BUILD_DIR}"
	@rm -rf ${BUILD_DIR}

config:
	@echo "Configuration"
	@$(shell [ ! -d "${BUILD_DIR}" ] && mkdir ${BUILD_DIR})
	@cd ${BUILD_DIR} && cmake ..

cpp_config:
	@echo "Configuration for cpptests"
	@$(shell [ ! -d "${BUILD_DIR}" ] && mkdir ${BUILD_DIR})
	@cd ${BUILD_DIR} && cmake .. -DENABLE_TESTING=True

build: config
	@echo "Starting build"
	@cd ${BUILD_DIR} && make

run: config build
	@echo "${COLOR_GREEN}--------   Running ray_tracing_demo --------${COLOR_CLEAR}"
	@./${BUILD_DIR}/${EXECUTABLE_NAME}

cpp_test: cpp_config
	@cd ${BUILD_DIR} && make
	./run_cpp_test.sh

clang_format:
	@find -iname *.h -o -iname *.cpp | xargs clang-format -i

valgrind: clean config build
	@valgrind --leak-check=yes ${BUILD_DIR}/${EXECUTABLE_NAME}

# Define the build directory
BUILD_DIR = build

# Default target: Clean and rebuild the project
all: clean build

# Remove the existing build folder
clean:
	rm -rf $(BUILD_DIR)

# Create the build directory and run CMake & Make
build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cd $(BUILD_DIR) && make

# Run the built executable
run: build
	./$(BUILD_DIR)/storage

# Clean build files and rebuild
rebuild: clean build

.PHONY: all clean build run rebuild


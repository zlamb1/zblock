rm -rf cross/build
mkdir cross/build
cmake -DCMAKE_TOOLCHAIN_FILE=cross/windows.cmake -DBUILD_SHARED_LIBS=OFF -B cross/build -S .

set -e

cd /app
cmake -GNinja -B/build .
cmake --build /build

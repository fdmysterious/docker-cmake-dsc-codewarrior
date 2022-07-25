mkdir -p build
docker run --rm \
	--mount type=bind,source="$(pwd)/SDK",target=/SDK         \
	--mount type=bind,source="$(pwd)/app",target=/app         \
	--mount type=bind,source="$(pwd)/scripts",target=/scripts \
	--mount type=bind,source="$(pwd)/build",target=/build     \
	buildenv:dsp56800 /bin/ash -c "/scripts/build.sh"

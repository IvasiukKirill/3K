docker build -t my-gcc-app .
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 gcc -o myapp main.cpp
docker run -it --rm --name my-running-app my-gcc-app

pause
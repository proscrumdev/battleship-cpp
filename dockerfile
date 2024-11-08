FROM gcc

Run apt-get update && apt-get install -y cmake
RUN apt-get update && apt-get install -y gdb
RUN apt-get install -y libgtest-dev
RUN apt-get install -y patchelf

WORKDIR /
FROM gcc

RUN apt-get update && apt-get install -y gdb
RUN apt-get install libgtest-dev

WORKDIR /
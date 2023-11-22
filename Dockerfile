FROM ubuntu:mantic-20231011

RUN apt-get update
RUN apt-get install --yes cmake g++-13 libgtest-dev

ENV USER=ubuntu
ENV HOME=/home/$USER
ENV SRC_DIR=$HOME/src
ENV BUILD_DIR=$SRC_DIR/build
ENV CXX=g++-13
ENV RESULT_DIR=$SRC_DIR/result

USER $USER
WORKDIR $SRC_DIR

COPY CMakeLists.txt main.cpp $SRC_DIR
RUN cmake -S $SRC_DIR -B $BUILD_DIR -D CMAKE_BUILD_TYPE=Debug
RUN cmake --build $BUILD_DIR
RUN ctest -T Test -T Coverage --test-dir $BUILD_DIR

ENTRYPOINT /bin/bash --login

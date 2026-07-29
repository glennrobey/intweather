FROM ubuntu:24.04

WORKDIR /app

RUN apt update && apt install -y \
    cmake \
    ninja-build \
    clang \
    git \
    curl \
    zip \
    unzip \
    tar \
    pkg-config \
    libssl-dev

# Install vcpkg
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg && \
    /opt/vcpkg/bootstrap-vcpkg.sh

# Install Drogon
RUN /opt/vcpkg/vcpkg install drogon

COPY . .

RUN cmake \
    -B build \
    -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake

RUN cmake --build build

EXPOSE 8080

CMD ["./build/intweather"]

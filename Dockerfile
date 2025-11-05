# syntax=docker/dockerfile:1.4

# -----------------------------------------------------------------------------
# Base
# -----------------------------------------------------------------------------

FROM ubuntu:24.04 AS base

SHELL [ "/usr/bin/env", "/bin/bash", "-c" ]

WORKDIR /maman01

COPY ./maman01.tar.gz /maman01

RUN apt-get update \
    && apt-get install \
    -y --no-install-recommends \
    tar zip curl perl unzip gcc-13 qemu-system build-essential \
    && apt-get autoremove \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# -----------------------------------------------------------------------------
# Build
# -----------------------------------------------------------------------------

FROM base AS build

RUN tar -xzf maman01.tar.gz

WORKDIR /maman01/xv6-01

# -----------------------------------------------------------------------------
# Final
# -----------------------------------------------------------------------------

FROM build AS final

ENTRYPOINT [ "/bin/bash" ]

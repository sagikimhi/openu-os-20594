# syntax=docker/dockerfile:1.4

# -----------------------------------------------------------------------------
# Base
# -----------------------------------------------------------------------------

FROM ubuntu:24.04 AS base

SHELL [ "/usr/bin/env", "/bin/bash", "-c" ]

WORKDIR /maman01

COPY ./xv6-01 /maman01

RUN apt-get update \
    && apt-get install \
    -y --no-install-recommends \
    gcc-13 build-essential qemu-system  \
    && apt-get autoremove \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# -----------------------------------------------------------------------------
# Build
# -----------------------------------------------------------------------------

FROM base AS final

ENTRYPOINT [ "/bin/bash" ]

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "uSocketsCryptoCpp",
    srcs = ["src/crypto/sni_tree.cpp"],
    deps = ["@openssl//:ssl"],
    copts = [
        "-std=c++17",
        "-flto",
        "-O3",
        ],
)

cc_library(
    name = "uSockets",
    hdrs = [
        "src/libusockets.h",
        "src/internal/internal.h",
        "src/internal/loop_data.h",
        "src/internal/networking/bsd.h",
        "src/internal/eventing/epoll_kqueue.h",
    ],
    srcs = [
        "src/bsd.c",
        "src/context.c",
        "src/loop.c",
        "src/socket.c",
        "src/crypto/openssl.c",
        "src/crypto/wolfssl.c",
        "src/eventing/epoll_kqueue.c",
        "src/eventing/gcd.c",
        "src/eventing/libuv.c",
    ],
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
    deps = [
        ":uSocketsCryptoCpp",
        "@openssl//:ssl",
        "@openssl//:crypto",
    ],
    copts = [
        "-DLIBUS_USE_OPENSSL",
        "-std=c11",
        "-Isrc",
        "-flto",
        "-O3",
        "-Wno-parentheses",
        ],
    linkopts = [
        "-std=c++17"
    ],
)
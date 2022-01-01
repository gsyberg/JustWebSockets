load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "uWebSockets",
    hdrs = glob(["src/*.h"]),
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
    deps = ["@uSockets"],
    copts = [
        "-lpthread",
        "-Wpedantic",
        "-Wall",
        "-Wextra",
        "-Wsign-conversion",
        "-Wconversion",
        "-std=c++2a",
        "-Isrc",
    ],
    linkopts = [
        "-lz"
    ],

)
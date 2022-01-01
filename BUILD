load("@rules_cc//cc:defs.bzl", "cc_binary")

filegroup(
    name = "certfiles",
    srcs = [
        "cert/server.crt",
        "cert/server.key",
    ],
)

cc_binary(
    name = "server",
    srcs = [
        "src/Server.cpp",
        "src/Utils.cpp",
        "src/Utils.h",
        "src/JustWebSocket.cpp",
        "src/JustWebSocket.h",
    ],
    data = [
        ":certfiles",
    ],
    deps = [
        "@uWebSockets",
        "@rapidjson//:rapidjson",
    ],
    copts = [
        "-std=c++2a",
    ],
)
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

http_archive(
    name = "openssl",
    sha256 = "17f5e63875d592ac8f596a6c3d579978a7bf943247c1f8cbc8051935ea42b3e5",
    strip_prefix = "boringssl-b3d98af9c80643b0a36d495693cc0e669181c0af",
    url = "https://github.com/google/boringssl/archive/b3d98af9c80643b0a36d495693cc0e669181c0af.tar.gz",
)

new_git_repository(
    name = "uSockets",
    remote = "https://github.com/uNetworking/uSockets.git",
    build_file = "@//bazel:uSockets.BUILD",
    branch = "master",
)

new_git_repository(
    name = "uWebSockets",
    remote = "https://github.com/uNetworking/uWebSockets.git",
    build_file = "@//bazel:uWebSockets.BUILD",
    branch = "master",
)

new_git_repository(
    name = "rapidjson",
    remote = "https://github.com/Tencent/rapidjson.git",
    build_file = "@//bazel:rapidJSON.BUILD",
    branch = "master",
)
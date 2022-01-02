# Just WebSockets
This is Just WebSockets. A packaging of the things you need to set up a secure C++ WebSockets server with one command. Packaged with RapidJSON serialization and a test client in JavaScript. Bazel will handle the few dependencies there are for you. Just WebSockets is essentially [uWebSockets](https://github.com/uNetworking/uWebSockets) packaged with some other stuff for use with Bazel.

# How to get started
1. Make sure you have Bazel. If not: [Install Bazel](https://docs.bazel.build/versions/4.2.2/install.html).
2. Clone Just WebSockets GitHub repo.
3. From the root of Just WebSockets, run: `bazel run server`

# Connecting to the server
You can test your server with the provided test client. Just open `index.html` in a browser.
- Add exception for the provided development certificates by pointing the browser to `https://localhost:3000` and accepting the certificate. Now the test client can connect to the server.
- Make sure you replace the provided temporary certificates with your own for any real implementation.
- You can generate your own development certificates with: `sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout server.key -out server.crt`.

# Manuals
- [uWebSockets](https://github.com/uNetworking/uWebSockets/blob/master/misc/READMORE.md)
- [RapidJSON](https://rapidjson.org/) 

# Notes
- Only OpenSSL, uSockets and uWebSockets are needed. You can remove the dependency on RapidJSON if you want to serialize the data soem other way.
- You can start the server with another port if you want to, just add a port number to the start command, i.e. for pport 4000 run: `bazel run server 4000`.
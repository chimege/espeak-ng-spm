// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
  name: "espeak-ng",
  products: [
      .library(name: "libespeak-ng", targets: ["libespeak-ng"]),
      .library(name: "espeak-ng-data", targets: ["data"]),
      .library(name: "libsonic", targets: ["libsonic"]),
  ],
  targets: [
      .target(
          name: "libsonic",
          exclude: ["_repo"],
          publicHeadersPath: "include",
          cSettings: [
              .headerSearchPath("_repo"),
          ]
      ),
      .target(
          name: "data",
          resources: [
              .copy("espeak-ng-data"),
              .copy("phsource"),
              .copy("dictsource"),
          ]
      ),
      // .executableTarget(name: "test", dependencies: ["libespeak-ng", "data", "libsonic"]),
      .target(
          name: "libespeak-ng",
          dependencies: ["libsonic"],
          exclude: [
              "_repo",
              "ucd/tests",
          ],
          publicHeadersPath: "include",
          cSettings: [
              .headerSearchPath("."),
              .headerSearchPath("_repo/src/include"),
              .headerSearchPath("_repo/src/include/compat"),
              .headerSearchPath("_repo/src/ucd-tools/src/include"),
              .define("ESPEAK_NG_API", to: ""),
              .define("N_PATH_HOME", to: "1024"),
          ]
      ),
  ]
)

# Libpostal WASM

At attempt to compile libpostal to a standalone .wasm file.

This would enable many host languages to use libpostal easily
and efficiently, since libpostal is sorta hard to setup
by itself.

Eventually I want to add an apache arrow interface,
to enable efficient bulk data parsing.

## Questions

- How does WASM handle the external data files that libpostal requires?
- Is the serialization the actual bottleneck? Like maybe I should
  just keep using the existing serial interface using pypostal, and the python<->C
  interop isn't actually the problem there.

## License

public domain, do what you want.
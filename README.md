# Mustache for Express for Arduino
Logic-less templates.

## Getting started

```cpp
...
auto mustacheExpress = require('mustache-express');

...
// Register ".mustache" extension with The Mustache Express
app.engine(F("mustache"), mustacheExpress());

app.set(F("view engine"), F("mustache"));
app.set(F("views"), __dirname + F("/views"));

app.get("/", [](request &req, response &res) {
  locals_t locals;
  locals[F("name")] = F("Chris");
  locals[F("value")] = F("42");
  res.render(index::file, locals);
});

```

## Dependencies
[Express for Arduino](https://github.com/lathoub/express).

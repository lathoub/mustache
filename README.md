# Mustache for Arduino


## Getting started

```cpp
auto mustacheExpress = require('mustache-express');

// Register ".mustache" extension with The Mustache Express
app.engine(F("mustache"), mustacheExpress());

app.set(F("view engine"), F("mustache"));
app.set(F("views"), __dirname + F("/views"));

app.get("/", [](request &req, response &res) {
  if (false)
    res.json("{'hello': 'world'}");
  else {
    locals_t locals;
    locals[F("een")] = F("in de titel");
    locals[F("twee")] = F("voor chapter 2");
    res.render(index::file, locals);
  }
});

```

## Dependencies
Express.

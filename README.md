# Mustache for Arduino


## Getting started

```cpp
auto mustacheExpress = require('mustache-express');

// Register ".mustache" extension with The Mustache Express
app.engine(F("mustache"), mustacheExpress());

app.set(F("view engine"), F("mustache"));
app.set(F("views"), __dirname + F("/views"));
```

## Dependencies
Express.

static struct logger logger_instance;

static void logger_init() {
  // ... initialize logger_instance ...
}

struct logger* logger() {
  static once_flag init = ONCE_FLAG_INIT;
  call_once( &init, &logger_init );
  return &logger_instance;
}

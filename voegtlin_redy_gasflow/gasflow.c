#include <stdio.h>
#include <errno.h>
#include <modbus.h>

float mbconverter(uint16_t val[]) {
  union mbfloat_t {
    float f;
    uint16_t H[2];
  } tmp;

  tmp.H[1] = val[0];
  tmp.H[0] = val[1];

  return tmp.f;
}

int main(int argc, char* argv[]) {

  modbus_t *ctx;
  int rc;
  const int DEVICE_ID = 247;
  uint16_t tab_reg[32];
  union tmp;

  if ( argc < 2 ) {
    fprintf(stderr, "Usage: %s dev\n", argv[0]);
    return -1;
  }

  ctx = modbus_new_rtu(argv[1], 9600, 'N', 8, 2);
  if (modbus_connect(ctx) == -1) {
    fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
    modbus_free(ctx);
    return -1;
  }

  rc = modbus_set_slave(ctx, DEVICE_ID);
  if (rc == -1) {
    fprintf(stderr, "Invalid slave ID\n");
    modbus_free(ctx);
    return -1;
  }

  rc = modbus_read_registers(ctx, 0, 2, tab_reg);
  if (rc == -1) {
    fprintf(stderr, "%s\n", modbus_strerror(errno));
    return -1;
  }

  modbus_close(ctx);
  modbus_free(ctx);

  printf("%f\n", mbconverter(tab_reg));

  return 0;
}

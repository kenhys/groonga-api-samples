#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main (int argc, char **argv)
{
  grn_ctx context;

  grn_init();
  grn_ctx_init(&context, 0);

  // https://www.clear-code.com/blog/2011/9/13.html
  // Tokyo station
  int latitude = ((35 * 60 * 60) + (40 * 60) + 52.975) * 1000;
  int longitude = ((139 * 60 * 60) + (45 * 60) + 57.902) * 1000;

  grn_obj point;
  GRN_WGS84_GEO_POINT_INIT(&point, 0);
  GRN_GEO_POINT_SET(&context, &point, latitude, longitude);
  grn_p_geo_point(&context, (grn_geo_point*)&point);

  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
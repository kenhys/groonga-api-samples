#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(int argc, char *argv[])
{
  grn_ctx context;
  grn_obj *db;

  grn_init();
  grn_ctx_init(&context, 0);
  db = grn_db_open(&context, "./testdb/db");

  grn_obj *obj;
  if (argc == 2) {
    obj = grn_ctx_get(&context, argv[1], strlen(argv[1]));
    if (obj) {
      grn_obj buffer;
      GRN_TEXT_INIT(&buffer, 0);
      grn_inspect_limited(&context, &buffer, obj);
      printf("INSPECT <%s>: <%.*s>\n", argv[1], (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));
    }
    goto exit;
  }

  const char *table_names[] = {
    "Int8PatTable",
    "ShortTextPatTable",
    "Int8HashTable",
    "ShortTextHashTable",
    "NoKeyTable",
    NULL
  };

  int i = 0;
  grn_obj buffer;
  while (table_names[i]) {
    GRN_TEXT_INIT(&buffer, 0);

    obj = grn_ctx_get(&context, table_names[i], strlen(table_names[i]));
    grn_inspect_limited(&context, &buffer, obj);
    printf("INSPECT <%s>: <%.*s>\n", table_names[i], (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));
    i++;
  }

exit:
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}

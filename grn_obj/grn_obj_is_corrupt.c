#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(void)
{
  grn_ctx context;
  grn_obj *db;
  grn_obj *obj;
  
  grn_init();
  grn_ctx_init(&context, 0);
  db = grn_db_open(&context, "./testdb/db");

  const char *obj_names[] = {
    "Int8PatTable",
    "Int8PatTable",
    NULL
  };

  int i = 0;
  while (obj_names[i]) {
    grn_obj buffer;
    GRN_TEXT_INIT(&buffer, 0);
    obj = grn_ctx_get(&context, obj_names[i], strlen(obj_names[i]));
    if (i % 2) {
      grn_obj_lock(&context, obj, GRN_ID_NIL, 0);
    }
    printf("<%s> corrupt?: <%s>\n",
           obj_names[i], grn_obj_is_corrupt(&context, obj) ? "true" : "false");
    GRN_OBJ_FIN(&context, &buffer);
    if (i % 2) {
      grn_obj_unlock(&context, obj, GRN_ID_NIL);
    }
    i++;
  }
  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}

**libfort** is a simple crossplatform library to create formatted text tables.

**libfort** is written in C and to use it you should include [fort.h](https://github.com/seleznevae/libfort/blob/develop/lib/fort.h) in your source files and compile with [`fort.c`](https://github.com/seleznevae/libfort/blob/develop/lib/fort.c) file. 

The functions generally follow standard C conventions. They tend to return 0 or a pointer when acting properly, and negative integer numbers or NULL when something went wrong.

**libfort** doesn't use any threading itself. Therefore you shouldn't specify default table properties or work with the same table from different threads without external synchronization. However, it should be safe to create different tables from different threads and work with them in each thread separately.

# Tutorial content
- [C API](C_API/Table-life-cycle.md)
  - [Table life cycle](C_API/Table-life-cycle.md)
  - [Filling tables with data](C_API/Filling-tables-with-data.md)
  - [Cell and table properties](C_API/Cell-and-table-properties.md)
  - [Border styles](C_API/Border-styles.md)
  - [Misc](C_API/Misc.md)


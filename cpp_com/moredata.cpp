/*
    // The following are the same:
    typdef existing_type new_type_name;
    using new_type_name = existing_type;
*/

/*
    // Unions allow a portion of memory to be accessed as diff. data types
    union type_name {
        member_type1 member_name1;
        member_type2 member_name2;
        member_type3 member_name3;
    } object_names;

    e.g.
    union mytypes_t {
        char c;
        int i;
        float f;
    } mytypes;

    mytypes.c
    mytypes.i
    mytypes.f

    union mix_t {
        int l;
        struct {
            short hi;
            short lo;
        } s;
        char c[4];
    } mix;
*/

/*
    // Anonymous unions
    // When unions are a member of a class or structure

    e.g.
    struct book_t {
        char title[50];
        char author[50];
        union {
            float dolloars;
            int yen;
        };
    } book;
    -->
    book.dollars, book.yen 

*/

/*
    // enum type
    enum type_name {
        value1,
        value2,
        value3,
        ...
    } object_names;

    e.g. 
    enum colors_t {black, blue, green, cyan, red, purple, yellow, white};
    colors_t myclolr;
    mycolor = blue;
    if (mycolor == green) mycolor = red;

    // Specific int value can be assigned
    e.g.
    enum months_t {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} y2k;

    // enum class
    enum class Colors {black, blue, green, cyan, red, purple, yellow, white};
    Colors mycolor;
    mycolor = Colors::blue;
    if (mycolor == Colors::green) mycolor = Colors::red;

    // Can have control over type
    enum class EyeColor : char {blue, green, brown};

*/
struct Options *create_options();

void load_options(struct Options * options,char * file);
//load the options from a file (if it doesn't exist load the default file)
void free_options(struct Options * options);
